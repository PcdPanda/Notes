[Toc]

# 1. 数据表示

### 1.1 整数

##### 符号数处理

- signed数字相当于把unsigned最高位当做负数处理
  - $1111=-2^3+7=-1$
- <u>unsigned数字数字恒大于等于0</u>,永远小于-1,因为-1会被转为unsigned
- unsigned和signed数字比较时会<u>把signed转成unsigned再比较</u>,因此
- INT_MIN的相反数还是INT_MIN (overflow)

##### 移位操作

- 位操作只会考虑位数的最后$w$个bit

  ```c++
  short x << 2 = x << 5 == x << (21 mod 16); 
  // 左移y位,只会考虑y mod 8的结果 (只看y最后4位,左移的)
  ```

- int32 expand到int64和或者truncate到short时会根据signed bit操作 (负数填1)

  ```c++
  -4 = 1100;
  -4 >> 2 = -1 = 1111; // 补了2个1
  ```

### 1.2浮点数

##### 浮点数表示方法

假设一共有n位,则可以将n拆分<u>S,Exp(k位),Frac</u>三部分

- $S$ 表示正负

- $Exp$ 决定绝对值是否大于1

  - $Exp=0$ Denormalized value

    绝对值小于0,只需要看$Frac$(用在0后面)

    $v=(-1)^S\cdot\{0.Frac\}\cdot2^{1-(2^{k-1}-1)}$

  - $Exp\notin\{0, 2^n-1\}$ Normalized value

    $Exp$不全为0或1,则需要同时看$Frac$(用在1后面)和$Exp$(用在2的指数)

    $v=(-1)^S\cdot\{1.Frac\}\cdot2^{\text{Exp}-(2^{k-1}-1)}$

  - $Exp=2^n-1$ 特殊数

    - $Frac$全0就是$\infty$
    - $Frac$全1就是NaN

- $2^{k-1}-1$用作bias,使得指数可以是负数,提高精度

##### 浮点数计算规律

- <u>浮点数overflow不会改变符号</u>

- <u>浮点数不完全符合结合律和分配率,因为精度有限,小数点会移动</u>

- 当因为精度不够,而必须截断小数位时,遵循四舍五入,如果刚好是5,就找最近的偶数,使末尾位为0

### 1.3 复杂数据结构

##### 指针

- 大小和address size一致

- 通过反推,决定指针类型

  ```c++
  int *p[3]; // p是指针数组,取下标后再取对象是int
  int (*p())[3]; // p是个函数,这个函数返回指针,指针再取下标可以得到int
  int ((*p)(double, int))[3]; // p是个函数指针,指向的函数接受(double, int)的输入,返回一个大小为3的数组
  ```

##### 结构体和类

- 结构体等于一片固定大小的内存,每个变量按照顺序连续分配
- 结构体内存对齐
  - 每个变量都会从类型大小的整数倍开始,例如int的初始位置只能是4的整数倍
  - 整个结构体的大小是成员变量最大类型大小的整数倍,如果有long long则必须是8的整数倍

# 2. 存储架构

### 2.1 基本概览

- 相关信息可以直接在/sys/devices/system下查看

##### 访问延时

| 访问     | 寄存器 | L1   | L2   | L3    | 内存 | SSD   | 机械硬盘 | 网络 |
| -------- | ------ | ---- | ---- | ----- | ---- | ----- | -------- | ---- |
| 耗时(ns) | 0.25   | 1    | 4    | 20-32 | 100  | 1.6E4 | 1E6      | 1E9  |

### 2.2 寄存器

- r开头用作64位,e开头用作32位

- 寄存器名字

  | rip                   | rsp                     | rax        | rdi/rsi/rdx/rcx/r8/r9 | rbx/r12/r13/r14              | CF/ZF/SF/OF  |
  | --------------------- | ----------------------- | ---------- | --------------------- | ---------------------------- | ------------ |
  | 指向下一条Instruction | 指向向下延伸的stack top | 函数返回值 | 函数参数              | 函数开始前寄存器的值(还原用) | 条件判断结果 |

### 2.3 缓存

##### 实现方式

n位内存地址被分为3部分

- T(tag):cache保存的标识符,标志是否是想要的block
- S(set):决定该block保存在哪个cache set中

- B(block)地址: 如果T和S相同,则所有block都会被放入cache

cache有$2^S$个set,每个set里可以放$E$个block(E ways of associative)

