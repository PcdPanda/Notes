# Clickhouse

### 1. 基本概念

1. 7200转机械磁盘每秒只能随机访问100次

2. SIMD(Single Instrument Multiple Data)使CPU实现简单的向量化

   

### 2. 部署和系统

目录结构

- /etc/clickhouse-server 存放全局配置config.xml
- /var/lib/clickhouse 默认的数据存放目录
- /var/log/clickhouse-server 日志保存目录

**启动和登录**

```shell
service clickhouse-server start # 启动
clickhouse-client -u <username> --password <password> # 登录,并交互式执行
```

#### 2.1 系统表system

- system.part 可以查询分区
- system.mutation可以查询update/delete的执行情况

#### 2.2 物化视图Materialized View

类似于触发器,当源表有改动时,会触发新表的结果(**只有insert会触发**)适合作为字表事实保存聚合的数据

物化视图**会实际储存数据,并有自己引擎,可以对其进行常规表的操作**



### 3. DDL数据定义

#### 3.1 复合类型

**当数据为Nullable的时候会浪费大量query时间,能不使用尽量不适用**

- Array 必须设置相同的数据类型
- Tuple 可以设置不同的数据类型
- Nested 相当于在行中加入了一个子表

#### 3.2 列的默认值

- default会真正储存,并作为一列
- materialize可以储存，但查询的时候默认不返回
- alias不会储存,只有在query时生成



### 4. MergeTree

#### 4.1 数据分区

对于每一个table,可以在创建时根据partition by进行分区,每个分区再分成不同的分区目录,每个目录下有分4类文件

- **txt**: 记录校验,ttl和列信息
- **idx**: 索引文件, primary idx的间隔是index granularity
- **bin**: **每列都有单独的bin**,为二进制数据文件,在bin文件内**再划分为小数据块进行压缩**
- **mrk**: 每列单独的mrk,以此连接索引和不同列的数据,**可以实现不同列的并行查询**

#### 4.2 分区子目录

每次写入会独立生成子分区,命名为 \<Partition>\_\<minBlock>\_\<maxBlock>\_\<level>

**之后定期(如15分钟)会对子分区进行合并**,并重新设定minBlock和maxBlock

也可以使用optimize手动合并

- 分区数据会先写入内存,再写入临时目录,嘴鸥胡再重命名
- 对于每个Table, BlockNum**会全局累加**
- 每次合并,会更新minBlock和maxBlock,并增加level

#### 4.3 分区的装载和卸载

```sql
ALTER TABLE <table> DROP PARTITION <key> -- 删除分区
ALTER TABLE <table_1> REPLACE PARTITION <key> FROM <table_2> -- 复制分区
ALTER TABLE <table> DEATCH/ATTACH PARTITION key -- 装载和卸载分区
```

#### 4.4 MergeTree Family

MergeTree的变种引擎可以在创建时添加参数,实现更多功能

在分区合并时,根据order by的主键进行不同的聚合操作

- **ReplacingMergeTree**: **相同分区内主键去重**

- **SummingMergeTree**: 在**同一分区中,根据order by**进行累加聚合

- **AggregatingMergeTree**: 通常作为View创建,提供能多的聚合方式

- **CollapsingMergeTree**: 通过插入**主键相同**的数据来删除原数据,只有**相同分区内的数据才会被折叠**

  折叠**对顺序有严格要求**,被折叠的数据必须sign是1(如果先写入sign=-1再写入sign=1则无法折叠)

- **VersionCollapsingMergeTree**: 在常规折叠树的基础上**加上version字段**,确保可以正常折叠

- **ReplicatedMergeTree**: 通过zookeeper在不同节点上创建副本的表



### 5. 其他引擎

#### 5.1 对外表接口

包括hdfs/mysql/jdbc/kafka/file

以clickhouse作为代理

#### 5.2 内存引擎

包括Memory/Set/Join/Buffer

作为查询中间件的表,创建后不可以进行DDL操作

用于临时存储或缓冲

