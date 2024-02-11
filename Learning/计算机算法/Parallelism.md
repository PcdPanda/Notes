- [1. Overview](#1-overview)
    - [1.1 Objectives of Parallelism Design](#11-objectives-of-parallelism-design)
        - [Hardware Design](#hardware-design)
        - [Software Design](#software-design)
    - [1.2 Performance Evaluation](#12-performance-evaluation)
        - [Absolute Performance](#absolute-performance)
        - [Speed Up](#speed-up)
        - [Efficiency](#efficiency)
        - [Arithmetic intensity](#arithmetic-intensity)
    - [1.3 Scalability 可扩展性](#13-scalability-可扩展性)
        - [Strong Scalability](#strong-scalability)
        - [Weak Scalability](#weak-scalability)
        - [Scalability Constrains](#scalability-constrains)
        - [Scalability Optimization](#scalability-optimization)
    - [1.4 Contention](#14-contention)
        - [Dead/Live Lock](#deadlive-lock)
        - [Starvation](#starvation)
        - [Contention Avoidance](#contention-avoidance)
- [2. Instruction-level-parallelism (ILP)](#2-instruction-level-parallelism-ilp)
    - [2.1 Pipeline架构](#21-pipeline架构)
        - [Instruction Parallelism](#instruction-parallelism)
        - [Data Hazard](#data-hazard)
        - [Control Hazard](#control-hazard)
    - [2.2 Single Instruction Multiple Data(SIMD)](#22-single-instruction-multiple-datasimd)
        - [AVX Architecture](#avx-architecture)
        - [Drawback](#drawback)
    - [2.3 Out-of-Order Execution (OoO)](#23-out-of-order-execution-ooo)
        - [Dataflow](#dataflow)
        - [Hazard](#hazard)
        - [Limitation](#limitation)
    - [2.4 Memory Consistency](#24-memory-consistency)
        - [Memory Access Out of Order](#memory-access-out-of-order)
        - [Memory Fence](#memory-fence)
        - [Dependency](#dependency)
- [3. CPU Multithread Parallelism](#3-cpu-multithread-parallelism)
    - [3.1 Multi-Threading](#31-multi-threading)
        - [Memory Latency Hiding](#memory-latency-hiding)
        - [Simultaneous Multi-Threading (SMT超线程)](#simultaneous-multi-threading-smt超线程)
        - [Thread Pool](#thread-pool)
    - [3.2 Interconnection Hardware Design](#32-interconnection-hardware-design)
        - [设计要点](#设计要点)
        - [架构对比](#架构对比)
        - [Flow Control](#flow-control)
        - [Routing](#routing)
    - [3.3 Cache Coherence](#33-cache-coherence)
        - [Consistency Problem](#consistency-problem)
        - [Shared Cache Architecture](#shared-cache-architecture)
        - [Reduce Consistency Problem (Line Padding)](#reduce-consistency-problem-line-padding)
        - [多级Cache一致性](#多级cache一致性)
    - [3.4 Cache Snooping-Based Model](#34-cache-snooping-based-model)
        - [Cache Controller](#cache-controller)
        - [VI模型 (Write back)](#vi模型-write-back)
        - [MESI模型 (Write Through)](#mesi模型-write-through)
        - [Optimization](#optimization)
    - [3.5 Cache Directory-Based Model](#35-cache-directory-based-model)
        - [Cache Directory](#cache-directory)
        - [工作流程](#工作流程)
        - [Optimization](#optimization-1)
- [4. GPU Parallelism](#4-gpu-parallelism)
    - [4.1 处理器架构](#41-处理器架构)
        - [Warp-Thread](#warp-thread)
        - [Core-Block](#core-block)
        - [Grid](#grid)
    - [4.2 显存架构](#42-显存架构)
        - [Global Level Memory](#global-level-memory)
        - [Block(Core) Level Memory](#blockcore-level-memory)
        - [Thread(Warp) Level Memory](#threadwarp-level-memory)
        - [Cache Coherence](#cache-coherence)
    - [4.3 Programming Model](#43-programming-model)
        - [Program Global Design](#program-global-design)
        - [Kernel Function Design](#kernel-function-design)
        - [图形渲染流程](#图形渲染流程)
- [5. Parallel Program Design](#5-parallel-program-design)
    - [5.1 Program Decomposition](#51-program-decomposition)
        - [抽象逻辑](#抽象逻辑)
        - [算法设计流程](#算法设计流程)
    - [5.2 Communication](#52-communication)
        - [通信延时](#通信延时)
        - [Shared Address Space Model](#shared-address-space-model)
        - [Message Passing Model](#message-passing-model)
        - [Data Parallel Model(Streaming)](#data-parallel-modelstreaming)
        - [Design Optimization](#design-optimization)
    - [5.3 Assignment](#53-assignment)
        - [静态分配](#静态分配)
        - [动态分配](#动态分配)
        - [分配算法优化](#分配算法优化)
    - [5.4 Orchestration](#54-orchestration)
        - [Fork-Join Pattern](#fork-join-pattern)
        - [Steal Method](#steal-method)
        - [动态调整颗粒度 (Cilk)](#动态调整颗粒度-cilk)
- [6. Synchronization](#6-synchronization)
    - [6.1 Lock Implementation](#61-lock-implementation)
        - [Lock要求](#lock要求)
        - [CAS Based Lock](#cas-based-lock)
        - [Test-and-CAS Lock](#test-and-cas-lock)
        - [Sleeping Lock](#sleeping-lock)
        - [Ticket Lock](#ticket-lock)
        - [Array Based Lock](#array-based-lock)
    - [6.2 Optimized Data Structure](#62-optimized-data-structure)
        - [Fine-grained Lock Queue](#fine-grained-lock-queue)
        - [Lock Free Queue](#lock-free-queue)
        - [CAS](#cas)
        - [ABA Problem](#aba-problem)
    - [6.3 Centralized Barrier](#63-centralized-barrier)
        - [功能](#功能)
        - [Implementation](#implementation)
        - [Traffic Analysis](#traffic-analysis)
    - [6.4 Transactional Memory](#64-transactional-memory)
        - [Advantage](#advantage)
        - [Eager Version (Optimistic)](#eager-version-optimistic)
        - [Lazy Version (Pessimistic)](#lazy-version-pessimistic)
        - [Cache Coherence Implementation](#cache-coherence-implementation)
- [7. Domain Specific Solution](#7-domain-specific-solution)
    - [7.1 硬件异构](#71-硬件异构)
        - [Asymmetric Amdahl's Law](#asymmetric-amdahls-law)
        - [异构性能提升](#异构性能提升)
        - [异构使用案例](#异构使用案例)
        - [Challenges](#challenges)
    - [7.2 Domain Specific Language (DSL)](#72-domain-specific-language-dsl)
        - [Main Idea](#main-idea)
        - [Liszt Program (Mesh Programming)](#liszt-program-mesh-programming)
        - [Halide (Image Blurring)](#halide-image-blurring)
    - [7.3 Graph](#73-graph)
        - [图的抽象](#图的抽象)
        - [执行引擎](#执行引擎)
        - [内存优化](#内存优化)
    - [7.4 Deep Learning Neuro Network](#74-deep-learning-neuro-network)
        - [矩阵计算](#矩阵计算)
        - [网络压缩](#网络压缩)
        - [并行训练](#并行训练)
    - [7.5 Web System](#75-web-system)
        - [Web Server](#web-server)
        - [Workload balance](#workload-balance)
        - [Data System](#data-system)


# 1. Overview
### 1.1 Objectives of Parallelism Design
##### Hardware Design
- 自动识别并行优化指令
- 调优系统参数,提高并行效率
##### Software Design
- 根据<u>依赖关系</u>合理分配任务
- 降低子任务间通信开销
- 提高程序扩展性

### 1.2 Performance Evaluation

##### Absolute Performance

- Wall clock time: 程序运行的总时间
- Operation per second: 单位时间执行的有效指令数

##### Speed Up

- 加速比:S=$\frac{T_1}{T_n}$
- Amdahl’s Law: 如果任务中有$P$比例的任务只能串行,则加速比上限$S_{max} \leq\frac{1}{p}$,本质上就是$T_n=PT_1$

##### Efficiency

- 单位资源的效用
- 单位可以是时间/金钱成本/功耗/芯片面积

##### Arithmetic intensity

$$
\text{Arithmetic intensity}=\frac{i\text{(instructions)}}{n\text{(bytes)}}
$$

- 衡量CPU计算效率高低,是否将大多数时间放在计算而不是通信上

### 1.3 Scalability 可扩展性

##### Strong Scalability

固定工作集大小,提高核心数$P$是否可以保持加速比 (通常不行)

- 根据arithmetic intensity, 来分析工作集大小和核心数的关系

- 每个核心计算量不变,通信量增加,导致效率加速比下降
- Cache的容量增加,导致加速比上升

##### Weak Scalability

当工作集大小为$P$倍时,是否可以成比例放大核心数$P$来保持performance

- 更具有现实意义,确保算法可扩展

##### Scalability Constrains

- Problem Constrains: 
  - 当问题规模变大时,程序的可扩展性
  - 问题的多个参数可能会相互影响, 例如data size的增加也会导致coverage iteration次数增加
  - 工作集和输入大小不一定成线性关系,取决于具体算法(例如矩阵运算)
- Memory Constrains: 
  - 内存大小不变,算法的可扩展性
  - IO耗时增加
  - 当Cache hold不住时,会明显增加开销
- Time Constrains:
  - 用时不变,问题的可扩展性
  - 应用于高频交易/网络响应/实时控制领域

##### Scalability Optimization

1. 确认问题重要特征和核心间的竞争关系
2. 保留特征,并合理缩小问题规模,并在小机器上测试
3. 通过帕里托曲线,剔除dominated strategy
4. 基于有意义的工作集大小进行大规模测试

5. 根据曲线和耗时,分析瓶颈
   - 删除所有计算过程,分析通信开销
   - 所有数据访问常数,分析locality开销
   - 移除所有原子操作和锁,分析竞争开销
   - 根据CPU运行曲线,分析利用率和内存瓶颈

### 1.4 Contention

当并行执行的任务同时需要共享资源时,就会出现竞争

##### Dead/Live Lock

- Dead Lock: Thread之间在互相等待对方的下一步操作,导致没有有效指令可以继续执行
- Live Lock: Thread进入dead lock之后可以回滚,但是回滚后又不断回到dead lock的状态

##### Starvation

随着任务数量的增加,每个任务的等待延时会无限增长,容易造成饥饿

- 通过Appointment排序: 实现逻辑复杂
- Tree structure: 每一个thread有上一级的thread来处理,但是子树之间的带宽有限
- Flat: 无竞争时速度快,有竞争时容易饥饿

##### Contention Avoidance

- 细分共享资源,减少同一资源的并发量 (分布式队列/Virtual Channel)
- 对输入数据预先排序,从有序性中挖掘信息以减少共享资源的访问次数 (Priority)

# 2. Instruction-level-parallelism (ILP)
<u>单独核心提供指令集层面的并行,但是结果和顺序执行一致</u>

### 2.1 Pipeline架构
##### Instruction Parallelism
- 将指令的执行分为fetch/decode/execute/commit等阶段
- 每个阶段有相应的执行器,可以分别对不同的指令进行操作
##### Data Hazard
- 指令间的数据可能存在依赖关系,后执行的指令可能必须等前一条指令的数据commit后才可以执行
- Forwarding: <u>在被依赖指令commit之前,CPU可以在commit前识别计算结果,用于下一条指令执行,可以减少IO/Memory的Stall延时</u>
##### Control Hazard
- CPU的指令选择可能依赖之前的结果,之前的结果不同,导致CPU需要执行的指令不同
- Speculation: CPU不会等待之前的指令全部运行完才做选择,而是提前选择一个branch执行 (正确率>95%)
- Branch Misprediction有时会成为程序运行的瓶颈

### 2.2 Single Instruction Multiple Data(SIMD)
##### AVX Architecture
- 超宽的寄存器,用来同时保存多个数据
- CPU包含多个ALU可以对AVX寄存器中的多个数据进行并行计算
- 提供特定的指令集,对AVX寄存器中的数据同时进行完全相同的计算
- 可以实现排序/bitwise OP/vectorization等计算
##### Drawback
- 需要程序里精调,或者显式声明SIMD
- 对编译器和CPU来说很难自动找出可优化点
- 只能执行简单逻辑的运算

### 2.3 Out-of-Order Execution (OoO)

<u>CPU可以同时fetch/commit多条指令,并有多个executor执行指令</u>

##### Dataflow

1. 同时fetch和decode多条指令到instruction buffer
2. 识别指令间的independency并消除不必要的依赖,并制定特定为这套指令执行使用的physical register
3. <u>根据buffer中指令的耗时,和互相依赖,修改指令的执行顺序</u>
4. 等有依赖的指令执行完后,再一起commit(节约了commit的耗时)
5. 清空这套指令依赖的register

##### Hazard

- 指令间的互相依赖Critical Path过长,无法并行化
- 执行时经常有Branch Misprediction,<u>导致上百条指令的优化失效</u>,且必须清空寄存器中的数据.
- 指令的执行需要特定硬件,如FP,Memory但资源都正在被使用

##### Limitation

- <u>提供的优化不会随着晶体管(执行器)的数量增加而无限增长</u>
- 判断指令间的dependency有开销
- 程序的逻辑限制并行度

### 2.4 Memory Consistency

##### Memory Access Out of Order

当针对共享变量的操作乱序执行时,可能导致多线程的逻辑错误

- 线程A 

  ```c++
  // a, b都初始为0
  a = 1; 
  b = 2; 
  ```

- 线程B (因为A的乱序执行B没有读到a=1的更新)

  ```c++
  while(b!=2)continue;
  y = a; // y = 0
  ```

##### Memory Fence

确保在fence之前的程序执行完成之后才会执行之后的

- 线程A: <u>添加fence确保a=1了以后,b才可以被更新为2</u>

  ```c++
  // a, b都初始为0
  a = 1;
  fence();
  b = 2;
  ```

- 线程B: <u>添加fence确保y=a会在b=2之后才运行</u>

  ```c++
  while(b!=2)continue;
  fence()
  y = a; // y = 1
  ```

##### Dependency

可以通过添加dependency的方法起到fence作用,但是要<u>小心编译器优化</u>

- 取地址

  ```c++
  // 线程A
  a = 1;
  b = a + 1; // b对a有依赖,因此不会乱序执行
  ```

- 条件判断,只对<u>共享变量写有效,读无效</u>

  ```c++
  // 线程B
  if(a);
  b = a; // 有效,会确保if判断完成才执行
  z = a; // 无效,可能会在if之前执行,并读到0
  ```

# 3. CPU Multithread Parallelism

### 3.1 Multi-Threading
每个CPU自己会维护一些threading,用来提高并行性,OS会把逻辑线程map到每个core维护的线程里去
##### Memory Latency <u>Hiding</u>
- 当线程因为Memory/IO Latency Stall时,CPU执行其他线程的Instruction
- 在线程还没有访问数据的时候,分析并预测线程运行模式,提前从memory获取数据
- 需要较大的Cache和内存带宽,且每个线程的运行时间会增加
##### Simultaneous Multi-Threading (SMT超线程)
- 利用CPU的并行性,同时fetch/decode/execut/commit多个thread的instruction
- 只有在ILP很差的情况下可以带来明显的speed up
- 需要有很大的Data Cache
##### Thread Pool
- 提前spawn很多线程,当空闲时,从一个global queue中获取task和参数执行,减少创建thread的overhead
- Task: 轻量级的线程,可以用function来描述

### 3.2 Interconnection Hardware Design

##### 设计要点

| 可扩展性                | 通信延迟                   | 路由结点               | 带宽                              |
| ----------------------- | -------------------------- | ---------------------- | --------------------------------- |
| 结点数量对性能的影响    | 结点的通信距离             | 是否可以和工作结点复用 | 是否受限于特定路径                |
| 增加/删除结点的难易程度 | 是否有多条路径到达相同结点 | 路由算法复杂度         | 结合使用场景分析local和global带宽 |

##### 架构对比

| Topology  | 优点                  | 缺点                                   | 优化                             | 应用            |
| --------- | --------------------- | -------------------------------------- | -------------------------------- | --------------- |
| Bus       | Node较少时,性能非常好 | 可扩展性弱,结点多消息会堵塞            | 不同类型的消息用多个bus,提高带宽 | Intel Core Ring |
| Cross Bar | 结点直连,带宽高       | 很难扩展,结点越多扩展成本越高,且体积大 | 自环绕节省空间                   | Oracle Sun      |
| Mesh      | 延迟小,扩展性强       | 路由算法复杂,每个结点都是router        | 只连接部分node为mesh             | Intel Xeon      |
| H-Tree    | 本地流量高            | 每棵树的根节点容易成为瓶颈             | 增加子树间的带宽,减少性能损失    | VLSI            |
| 可变门    | 延迟小,性能高         | 单条链路负载会变高,容易堵塞            | 优化router布局,添加router数量    | FPGA            |

##### Flow Control

- Package:
  - 网络间传输消息的最小单位,包含header和tail
  - Header: 包含Package的目的地和Package大小,便于router
  - Tail: 消息发送/转发者提供的附加信息
- Flit: Package的子单位,作为拥塞控制的最小单位,同一个Package的Flit都按照相同顺序和路径传播

- Buffering: 当Flow过大时,将package先保存在buffer中,之后再转发

##### Routing

- Message-Based:

  - 发送消息前,<u>先probe可用链路</u>,确定可用后再发送(Probe成本可能很高)
  - 获得可用链路后,可以<u>发送任意数量的消息</u>,直到发完为止

  - 容易造成Contention,且容易blocking

- Package-Based:

  - 同一条Msg的不同package可以按照不同的路线抵达目的地
  - <u>每个路由器一收到Pkg的Header就可以规划下一条路径,而不是等待所有payload抵达</u>
  - <u>当路由器对于Pkg的负载过大时,将package拆分成flit,降低每个package使用的带宽,从而发送多个package的消息避免死锁</u>

### 3.3 Cache Coherence

##### Consistency Problem

- 当Core/IO设备更新Cache/buffer时,其他的Core不知道,而导致hit错误数据

- 当有多个Core/IO设备同时更新Cache/Buffer时,可能出现访问结果不一致
- <u>出现冲突的概率不高,只有个别的Cache Line会在少数CPU之间共享,但是必须保证正确</u>

- Cache中的数据生命周期由Instruction Order决定,而不是执行时间
- 通过Cache访问内存数据的结果必须一致,且符合某种序列化顺序,不会出现得到"ab"和"ba"的场景

##### Shared Cache Architecture

- 所有核心共享Cache,1个line只会在所有cache中出现一次
- 核心之间要经常互相访问Cache,导致很高的延迟
- 需要通过pre-fetch来hide latency

##### Reduce Consistency Problem (Line Padding)

- False sharing: 每个核心访问同一个cache line中的不同数据,频繁同步cache带来大量开销

- Cache line太小可能导致冷数据过多的overhead, 太大容易造成false sharing

- 通过padding 变量的大小为cache line来避免false sharing

  ```c++
  // false sharing: thread之间可能共享cache line
  int myPerThreadCounter[NUM_THREADS]; 
  
  // padding version: 每个thread只访问自己的cache line
  struct PerThreadState {
      int myPerThreadCounter;
      char padding[CACHE_LINE_SIZE - sizeof(int)];
  };
  PerThreadState myPerThreadCounter[NUM_THREADS];
  ```

##### 多级Cache一致性

- 在每层Cache之间都设置controller开销很大,不现实
- 确保L1中的数据永远在L2内,则只需要在L2设置controller (需要调整LRU算法来保证inclusion)
- 当L1中的数据更新时,更新L2 cache line的标志位,而不是立刻更新数据以节省时间

### 3.4 Cache Snooping-Based Model

##### Cache Controller

- 使用Bus在所有核心之间广播操作
- 受限于总线带宽,不好扩展
- 维护所有核心中的Cache Line状态,当出现影响Coherence的指令时,触发对应操作 (可以Pipeline化)
  1. Request: CPU请求总线使用权,获得后把访问的地址置于总线
  2. Validate: 其他Core的Controller更新各自Cache状态,并发送Ack
  3. Response: 其他Core/Memory找到数据,并请求发送数据
  4. Update: 当requestor准备好时,获取Data

##### VI模型 (Write back)

维护两种状态,但每次状态切换都要访问内存,低效

| Valid                                                             | Invalid                                               |
| ----------------------------------------------------------------- | ----------------------------------------------------- |
| 有效数据,核心可以直接执行write,但<u>写入内存费时,且需要高带宽</u> | 无效数据,read/write前<u>加载内存数据</u>进入Valid状态 |

##### MESI模型 (Write Through)

- 把Valid状态拆分成M, S和E, E状态写入不用上锁
- 支持核心之间互相获取数据

| Modified                | Exclusive                          | Shared                                       | Invalid  |
| ----------------------- | ---------------------------------- | -------------------------------------------- | -------- |
| 已更新,且表示本Core独占 | 独享只读状态,<u>修改不需要上锁</u> | 共享只读状态,<u>修改时需要对其他Core上锁</u> | 无效数据 |

##### Optimization

- 当多个Cache中的数据都有效时,需要决定用哪个core的cache提供数据最高效

  | Cache Model | CPU   | State      | State描述                                 |
  | ----------- | ----- | ---------- | ----------------------------------------- |
  | MESIF       | Intel | Forward(F) | 由S状态的Cache line竞争获取F态,并提供数据 |
  | MOESI       | AMD   | Owned(O)   | 由最先更新数据的核心提供数据              |

- 通过Write-back buffer减少写入内存的延时
  - 数据进入write buffer之后,直接更新Cache的State
  - 当CPU想要获取数据时,优先对Write Buffer做检查
  - 在Cache中维护两份数据,减少Processor和Bus检查Cache Line的竞争

- 总线是共享资源,容易造成死锁/活锁/竞争
  - 将总线分成Request (Address)部分和Response (Data) 部分,提高带宽
  - 均匀分配总线使用权
  - Coherence Protocol将容易造成死锁/活锁的操作原子化

### 3.5 Cache Directory-Based Model

##### Cache Directory

- 一个Cache Line<u>通常只会在少数CPU之间共享</u>,因此<u>点对点同步比使用总线同步效率更高,且可扩展性高</u>

- 通过保存每个cache line的CPU序号,来确定通信的目标
- 每个Cache Directory只维护本地Numa Region内存对应的Cache

##### 工作流程

1. CPU0需要读取Cache Line
2. 该Cache Line对应的memory属于CPU2负责,因此发消息给CPU2
3. CPU2访问Cache Directory,得知最新的版本在CPU3,因此发消息给CPU3
4. CPU3将数据发给CPU1,并告知CPU2更新该Directory 
5. 如果是write,则同时告诉其他所有保存该Cache Line的CPU修改validation bit

##### Optimization

- 当CPU很多时,使用CPU序号代替bitmap来保存每个Cache Line的所有者
- 将Cache Directory保存在L3 Cache中
  - 实现Cache Directory共享 
  - 不用保存memory中所有cache line的状态,只要保存出现在L1和L2中的Cache Line状态,节省空间



# 4. GPU Parallelism

### 4.1 处理器架构

##### Warp-Thread

- 一组Warp/Thread会执行相同的程序和指令(kernel function),但是操作的数据不同 (Same Program Multiple Data)
- Thread: GPU执行的<u>最小逻辑单位</u>,当时数量超过Warp大小时,<u>不一定同时执行</u>,但是通常都在一个Core中执行
- Warp: GPU<u>执行指令的最小物理单位,同时执行多个Thread</u> (例如32个)

##### Core-Block

- Core: GPU的物理核心,1个Block通常在一个Core内执行
- Block: 包含多个Thread (可以多维定义Thread的排列),是GPU调度系统的最小逻辑单位
- 当有空闲的Core的时候,就会分配Block执行,因此<u>Block间可能乱序执行</u>

##### Grid

- GPU的逻辑形式,可以在不同维度定义多个Block
- 一共有几十个Core,上千个Warp Executor,并行效率非常高

### 4.2 显存架构

##### Global Level Memory

- GDDR6(10GB-level): 带宽为100-1000GB/s,由于GPU的高并行度,<u>显存带宽往往成为程序瓶颈</u>
- L2-Cache(MB-level): 给所有的Core共享

##### Block(Core) Level Memory

- Shared-Memory(100KB-level): Block内所有thread共享

- 多个L1 Cache: Warp间共享,用来保存Thread运行时的local variable

  

##### Thread(Warp) Level Memory

- Register/L0 Cache: 保存局部变量, 但通常不在thread间共享数据

##### Cache Coherence

- 没有L1的Cache Coherence机制,因为同步成本过高

- 编译时发现写入L1的指令时,会直接改成写入到L2 <u>(Write-through)</u>
- 每次launch kernel时会Flush L1 Cache,避免因为上个Kernel Function而hit错误数据

### 4.3 Programming Model

##### Program Global Design

- 需要GPU Malloc才可以在Device分配内存,这些内存所有Block的任意Thread都可以访问

- 在GPU执行计算时,使用<u>Streaming从而同时显存传输数据</u>
- 定义Block大小时,要<u>考虑会使用的Shared Memory大小,从而让一个Core执行多个Block</u>

```c++
int N = 1024
// 在GPU中分配显存
cudaMalloc(&devInput, sizeof(float) * (N+2));  
cudaMalloc(&devOutput, sizeof(float) * N);  

const int Nx = 1024, Ny = 1;
dim3 threadsPerBlock(32, 1, 1); // 定义每个block中有32个线程
dim3 numBlocks(Nx/threadsPerBlock.x, Ny/threadsPerBlock.y, 1); 
// grid中x维度有32个block,y维度有1个block,一共32个block
```

##### <u>Kernel Function Design</u>

- 并行执行,因此参数是并行化传入的(例如数组坐标)
- 一般没有return,而是直接修改global memory里的值
- 运行时可以根据thread/block坐标执行不同逻辑(不适合复杂逻辑)

- Block之间的Kernel会乱序执行,因此不能有互相依赖(<u>对Global Memory的访问不要有重叠</u>)
- Thread之间可以有依赖,通过同步实现,同时共享block的数据

```cpp
__global__ void convolve(int N, float* input, float* output) {
    // 每个thread在block中申请共享内存,block内其他线程都可以访问
    __shared__ float support[THREADS_PER_BLK+2];    
    // 从输入中读取自己负责的数据,导入到block内
    int index = blockIdx.x * blockDim.x + threadIdx.x;  
    support[threadIdx.x] = input[index];
    // 卷积运算需要额外导入两次
    if (threadIdx.x < 2) {
    	support[THREADS_PER_BLK + threadIdx.x] = input[index+THREADS_PER_BLK]; 
    }
    // 等block内所有线程都导入完成后再开始计算
    __syncthreads();
    float result = 0.0f;  // 线程执行计算
    for (int i=0; i<3; i++)   
    result += support[threadIdx.x + i];
    output[index] = result / 3.f; // 输出到全局内存
}
// 并行执行kernel
convolve<<<N/THREADS_PER_BLK, THREADS_PER_BLK>>>(N, devInput, devOutput); 
```

##### 图形渲染流程

1. 定义并用顶点描述一个需要渲染的实体
2. 根据展现实体的视角变换像素点
3. 根据实体的特征和视角,将实体分片
4. <u>对每个分片进行并行的pipeline计算</u>
5. 对分片上色,并拼接组合

# 5. Parallel Program Design

### 5.1 Program Decomposition

##### 抽象逻辑

- Abstraction (Single Program Multiple Data): 
  - 每个核心上运行相同的程序,但是input data不同
  - 大多数变量都定义为uniform,标识所有task都有相同的value
- Implementation (Single Instruction Multiple Data)
  - 每个程序中使用向量化计算,来并行地处理数据

##### 算法设计流程

将程序分解成可并行执行的task,只能由程序员来设计,编译器很难做优化
1. 先用最简单的方法实现program
2. 分析program的scalability, max sequential task，再结合硬件decomposition
3. <u>控制颗粒度是关键</u>,每个core之间的task尽可能independent,但是自己的task应该尽可能多,且dependent,从而减少调度开销
4. 理想情况是所有core都处于busy状态

### 5.2 Communication

##### 通信延时

传输$n$大小的数据,则有$T(n)=T_0+T_1+\frac{n}{b}$

- 传输延时$T_0$: 准备buffer等耗时
- 网络延时$T_1$: 数据传输的时间,由距离和传输速度决定
- 传输带宽 $b$: 把数据送到链路的时间,由位宽和数据量决定

$T_0,T_1$的延时可以通过pipeline隐藏,<u>通常带宽最终成为瓶颈</u>

##### Shared Address Space Model

- 维护一块所有线程可以访问的critical region,使得task之间可以获取互相的状态
- 需要上锁/原子变量/barrier来维护数据结构的invariability,有不小的开销
- 需要硬件支持不同core访问相同数据(NUMA/SMP)

##### Message Passing Model

- 每个Task只在private address space工作,并通过互相之间发送消息来通信
- 对硬件没有特定要求,但通信效率比较低,适合机器间通信
- 可以和Shared Address Space Model互相转换
- recv和send应该为异步,否则会产生死锁

##### Data Parallel Model(Streaming)

- 适合分支少,高吞吐量,粗颗粒度的计算程序
- Kernels是作用于data中每个element的function
- Kernel可以调用下一个Kernel,形成Stream,提高cache affinity
- 需要提供复杂的算符,来实现kernel间的计算

##### <u>Design Optimization</u>

- 尽可能提高Arithmetic intensity,让每个thread多完成local task
- 优化算法,减少Inherent communication
- 根据硬件机制Cache Design合理分配颗粒度,减少Artifactual communication
- 重新编排每个Task中的数据存储顺序,增加内存连续读取

### 5.3 Assignment
由操作系统/硬件/编译器负责,将task分给每个core来执行,需要考虑<u>负载均衡和locality</u>
##### 静态分配
- 适合每个task的workload可知的场景
- 分配的开销可以忽略不计
- 适合很多小任务和精细化控制
##### 动态分配
- 适合每个task开销未知的场景
- 适合使用shared work queue model
- 分配的开销限制了speed up的上限
- 适合很多大任务,和粗颗粒度控制,以减少分配的开销
##### 分配算法优化
- 优先分配开销大的task,需要对任务的开销做估计
- 使用分布式任务队列
  - 减少从shared queue中获取的延迟
  - 提高locality,但需要让每个core在空闲时,有能力从其他core的queue中steal task
### 5.4 Orchestration
尽可能降低task之间通信和同步的开销
##### Fork-Join Pattern
- 适合divide and conquer problem
- fork若干个子线程执行任务,并等待所有子线程完成后join同步

##### Steal Method

- 当线程空闲时,从其他核心的task queue中steal task来运行
- 使用dequeue保存任务,从top steal可以减少对局部性的影响
- steal的时候需要同步

##### 动态调整颗粒度 (Cilk)

- 设计两个调度模式,粗颗粒度和细颗粒度
- 当task数大于thread数时,分配颗粒度较粗,提高每个thread的运行效率
- 当thread数大于task时,分配颗粒度较细,增加task数量,减少idle的thread

# 6. Synchronization

### 6.1 Lock Implementation

##### Lock要求

| Low Latency              | Low Traffic                  | Scability                 | Low Storage      | Fairness           |
| ------------------------ | ---------------------------- | ------------------------- | ---------------- | ------------------ |
| Lock Free时,应当立即获得 | 竞争锁的时候,Traffic越少越好 | 处理器过多时,性能影响有限 | 不会占用大量内存 | 不会造成Starvation |

##### CAS Based Lock

```c++
// 上锁: 不断进行原子操作,直到可以得到1为止,代表上锁成功
while(compare_and_swap(lock, 1)); 
// 解锁
lock = 0;
```

- 不保证公平性,因为不知道谁第一个CAS成功
- Traffic很多,且当CAS失败时,OS可能进入Kernel让线程Sleep

##### Test-and-CAS Lock

只有当前lock空闲时,才会尝试竞争,减少CAS尝试次数

```c++
while(1){
    while(lock!=0); // 这里只是Read,没有interconnection
    if(compare_and_swap(lock, 1))break; // 这一步要求同步cache非常耗时
}
```

##### Sleeping Lock

```c++
sleep_time = 1;
while(1){
    if(compare_and_swap(lock, 1))break
    sleep(sleep_time);
    sleep_time *= 2;
}
```

- 没有抢到锁时sleep,进一步减少contention
- sleep_time增长太快,可能导致严重的不公平

##### Ticket Lock

```c++
struct Lock{
    volatile int next_user;
    volatile int user;
}
// 上锁
int my_ticket = atomic_incre();
while(my_ticket != lock->next_user); // 通过叫号来判断是否轮到自己
// 解锁
lock->next_user++;//上一个释放锁的线程叫下一个线程
```

- 只有取票和解锁需要同步

##### Array Based Lock

```c++
struct Lock{
    volatile padding_int status; // 把lock填充到cache line大小,减少false sharing 
}
int my_ticket;
// 上锁
int my_ticket = atomic_incre();
while(!locl->status[myticket]); // 通过叫号来判断是否轮到自己
// 解锁
lock->status[my_ticket] = 0;
lock->status[my_ticket++] = 1; // 交下一个号 
```

- 需要额外空间(O[P])
- 每次释放锁只要更新一个Cache

### 6.2 Optimized Data Structure

##### Fine-grained Lock Queue

- 每个结点都有各自的lock
- 每次删除/添加结点时,必须先持有上一个结点的锁,才可以进行操作
- 通过连环锁的机制,保证了访问的序列化
- 并行度提高,存储开销大,且访问第$n$个点,要操作$n$个锁

##### Lock Free Queue

- <u>Push和Pop操作各自private的数据结构</u>
- 数组实现: 通过head_index和tail_index记录push和pop的位置
- 链表实现: tail和head操作不一样的指针,pop删除数据,而是修改上次pop的指针位置

##### CAS

- 使用CAS操作来检验添加/删除是否有效
- CAS前,可能因为其他线程free结点,而导致引用空内存
- 维护一个全局的私有指针数组,每个指针只有自己线程可写,其他线程可读,记录了当前使用的内存. 只有不在指针里的结点可以被删除
- <u>如果竞争非常激烈,线程要一直循环CAS的话,lock-free的效果可能不好</u>

##### <u>ABA Problem</u>

- 在CAS操作之前,另一个线程可能pop再push了一次<u>,导致没有被CAS发现,从而得到错误数据</u>
- 需要维护一个计数的原子变量,可以在CAS时发现被push的次数
- 把CAS的变量和计数放在一个struct里,并使用更高宽度的CAS操作一次比较多个值

### 6.3 Centralized Barrier

##### 功能

- 使得<u>多个Thread在Barrier前同步</u>
- 需要考虑线程切换和同步开销. 如果Thread 1释放后又执行Barrier,需要让Thread 2知道中间的Barrier已经完成

##### Implementation

```c++
struct Barrier_t {
    LOCK lock;
    int  counter;   // 记录Block的Thread数量
    int  flag;      // Barrier是否已释放
};
int local_sense = 0;  // 每个Thread认可的Barrier
void Barrier(Barrier_t* b, int p) {
    local_sense = (local_sense == 0) ? 1 : 0; // 下一次只认可flag和local_sense不同的barrier,避免重复堵在同一个Barrier前
    lock(b->lock);
    int num_arrived = ++(b->counter);
    if (b->counter == p) {  
        unlock(b->lock);
        b->counter = 0;
        b->flag = local_sense;
    }
    else {
    	unlock(b->lock);
        while (b.flag != local_sense);  // wait for flag
    } 
}
```

##### Traffic Analysis

- 每次更新counter都会需要告知所有的Processor,有$O(N)$的开销
- 更新Counter和unlock都有竞争,会碰到scalability问题
- 通过Tree-Like Barrier Structure来减少通信延迟($O(\ln N)$)

### 6.4 Transactional Memory

##### Advantage

```c++
void transfer(char* A, char* B, int amount){
    atomic{ // 程序员不需要实现并发控制和回滚
        withdraw(A, amount);
        deposit(B, amount);
    }
}
```

- 程序员只需要实现程序逻辑,不用管并发问题,减少犯错概率
- 系统自动使用细颗粒度的并发控制,提高运行效率
- 自动实现Transaction Abort的Restart

##### Eager Version (Optimistic)

- 每次R/W会直接更新内存,发现conflict就abort
- 可以较早发现conflict,但是比对频率高,开销大
- 如果失败就执行Undo Log (<u>执行过程中需要上锁,且执行慢</u>)

##### Lazy Version (Pessimistic)

- 只有Commit的时候比对Conflict再更新内存
- 运行过程开销小,commit开销大,且发现晚
- commit前数据都保存在local working set,commit时提交

##### Cache Coherence Implementation

- 以Cache line为颗粒度,每个Thread Cache在本地操作,添加了标志位说明R/W
- Commit的时候作为Coherence协议的一部分和其他CPU同步
- 可能要维护两份Cache line,一份是undo log
- <u>不适合对很大的memory set进行操作,因为cache line会被置换出去</u>

# 7. Domain Specific Solution

### 7.1 硬件异构

##### Asymmetric Amdahl's Law

| $f$                | $V_1$          | $r,n$                     |
| ------------------ | -------------- | ------------------------- |
| 并行计算的指令比例 | 顺序执行的速度 | 性能分别为$V_r,V_n$的核心 |


$$
\text{speed up}=\frac{1}{\frac{1-f}{V_1} + \frac{f}{r\cdot V_r+n\cdot V_n}}
$$

- 当核心数量增加时,异构可以取得更好的加速比

##### 异构性能提升

|      | 能耗比     | 芯片面积  |
| ---- | ---------- | --------- |
| GPU  | 10x        | 1/7x-1/5x |
| ASIC | 100x-1000x | 1/1000x   |

##### 异构使用案例

- CPU大小核设计
- 相机的光学图像处理单元
- GPU浮点运算和纹理单元分离

##### Challenges

- 可扩展性不强,无法reprogramm
- 设计/验证成本高
- 需要合理评估并分配不同异构单元占用的资源,<u>避免特定单元成为瓶颈</u>

### 7.2 Domain Specific Language (DSL)

##### Main Idea

- <u>将特定领域的问题抽象化,专注于运行性能和开发遍历,放弃可扩展性</u>
- 在编译时挖掘并行性,并自动优化提高性能 (SQL)

##### Liszt Program (Mesh Programming)

- 将Mesh中的vertex, cell, edges抽象化,用户只能使用特定的接口访问attribute
- 在编译时,根据抽象数据结构的访问结构,挖掘locality, parallelism和synchronization来提高性能
- 在Cluster上运行时,会把mesh按照每个结点的内存大小分片到每个机器上运行,不同结点仅仅交互边界数据
- 在GPU上运行时,会挖掘可同时运行的task(不连接的vertex),并放在不同CUDA threads上迭代运行

##### Halide (Image Blurring)

- 每个像素通过平滑四周3*3的像素计算

- 按行使用Buffer,尽可能多地使用连续访问,并保存会重复访问/读取的数据到cache
- <u>Buffer的大小根据Cache和Cache Line的大小决定,确保没有Reload Cache Line</u>
- 需要权衡Instruction次数和Cache处理的Locality
- 抽象向量和并行化操作

### 7.3 Graph

##### 图的抽象

- 将图提取成Vertex和Edges,并定义相关的operator来实现有关算法(例如Page Rank)
- 提供同一接口,而不用管底层图的压缩和集群上的表示
- 将图分片成若干个shard,每个shard只保存指向到特定destination nodes的边,且这些边都按照source node排序

##### 执行引擎

- 同步执行: 保存一个副本数据结构,每次同步更新所有节点,并把结果保存在副本上,两个副本交替使用(因为有同步所以速度慢)
- 异步收敛执行: 当一个结点更新后,会触发signal并告知调度器更新其他shard中的结点(调度顺序会在很大程度上影响performance)

##### 内存优化

- 单机上内存有限,不可能放下整个图,但是磁盘随机访问效率过低
- 每次访问,将当前shard和相关的shard连接构成子图,当前shard里的edge已经排好序了,所以都是顺序访问
- 图的访问受限于带宽,因此CPU较空闲,可以对图进行压缩,提高性能

### 7.4 Deep Learning Neuro Network

##### 矩阵计算

- 将矩阵拆分成Cache Line大小的block,进行block matrix multiplication
- 使用稀疏矩阵保存每一层的输入/输出矩阵

##### 网络压缩

- 删除反复迭代后接近为0的权重
- 将不同的weight聚类,聚类后使用相同的变量进行训练

##### 并行训练

- <u>使用集群训练,可以异步更新数据(因为难得碰到一次读写冲突不会影响参数迭代)</u>
- 结点间共享参数,但是可以独立计算梯度,并累加
- 也可以水平/垂直划分网络,但是需要考虑依赖和通信开销

### 7.5 Web System

##### Web Server

- 使用多进程,可以确保系统的鲁棒性
- 进程池会根据当前web server的负载调整worker数量
- 通过优化的convertor来提高web脚本语言的运行效率
- 无状态运行(将session信息保存在DB中),防止因server宕机影响用户访问

##### Workload balance

- 使用roundrobin/状态监控等方式来实现负载均衡
- 监控<u>response time</u>,当发现response time明显延长时,启用备用服务器执行web任务,不用时则作为云计算服务器租借
- 在每一层都添加缓存包括前端服务器/CDN/Web server和DB

##### Data System

- 包含内存数据库缓存(Key-value)和常规数据集群(Relation DB)来提高query效率
- 通过分片和副本提高吞吐量,但是要考虑到同步开销

- 保存服务器的状态信息,提高系统鲁棒性,但也会增加负载