写入策略: 先把数据load进cache再写入. block被置换的时候,再写入磁盘

#### 基本架构

| 用途   | L1 Data | L1 Instruction | TLB L1 Data | TLB L1 Instruction | L2                | TLB L2    | L3         |
| ------ | ------- | -------------- | ----------- | ------------------ | ----------------- | --------- | ---------- |
| 使用者 | 单个CPU | 单个CPU        | MMU         | MMU                | 单个处理器(2 CPU) | MMU       | 单个Socket |
| 大小   | 32KB    | 32KB           | 64 Entry    | 128 Entry          | 256KB             | 512 Entry | 8MB        |
| Way    | 8       | 8              | 4           | 4                  | 8                 | 4         | 16         |

### 2.4 内存

##### Implicit free list:

最简单的分配算法 (实际没有使用)

1. 获得用户要分配的内存大小,根据first/next/best fit算法,寻找合适的block (O(n))

2. 设置block的header,包含

   | block的大小 | 指向下一个block的指针 | 1个bit说明这个block是否被分配 | 1个bit说明上一个block是否被分配(用于合并) |
   | ----------- | --------------------- | ----------------------------- | ----------------------------------------- |

3. 释放时,修改分配bit,说明自己没有分配

4. 查看bit判断上一个block是否被分配,如果没有就合并

5. 使用指针查看下一个block是否被分配,如果没有就合并

##### Segregated List

实际应用的list

1. 根据不同block size各自构造free list
2. 根据用户要分配的内存,在合适大小的free list里找到block来分配
3. 如果没有找到,就用sbrk()分配额外内存

##### 内存池

1. Python/Java使用,在OS的内存基础上,维护一块buffer

2. 通过引用计数来记录内存是否被使用

3. 内存释放时,不会立即执行系统调用,而是保留给之后使用

4. 通过标记来记录使用内存

   ```c++
   void mark(void * ptr){
       if(!is_ptr(ptr))return; // 只标记指向内存的指针
       if(markBitSet(ptr))return; // 已经标记了
       setMarkBit(ptr); //标记为1
       for(auto i=0;i<ptr.size();i++)mark(ptr[i]); //标记ptr保存的其他内存
   }
   ```

5. 释放所有没标记的内存

   ```c++
   void sweep(void * ptr, void * end){
       while(ptr< end){
           if(markBitSet(ptr))clearBitSet(ptr); // 如果被mark了,说明正在被使用,不能释放
           else if(allocateBitSet(ptr))free(ptr); // 如果没被mark,且存放了不会被使用的数据,就释放
           ptr += ptr.size()
       }
   }
   ```

6. is_ptr实现:

   维护一个balance tree记录所有分配的block,判断ptr是否指向这些block

##### 多核内存访问

- SMP (Symmetric Multi Process): 所有CPU通过总线访问内存
- Numa (Non-uniform): 
  - 每个插槽有距离自己更近的memory
  - Malloc的时候不会真正分配内存,而是在访问时分配在对应的Numa Region

- RDMA (Remote Direct): 通过infini-band协议构建,使分布式服务器共享内存 

### 2.5 硬盘

##### 固态硬盘

- Page: 512KB-4KB. **必须flush整个block才能写入page** 随机写入<u>1ms</u>
- Block: Page组成的分区,有32-128 Pages. **写入10w次以后就报废了**
- 读取速度$10\mu s$

##### 机械硬盘

操作顺序

1. 磁道(track):寻道耗时<u>9ms</u> (电梯寻道算法)
2. 扇区(track):旋转耗时<u>4ms</u>,取决于转速,一个扇区<u>512KB</u>
3. 盘面(plate):读取数据,耗时<u>0.02ms</u>
4. Disk Controller读取数据后通过DMA写入内存,然后发出中断。

### 2.6 虚拟内存

本质上用内存作为磁盘的cache (demand paging,当进程用到数据时,才会加载)

##### Page和文件系统

磁盘和内存交互基本单位

- 一个Page(空文件)大小<u>4KB</u>
- 空文件只有inode,大小<u>256B</u>

##### 页表

- Page Table(TLB) 维护地址空间(VPN)到物理内存的映射 (12位offset)
- 分级页表: 高级页表保存低级页表指针,只有需要使用时,才会真正占用空间

##### Page Fault

mmap的本质就是往Page Table中添加一条映射

1. Page Table寻找失败,中断进入内核
2. 在磁盘中寻找对应的Page
3. 通过页面置换算法,和内存里的Page交换
4. 再次寻找

