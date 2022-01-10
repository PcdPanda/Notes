[toc]
# 1. Overview
### 1.1 Objectives of Parallelism Design
##### Hardware Design
- 自动识别并行优化指令
- 调优系统参数,提高并行效率
##### Software Design
- 根据<u>依赖关系</u>合理分配任务
- 降低子任务间通信开销
- 提高程序扩展性
##### Speed Up
- 加速比:S=$\frac{T_1}{T_n}$
- Amdahl’s Law: 如果任务中有$P$比例的任务只能串行,则加速比上限$S_{max} \leq\frac{1}{p}$,本质上就是$T_n=PT_1$
# 2. Instruction-level-parallelism (ILP)
<u>提供指令集层面的并行,但是结果和顺序执行一致</u>
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
### 2.2 Out-of-Order Execution (OoO)
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
### 2.3 Single Instruction Multiple Data(SIMD)
##### AVX Architecture
- 超宽的寄存器,用来同时保存多个数据
- CPU包含多个ALU可以对AVX寄存器中的多个数据进行并行计算
- 提供特定的指令集,对AVX寄存器中的数据同时进行完全相同的计算
- 可以实现排序/bitwise OP/vectorization等计算
##### Drawback
- 需要程序里精调,或者显式声明SIMD
- 对编译器和CPU来说很难自动找出可优化点
- 只能执行简单逻辑的运算
### 2.4 Limitation
- <u>提供的优化不会随着晶体管(执行器)的数量增加而无限增长</u>
- 判断指令间的dependency有开销
- 程序的逻辑限制并行度
# 3. CPU Architecture Parallelism
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
### 3.2 Communication Model
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
# 4. GPU Parallelism

# 5. Programming Model
### 5.1 基本概念
##### Abstraction (Single Program Multiple Data)
每个核心上运行相同的程序,但是input data不同
大多数变量都定义为uniform,标识所有task都有相同的value

##### Implementation (Single Instruction Multiple Data)
每个程序中使用向量化计算,来并行地处理数据
### 5.2 Decomposition
将程序分解成可并行执行的task,只能由程序员来设计,编译器很难做优化
1. 先用最简单的方法实现program
2. 分析program的scalability, max sequential task，再结合硬件decomposition
3. 控制颗粒度是关键,每个core之间的task尽可能independent,但是自己的task应该尽可能多,且dependent,从而减少调度开销
4. 理想情况是所有core都处于busy状态
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