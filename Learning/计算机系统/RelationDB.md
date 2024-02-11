- [1. Overview](#1-overview)
    - [1.1 Algebra 用来描述DB的操作](#11-algebra-用来描述db的操作)
    - [1.2 内存/磁盘数据库](#12-内存磁盘数据库)
    - [1.3 Data Layout](#13-data-layout)
        - [Tuple数据概念](#tuple数据概念)
        - [数据类型](#数据类型)
        - [Precision](#precision)
        - [Column vs Row](#column-vs-row)
        - [Compression](#compression)
    - [1.4 Compression](#14-compression)
        - [压缩目标](#压缩目标)
        - [压缩颗粒度](#压缩颗粒度)
        - [列式压缩算法](#列式压缩算法)
    - [1.5 Data Pool](#15-data-pool)
        - [磁盘数据库的Memory Buffer Pool](#磁盘数据库的memory-buffer-pool)
        - [内存数据库 Data Pool](#内存数据库-data-pool)
- [2. Index Data Structure](#2-index-data-structure)
    - [2.1 Latch and Lock](#21-latch-and-lock)
        - [实现](#实现)
        - [分类](#分类)
        - [避免死锁方法](#避免死锁方法)
    - [2.2 Index](#22-index)
        - [分类](#分类-1)
        - [优化](#优化)
    - [2.3 Hash Table](#23-hash-table)
        - [Common hash function (**high throughput,collision rate low**) :](#common-hash-function-high-throughputcollision-rate-low-)
        - [Different Hash Schema](#different-hash-schema)
        - [分片并行优化](#分片并行优化)
    - [2.4 Whole Key Tree](#24-whole-key-tree)
        - [B+ Tree](#b-tree)
        - [T-Tree (Latch-free)](#t-tree-latch-free)
        - [B-W Tree (Latch Free)](#b-w-tree-latch-free)
    - [2.4 Partial Key Tree](#24-partial-key-tree)
        - [Trie](#trie)
        - [Radix Tree](#radix-tree)
        - [Inverted Tree](#inverted-tree)
        - [Judy Array/ART](#judy-arrayart)
- [3. Query Execution \& Optimization](#3-query-execution--optimization)
    - [3.1 Working Model](#31-working-model)
        - [Execution Model](#execution-model)
        - [Process Model](#process-model)
        - [Concurrency Model](#concurrency-model)
        - [Task Scehduling](#task-scehduling)
    - [3.2 Network \& API](#32-network--api)
        - [ODBC/JDBC Driver](#odbcjdbc-driver)
        - [数据处理](#数据处理)
        - [性能优化](#性能优化)
    - [3.3 Query Cost](#33-query-cost)
        - [Cost Components](#cost-components)
        - [Estimate Method](#estimate-method)
        - [Estimate Quality](#estimate-quality)
    - [3.4 Query Optimization](#34-query-optimization)
        - [Query Plan](#query-plan)
        - [Optimization Granularity](#optimization-granularity)
        - [Optimization Consideration](#optimization-consideration)
        - [Optimization Algorithm](#optimization-algorithm)
    - [3.5 Compliation](#35-compliation)
        - [Optimization](#optimization)
        - [Compliation Latency](#compliation-latency)
    - [3.6 Vectorization](#36-vectorization)
        - [基本概念](#基本概念)
        - [实现方式](#实现方式)
        - [应用场景](#应用场景)
        - [优缺点](#优缺点)
    - [3.7 Execution](#37-execution)
        - [Scanning](#scanning)
        - [Sort](#sort)
        - [Aggregate](#aggregate)
        - [Join](#join)
    - [3.8 User Define Function](#38-user-define-function)
        - [基本概念](#基本概念-1)
        - [SQL Server Froid](#sql-server-froid)
        - [UDF-to-CTE](#udf-to-cte)
- [4. Concurrency Control Protocol](#4-concurrency-control-protocol)
    - [4.1 Transaction](#41-transaction)
        - [Atomic](#atomic)
        - [Consistency](#consistency)
        - [Isolation](#isolation)
        - [Durability](#durability)
        - [Transaction Concurrency Detection](#transaction-concurrency-detection)
    - [4.2 Phase Locking Control (Pessimistic)](#42-phase-locking-control-pessimistic)
        - [2-Phase Procedure](#2-phase-procedure)
        - [Avoid Deadlock](#avoid-deadlock)
        - [Partition Control](#partition-control)
    - [4.3  Time Stamp Ordering Control (Optimistic)](#43--time-stamp-ordering-control-optimistic)
        - [Procedure](#procedure)
        - [Different Implementations](#different-implementations)
    - [4.4 Multi-Version Concurrency Control (MVCC)](#44-multi-version-concurrency-control-mvcc)
        - [Tuple Vesion and TimeStamp](#tuple-vesion-and-timestamp)
        - [Tuple's Link List for MV](#tuples-link-list-for-mv)
        - [Lath-Free Protocol Procedure](#lath-free-protocol-procedure)
        - [Garbage Collection](#garbage-collection)
        - [索引管理](#索引管理)
        - [Write-Skew-Anomaly](#write-skew-anomaly)
- [5. Transaction and Failure Recovery](#5-transaction-and-failure-recovery)
    - [5.1 Failure Recovery](#51-failure-recovery)
        - [Failure Type](#failure-type)
        - [Recover Method](#recover-method)
    - [5.2 Shawdow Paging](#52-shawdow-paging)
    - [5.3 Write Ahead Log (WAL)](#53-write-ahead-log-wal)
        - [写入内容](#写入内容)
        - [运行流程](#运行流程)
        - [Checkpoint](#checkpoint)
        - [Recovery 流程](#recovery-流程)
- [6. Distributed System](#6-distributed-system)
    - [6.1 System Architecture](#61-system-architecture)
    - [6.2 Data Replication](#62-data-replication)
        - [储存架构](#储存架构)
        - [访问控制](#访问控制)
    - [6.3 Analysis Pattern](#63-analysis-pattern)
        - [OLTP](#oltp)
        - [OLAP](#olap)
- [7. Hardware Optimization](#7-hardware-optimization)
    - [7.1 Persistent Memory](#71-persistent-memory)
        - [硬件结构](#硬件结构)
        - [PM特性](#pm特性)
        - [PM问题](#pm问题)
        - [DBMS Design Optimization](#dbms-design-optimization)
    - [7.2 GPU Acceleration](#72-gpu-acceleration)
        - [优点](#优点)
        - [缺点](#缺点)
        - [DBMS Design Choice](#dbms-design-choice)
- [8. DB数据特征](#8-db数据特征)
    - [8.1 实时时间序列数据](#81-实时时间序列数据)
        - [写入数据特征](#写入数据特征)
        - [读取特征](#读取特征)
    - [8.2 金融数据仓库](#82-金融数据仓库)
        - [写入数据特征](#写入数据特征-1)
        - [读取特征](#读取特征-1)

| 概念     | 诠释                                          |
| -------- | --------------------------------------------- |
| 执行力   | 在<u>遇到挫折</u>时继续完成任务               |
| 注意力   | 深度工作思考的效率,是个人最宝贵的东西         |
| 创造力   | 将不同概念联系在一起并产出新的<u>市场刚需</u> |
| 学习能力 | 找到<u>必要</u>知识和资源并迅速掌握           |
| 人际关系 | 使自己为人所需                                |

##### 执行力

1. <u>坚信自己在未来可以成功,明确未来的可塑性</u>
2. 给执行设立客观的度量方法和目标,并不断提高对自己的标准
3. 明确<u>困难和无趣是完成任务的必要条件</u>,离开舒适区才可以成功
4. 通过好奇心和给自己的奖励来激励自己执行

##### 专注力

1. <u>明确专注是快速通过不适区的最好方法</u>
2. 分析哪些哪些事物有价值,摈弃所有不具有价值的事物,减少<u>工作时和外界的联结</u>
3. 放松和调节情绪,提高对大脑的控制程度,并针对<u>快速进入专注和保持专注做训练以养成习惯</u>
4. 划分专注时间和闲暇时间,并在<u>专注时间给自己设立具有挑战性的目标</u>

##### 创造力

1. 基于逻辑,而不是从众心理来思. 理解大众的心态,参考精英的意见,并基于逻辑思考做出决定.
2. 探索概念的可扩展性和自动化程度,扩展性强可自动化的事业才有市场
3. 探索未来需求,思考未来什么东西让<u>大众高兴,用户的需求才是真正的需求</u>,
4. 先思考怎样提出好问题,再通过创造力去寻找答案

##### 学习能力

1. 反复被大众认可的书籍就是最有效的学习资源之一
2. 通过筛选法来找到学习新技能的最小必要条件,并以此快速掌握
3. 从过去不同领域的知识中进行归纳,总结和对比,提取事物的本质
4. 知识往往不是唯一的真理,将其<u>应用到实践</u>,才说明真正有收获

##### 人际关系

1. 明确痛苦往往都是幻觉,没必要宣泄负能量
2. 做出令人敬佩的事情后自然会有优质的人际关系
3. 明确自己和他人的共同利益和矛盾,以他人可以理解的方式进行合作

4. 学会主动感恩,<u>思考别人为自己付出了什么</u>
    - [1.4 Compression](#14-compression)
        - [压缩目标](#压缩目标)
        - [压缩颗粒度](#压缩颗粒度)
        - [列式压缩算法](#列式压缩算法)
    - [1.5 Data Pool](#15-data-pool)
        - [磁盘数据库的Memory Buffer Pool](#磁盘数据库的memory-buffer-pool)
        - [内存数据库 Data Pool](#内存数据库-data-pool)
- [1. Overview](#1-overview)
    - [1.1 Algebra 用来描述DB的操作](#11-algebra-用来描述db的操作)
    - [1.2 内存/磁盘数据库](#12-内存磁盘数据库)
    - [1.3 Data Layout](#13-data-layout)
        - [Tuple数据概念](#tuple数据概念)
        - [数据类型](#数据类型)
        - [Precision](#precision)
        - [Column vs Row](#column-vs-row)
        - [Compression](#compression)
    - [1.4 Compression](#14-compression)
        - [压缩目标](#压缩目标)
        - [压缩颗粒度](#压缩颗粒度)
        - [列式压缩算法](#列式压缩算法)
    - [1.5 Data Pool](#15-data-pool)
        - [磁盘数据库的Memory Buffer Pool](#磁盘数据库的memory-buffer-pool)
        - [内存数据库 Data Pool](#内存数据库-data-pool)
- [2. Index Data Structure](#2-index-data-structure)
    - [2.1 Latch and Lock](#21-latch-and-lock)
        - [实现](#实现)
        - [分类](#分类)
        - [避免死锁方法](#避免死锁方法)
    - [2.2 Index](#22-index)
        - [分类](#分类-1)
        - [优化](#优化)
    - [2.3 Hash Table](#23-hash-table)
        - [Common hash function (**high throughput,collision rate low**) :](#common-hash-function-high-throughputcollision-rate-low-)
        - [Different Hash Schema](#different-hash-schema)
        - [分片并行优化](#分片并行优化)
    - [2.4 Whole Key Tree](#24-whole-key-tree)
        - [B+ Tree](#b-tree)
        - [T-Tree (Latch-free)](#t-tree-latch-free)
        - [B-W Tree (Latch Free)](#b-w-tree-latch-free)
    - [2.4 Partial Key Tree](#24-partial-key-tree)
        - [Trie](#trie)
        - [Radix Tree](#radix-tree)
        - [Inverted Tree](#inverted-tree)
        - [Judy Array/ART](#judy-arrayart)
- [3. Query Execution \& Optimization](#3-query-execution--optimization)
    - [3.1 Working Model](#31-working-model)
        - [Execution Model](#execution-model)
        - [Process Model](#process-model)
        - [Concurrency Model](#concurrency-model)
        - [Task Scehduling](#task-scehduling)
    - [3.2 Network \& API](#32-network--api)
        - [ODBC/JDBC Driver](#odbcjdbc-driver)
        - [数据处理](#数据处理)
        - [性能优化](#性能优化)
    - [3.3 Query Cost](#33-query-cost)
        - [Cost Components](#cost-components)
        - [Estimate Method](#estimate-method)
        - [Estimate Quality](#estimate-quality)
    - [3.4 Query Optimization](#34-query-optimization)
        - [Query Plan](#query-plan)
        - [Optimization Granularity](#optimization-granularity)
        - [Optimization Consideration](#optimization-consideration)
        - [Optimization Algorithm](#optimization-algorithm)
    - [3.5 Compliation](#35-compliation)
        - [Optimization](#optimization)
        - [Compliation Latency](#compliation-latency)
    - [3.6 Vectorization](#36-vectorization)
        - [基本概念](#基本概念)
        - [实现方式](#实现方式)
        - [应用场景](#应用场景)
        - [优缺点](#优缺点)
    - [3.7 Execution](#37-execution)
        - [Scanning](#scanning)
        - [Sort](#sort)
        - [Aggregate](#aggregate)
        - [Join](#join)
    - [3.8 User Define Function](#38-user-define-function)
        - [基本概念](#基本概念-1)
        - [SQL Server Froid](#sql-server-froid)
        - [UDF-to-CTE](#udf-to-cte)
- [4. Concurrency Control Protocol](#4-concurrency-control-protocol)
    - [4.1 Transaction](#41-transaction)
        - [Atomic](#atomic)
        - [Consistency](#consistency)
        - [Isolation](#isolation)
        - [Durability](#durability)
        - [Transaction Concurrency Detection](#transaction-concurrency-detection)
    - [4.2 Phase Locking Control (Pessimistic)](#42-phase-locking-control-pessimistic)
        - [2-Phase Procedure](#2-phase-procedure)
        - [Avoid Deadlock](#avoid-deadlock)
        - [Partition Control](#partition-control)
    - [4.3  Time Stamp Ordering Control (Optimistic)](#43--time-stamp-ordering-control-optimistic)
        - [Procedure](#procedure)
        - [Different Implementations](#different-implementations)
    - [4.4 Multi-Version Concurrency Control (MVCC)](#44-multi-version-concurrency-control-mvcc)
        - [Tuple Vesion and TimeStamp](#tuple-vesion-and-timestamp)
        - [Tuple's Link List for MV](#tuples-link-list-for-mv)
        - [Lath-Free Protocol Procedure](#lath-free-protocol-procedure)
        - [Garbage Collection](#garbage-collection)
        - [索引管理](#索引管理)
        - [Write-Skew-Anomaly](#write-skew-anomaly)
- [5. Transaction and Failure Recovery](#5-transaction-and-failure-recovery)
    - [5.1 Failure Recovery](#51-failure-recovery)
        - [Failure Type](#failure-type)
        - [Recover Method](#recover-method)
    - [5.2 Shawdow Paging](#52-shawdow-paging)
    - [5.3 Write Ahead Log (WAL)](#53-write-ahead-log-wal)
        - [写入内容](#写入内容)
        - [运行流程](#运行流程)
        - [Checkpoint](#checkpoint)
        - [Recovery 流程](#recovery-流程)
- [6. Distributed System](#6-distributed-system)
    - [6.1 System Architecture](#61-system-architecture)
    - [6.2 Data Replication](#62-data-replication)
        - [储存架构](#储存架构)
        - [访问控制](#访问控制)
    - [6.3 Analysis Pattern](#63-analysis-pattern)
        - [OLTP](#oltp)
        - [OLAP](#olap)
- [7. Hardware Optimization](#7-hardware-optimization)
    - [7.1 Persistent Memory](#71-persistent-memory)
        - [硬件结构](#硬件结构)
        - [PM特性](#pm特性)
        - [PM问题](#pm问题)
        - [DBMS Design Optimization](#dbms-design-optimization)
    - [7.2 GPU Acceleration](#72-gpu-acceleration)
        - [优点](#优点)
        - [缺点](#缺点)
        - [DBMS Design Choice](#dbms-design-choice)
- [8. DB数据特征](#8-db数据特征)
    - [8.1 实时时间序列数据](#81-实时时间序列数据)
        - [写入数据特征](#写入数据特征)
        - [读取特征](#读取特征)
    - [8.2 金融数据仓库](#82-金融数据仓库)
        - [写入数据特征](#写入数据特征-1)
        - [读取特征](#读取特征-1)


# 1. Overview

### 1.1 Algebra 用来描述DB的操作

- $\sigma$ (Select): $\sigma_{a_{id}='a2'\and b_{id}>102}$
- $\pi$ (Projection): $\pi_{b_{id}-100, a_{id}}(\sigma_{a_{id}='a2'})$
- $\cup$ (Union): $R\cup S$
- $\cap$ (Intersection): $R\cap S$
- $-$ (Difference): $R-S$ 
- $\times$ (Product): $R\times S$ 笛卡尔积
- $\Join$ (Join): $R\Join S$ 内连接

### 1.2 内存/磁盘数据库

| 磁盘数据库       | 内存数据库                      |
| ---------------- | ------------------------------- |
| page table       | 数据库和App之间的网络通信       |
| 页面置换算法     | cache miss                      |
| log和故障恢复    | CPU通信时间 (log只需要保存redo) |
| 磁盘顺序读取延迟 | 无锁化(上锁延迟)                |

### 1.3 Data Layout

#####  Tuple数据概念

- 每个table称为bag: <u>无序,允许重复</u>
- 每个row为tuple

#####  数据类型

<u>Tuple内通过padding/reordering提高cache affinity</u>

- Fixed length(直接保存)
- Blob, Varchar 
  - tuple中只保存指针
  - <u>通过trie/index等方法提高cache locality并减少branch misprediction</u>
- Null
  - 用inf代替
  - <u>每列用一个bitmap表示null</u>

#####  Precision

- 默认使用常规浮点数保存,计算效率高
- <u>高精度场合(科学计算),可以指定精度,但是会影响计算性能</u>

- Large value:当tuple中的数值太大时,会保存指针,指向专门存这个数值的page(overflow page)

#####  Column vs Row

- N-Ary (行式存储): 适合OLTP, 增删改速度快
- DSM (列式存储): 
  - 适合OLAP, 查询速度快
  - sort后存储,可以节省空间
  - delta partition: 根据range把数据分区,插入后调整分区分界线

- Hybrid:
  - hot data用row, cold data用column
  - 定期由后台线程执行,将hot data导入到cold data


#####  Compression

- 不储存整个数字/字符串,而是保存offset(在sorted的数据中特别有效)

### 1.4 Compression

适合cold data, OLAP query

|          | 磁盘数据库          | 内存数据库 |
| -------- | ------------------- | ---------- |
| **重点** | 压缩比              | 解压缩速度 |
| **效果** | IO耗时少,占用空间少 | 读取速度快 |

##### 压缩目标

- 数据长度固定
- 直到最终输出结果的时候才解压缩
- 信息不会丢失

##### 压缩颗粒度

<u>每次对压缩内容进行更新/或者删除,都需要重新解压缩并再压缩</u>

| 颗粒度 | block             | tuple | Attribute  | column |
| ------ | ----------------- | ----- | ---------- | ------ |
| 例子   | 一定范围内的tuple | 每行  | 字符串数据 | 每列   |

##### 列式压缩算法

不同算法可以嵌套使用,提高压缩比

- Dictionary Encoding:
  1. 构造dictionary记录value到其他数据的code的映射 (order preserving)
  2. 可以使用array/hash/b+Tree用来作为映射
  3. 根据数据调整作用域,可以作用于column/table/block
  4. 在处理query的时候用dictionary转换

- Run length Encoding (RLE): 记录列中元素出现的offset和连续的count

- BitMap Encoding: column中为每个可能的value保存一个bitmap

- Oracle Byte-align Bitmap Codes:

  1. 把bitmap先分成byte

  2. 把byte分成chunk,每个chunk由若干个全0bytes添加非0的bytes
  3. 每个chunk记录
     - 非0 byte的序号
     - 每个非0byte中1的序号

- Delta Encoding: 记录offset/prefix和数据之间的delta

- Mostly Encoding: 分两个表,一个表只保存数据的若干位,如果overflow,就保存在另一个大表中

### 1.5 Data Pool

#####  磁盘数据库的Memory Buffer Pool

- Storage Layout
  - 以大小固定的page文件为单位存储,其中包含若干个tuple

  - 保存一个Page Directory,记录了每个page和table之间的映射关系

- Page Header Layout

  - 元数据(schema,page大小,版本号等)
  - 校验和
  - 属于的database和table

- Page Data Layout

  - Slotted pages (tuple和slot指针都存在同一个文件里):
    - 以tuple为格式存储,每个tuple有唯一的page_id+offset和header 
    - 从前往后是slot指针,指向文件内的tuple
    - 从后往前是每一个tuple数据,被slot指向
  - Log-Structure (HDFS和分布式系统常用)
    - 保存每次增删改日志,每次加载时,生成数据
    - 都是连续读写,磁盘利用率高
    - 读取速度慢,因为需要回滚所有日志(可以通过添加索引优化)

- Memory Buffer Pool <u>(不能使用mmap,因为无法控制回写)</u>

  类似页面置换算法,维护一块内存储存访问的page

  1. 通过malloc申请一大块内存,作为memory pool
  2. 将memory pool分区,每个区和page大小一样
  3. 从disk读取page时,先把page放入memory pool中. <u>读取disk时使用direct IO,因为file system的cache没有任何用</u>
  4. 维护一个Hash Table,
     - 保存每个内存区储存的page num
     - 维护每个page的dirty和reference count(使用page的线程数)
  5. 每一个线程从Memory buffer pool中获取数据 

#####  内存数据库 Data Pool

- Fixed data pool: 
  - 保存固定长度tuple数据
  - 如果有blob就保存指向Variable data pool的指针
  - 保存variable中blob的prefix以提高cache affinity
- Variable data pool: 保存blob长度和内容
- Disk Cold Data Pool: 内存数据库使用disk来保存不常用的冷数据
  - Cold/Hot Data Identification
    - 在每个tuple中添加字段,记录访问次数,容易导致并发竞争
    - 使用后台线程根据日志汇总tuple的访问模式   
  - 内存数据管理:
    - 将table中的数据根据hot/cold划分区域,index可能指向任何区域
    - 使用bloom filter保存冷数据,如果在index中找不到数据,就检索bloom filter和磁盘 
    - 统一index和tuple的数据结构,通过指针上的offest标记数据在disk/memory
  - 置换时点:
    - 设置Memory Threshold,当内存使用量过高,置换数据到disk
    - 当内存用满,且需要导入更多数据时,置换数据到disk
    - DBMS只负责热数据一直在内存,冷数据交给OS保管(操作简单,但是OS行为不确定,且系统调用费时)
    - 只有disk中tuple被经常访问,才被置换到memory
    - 只有disk中tuple被update时,才被置换到memory
  


<div STYLE="page-break-after: always;"></div>

# 2. Index Data Structure

### 2.1 Latch and Lock

| Latch                          | Lock                                    |      |
| ------------------------------ | --------------------------------------- | ---- |
| 面向数据结构,例如B-plus tree   | 面向logic data, 例如tuple value         |      |
| 用于每次SQL操作                | 用于Transaction实现Ioslation            |      |
| 通过mutex/atomic spin lock实现 | 没有固定实现方式,通常有lock manager处理 |      |

#####  实现

- adaptive spinlock

  1. 查看是否有其他线程在等锁
  2. 如果没有,就尝试spin获取锁
  3. 一段时间获取不到就把自己放入等待队列
- mutex lock: 使用方便,但是<u>需要进入kernel操作,成本高</u>

- atomic变量作为自旋锁: 通过CAS操作实现, <u>浪费cycle</u>

  - <u>浪费cycle</u>
- 连环锁 (Queued-based Spinlock)

  - 每个CPU的cache中都用一个变量标志latch
  - 当一个CPU的latch被锁住时,其他CPU的latch都被锁住,形成连锁
  - 每个CPU只等待自己cache中的latch释放

#####  分类 

- 读/写锁

  - 读锁通过count实现
  - 写锁只能被单独占用
  - 优化读锁方法: 给每个节点添加版本号,每次被写锁更新时升级版本,读锁读取数据后会recheck 版本号确认读取有效
- 悲观/乐观锁
  - 悲观: 在运行时给每个可能cover的table/page/tuple上锁
  - 乐观: 只在最后一步上锁,如果发现confliction再处理 (适合高并发)


#####  <u>避免死锁方法</u>

- 后台线程定期查看dependency graph
- 发现数据上锁时,就<u>杀死自己</u>

### 2.2 Index

只需要支持delete和insert, <u>update会被当做两者结合</u>

#####  分类

- <u>clustered index: 一个表只能有1个cluster index,数据会按照这个index排序</u>
- partial index: 只对部分数据有效的index,创建时添加where字句
- functional index: 针对key的计算结果生成的index
- cover index: index中不仅存key,还存一些数据,可以提高query速度

#####  优化

- 当有多个Index需要使用时,依次使用每次index删选,生成对应record ID的bitmap进行操作
- 根据Index获得Page ID后,先根据Page ID排序以减少随机IO次数

### 2.3 Hash Table

#####  Common hash function (**high throughput,collision rate low**) :

- Murmur-hash
- Facebook XX Hash

#####  Different Hash Schema

- linear Probe(现实中最常用的): 当本来分配的slot被占用时,用下一个空的 (当key被删除后还原很麻烦)
- Robin Hood Hash: 
  	- 尽可能将让每个key尽可能靠近应该被分配的slot
  	- <u>slot里记录每个key相对应该分配位置的偏移量</u>
  	- 经常重复分配,对cache不友好
- Hopscotch Hash
	- 每次hash将key分配到指定位置和周围的区域为[hash(key), hash(key)+offset]
  	- 如果指定区域都被用满了,就尝试rehash区域中的别的key,并将其移出
- Cuckko Hashing:
  	- 使用多个不同seed的hash function
  	- 如果一个hash function发生碰撞了,就弹出本来保存的key
  	- 使用下一个hash function来保存另一个key
  	- <u>当发生循环或者无法hash时,就要resize</u>
- Extending Hashing (Chain Hashing升级版)
  - 每一个slot维护一个local count记录使用多少bit
  - 当slot用满了以后,增加local count
  - 当有一个slot放的value太多时,增加count,重新hash到新的两个slot中
  - <u>rehash非常耗时</u>

##### 分片并行优化
- <u>将数据分片,可以有效提高并行度,但需要精调</u>
- Share Partition: 每个线程将key直接hash到shared hash table中,当访问同一个partition时,需要上锁
- Private Partition: 每个线程自己维护一个hash table,使用相同的hash 函数,再有额外的线程,负责把每个hash table相同partition整合到一起,整合时需要额外copy
- Radix Hash: 每个线程按照radix的方式,对自己key中的第1位进行hash并统计数量,再合并计算每个hash值占用的大小. 第一位完成后,再对第二位操作,以此类推. <u>对于向量化操作很友好</u>

### 2.4 Whole Key Tree

#####  <u>[B+ Tree](https://www.cs.usfca.edu/~galles/visualization/BPlusTree.html)</u>

- 性质
  - B+树是平衡的
  - 根节点外每个节点至少half-full ($M/2\leq\text{\#keys}\leq M-1$)
  - 每一个有$K$个key的节点,有$k+1$个子节点
- 插入
  1. 找到合适的节点
  2. 插入key
  3. 如果key的数量>=M了,就拆分节点的key
  4. 把节点的中位key提到父节点中,向上递归
- 一个节点通常对应一个Page
  - 节点内部的操作通常可以忽略,因为在内存中进行(binary search)
  - 非叶子节点会保存指向子节点的指针,这个指针可能在每次数据库启动的时候更新
- 子节点构成链表,方便range scan
- 访问流程
  1. 每次操作一个节点/子节点时,使用latch锁住节点
  2. read: 只需要锁住当前节点
  3. delete/insert: 需要判断是否会merge/split后再释放上层锁
  4. 确保节点不会merge/split后,再释放latch
- 乐观控制:write和read一样先只对当前节点上锁,发现冲突了以后用write lock重新来

#####  T-Tree (Latch-free)

- 节点数据结构
  - 包括的数据范围, min-key, max-key
  - 数据指针 (可能指向一个小的table)
  - 父节点,子节点指针 (每个节点都保存数据)
- 特点
  - 占用内存少
  - 很难平衡,指针太多

#####  <u>[B-W Tree (Latch Free)](https://15721.courses.cs.cmu.edu/spring2020/papers/06-oltpindexes1/mod342-wangA.pdf)</u>

- 节点数据结构 (delta实现无锁化)
  - 维护每个node的logic ID
  - 通过<u>global map</u>保存logic ID到physical address的映射
  - physical address指向该page中最新一条的delta record,并会定期压缩
  - page中的最大key和最小key
- 压缩方法
  1. 后台线程创建tuple副本
  2. 后台线程在副本上进行delta操作
  3. 使用cas修改global map指向副本
  4. 回收原index page
- 回收index
  - 给每个index page维护引用计数: <u>多核协调成本高</u>
  - 在cas重新指向时,将原index page放入epoch table,并记录访问的thread,在thread结束后回收

### 2.4 Partial Key Tree

可以更早知道key在不在

<u>遍历速度</u>慢,因为需要回溯. 如果每层只存一个bit,<u>需要考虑endian和sign问题</u>

#####  Trie

- span: 每一层节点保存的字符/bit数

#####  Radix Tree

- 与Trie类似,但当节点只有一个child时,不再延伸,而是保存剩余所有数据

#####  Inverted Tree

- 用于保存key很大的情况(例如key是一篇article), map(words -> article)

#####  <u>Judy Array/ART</u>

每个节点根据保存的key的数量,来使用不同保存方式. 切换时需要上latch

- Linear Node: 大小契合两个cache line,根据key的offset来匹配指针的offset
- Bitmap Node:用bitmap表示key并分块,根据每块中有效位的offset,来匹配指针的offset. 大小依然契合cache line
- Dense Node:每个key后都直接保存指针

<div STYLE="page-break-after: always;"></div>

# 3. Query Execution & Optimization

### 3.1 Working Model

##### Execution Model

- Iterator Model : 每次子节点yield一个tuple给父节点,类似cursor
- Vectorization Model: 类似Iterator,但是每个节点返回batch of tuple
- Materialization Model: 每个节点一次性返回所有结果 (浪费内存)

#####  Process Model

每个worker可以是thread/processs,负责处理一个work

| One Worker per Core | Multiple Workers per Core |
| ------------------- | ------------------------- |
| Cache友好           | 任务调度复杂,cache miss高 |
| 被阻塞时浪费cycle   | 提高CPU利用率             |

- Process Per Worker/Process Pool

  - 使用OS/Dispatcher进程调度worker
  - 用shared memory来减少每个process占用的内存,减少重复copy
  - <u>Cache不友好</u>
  - 一个进程crash不会影响整个DBMS
- Thread Per Worker (常用)
  - DBMS进程负责调度所有线程
  - 减少开销
  - <u>一个线程crash可能导致所有线程crash</u>

##### Concurrency Model

- Inter query parallelism:
  - 每个worker负责执行一个query,使DBMS同时执行多个query
  - 每个operator由一个worker独立执行

- Intra query parallelism:
  - 许多worker一起执行一个query,减少每个query的耗时
  - 把query中的每个操作分成若干个独立完成的任务,交给每个worker执行(例如遍历)
  - 添加了exchange operator在worker中交换数据


##### Task Scehduling

1. 尽量把同时访问的数据放在同一个socket的RDMA region里,再划分为morsel
2. 每个socket里的CPU优先执行访问本morsel的任务
3. 当有CPU空闲时,可以协助其他CPU执行task
   - hard queue: 不可以被其他CPU执行的task
   - soft queue: 可以被其他CPU执行的task
4. 使用watch dog/SQLOS管理线程和数据的调度

### 3.2 Network & API

##### ODBC/JDBC Driver

- 序列化/反序列化传输的数据,并统一用户/服务器端的数据结构
- 提供细节功能实现(解压缩,cursor迭代)
- 统一使用TCP/IP
- row-format,逐个解析tuple
  - client得到driver读到一个batch的tuple之后再开始操作,提高效率

##### 数据处理

- Bytes encoding(常用): 数据量小,格式统一,但是需要考虑大小端
- Text encoding: 把数据转换成ASCI字符串,浪费空间

- <u>网络延迟越大,数据压缩越有效</u>
- 更适合列式传输的protocol

##### 性能优化

TCP/IP需要触发OS的中断和系统调用,浪费大量时间

- Kernel Bypass: 用DPDK库绕过OS,直接访问network buffer
- RDMA: 
  - <u>速度非常快,但实现非常复杂</u>
  - database直接把数据写入本地内存,client通过远程访问内存获得数据
  - DBMS不知道什么时候client来读数据,可能会flush

### 3.3 Query Cost 

##### Cost Components
- Physical Costs:
  - CPU cycles
  - IO (Disk/Network)
  - Memory/Cache
- <u>Logical Costs</u>:
  - 每个table的tuple数量
  - 每个字段,distinct value的数量
  - Selectivity: 符合特定where条件的tuple数量
- Algorithmic Costs:
  - Access method (Index/Sequential/Random IO)
  - Join method (Hash/Sort/Nested Loop)

##### Estimate Method
<u>获得精准成本很高,因此不值得的</u>
- 通过跑micro-benchmarks获得系统参数和当前状态
- 构造抽样表,估计selectivity和cardinality
- Adaptive Optimization: 在query运行时,更新统计信息
- 指定/发现correlated的column并构造联合分部
- Estimate output=Estimate Input * Selectivity

##### Estimate Quality
- 当需要Join的表越来越多时,Optimizer的误差也会越来越大,倾向于低估cardinality
- 强行指定使用Hash Join和Sequential IO可以有效减少Optimizer犯错的概率
- 估计每个operator的输入输出是最重要的,也是最难的

### 3.4 Query Optimization
<u>优秀的Query Optimizer远比Execution Engine更重要</u>
##### Query Plan

1. 解析并重写SQL语句,删除无效部分
2. 根据Query遍历所有可行的logic plan
    - 拆分filter,并作用到单个表上
    - 修改每个table中读取的列
    - 使用不同的join顺序
    - 转化为不同的physical operator
3. 根据cost model生成最高效的plan
4. 将优化完成的plan变成由physical operator组成的pipeline,交给execution engine

##### Optimization Granularity 
- Single Query:
  - 可以从每个表自底向上/自顶向下
  - 优化简单,选择空间少  
  - 可能会受其他运行的Query影响
- Multiple Queries:
  - 可以先将一条复杂Query拆分成multiple queries 
  - 选择空间多,优化复杂,但更加实用  
  - 生成的plan并行性好

##### Optimization Consideration
- Search Time
  - Time Threshold： 优化耗时过长则停止优化
  - Cost Threshold： cost足够小则停止优化
  - Exhaustion: 当query较复杂时可能会需要好几天
- 选取Initial Plan
  - 将每次运行完的plan cache住,当有相似Query运行时,基于上次的plan和performance优化
  - 使用过去平均表现较好的plan,需要保存大量query执行数据
- Stability (相同Query在相同数据集上生成的query plan应该相同)
  - 根据SQL生成固定的random seed
  - 生成Query Plan时可以提供hints,例如使用特定的physical plan
  - 控制好Optimizer的版本
- <u>Adaptive Optimization</u>
  执行Query时,由于系统状态和数据改变,好的Query Plan会变差,因此需要实时优化
  - 将Query Plan模块化,并给每个模块生成equivalent的sub choice,可以在优化时选择
  - 运行时,监控系统参数并通过bloom filter来估计table的cardinality
  - 当Cost Model更新时,尝试Transform并优化尚未运行的Query部分

##### Optimization Algorithm
- Heuristic 
  1. 把复杂query拆分成很多简单小query,并把数据保存到临时表
  2. 按照固定逻辑进行简单优化每一条小query,例如根据表的大小join等,尽可能使用索引
  3. 便于实现和debug,但对于复杂query效果不佳
- Dynamic Programming
  1. 自底向上,构造每个table的访问和join方式
  2. 在构造的每一层,遍历所有plan,并删除表现不好的plan
  3. 在之前获得的plan基础上进一步构造上一层
  4. 内存消耗大,当表很多时遍历耗时
- Genetic
  1. 随机生成一些Query Plan
  2. 对Query Plan进行一些随机的Transformation
  3. 表现差的Query Plan大概率会在迭代中删除
  4. 内存消耗少,适合表很多的情况,但是大概率只能找到局部最优,plan的可解释性差
- <u>Cascade</u>
  1. 自顶向下,遍历所有可行的logic plan
  2. 通过Transform操作,将所有结果一样的logic plan划分到一个group
  3. 在每个group中继续遍历,到最后一层时,使用cost model转化为physical plan
  4. 保存每个group的最优physical plan和cost并提供给上一层计算
  5. 最优plan可以保存在哈希表中,给其他group plan时使用


### 3.5 Compliation

根据query plan,生成c++/byte/IR再执行

##### Optimization

- 在转译代码中将schema信息硬编码
- 代码中的function call全部inline化
- 压缩循环体,在每个loop中只有简单的scan
- 可以把pipeline中的每个operator分别编译,提高并行效率

##### Compliation Latency

- OLAP的复杂query会明显提高编译耗时,甚至超过query执行
- 通过cache硬编码后的code来减少编译延时(可以直接填充filter参数)
- OPCode
  - 既可以被编译,也可以被直接执行
  - 先用解释器,在无优化模式下执行一部分opcode (编译快,运行慢)
  - 执行时，后台编译器在优化模式下编译剩余的opcode (编译慢,运行快)

### 3.6 Vectorization

##### 基本概念

- AVX-512寄存器: CPU中4个特殊的512bit宽寄存器,可以依从性保存多个数据
- SIMD (Single Instruction Multiple Data): 针对AVX寄存器的特殊指令,可以对其中的多个数据进行并行操作,<u>一条指令可能消耗多个cycle</u>
- 纵向向量化(常用): 若干个寄存器进行向量求和等计算 
- 横向向量化: 对一个寄存器内的数据进行累计计算

##### 实现方式

- Query Plan: 通常在pipeline的一个stage中所有数据向量化计算完成后,才进入下一个阶段
- Auto Compilation: 在编译过程中,由编译器自动寻找可以向量化的部分,但是非常tricky,效果有限
- Explicit Vectorization: 在解析query的过程中,调用人工实现的基本vectorization函数,这些函数显式使用AVX寄存器
- Selective Load/Store: AVX寄存器和内存交互时,通过512bit掩码,决定内存中的数据对应寄存器中的哪个bit
- Selective Gather/Scatter: AVX寄存器和内存交互时,通过512长个元素的下标数组,决定寄存器的每个bit对应内存的offset

##### 应用场景
- 向量化计算: 基本加减乘除/比大小/位运算等
- Hash表检测碰撞:通过向量化比较hash 冲突
- 过滤: 并行计算where字句结果

##### 优缺点
- 结合iteration model可以提高运行速度,但是需要合理划分pipeline. 计算和hash join使用SIMD,而聚合使用iteration model
- 对Cache不友好,每次加载数据都会破坏cache line, 且擅长的hash join因为随机性本来就容易造成cache miss
- 可以prefetch data来减少cache miss的penalty
- 寄存器的导入/导出和计算需要有额外逻辑
- 性能提高有限,最后memory和cache还是会成为瓶颈

### 3.7 Execution

##### Scanning

- Prefetching: 在worker读取的时候,buffer pool manager提前加载后面的page
- Parallelization: 多线程同时取不同Page,减少IO耗时
- Buffer Pool Bypass: 额外使用内存作为buffer pool,避免sequential flooding
- Zone Map: 在每个page中保存一些聚合结果,可以避免全部遍历数据
- Late Materialization: <u>适用于列式存储,在join和where时,只读取特定列和offset</u>

##### Sort

<u>使用 Merge Sort减少随机IO</u> 

1. 从disk中读取page到memory
2. 在memory中sort page
3. 将排序好的page作为temporary file导出
4. 继续merge两两sorted temporary file
5. <u>在导出的时候,已经排序好的内存可以释放,用来加载下一次排序的Page,以减少IO耗时</u>

- <u>Level1 寄存器排序</u>:
  1. 把tuple 指针和tuple key导入4个AVX寄存器,每个寄存器有4个tuple
  2. 在寄存器间对每个数进行10次比较的wire sort. 因为时寄存器间操作,可以有效向量化
  3. 对寄存器间的数据进行转置,每个寄存器里的数据都是排序好的

- Level2 缓存排序
  1. 每个core将优先负责排序自己cache中的数据,并将数据导入到AVX寄存器
  2. 对AVX寄存器进行L1排序
  3. 使用进一步的wire sort将排序好的数据保存到自己的numa region中

- Level3 全局排序
  - <u>M-way(常用)</u>
    1. 每个core对inner table的一部分进行level1和level2排序
    2. <u>给每个core分配指定的range,core之间将自己排序好的数据根据range发送到别的core/numa(比较费时)</u>
    3. 所有core对outer table进行相同操作
    4. 每个core对自己numa部分的数据进行排序后再join
  - M-Pass
    1. 针对inner table和outer table,每个core都对一部分数据进行level1和level2排序
    2. MPMS会对inner table额外进行和M-way相同的操作
    3. 每个core各自遍历outer table的结果进行join

##### Aggregate

- Sort后聚合
  1. 根据group key排序
  2. 通过连续IO计算结果
- Hash后聚合
  1. 根据group key,把hash结果相同的数据放到相同partition
  2. 内存中每个partition只有一个Page,写满了就直接导出
  3. 如果partition中出现hash冲突,就换个function再hash一次,再区分
  4. 在每个partition不同的key上做聚合计算


##### Join

<u>把行数小的表作为left table</u>

- <u>Hash Join</u>:
  1. 计算left table所有key的值(<u>radix sort效果最好</u>),放到对应slot里
  2. 计算right table的hash值,和left匹配
- Nest Join: 读取left table的page,再遍历right table的所有page进行join
- Sort Merge Join: 先根据key排序,在两个排序好的表上使用cursor join (M-way效果最好)

### 3.8 User Define Function

##### 基本概念
- 优点
  - 减少网络通信次数
  - 整合应用逻辑,提高代码复用
- 缺点
  - 因为行为不可预测,没有cost model用来优化query plan
  - 执行无法使用并行化/向量化等特性

##### SQL Server Froid
 将UDF代入到原Query再生成新的Query交给Optimizer,可以带来上百倍的性能提升
1. 把function中的declarative语句转化为SQL
2. 拆分function中的逻辑如if,每部分逻辑的SQL会从临时表取数据并写入到临时表
3. 拼接或join所有逻辑和临时表
4. 把拼接好的结果代入调用UDF的query
5. 简化最终的Query并交给Optimizer生成query plan

##### UDF-to-CTE
通过将Query转化为可递归的CTE来处理UDF中的循环逻辑
1. 将UDF转化为由goto组成的赋值命令
2. 去除goto,把udf转化成内部function call的形式
3. 整合function call,转化成单独的函数递归调用形式
4. 把递归函数转化为CTE SQL

<div STYLE="page-break-after: always;"></div>

# 4. Concurrency Control Protocol

### 4.1 Transaction

数据库执行命令的最小单元

#####  Atomic

- Logging: 通过日志来记录修改过程,因此可以复原
- Shadow Page: 每次transaction开始前,copy需要用的page (速度很慢)

#####  Consistency

- 结合Concurrency Protocol和Lock确保data integrity

#####  <u>Isolation</u>

- 所有transaction不会互相影响,但是可以利用多核提高每个transaction性能

- <u>并行执行Transaction后的结果应该和某种顺序执行结果一致</u>
- 同一个transaction里多次read相同数据的结果应该相同

- 没有commit的transaction不会影响其他transaction

- 一个transaction应该不会修改其他transaction里还没commit的变量

#####  Durability

- Transaction执行后的结果应该永远保存

##### Transaction Concurrency Detection

- 根据不同TNX的query形成dependency graph
  - 如果有冲突操作,就形成一条依赖关系从先执行的指令指向后执行的指令
  - 出现环形依赖则abort

### 4.2 Phase Locking Control (Pessimistic)

#####  2-Phase Procedure

1. grow(获取锁): <u>使用tuple级锁并发度最高</u>
2. shrink(释放锁):<u>期间不能再获得锁</u>

#####  Avoid Deadlock

- 后台线程定期scan (DL Detect): 检查dependency graph
- 直接杀死特定txn (No wait): 普遍采用,但是要考虑重启transaction的消耗
- 根据ts设定优先级 (Wait die): 需要考虑设置timestamp的开销

#####  Partition Control

1. 每个线程单独负责一块partition
2. 每个partition有一个queue,需要访问的TNX进去排队
3. 只有TNX完成grow phase,才可以开始工作

### 4.3  Time Stamp Ordering Control (Optimistic)

#####  Procedure

1. 给每个transaction<u>添加时间戳</u>:有一定开销
2. 如果发现存在冲突情况(对象时间戳比自己大),就重新设置时间戳,重新开始transaction。
3. 带有新时间戳的transaction必然发生在旧的后面
4. 访问过X以后修改TS(X)的时间戳为自己transaction的TS(T)

#####  Different Implementations

- Basic T/O: 
  1. 判断想要读写的tuple时间戳是否比自己小,否则就abort
  2. 先把tuple保存到自己空间再读取
  3. write会直接到table中并附上时间戳
- Optimistic (OCC)
  1. 把所有可能触及的操作copy到自己空间(<u>copy成本大</u>)
  2. commit时进入validate,确认时间戳是否有效,否则就重来

### 4.4 <u>Multi-Version Concurrency Control (MVCC)</u>

#####  Tuple Vesion and TimeStamp 

每个tuple额外保存信息 (每个字段都是8 Bytes)

| TXN-ID             | Begin-TS: | End-TS   | Pointer                 | Read-Ts (Optional) | Read-Ct(Optional) |
| ------------------ | --------- | -------- | ----------------------- | ------------------ | ----------------- |
| 持有tuple写锁的TXN | 生效时间  | 失效时间 | 指向其他版本tuple的指针 | 上一次被写入时间   | 读者数量          |

#####  Tuple's Link List for MV

- Old-to-New

  表中始终维护最老版本,每个版本的指针指向新版本

  - 不用动index(gc很烦)
  - 如果有很多版本会浪费时间

- New-to-Old (适合OLAP)

  表中维护最新版本,每个版本指针指向老版本

  - 每次写入需要动index

- Time-Travel: main table中维护最新的版本,指针指向time-travel表中保存tuple老版本

- **Delta Storage (Best)**: main table中维护最新的版本,每个字段有指针指向delta表中只保存老版本的特定attribute

#####  Lath-Free Protocol Procedure

- MVTO (基本TimeStamp)
  1. 读的时候,刷新begin-TS
  2. 写时上锁创建新的tuple,完成后设置begin-ts
  3. <u>写时如果发现tuple的begin-TS比自己晚,则abort</u>(因为之后的transaction已经读取了)
- MV2PL
  1. 读时确认TXN-ID并设置Read-CT实现shared lock
  2. 写时同时设置TXN-ID和Read-CT实现mutex-lock

#####  Garbage Collection

和当前tnx时间无交集的tuple (可能过期,也有可能在未来),需要被删除

- 回收频率

  - 定期调用后台线程scan tuple并删除
    - 速度可能跟不上

  - 每次transaction traverse tuple链表的时候删除
    - 不被访问的tuple永远不会删除

  - 每次transaction结束后,过一定时间删除创建的版本

- 回收颗粒度

  - 单个tuple控制 (耗时高)
  - 按照时间戳,分批控制所有时间戳之前的tuple (每次tnx commit的时候,会把tuple的指针根据时间戳归类)
  - 按照table控制,在没有tnx时,回收整个table(需要知道每个query访问的table)

- 回收后处理

  - 把时间戳相近的tuple放在block中,减少下次清理成本

#####  索引管理

- 主键索引永远指向主数据
  - 每次update可以视为delete后create

- 二级索引指向主键索引

- 从undo log里找数据

#####  Write-Skew-Anomaly

两个tnx都只给需要修改的tuple添加时间戳,合并后不需要修改的反而被对方修改了 (黑白球)

- 验证方法:
  - 每个tnx维护自己的write/read set中每个tuple的指针
    - 每个tuple的start-ts应该在自己的start-ts之前
    - 如果是write则该tuple的end-ts应该在自己的end-ts之前,否则覆盖了未来数据
  - tnx commit时遍历运行期间所有committed tnx的redo log, 查看覆盖的tuple是否有交集,有则abort
- 减少寻找version方法
  - 分离main table和time travel table (new to oldest): 运行的tnx只需要修改time-travel table而不会影响正在运行的olap query
  - tnx的write/read set不保存每个tuple的指针,而是维护tuple索引区间
- version chain寻找优化
  - 在table中给最新版本预留空间,而不是只保存指针
  - table中额外保存一个指针,记录上次索引的version地址,这样不用每次从头开始找
  - 给index节点也提供ts

<div STYLE="page-break-after: always;"></div>

# 5. Transaction and Failure Recovery

### 5.1 Failure Recovery

#####  Failure Type

- Transaction Failure:
  - Logical Error: 违反数据定义
  - Internal State Error: 死锁等错误

- System Failure
  - Software Failure: 除以0
  - Hardware Failure: 断电等

- 硬件损坏

#####  Recover Method

基于Tnx的运行权限,recovery也不同。 权限越高,执行速度越快,recovery越复杂

- Steal:
  - 没有commit的transaction可以修改table里的数据 (省时)
  - <u>Steal在Recovery时需要Undo把table里的数据还原</u>
- Force: 
  - Transaction commit之前数据已经保存在disk page里 (耗时)
  - <u>Non-force在Recovery时需要Redo把log中的内容输出到磁盘</u>

### 5.2 Shawdow Paging

1. 每个TNX把自己的数据写入到disk到自己的copy里 (Non-streal)
2. commit的时候通过CAS使自己的copy生效 (Force)

- 问题
  - TNX执行耗时,需要batch commit
  - 反复修改指针,增加内存碎片和随机IO

### 5.3 <u>Write Ahead Log (WAL)</u>

数据先写入log,之后再持久化,将<u>随机IO变成顺序IO</u>

#####  写入内容

- log record

  | Log ID  | TNX ID  | Page ID  | Undo       | Redo       | Previous TNX Log ID  |
  | ------- | ------- | -------- | ---------- | ---------- | -------------------- |
  | log序号 | TNX序号 | Page编号 | 修改前的值 | 修改后的值 | 该TNX的上一条log序号 |

  - 其他数据

    - 写入sql逻辑指令

    - 写入uncommitted的数据 (速度快,但系统复杂)

- Dirty Page Table

  - PageID: 脏页号
  - First Log: 导致该页dirty的第一条log ID

- TNX Table
  - TNX ID: 事务ID
  - Lasg Log ID: 该事务的最后一条log ID
- Global LogID: 全局的最新log

##### 运行流程

可以将log颗粒度调整为每个CPU Socket提高并行效率

1. TNX直接修改数据(STEAL),这时写入log record
2. Abort时补充compensation log record (CLR),写入新的log,只不过undo和redo项相反
3. commit后添加transaction end标识符,说明该部分log可以被视为持久化
5. 定时/定量保存check point,执行log更新数据(此时可能停止接受新的transaction或暂定正在运行的transaction)
5. 更新数据的同时,把log Id也持久化到磁盘

##### Checkpoint

- 维护全局标识,记录每个TNX的执行情况(commit, abort, epoch time)
- 根据epoch time/content size为周期来触发checkpoint
- 可配合MVCC在获取snapshot的时候做checkpoint
- 可通过OS Fork专门构造log进程来保存snap shot(需要跳过abort的commit)

#####  Recovery 流程

1. 从log中找到check point,还原现场
2. 对于DPT中的每个Page, 找到page checkpoint导入的log Id
3. 对比DPT中保存的Page log ID和持久化的log Id
4. 如果DPT的log更大,说明这个page还没更新,需要redo
5. 根据TNX Table,找到所有uncommited TNX的最后一条log ID
6. 从后往前生成对应的CLR并undo

<div STYLE="page-break-after: always;"></div>

# 6. Distributed System

分布式系统不仅要考虑协调多个核心工作,还要考虑<u>协调的成本</u>

### 6.1 System Architecture

- 硬件架构: 内存/磁盘/(RDMA)
- 功能架构: 每个节点负责query中的不同功能(MongoDB)/所有节点都一样
- 流程架构: client和scheduler沟通/client直接把query发给每个节点

### 6.2 Data Replication

##### 储存架构

- 整个表存在一个节点,实现简单,通信成本低
- 每个节点存表的一部分<u>(需要合理选择partition key)</u>,实现复杂,效率高
  - Consistent Hash:每个节点存一定range的数据,添加节点只需要rehash一部分数据,非常方便
- 副本和分片控制:
  - 每个节点都可以写入,需要使用一致性协议
  - 针对每个副本和分片设置一个master node,负责控制每个节点的数据

##### 访问控制

- Master-Replica: 
  - 只有Master可以Write,完成后propogate到replica
  - Propogate不原子,但保证最终一致性,协调成本低
- Multi-Master:
  - 所有节点都可以写
  - 事实一致性,协调成本高
- Query Optimization
  - 全局的Optimizer为整个Query生成全部Plan
  - 有一个全局Optimizer决定子节点执行的Query内容,每个子节点本地还有个Optimizer为自己的Query生成Plan

### 6.3 Analysis Pattern

#####  OLTP

- Atomic Commit Protocol(使用一致性协议ZAB/RAFT/PAXOS达成同步)
  - Two Phase Protocol: <u>如果有一个子节点abort,则整个transaction都要abort</u>
    1. request commit
    2. confirm protocol
  - Paxos: <u>只要majority节点confirm,则整个transaction可以继续</u>
    1. Proposer提出transaction
    2. 如果在commit阶段,收到了其他冲突的transaction就会reject当前的proposal
    3. 为了防止loop forever, 节点会周期性的选举leader来决定处理冲突的优先级

#####  OLAP

数据通常从OLTP数据库ETL到OLAP之后被用作分析,<u>对数据的时效性不高</u>

- Schema
  - Star Schema: Facet Table保存event,其他数据都通过外键连接到dimension table (尽量减少Join)
  - Snowflake Schema: 在Star Schema基础上,<u>dimension table继续通过外键连接到其他表</u>
- Query Fault Tolerance: 在query执行过程中take snapshot,以减少big query rerun的时间 (Hadoop使用,但是速度慢)


<div STYLE="page-break-after: always;"></div>

# 7. Hardware Optimization
### 7.1 Persistent Memory
##### 硬件结构
- Memristor: 电路基本元件,电阻和电压正相关
- Phase-change Memory: 通过改变温度/电流方向修改元件状态
- <u>STT-MRAM</u>: 使用磁场控制内部数据,体积小,容量大,可以提供L1cache级别的延迟
##### PM特性
- 快速的随机访问,颗粒度到byte
- 可以持久化保存的数据
- 提供特殊的API让应用程序控制持久化
##### PM问题
- 数据库重启之后,页表会改变,需要维护到PM的持久化映射
- 需要由CPU负责讲cache中的数据持久化,类似fsync
##### DBMS Design Optimization
- Copy-On-Write : 当TNX拷贝/写入数据时,不用copy page而是只copy需要的tuple
- Write-Behind-Log: 
  - 因为提供数据持久化,所以不需要redo
  - 将TNX维护成组,分配commit TS
  - 只记录没有commit的组,并进行GC和Undo 
### 7.2 GPU Acceleration
##### 优点
- 非常适合并行化操作,可以快速基于where条件scan table
- 可以提供更大规模的向量化操作
- 适合开发Matrix Database适合机器学习等计算
##### 缺点
- 不擅长分支预判,例如处理B+树效率低
- CPU和GPU之间copy数据的带宽有限
##### DBMS Design Choice
- 把整个DBMS运行在GPU中,对所有Query暴力使用Seq Scan
- 通过Batch Iteration Model,使GPU可以先对一个batch进行计算

<div STYLE="page-break-after: always;"></div>

# 8. DB数据特征

### 8.1 实时时间序列数据

Influx DB

##### 写入数据特征

- 高吞吐量,写入频率高
- 写入和读取延迟低,不能互相阻塞(wal)
- 临近数据差别不会特别大,有连续性(适合delta存储)
- 数据根据TS排序

##### 读取特征

- 大部分数据不会被访问,但是需要<u>实时聚合降采样</u>

- 对近期数据精度要求高,长期数据需要删除(处理删除速度要快)

### 8.2 金融数据仓库

[Smooth Storage]([Smooth Storage: A Distributed Storage System for Managing Structured Time Series Data at Two Sigma - Two Sigma](https://www.twosigma.com/articles/smooth-storage-a-distributed-storage-system-for-managing-structured-time-series-data-at-two-sigma/))

##### 写入数据特征

- 数据经过预处理
- 写入的数据对应TS Range而不是TS (range shard)
- 需要原子性,不能影响其他线程读取数据 (shard指向数据,每次更新生成新的shard和指针)
- Table的Schema需要经常更新 (schema保存在shard,和数据分离)

##### 读取特征

- 并发量不高,但是每个线程的吞吐量很大
- 需要权限管理
- 会从多个维度进行filter,需要将数据作为cube data来处理