# 3. 程序运行流程

### 3.1 g++编译

##### 不同参数的作用

| -O(g,1,2,3)  | -S           | -o           | -L                             | -shared |
| ------------ | ------------ | ------------ | ------------------------------ | ------- |
| 优化编译过程 | 生成汇编代码 | 生成目标文件 | 链接时在LD_LIBRARY中寻找.a/.so | 创建so  |

##### 编译流程

$.cpp/.h\rightarrow.i\rightarrow.s\rightarrow.o\rightarrow (.so/.a)\rightarrow elf$

1. 预编译,去除macro和comment

   ```sh
   cpp main.cpp > main.i # 用cpp命令查看预处理结果
   ```

2. 调用编译器产生汇编代码

   ```sh
   g++ main.i -o main.s # 生成.s结尾的汇编
   ```

3. 汇编,生成object文件

   ```sh
   as main.s -o main.o # 生成.o结尾的object elf文件(二进制)
   readelf main.o # 二进制变回汇编
   ```


4. link,生成elf可执行文件

### 3.2 汇编指令集

##### 取内存地址

- 寄存器外面加括号,代表用作内存地址
- leaq用来取地址,也可以用来简单计算 

```assembly
movl	$4, (%rsp) # 在rsp保存的地址中,存放4
movl	$5, 4(%rsp) # 在地址rsp+4的地方保存5
leaq	4(%rsp), %rsi # 获得地址rsp+4位置的数,保存在rsi中,实现+4
```

##### 条件判断

- <u>CPU会通过forward在判断结果出现前提前执行指令,如果判断失败就回滚</u>

- 条件判断/状态的结果会存在4个寄存器中

  | ZF       | CF           | SF         | OF                 |
  | -------- | ------------ | ---------- | ------------------ |
  | 相等比较 | unsigned比较 | signed比较 | 加减后是否overflow |

- 编译器会为switch指令创建一个跳转表(jump table)

##### 执行耗时

CPU不一定会完全按照代码顺序执行指令,而是会根据dependency做优化

| 操作 | int 加法 | int 乘法 | float 乘法 | 函数调用 | 分支预测 | mutex | 系统调用   | 上下文切换/软中断 |
| ---- | -------- | -------- | ---------- | -------- | -------- | ----- | ---------- | ----------------- |
| 耗时 | 1c       | 3c       | 5c         | 1ns      | 3ns      | 17ns  | 200ns~50us | 2.5-6us           |

### 3.3 程序装载

##### elf文件

可执行/链接文件,可以用readelf/objdump查看

```sh
readelf -a main
```

| elf header            | data                | bss                   | symbol table             | text/read only   |
| --------------------- | ------------------- | --------------------- | ------------------------ | ---------------- |
| 记录大小端/机器位数等 | 初始化全局/静态变量 | 未初始化全局/静态变量 | 记录每个函数和变量的位置 | 保存代码和跳转表 |

##### 程序内存划分

elf文件被装载进内存,运行时主要涉及6部分

| kernel code/data | stack            | heap                 | data/bss      | text   |
| ---------------- | ---------------- | -------------------- | ------------- | ------ |
| 内核态相关数据   | 自动分配,最大8MB | 通过malloc等方式分配 | 全局/静态变量 | 代码段 |

##### 函数调用

- 开始阶段 (call)
  1. 下降sp腾出保存参数 (如果参数超过6个,就会存在内存里)
  2. sp中push调用函数完成之后指令
  3. 修改rip寄存器,指向被调用函数的指令

- 进入函数:
  - pushq保存一些寄存器的值,例如rbx
  - 使用sp和寄存器获得输入,并进行逻辑操作
  - popq还原现场,使rbx还原被调用前的状态
  - ret sp指向的地址

- 结束阶段 (ret)
  1. 从sp中pop函数完成之后的指令,并赋值给rip寄存器
  2. 新的指令从rax中获取调用结果
  3. 指向return address

##### 运行时注入攻击

- 输入时,输入的数据超过buffer大小,从而覆盖代码段
  - 通过随机分布stack和heap的相对地址解决
  - 在代码段每行添加权限,确保无法被修改
  - 输入的API添加长度限制
- Return Oriented Programming
  - 在输入时,修改sp指针的位置,使程序按照自己的逻辑进行

### 3.4 程序优化

##### 底层优化

优化<u>constant factor</u>

