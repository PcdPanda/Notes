# Cache

### 1. 缓存构造

#### 1.1 硬件结构

SRAM,常用于cache,1bit需要6个晶体管。**体积大,成本高,容量小,速度快**,和cpu频率相同

<img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210628223134940.png" alt="image-20210628223134940" style="zoom:75%;" />



DRAM, 常用于memory,1bit,需要1个晶体管和1个电容,因此**需要不断充电**,有独立的工作频率。

<img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210628223311437.png" alt="image-20210628223311437" style="zoom:70%;" />

**内存和缓存都是二维的,缓存可以同时传输列和行地址,减少寻址时间**

<img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210628224303648.png" alt="image-20210628224303648" style="zoom:75%;" />



#### 1.2 Cache工作机制模型

根据index和tag分成不同block

<img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210628232116491.png" alt="image-20210628232116491" style="zoom:50%;" />



ways of associative, 调整index和tag的位长,获得不同的性能

<img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210628231810805.png" alt="image-20210628231810805" style="zoom:75%;" />

查看缓存构造

```bash
cat /sys/devices/system/cpu/cpu0/cache/index1/size
# 32K 
cat /sys/devices/system/cpu/cpu0/cache/index1/number_of_sets
# 64 一共64组set
cat /sys/devices/system/cpu/cpu0/cache/index1/ways_of_associativity
# 8 每组set里有8个cache line
# /sys/devices/system/cpu/cpu0/cache/index1/coherency_line_size
# 64, cache line大小 2^(15-6-3)=64 byte
```

缓存性能分析

- hit rate
- miss punishment

#### 1.3 缓存模型与算法

<img src="https://i.imgur.com/suD65Rs.png" alt="img" style="zoom:50%;" />

缓存不单指cache,还包括memory, ssd等,淘汰LFU, LRU, FIFO

**缓存无关算法**:不会因为缓存的大小,而改变时间复杂度



### 2. 缓存无关算法分析

#### 2.1 符号和概念

- $B$ 缓存中1个block的大小,每次传输一个$B$有固定的时间
- $M$ 缓存的总大小
- $MT(N)$: 从硬盘往缓存传输$N$数据的耗时,通常忽视对一个block内的操作耗时



#### 2.2 简单实例

 **遍历数组**

<img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210501104006867.png" alt="image-20210501104006867" style="zoom:33%;" />	

内存中取数据的Time是$O(N/B+2)$

$O(2)$因为可能数组头和尾可能没有和block对齐

##### 二分搜索

需要查询$O(\log_2N)$次数据,但是当$N=B$时就没有需要传输耗时

$MT(N)=O(\log_2N)-O(\log_2B)=O(\log_2\frac{N}{B})$



#### 2.3 矩阵乘法

$$
C^{n\times n}=A\cdot B
$$

- 传统计算方法

  - $A$是行式存储,$B$是列式存储
  - 对于$C$的每个元素,需要$MT=O(\frac{n}{B})\rightarrow MT(n)=O(\frac{n^3}{B})$

- **更好的计算方法**

  - 把$A,B$拆成$2\times2$的子矩阵
    $$
    C=AB=\left[\begin{array}{cc}A_{11} & A_{12} \\A_{21} & A_{22}\end{array}\right]\cdot\left[\begin{array}{cc}B_{11} & B_{12} \\B_{21} & B_{22}\end{array}\right]=\left[\begin{array}{cc}A_{11}\cdot B_{11} & A_{11}\cdot B_{12} \\A_{21}\cdot B_{11} & A_{21}\cdot B_{12} \\\end{array}\right]+\left[\begin{array}{cc}A_{12}\cdot B_{21} & A_{12}\cdot B_{22} \\A_{22}\cdot B_{21} & A_{22}\cdot B_{22} \\\end{array}\right]
    $$

  - $MT(n)=8(n/2)+O(\frac{n^2}{B})\rightarrow MT(n)=O(n^3)$

  - 终止条件:**缓存$M$里刚好放了三个submatrix**,此时边长$3n^2=M\rightarrow n=\sqrt{\frac{M}{3}}$

  - 缓存中数据总量是$\frac{M}{3}$,加载$O(\frac{M}{B})$次 $\rightarrow MT(\sqrt{\frac{M}{3}})=O(\frac{M}{B})$

  - 当边长是$O(\sqrt M)$时停止拆分$\rightarrow MT(n)=O((\frac{n}{\sqrt M})^3)\times O(\frac{M}{B})=O(\frac{n^3}{B\sqrt M})$



### 4. 静态搜索树

**访问有N个节点的二叉树的叶子（对多路树同样有效）**

- 将二叉树根据高度$\log N$对半分,直到$N\leq B$为止

- 将分割后的每颗子树放在1个block的大小里

  <img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210501155424842.png" alt="image-20210501155424842" style="zoom:50%;" />

  - 读取节点数小于B的子树,最多访问两次block, $MT(N)=O(1)\leq2\text{ for }N\leq B$
  - 每颗子树的高度$\frac{1}{2}\log B< h\leq\lceil\log B\rceil$. 当高度刚好为$\lfloor\log B+1\rfloor$时还要额外分一次

- 一次搜索遍历的子树数量$MT(N)=h(tree)/h(cache)\leq2\log N/\log B$

- 总耗时$MT(N)=O(4\log N/\log B)=O(\log_B N)$