#### 5.3 日志表

包括TinyLog(无并行和索引), StripeLog(有并行,只有一个文件), Log(文件多,并行性好). 

- 支持并行,列式存储和**写锁**.
- 不支持ALTER和索引,数据直接写入文件末尾

#### 5.4 接口表

1. **Merge**: 作为视图创建在**结构相同(引擎可以不同)**的表之上,来统一查询数据
2. **Distributed**: 分布式表,不储存数据,作为view建立在集群各个节点的本地表上,名字结尾必须是_all

3. **URL**: 作为http的客户端,查询数据时自动发送http请求到url返回表数据



### 6. 数据查询

通过客户端查询log可以知道查询计划

```sh
clickhouse-client -h ch7.nauu.com --send_logs_level=trace 'SELECT * FROM table;' > /dev/null
```

#### 6.1 特殊查询语句

1. with放在开头,用作临时语句

   ```sql
   WITH SUM(SELECT * FROM table2) as var
   SELECT SUM(*) * var FROM table2; -- 定义临时函数/查询结果
   ```
   
1. sample,**只能用于MergeTree**,可以根据int型column进行采样

   ```sql
   CREATE TABLE table(
   	ID Uint64,
       Val double
   ) ENGINE = MergeTree()
   SAMPLE BY intHash32(ID); -- sample的列必须是int
   
   SELECT Val, _sample_factor From table SAMPLE 0.1 [OFFSET 0.5];
   -- _sample_factor是采样系数(0.1) offset是从偏移量开始采样
   
   SELECT Val, _sample_factor From table SAMPLE 1000;
   -- 至少采样1000条数据
   ```

#### 6.2 Join

1. **array join**, 作用于嵌套或者array类型的column

   会将array列展开,拆分成单个元素,展开成多行

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

2. **连接精度**
   - all: 只要被连接表的列相等才会连接
   - any: 只有被连接表第一条相等的列才会连接
   - asof: 只要两者之差小于特定value就会连接 


#### 6.3 查询和聚合

1. **WHERE和PREWHERE**: 配合主键可以提高查询速度, PREWHERE会先取出要filter的键,再进行过滤,可以提速
2. **WITH (ROLLUP/CUBE/TOTALS)** 放在group by之后,可以汇总每次聚合的结果

3. **LIMIT by**: 运行与order by 和limt之间,可以返回**特定列固定的条数**



### 7. 分布式集群

借助zookeeper来实现同步,每个表都会有主副本,mutation在主表上进行,副本监听

#### 7.1 副本同步

1. **手动**在每个节点创建本地表
2. 各个节点通过在zk中创建znode来选举主副本
3. 对于表格的操作通过**log方式同步到所有节点**
   - 副本节点监听log消息,获悉主副本数据insert完成后发布的insert/merge/mutate的消息
   - 将从主副本获取/优化数据的任务加入队列
   - 构造临时分区,从主节点获取数据或者在本地merge/mutate,完成后重命名分区

#### 7.2 数据分片

每个结点存放的数据不同,因此需要构造**Distributed接口表**来统一处理,sql语句中需要加入**On Cluster \<cluster name\>**

- 本地表以\_Local结尾,分布式表用\_all结尾
- 分布式表是读时查的,因此一般创建都可以成功,**创建时会在所有节点创建**

```sql
CREATE TABLE test_all ON CLUSTER my_cluster(
	id int
)ENGINE = Distributed(my_cluster, database, test_local, rand()) -- <集群名>, <数据库>, <本地表>, [分片规则]
```

**写入数据时会根据分片规则,或者分片键和slot写入**

#### 7.3 集群数据查询

- 默认会**在每个节点上独立完成查询**,当筛选条件和全局有关时,查询结果会不一致

- 使用global关键字优化查询,会先汇总结果再过滤

  ```sql
  SELECT id FROM table_all WHERE id GLOBAL IN (SELECT DISTINCT id FROM table_all WHERE repo=200);
  ```

  