- 设计数据结构时注意cache line

- 使用寄存器保存数据,而不是内存

  ```c++
  ans = *b;
  for(int i=0,i<length;i++){
      ans += a[i]; //可以把ans放在register中,避免内存写入
  }
  *b = ans;
  ```

- 利用CPU并行性优化

  ```c++
  void(int a[12]){
      sum = 0;
      for(int i=0;i<12;i++4){ // cpu可能可以并行执行4次取地址
  		sum += a[i] + a[i+1] + a[i+2] + a[i+3]; 
      }
  }
  ```

- 减少分支预测

  在不必要的时候,尽量不用条件判断和跳转,而是尽量用表达式+掩码等形式

  ```python
  i = 0
  for t in table:
  	copy(t, output[i]) # 先把tuple复制到buffer
      key = t.key
      m = (key≥low ? 1 : 0) && (key≤high ? 1 : 0) # 不用if
      # 根据filter结果判断buffer的这个slot是否有效
  	i += m
  ```

##### 算法优化

优化时间/空间复杂度

- 注意调用的API复杂度

  ```c++
  void lower(char * s){
      for(size_t i=0;i<strlen(s);i++){ //每次循环都会额外用O(n)都会计算strlen
          if(s[i]>='A'&&s[i]<='Z') s[i] -= 'A'- 'a';
      }
  }
  ```

# 4. 进程和线程

### 4.1 基本概念

- 初始只有1个进程 (init)
- 通过strace可以追踪进程的system call
- 所有进程共享open file table和v-node table

### 4.2 子进程

不同进程之间形成树状结构

##### 复制进程 (fork)

- 共享当前进程所有内容,包括文件指针 

  ```c++
  int main(int argc, char* argv[]){
      int fd, s = 10000 & 0x1;
      char c1, c2;
      fd = open("./file", O_RDONLY, 0);
      read(fd, &c1, 1); 
      if(fork()){ // 返回PID是父进程
          sleep(1);
          read(fd, &c2, 1); 
          printf("parent read %c %c", c1, c2); // parent read a b
      }
      else{ //返回0是子进程,代码一样但结果不一样
          sleep(2);
          read(fd, &c2, 1); 
          printf("child read %c %c", c1, c2); // child read a c
      }
      return 0;
  }
  ```

- 当父进程/子进程写入时,通过COW来区分

##### 装载其他程序 (execve）

```c++
int execve(char * filename, char * argv[], char * envp[]); // 运行失败返回-1
```

| filename     | argv                    | envp     |
| ------------ | ----------------------- | -------- |
| elf文件/脚本 | 输入参数,第一个是文件名 | 环境变量 |

- elf文件中包含的内容会被修改 (heap/stack等)
- 文件描述符,PID等不会改变

##### 进程间关系

- 僵尸进程: <u>子进程完成后仍然会占据OS资源,需要父进程调用wait/waitpid后才会被杀死</u>

  ```c++
  int wait(int * child_status) // 等待某个子进程结束
  // 返回运行完成的子进程PID
  // child_status会被设置为子进程结束时的状态
  int waitpid(int pid, int & status, int options) // 等待特定进程结束
  ```

- 如果父进程直接被杀死了,init(pid=0)就会成为子进程的父进程,并等子进程运行完后kill

- wait可以等待某个子进程运行完成,并获得返回结果

### 4.3 进程间通信

##### signal信号

每个进程描述文件中有两个bit array,对应30种signal

信号触发流程

1. kernel在reschedule时进入检查阶段

2. 查看进程的pending文件,获得signal

3. 和屏蔽掩码mask做交集,过滤不用的信号

4. 调用handler

   ```c++
   handler_t * signal(int signum, handler *t handler) 
   signal(SIGINT, my_handler);  // 设置定义信号量的处理方式,返回和输入都是函数指针
   ```

信号处理函数要点**(signal可能会在任何时候发生)**

- 只调用简单接口,不要访问外部资源
- 在进入获得errno并在退出时重置

- 不破坏shared data structure
- 定义全局变量为volatile,全局flag为原子变量

- 不能用handler来计数,因为可能多次相同的signal只触发一次handler (reschedule时只看到一次)

- 灵活运用signal mask (sigprocmask和sigsuspend)以延迟handler的运行时点

##### shared memory

- 使用memmap来映射各自的地址空间到同一片区域

##### socket (FIFO)

如果是本机的话,不走网卡

##### 文件

