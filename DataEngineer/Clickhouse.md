[toc]

# 1. Merge Tree 

### 1.1 数据分区

##### Part

- Clickhouse处理数据的最小单位
- 根据建表时的partition key将数据分成不同的part
- 每个part内列式存储,<u>query时可以使用向量化计算(SIMD)</u>
- <u>每个part可以由不同核心访问,充分提高并行度</u>

##### Primarily Index

- 每个part内有独立的primarily index,且按序存储
- 按照建表时的granular,指向其他列文件

| txt                                 | idx                                    | mrk                                    | bin              |
| ----------------------------------- | -------------------------------------- | -------------------------------------- | ---------------- |
| part元信息,生命周期,schema,校验和等 | 基于granularity的索引,用于快速查找数据 | 维护从idx文件到数据文件bin的offset映射 | 被压缩的数据文件 |

### 1.2 数据修改

##### 数据编辑

- 每次编辑数据,会生成新的分区,名字为\<Partition>\_\<minBlock>\_\<maxBlock>\_\<level>
- 生成新分区时,不会影响当前正在运行的Query
- 可以手动/系统周期性合并分区,<u>并通过修改指针进行原子替换</u>,再修改minBlock和maxBlock的值

##### 装载/卸载分区

可以直接通过编辑table包含的分区,快速修改数据

```sql
ALTER TABLE <table> DROP PARTITION <key> -- 删除分区
ALTER TABLE <table_1> REPLACE PARTITION <key> FROM <table_2> -- 复制分区
ALTER TABLE <table> DEATCH/ATTACH PARTITION key -- 装载和卸载分区
```

### 1.3 Merge Tree Family 变种

Merge Tree的变种引擎可以在创建时添加参数,实现更多功能

##### 去重引擎

去重引擎通过insert来代替delete,避免删除时创建分区

- Replacing Merge Tree: 相同分区内主键去重

- Collapsing Merge Tree: 通过插入<u>主键相同的数据来删除原数据</u>,只有相同分区内的数据才会被折叠

  折叠对顺序有严格要求,被折叠的数据必须sign是1(如果先写入sign=-1再写入sign=1则无法折叠)

- <u>Version Collapsing Merge Tree: 在常规折叠树的基础上加上version字段,确保可以正常折叠</u>

##### 聚合引擎

<u>在分区合并时</u>,主键进行不同的聚合操作

- Summing Merge Tree: 在同一分区中,根据order by的key进行累加聚合
- Aggregating Merge Tree: 通常作为View创建,提供能多的聚合方式

### 1.4 分布式引擎

使用replicated merge tree引擎, Clickhouse通过Zookeeper来实现结点间的通信

```sql
CREATE TABLE test_all ON CLUSTER my_cluster(
	id int
)ENGINE = Distributed(my_cluster, database, test_local, rand()) -- <集群名>, <数据库>, <本地表>, [分片规则]
```

##### 副本同步

1. <u>手动</u>在每个节点创建本地表,
2. 各个节点通过在zk中创建znode来选举主副本
3. 对于表格的操作通过<u>log方式同步到所有节点</u>
   - 副本节点监听log消息,获悉主副本数据insert完成后发布的insert/merge/mutate的消息
   - 将从主副本获取/优化数据的任务加入队列
   - 构造临时分区,从主节点获取数据或者在本地merge/mutate,完成后重命名分区

##### 数据分片

每个结点存放的数据不同,因此需要构造<u>Distributed接口表</u>来统一处理,sql语句中需要加入<u>On Cluster \<cluster name\></u>

- 本地表以\_Local结尾,分布式表用\_all结尾
- 分布式表是读时查的,因此一般创建都可以成功,<u>创建时会在所有节点创建</u>

##### 负载均衡

- 保存数据时,Clickhouse会基于round robin原则在各个结点写入数据
- 删除数据后,<u>用户需要手动rebalance</u>

# 2. 功能特性

### 2.1 数据类型

##### 可嵌套数据类型

```sql
CREATE TABLE table1(
    title String,
    nest Nested(
    	v1 int,
        v2 int
    )
)Enging=MergeTree()
SELECT title, nest.v1, nest.v2 FROM table1 ARRAY JOIN nest.v2; -- v2会被展开,而v1还是array
SELECT title, nest.v1, nest.v2 FROM table1 LEFT ARRAY JOIN nest.v2; -- 如果v2是空,则依然会展开该行
```

- Array 必须设置相同的数据类型
- Tuple 可以设置不同的数据类型
- Nested 相当于在行中加入了一个子表

##### 列类型

- Default: 会真正储存,并作为一列
- Materialize: 可以储存，但查询的时候默认不返回
- Alias: 不会储存,只有在query时生成

### 2.2 Query查询

Clickhouse没有query optimizer,所以都是顺序读取,且性能具有一致性

##### 执行流程

1. 根据partition找到数据所在part

2. 读取part的idx文件,找到索引序号
3. 在mrk文件中根据索引序号找到offset
4. 根据offset从bin文件中解压并读取数据

##### 分布式查询

- 默认只会在每个结点上<u>独立执行查询,并汇总结果</u>,此时DISTINCT可能无效

- 使用全局聚合或者全局子查询结果时,必须手动指定global关键字

  ```sql
  SELECT id FROM table_all WHERE id GLOBAL IN (SELECT DISTINCT id FROM table_all WHERE repo=200);
  ```

### 2.3 特殊表引擎

##### <u>Materialized View</u>

- 本质上是一个<u>保存实际数据</u>的表,有自己的引擎,但其中的<u>数据对其他表有依赖</u>
- 当被依赖表数据更新时,materialized view会被触发修改自身数据

##### 外部引擎接口

使用Clickhouse作为代理,提供访问其他系统数据的接口

| hdfs | mysql | jdbc | kafka | file |
| ---- | ----- | ---- | ----- | ---- |

##### 日志引擎

- 支持并行,列式存储和**写锁**.
- 不支持ALTER和索引,数据直接写入文件末尾

| Tiny Log     | Stripe Log                     | Log             |
| ------------ | ------------------------------ | --------------- |
| 无并行和索引 | 有并行,但只有一个文件,会有竞争 | 文件多,并行性好 |

##### 内存引擎

- 包括Memory/Set/Join/Buffer

- 作为查询中间件的表,创建后不可以进行DDL操作

- 用于临时存储或缓冲

##### 接口表

- <u>Merge</u>: 作为视图创建在<u>结构相同(引擎可以不同)</u>的表之上,来统一查询数据
- <u>Distributed</u>: 分布式表,不储存数据,作为view建立在集群各个节点的本地表上,<u>名字结尾必须是_all</u>

- URL: 作为http的客户端,查询数据时自动发送http请求到URL返回表数据