共享文件描述符

##### pipe (FIFO)

父子进程常用,本质上是通过共享file和文件描述符

### 4.4 线程

进程以类似tree的形式生长,线程类似Pool

共享

| 页表 | 地址空间 | kernel | data | text | heap |
| ---- | -------- | ------ | ---- | ---- | ---- |

独占

| register | sp   | PC   | stack (可以通过传指针共享) |
| -------- | ---- | ---- | -------------------------- |

##### CPU间同步

- mutex:开销大(获取失败会进入内核reschedule)

- semaphore: 支持原子操作P和**V(记得释放信号)**

  - P(s):如果s=0就阻塞到可以-1并返回
  - V(s): s++并检查是否有阻塞的进程可以启动
- cache: 通过总线,触发获得cache数据的请求,从其他cpu获得数据
- CPU间共享MMU,可能成为瓶颈

# 5. 网络IO

### 5.1 client-server model

1. 通过getaddrinfo获得addrinfo链表

   ```c++
   # include <sys/socket.h>
   # include <netdb.h> // 定义了getaddrinfo
   struct addrinfo *p, *list_p, hints; // addrinfo是一个链表，hint定义了需要获得特征的信息
   memset(&hints, 0, sizeof(struct addrinfo));
   hints.ai_family = AF_INET; // 使用IPV4地址
   hints.ai_socktype = SOCK_STREAM; // 使用TCP协议
   int flag = getaddrinfo(domain, NULL, &hints, &list_p);// 返回的结果放在链表list_p中
   ```

2. 遍历addrinfo链表,尝试构造socket描述符

   ```c++
   for(p=list_p;p;p=p->ai_next){ // 遍历链表
        // 通过get name info把socket address转化成domain name并打印
       getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flag); 
       int fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol); 
       // 成功构造socket就break
       if(fd >-1)break;
   }
   ```

3. client和server进行各自操作

   - client会自动生成临时端口

     ```c++
     connect(client_fd, p->ai_addr, p->ai_addrlen); // client会去连接server
     ```

   - server需要先绑定端口,在接受连接请求,提供服务

     ```c++
     bind(server_fd, p->ai_addr, p->ai_addrlen); // server绑定端口
     listen(server_fd, 100); // server监听端口连接,等待队列长度为100个
     conn = accept(server_fd, p->ai_addr, p->ai_addrlen ); // 获得client描述符,可以像文件一样通信
     ```

### 5.2 并发服务器模型

如果没有并发,一个用户堵住了就会导致server无法正常工作

- 进程模型

  server在accept client后,fork一个子进程来处理和这个client的通信 (开销大,IPC麻烦)

  ```c++
  int listen_df = socket(p->ai_family, p->ai_socktype, p->ai_protocol); // 获得server监听socket
  while(1){
      int client_end = accept(listen_fd, p->ai_addr, p->ai_addrlen);
      if(fork()==0){ // 子进程
          close(listen_fd); // 关闭server socket
          echo(client_end);// 子进程关闭监听
          close(client_fd); // 子进程完成服务,关闭连接
          exit(0);
      }
      close(client_end); // 
  }
  ```

- 使用Select/Epoll来实现event-based IO多路复用 <u>(nginx,Node.js等高并发服务器使用)</u>

  <u>debug很容易,需要精心设计回调函数</u>

  1. listen_fd accept到一个client后创建client_end
  2. 当某个client_end有event触发时,会读取数据并触发回调函数

- 多线程并发模型

  每个线程有自己独享的stack frame, PC和register

  <u>主线程必须在heap上创建变量给子线程,否则主线程下一次循环后可能改变子线程的输入</u>

  ```c++
  void * thread_job(void * client_end){ // server处理的函数
      int client_fd = *((int *)client_end); // 在自己的stack上创建描述符
      free(client_end); //free heap上分配的空间
      pthread_detach(pthread_self()); // 脱离主线程
      echo();
      close(client_fd);
      return nullptr;
  }
  pthread_t tid;
  int listen_df = socket(p->ai_family, p->ai_socktype, p->ai_protocol); // 获得server监听socket
  while(1){
      int * client_end = malloc(sizeof(int)); // 在heap上分配内存,可以给子线程使用
      *client_end = accept(listen_fd, p->ai_addr, p->ai_addrlen); // 获得client描述符
      pthread_create(&tid, NULL, thread_job, client_end); // 创建子线程处理
  }
  ```

  







