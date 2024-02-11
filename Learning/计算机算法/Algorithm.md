- [1. 算法分析基础](#1-算法分析基础)
    - [1.1 评价标准](#11-评价标准)
        - [正确性](#正确性)
        - [性能](#性能)
        - [可维护性](#可维护性)
    - [1.2 复杂度分析](#12-复杂度分析)
        - [定义](#定义)
        - [考虑场景](#考虑场景)
    - [1.3 递归分析](#13-递归分析)
        - [常规解法](#常规解法)
        - [Master Theorem](#master-theorem)
    - [1.4 均摊分析](#14-均摊分析)
        - [Vector时间复杂度案例](#vector时间复杂度案例)
        - [Accounting Method](#accounting-method)
        - [Potential Method](#potential-method)
    - [1.5 竞争分析](#15-竞争分析)
        - [基本概念](#基本概念)
        - [自组织表案例](#自组织表案例)
        - [均摊在线操作](#均摊在线操作)
- [2. 分治](#2-分治)
    - [2.1 分治](#21-分治)
        - [复杂度分析](#复杂度分析)
        - [求斐波那契数](#求斐波那契数)
        - [VLSI布局](#vlsi布局)
    - [2.2 非比较排序](#22-非比较排序)
        - [Count Sort](#count-sort)
        - [Radix Sort](#radix-sort)
    - [2.3 Random Select](#23-random-select)
        - [常规思想](#常规思想)
        - [优化算法](#优化算法)
- [3. 哈希表](#3-哈希表)
    - [3.1 基本概念](#31-基本概念)
        - [重要概念](#重要概念)
        - [链表哈希碰撞问题](#链表哈希碰撞问题)
    - [3.2 Hashing Application](#32-hashing-application)
        - [Universal Hashing 全域哈希](#universal-hashing-全域哈希)
        - [Perfect Hashing 完全哈希](#perfect-hashing-完全哈希)
- [4. Tree](#4-tree)
    - [4.1 二叉搜索树](#41-二叉搜索树)
        - [基本概念](#基本概念-1)
        - [Treap](#treap)
        - [区间树](#区间树)
        - [线段树](#线段树)
    - [4.2 平衡树](#42-平衡树)
        - [红黑树 (常用平衡二叉树)](#红黑树-常用平衡二叉树)
        - [2-3-4树](#2-3-4树)
    - [4.3 多路树的数据库应用](#43-多路树的数据库应用)
        - [B树 (中位附近的数据查询很快)](#b树-中位附近的数据查询很快)
        - [B+树 (m很大)](#b树-m很大)
        - [LSM-Tree](#lsm-tree)
    - [4.4 跳跃表](#44-跳跃表)
        - [思想分析](#思想分析)
        - [插入流程](#插入流程)
    - [4.5 默尔克树](#45-默尔克树)
- [5. 图论算法](#5-图论算法)
    - [5.1 Graph基本概念](#51-graph基本概念)
        - [分类](#分类)
        - [分析](#分析)
    - [5.2 最小生成树 (MST)](#52-最小生成树-mst)
        - [Prim算法](#prim算法)
        - [Kruskal算法](#kruskal算法)
    - [5.3 搜索单源最短路径](#53-搜索单源最短路径)
        - [基本设定](#基本设定)
        - [Dijkstra 算法(不能有负边)](#dijkstra-算法不能有负边)
        - [Bellman-Ford 算法（可以有负边，且可以找出负环）](#bellman-ford-算法可以有负边且可以找出负环)
    - [5.4 多源最短路径](#54-多源最短路径)
        - [Floyd - Warshall 算法](#floyd---warshall-算法)
        - [Johnson 算法](#johnson-算法)
- [6. 缓存算法](#6-缓存算法)
    - [6.1 设定和表示](#61-设定和表示)
    - [6.2 数组操作](#62-数组操作)
        - [遍历数组](#遍历数组)
        - [二分搜索](#二分搜索)
        - [随机查找](#随机查找)
    - [6.3 矩阵乘法](#63-矩阵乘法)
    - [6.4. 静态搜索树](#64-静态搜索树)
        - [访问有N个节点的二叉树的叶子结点](#访问有n个节点的二叉树的叶子结点)
    - [6.5 排序](#65-排序)
        - [用搜索树排序](#用搜索树排序)
        - [merge sort](#merge-sort)
        - [缓存相关merge sort](#缓存相关merge-sort)
      - [缓存无关高效merge sort](#缓存无关高效merge-sort)
- [7. 并行算法](#7-并行算法)
    - [7.1 设定和表示](#71-设定和表示)
    - [7.2 贪婪调度](#72-贪婪调度)
    - [7.3 矩阵乘法](#73-矩阵乘法)
- [\\end{array}\\right\]](#endarrayright)
    - [7.4 并行排序](#74-并行排序)


# 1. 算法分析基础

### 1.1 评价标准

##### 正确性

- 稳定性: 相同输入有相同输出
- 边界条件: 是否覆盖所有可能的输入
- 安全性: 是否可靠

##### 性能

<u>实际应用时需要考虑常数项</u>

- 时间复杂度
- 空间复杂度
- 性能是否稳定

##### 可维护性

- 模块化
- 开发成本

### 1.2 复杂度分析

本质上为了忽略不同计算机间的区别

##### 定义

$\exist c \quad f(n)<c\cdot g(n)\quad\forall n\geq n_0$

- $O(n)$ 决定上界,对于任意$n_0$存在c都可以$f(n)$比$g(n)$小
- $\Omega(n)$ 决定下界,对于任意$n_0$存在c都可以$f(n)$比$g(n)$大
- $\Theta(n)$ **同时包括上下界**

##### 考虑场景

- 最差场景
- 期望场景,需要考虑<u>输入的分布</u>

### 1.3 递归分析

由形如$T(n)=g(T(n/b))$递归式得到$T(n)$的复杂度

##### 常规解法

- 代换法: 猜测表达式，用表达式替代原公式，再用数学归纳法自底向上证明

- 递归树法: 一层一层求**非递归项的和并累加**

##### <u>Master Theorem</u>

可以通过递归树证明,高度为$\log_b n$，叶节点数量为$a^{\log_b n}$

<u>比较$f(n)$的复杂度和$n^{\log_b a}$</u>
$$
T(n)=aT(n/b) + f(n) \\
\text{ s.t   } a\ge1,b>1
$$

- 如果$f(n)=O(n^{\log_b a-\omega})$, 即**f(n)更小,则$T(n)$受限于**$n^{\log_b a}$
  $$
  T(n)=\Theta(n^{\log_ba})
  $$

- 如果$f(n)=\Theta(n^{\log_b a})$, 即**f(n)很接近,则$T(n)$受限于**$n^{\log_b a}\log n$
  $$
  T(n)=\Theta(n^{\log_ba}\log n)
  $$

- 如果$f(n)=\theta(n^{\log_b a}\log^k n)$,**即f(n)大log阶,则**$T(n)$**受限于**$\log nf(n)$
  $$
  T(n)=\theta(n^{\log_b a}\log^{k+1}n)
  $$

- 如果$f(n)=\Omega(n^{\log_b a+\omega})$, 即**f(n)更大,则$T(n)$受限于**$f(n)$
  $$
  T(n)=\Theta(f(n))
  $$

### 1.4 均摊分析

##### Vector时间复杂度案例

- 每次$n\text{(\# keys) }\approx m\text{(\# slots) }$时,slot数扩大一倍

- <u>平均</u>插入时间是$\Theta(1)$

##### Accounting Method

- 每次操作可以累计常数级费用用作日后开支

- 每次操作需要支付不同的费用,扩表时需要$n$,平时是常数

##### Potential Method

1. <u>找到合理的函数</u>$\Phi$将数据结构映射到$\mathbb{R}, \Phi(D(0))\rightarrow0$

2. 操作$i$将$D(i-1)\rightarrow D(i)$,支付$c_i$作为费用

3. 平摊代价 $\hat{c_i}=c_i + (\Phi(D(i-1))-\Phi(D(i))$  (势能的变化加上费用)

   $\sum_i^n\hat{c_i} \geq \sum_i^nc_i + \Phi(D(i)) $ 平摊代价**(就是复杂度)**总和大于实际代价

对于动态增长哈希表 $\Phi(D(i))=2i-\log \lceil i\rceil$ (根据resize频率得出$\log \lceil i\rceil$)

### 1.5 竞争分析

##### 基本概念

- 离线操作: 知道用户所有访问的顺序和请求
- 在线操作: 不知道用户的请求顺序
- 目标: 优化在线操作的开销,使其接近离线操作

##### 自组织表案例

- 有一个链表$L$,可以执行两种操作, 随机访问元素 $O(n)$或交换相邻元素$O(1)$

- 每次操作后，按照每个元素访问概率排序
- 访问概率: 经验法(根据过去的访问次数),把<u>访问的数据交换到最前</u>,消耗$O(n)$,<u>对于热点数据特别有用</u>

##### 均摊在线操作

<u>对于任意输入$S$,在线操作消耗和最优离线方法是同阶的</u>
$$
C_a(S)\leq\alpha C_{opt}(S) + k
$$
通过势能法来计算算法$a$和最优解$opt$间的距离

- $\Phi:\{L_i\}\rightarrow\mathbb{R}$

- $\Phi(L_i)=2|\{x,y\},x\prec_{a}y\text{ and }y\prec_{opt}x|$

势能=两个算法当前顺序相反的元素数的两倍,初始为0, <u>最优解和当前算法解差距越大,可以储存的势能越大</u>

$\Delta\Phi(i)\leq|A-B|+t_{opt}$

对于每次操作$c_i\leq4\hat{c_i}$

$\sum c_i\leq \sum \hat{c_i}+\Delta\Phi(i)\leq\sum \hat{c_i}-\Phi(L_s)$



# 2. 分治

### 2.1 分治

##### 复杂度分析

基于Master Theorem,判断$f(n)$和$n^{\log_b a}$的关系 

$T(n) = aT(n/b) + f(n)$

##### 求斐波那契数

$$
\left[
\begin{array}{1}
F_{n+1} & F_n\\
F_n & F_{n-1}
\end{array}
\right]=\left[
\begin{array}{1}
1 & 1\\
1 & 0
\end{array}
\right]^n
$$

##### VLSI布局 

给定n个结点和结点间最小间距,求面积最小的布局方式

- H型布局 

  - 宽度 $L(n)=2L(n/4)+O(1)\rightarrow L(n)=\Theta(\sqrt{n})$

  - 面积 $S(n)=\Theta(n)$

- 树型布局 

  - 高度 $H(n)=H(n/2)+O(1)\rightarrow H(n)=\Theta(\log n)$

  - 宽度 $W(n)=2W(n/2)+O(1)\rightarrow W(n)=\Theta(n)$

  - 面积 $S(n)=\Theta(n\log n)$

### 2.2 非比较排序

##### Count Sort

- 维护一个表记录每个元素出现的次数,再反向遍历输入在表中的value

- 复杂度为$O(k+n),k$是元素的大小范围（初始化和累加时需要）

##### Radix Sort

- 先按照最后一位排序，再往前
- <u>使用count sort对每一位数字排序</u>

### 2.3 Random Select

从未排序的数列中找到特定rank的数

##### 常规思想

 1. 用quick sort思想进行partition，复杂度为$O(n)$

 2. 根据pivot的位置,进行递归partition

    $T(n) = T(n/k) + O(n)$

3. 最终复杂度为$O(\log n)$

##### 优化算法

1. $n$个数字每5个分一组，每组求median,复杂度为$O(n)$

2. 获得$\frac{n}{5}$个组，求每组median的median作为pivot，用时$T(\frac{n}{5})$

   - 可以知道有$\frac{3}{10}N \text{个元素}\leq p\leq\frac{3}{10}N\text{个元素}$

   - 可能有$0.3\sim0.7N$个元素比$p$小,反之亦然（pivot的位置在0.3~0.7之间）

3. 已知pivot的位置,可以得到最差情况下的递推式和复杂度

    $T(N)\leq T(\frac{N}{5})+T(\frac{7N}{10})+\Theta(N)\rightarrow T(N)=O(N)$

# 3. 哈希表

### 3.1 基本概念

把无限的key映射到有限的slot中,寻找空间和时间的平衡

##### 重要概念

- $m$: slot数量,需要先分配内存,随机访问耗时为常数
- $n$: key的数量,可能大于$m$

- load factor $\alpha=\frac{n}{m}$, 会<u>随着数据变化而变化</u>

##### 链表哈希碰撞问题

- 链表法: 相同slot用链表扩展,时间复杂度为$\Theta(1+\alpha),\alpha$刚好是链表平均长度
- 开放寻址法
  - 出现hash冲突后找下一个可用slot. 具体可用Linear/Round robin/Cuckoo Hash等方法
  - 碰撞概率$\mathrm{Pr}(\text{Probe})=\prod\frac{n}{m}\frac{n-1}{m-1}...\leq1+\alpha(1+\alpha(1+\alpha...))\leq1+\alpha+\alpha^2...=\frac{1}{1-\alpha}$
  - 需要定期扩大$m$

### 3.2 Hashing Application

##### Universal Hashing 全域哈希

随机选取Hash函数解决安全问题

 1. 有$|H|$个哈希函数,对于任意两个key,<u>随机取出的hash函数</u>使他们分配到相同slot的概率是$\frac{1}{m}$

 2. 如果有$n$个key,且哈希表共$m$个slot,则对于任意$x,y\in keys,x\neq y$,随机选择哈希函数使他们碰撞的概率是$\frac{n-1 }{m}$

 3. <u>构造方法</u>

    - 选定m为质数

    - 把任意key分解成$r+1$位(m进制)

    - <u>随机取哈希函数方法</u>

      随机生成一个r位的m进制数$\alpha$,生成如下哈希函数
      $$
      H(key) = (key\cdot\alpha)\mod m
      $$
      哈希函数总数: $|H|=m^{r+1}$

4. 如果$\alpha$和$m$互质,则必然存在$\alpha^{-1}$使得$\alpha\alpha^{-1}\mod m=1$

##### Perfect Hashing 完全哈希

给定一个固定的key集合,哈希表有$m=O(n)$个槽,且需要保<u>证最差情况下</u>查找为$O(1)$

1. 构建两层哈希表,<u>在第二层没有碰撞</u>
2. 第一级使用Universal Hashing,第一层Hash过后会得到
   - 指向第二层特定哈希表的指针
   - 一个特定数字,配合key在第二层进行Hash
3. 第一层Hash有$n$个槽,第二层第$i$个Hash有$n_i^2$个槽 (因为keys的集合已知,且第一个Hash函数在程序开始的时候可知,则可以得出$n_i$)

# 4. Tree

### 4.1 二叉搜索树

##### 基本概念

- 二叉搜索树:
  - 左节点<=根节点<=右节点
  - $\mathbb{E(\text{height})}=\log N$


##### Treap

同时具有bst和heap性质

1. 先按照bst方式插入
2. 插入后生成随机数,并根据随机数实现heap的性质,向上攀升
3. 通过旋转来攀升(插入7后再根据随机值12攀升)

##### 区间树

​	用于查找指定区间是否和树中区间有overlap

- 定义

  - 每个节点存放区间的信息

  - key是区间的<u>left bound</u>

  - 每个节点还额外存放根节点和子树区间<u>right bound的最大值</u>

- 查找顺序(如果左没有,则右也必然没有)
  - 给定查找区间的right bound<u>小于等于左子树的righ bound,就找左边</u>

##### 线段树

- 定义

  - 每个节点存放了区间的左右bound和两个子树key的sum/max

  - 从中间划分区间,<u>分给子树</u>

  - <u>对于长度为N的区间,需要4N的空间(应对最后一层只有1个节点的情况)</u>

  - <u>叶子节点存放实际值</u>

1. 修改区间值(即叶子节点)的时候,递归向上更新,每次$O(\log N)$
2. 查询区间值,<u>拆分区间递归查询</u>,每次$O(\log N)$
3. <u>区间更新,懒标记</u>
   - <u>区间更新是自上往下的</u>
   - 区间更新的时候,不更新到叶子结点,而是留下标记,等到以后遍历到该结点的时候再往下操作

### 4.2 平衡树

子树高度差小于2

##### 红黑树 (常用平衡二叉树)

1. 定义

    - 根节点为黑
    - 无连续红节点
    - 叶节点黑色高度相同 (可以压缩红节点变成2,3.4树)

2. 插入方法

   - 新节点始终为**红色**,如果父节点为红(黑色不用考虑),则判断aunt节点

   - 如果aunt为红
     - 上色父辈为黑,祖父为红,并**递归**
     - 递归结束,设置root为黑

   - 如果aunt为黑或者没有
     - 如果祖孙三代呈直线,则旋转祖父连线,并设置原父节点为黑
     - 如果呈折线,则先旋转父子连线,再进行上一步操作

##### 2-3-4树

- 多路数,一个节点可以包含1/2/3个key,并分出2/3/4个子节点
- **插入节点时避免子树高度变化**
  - 类似红黑树插入，现在叶子节点插入
  - 如果父节点超过4个叶子，就往上升（父节点等于往祖父节点插入）
- 2-3-4树可以展开为红黑树(多余的节点作为红色)

### 4.3 多路树的数据库应用

每个结点可以保存$m$个子节点

##### B树 (中位附近的数据查询很快)

- <u>数据量大</u>,但<u>常用数据接近</u>root时合适

- m代表每个节点的最多子节点数

- 除了根节点，每个节点至少有$\lceil m/2\rceil-1$个key,例如$m=5\rightarrow \text{ \#key}=(m-1)/2$ 

- 插入时,<u>只有key超过m时才拆分</u>

  - 将节点拆分成两半，并把父节点向上插入
  - 递归向上操作(类似红黑树)

- <u>所有叶子节点在同一层</u>

- node保存在磁盘,因此一次加载很多value


##### B+树 (m很大)

​	和B树的区别

- 非叶子节点不存放数据,<u>因此可以存放更多索引</u>
- 叶子节点有<u>指向下一个叶子节点的指针</u>(因此全遍历速度快)
- 根节点存放最大key(每个节点key数和子node数相同)

- 一个节点除了存放key之外还会有占用空间的tuple数据,因此B+树只用叶子节点保存卫星数据，使一个节点可以保存很多key

##### LSM-Tree

- 牺牲小部分读性能换高性能写
- 将数据分为内存区和磁盘

### 4.4 跳跃表

##### 思想分析

- 思路来源于<u>地铁快慢线</u>(有不同长度的链表)

- 在每一个链表上进行$\sqrt[k]{N}$次查询(一共有$k$层和$N$个node)  \

  <u>每一层长度比例是</u>$\bf{\sqrt[k]{N}}\approx2$ , $\frac{n}{q^2}+2q\rightarrow q=3\sqrt[3]{n}$

- 设置k为$\log N$可以得到$O(\log N)$的查询时间

  $\log N\sqrt[\log N]{N}=2\log N$

##### 插入流程

1. 在底层插入
2. 以50%概率决定是否向上提升
3. 如果提升则递归
4. 极大概率高度是$O(\log N)$ (通过布尔不等式证明)

### 4.5 默尔克树

每一个节点存放的是叶子节点hash后的结果,每一个节点都是256位(如果用SHA-256)

- 校验文档的正确性,在下载前计算哈希值

- 快速定位错误,发现一个节点的hash值不正确,就可以定位错误

# 5. 图论算法

### 5.1 Graph基本概念

##### 分类

- DAG (有向无环图): Directed Acrylic Graph
- UCG (无向连通图): Undirected Connected Graph
  - $|E|>|V|$

##### 分析

$O(\log|E|)=O(\log|V|)$

<u>稠密图适合用adjacency matrix</u>

<u>稀疏图适合用adjacency list</u>

### 5.2 最小生成树 (MST)

对于UCG,找出一个连接所有点,且总边长最小的树

最小生成树的子图，也是图自身的最小生成树

<u>Greedy algorithm的前提： 局部最优解也是全局最优解</u>

##### Prim算法

1. 广度优先遍历所有顶点(用斐波那契heap实现一次遍历的队列)

2. 更新遍历的点$V$的相邻点$V'$($V'$必须未被遍历)的key(key就是$\min{(\text{key}, E(V,V'))}$)

   $\text{Time}=\Theta(V)\cdot\text{Exract Min} + \Theta(E)\cdot\text{Update Key}$

   $\text{Time}=\Theta(V\log V+E)$

##### Kruskal算法

1. 根据权重排序所有边
2. 用排序好的边和并查集把所有子集连接

### 5.3 搜索单源最短路径

##### 基本设定

存在条件:

- 存在路径
- 路径长度不为负无穷(**不存在负环**)

常用表示

- $\delta(u,v)$: u和v两点间的最短路径权值
- 松弛: $\delta(u, v)'=min(\delta(u,v),\delta(u,x)+w(x,v))$

##### Dijkstra 算法(不能有负边)

 1. 初始化所有点的key为$\infty$，原点除外

 2. key为原点到该点的估算距离

 3. 从未遍历的点中找出key最小的node，总耗时($V\log V$  )

 4. 遍历该node,并更新它周围的node的key,总耗时($E\log V$)

    $\text{x.key' } = \min(\text{x.key}, V.key + E(V+x))$

    一共有$|V|$次遍历,每次遍历耗时$\text{degree}\cdot\log V$

##### Bellman-Ford 算法（可以有负边，且可以找出负环）

遍历所有边$V$次,每次遍历松弛每一条边(根据三角不等式更新$d(v)'=\min(d(v), d(u) + w(u,v))$)	

1. 添加一个node s,到所有其他node的边长是0
2. 运行BF算法(n+1)次,得到的$\delta(s,i)$就是$x_i$
3. 且$\max(x)-\min(x)$最小

$\text{Time}=O(V*E)$

<u>BF算法可以用来解不等式组</u>
$$
\left[\begin{array}{c}
x_1-x_2\leq w_{21}\\
x_2-x_3\leq w_{32}\\
\cdots\\
x_n-x_1\leq w_{1n}
\end{array}\right]
$$
可以把x转化为n个node,w转化为edge的有向图 $w_{xy}:V_y\rightarrow V_x$

可以通过累加等式两边证明<u>图中如果有负环则无解</u>

### 5.4 多源最短路径

在负权图中找任意两点间的最短路径

构建最短路径矩阵 $D_m^{N\times N}$代表用最多m条边构成的路径,构造的最短路径

$D_m^{N\times N}=D_m^{N\times N}\otimes A^{N\times N}$

$A$代表对所有边一次松弛操作

$D_m^{N\times N}=A^{m}$ (**可以用divide and conquer优化 **$O(n^3\log n)$)
$$
D_0^{N\times N}=A^0=
\left[\begin{array}{cccc}
0 & \infty & \infty & \cdots\\
\infty & 0 & \infty&\cdots\\
\cdots & \cdots & \cdots & \cdots\\
\infty & \infty & \cdots & 0
\end{array}\right]
$$

##### Floyd - Warshall 算法 

松弛所有边$V$次,每次通过引入额外一个点松弛, $\text{Time}=O(V^3)$

```python
for k in range(0, v):
    for i in range(0, v):
        for j in range(0, v):
            d(i,j,k) = min(d(i,j), d(i,k) + d(k,j))
```

- $i,j$路径的起止两点

- $k$: 经过的最大点数

##### Johnson 算法

给每个边重新赋值$w_h(u,v)=w(u,v)+h(u)-h(v)\geq0\rightarrow h(v)-h(u)\leq w(u,v)$

<u>不能无脑给所有边加上相同权重,因为每条路径的边数不一样</u>

1. 找到函数$h:V\rightarrow\mathbb{R}$使得所有边$w(u,v)\geq0$
2. 用BF$O(V\cdot E)$找到$h$
3. $h$通常是添加一个虚点$s$($s$到各点的距离为0),则$h(v)=\delta(s,v)$
4. 调用$V$次Dijkstra算法$O(V^2\log V+ VE)$
5. $\delta(u,v)=\delta_h(u,v)-h(u)+h(v)$

# 6. 缓存算法

### 6.1 设定和表示

- $B$ 缓存中1个block的大小,每次传输一个$B$有固定的时间
- $B$内的耗时忽略
- $M$ 缓存的总大小
- $MT(N)$: 从硬盘往缓存传输$N$数据的耗时
- 缓存无关算法: 可以在任意$B,M$下高效运行,<u>无论在几层缓存结构中</u>

### 6.2 数组操作

##### 遍历数组

内存中取数据的Time是$O(N/B+2)$

$O(2)$因为可能数组头和尾可能没有和block对齐

##### 二分搜索

需要查询$O(\log_2N)$次数据,但是当$N=B$时就没有需要传输耗时

$MT(N)=O(\log_2N)-O(\log_2B)=O(\log_2\frac{N}{B})$

##### 随机查找

- 计算$MT(N)$
  - 找$\frac{N}{5}$个subarray的中位数,$MT=O(\frac{N}{B})$
  - 找$\frac{N}{5}$的中位array的中位数,$MT(N)=MT(\frac{N}{5})$
  - 根据pivot递归找$MT(N)=MT(\frac{3}{4}N)$
  - $MT(N)=MT(\frac{3}{4}N)+MT(\frac{N}{5})+O(\frac{N}{B})$
- 计算叶节点数量$L(N)=L(N/5)+L(\frac{3N}{4})\rightarrow L(N)\approx O(N^{0.8393})$
  - 需要传输$N^{0.8393}$次
  - 当$B\geq N^{0.2}\rightarrow O(\frac{N}{B})=\Omega(N^{0.8})\rightarrow MT(N)=\Omega(\frac{N}{B})$
    - 当$B$足够大时,$MT(N)\geq O(\frac{N}{B})$

- 更好的分析,不使用叶节点数量,而是$N=B$的节点数量($L(B)=1$)
  - 等效于根节点是$\frac{N}{B}$的传输时间
  - 需要传输$(\frac{N}{B})^{0.8393}$次
  - $MT(N)=O(\frac{N}{B})$

### 6.3 矩阵乘法

$C^{n\times n}=A\cdot B$

- 把$A,B$拆成$2\times2$的子矩阵
  $$
  C=AB=\left[\begin{array}{cc}A_{11} & A_{12} \\A_{21} & A_{22}\end{array}\right]\cdot\left[\begin{array}{cc}B_{11} & B_{12} \\B_{21} & B_{22}\end{array}\right]=\left[\begin{array}{cc}A_{11}\cdot B_{11} & A_{11}\cdot B_{12} \\A_{21}\cdot B_{11} & A_{21}\cdot B_{12} \\\end{array}\right]+\left[\begin{array}{cc}A_{12}\cdot B_{21} & A_{12}\cdot B_{22} \\A_{22}\cdot B_{21} & A_{22}\cdot B_{22} \\\end{array}\right]
  $$

- $MT(n)=8(n/2)+O(\frac{n^2}{B})\rightarrow MT(n)=O(n^3)$

- 终止条件:**缓存$M$里刚好放了三个submatrix**,此时边长$3n^2=M\rightarrow n=\sqrt{\frac{M}{3}}$

- 缓存中数据总量是$\frac{M}{3}$,加载$O(\frac{M}{B})$次 $\rightarrow MT(\sqrt{\frac{M}{3}})=O(\frac{M}{B})$

- 当边长是$O(\sqrt M)$时停止拆分$\rightarrow MT(n)=O((\frac{n}{\sqrt M})^3)\times O(\frac{M}{B})=O(\frac{n^3}{B\sqrt M})$

### 6.4. 静态搜索树

##### 访问有N个节点的二叉树的叶子结点

对多路树同样有效果

1. 将二叉树根据高度$\log N$对半分,分成子树,直到$N\leq B$为止

2. 将分割后的每颗子树放在1个block的大小里

   - 读取节点数小于B的子树,最多访问两次block, $MT(N)=O(1)\leq2\text{ for }N\leq B$

   - 每颗子树的高度$\frac{1}{2}\log B< h\leq \log B$. 下界源于当高度刚好为$B+1$时还要额外分一次

- 从高度出发每一次遍历的三角形数量$MT=h(tree)/h(cache)\leq2\log N/\log B$

- 总耗时$MT(N)=O(4\log N/\log B)=O(\log_B N)$

### 6.5 排序

##### 用搜索树排序

$MT(N)=N\cdot O(\log_BN)=O(N\log_BN)$

##### merge sort

- $MT(N)=2MT(\frac{N}{2})+O(\frac{N}{B})\rightarrow MT(N)=O(N\log N)$
- 当数据量为$M$时, $MT(M)=O(\frac{M}{B})\rightarrow MT(N)=O(\frac{N}{B}\log\frac{N}{M})$

##### 缓存相关merge sort

将数据分成$\frac{M}{B}$份 (必须知道M和B才可以操作), 使得每个sub array至少有一个cache block可以用

- $MT(N)=\frac{M}{B}MT(\frac{N\cdot B}{M})+O(\frac{N}{B})$

- 当数据量为$M$时, $MT(M)=O(\frac{M}{B})$
- 递归树高度 $h=\log_{M/B}\frac{N}{M}+1=\log_{M/B}\frac{N}{B}$

- 总$MT=$每层$MT\times h=\frac{N}{B}\log_{M/B}\frac{N}{B}$

#### 缓存无关高效merge sort

​	采用高效缓存merge

1. 先估计cache的大小 $M=\Omega(B^{1+\epsilon})$

   $M=B^2$即可

2. 使用 $\epsilon$路merge sort 

3. 取$\epsilon=\frac{1}{3}$，则使用过$N^\frac{1}{3}=K$路merge sort

4. **假设已知merge的消耗**$MT(N)=O(\frac{K^3}{B}\log_\frac{M}{B}\frac{K^3}{B}+K)$

5. 得到$MT(N)=N_{\frac{1}{3}}MT(N^\frac{2}{3})+O(\frac{N}{B}\log_\frac{M}{B}\frac{N}{B}+N^\frac{1}{3})$

6. 假设$N=\Omega(M)=\Omega(B^2)$,则$\frac{N}{B}=\Omega(\sqrt{N})=\Omega(N^\frac{1}{3})$

7. 由于$\log_\frac{M}{B}\frac{N}{B}>1$(5)中merge的消耗变成$O(\frac{N}{B}\log_\frac{M}{B}\frac{N}{B})$

8. 递归树每一层减小$\frac{2}{3}$

# 7. 并行算法

### 7.1 设定和表示

$T_i$: 所有操作在$i$个处理器上串行执行的耗时

$T_{\infty}$:最长串行路径的耗时(有无穷个处理器的耗时)

$T_1\geq T_p\geq T_\infty$

加速比$T_1/T_p$

<u>最大加速比</u>$T_1/T_\infty=\bar{P}$,平均每步并行操作做的功

### 7.2 贪婪调度

- 一空闲就执行下一个任务
- 耗时$T_p\leq T_\infty+T_1/p$,<u>小于最优耗时的两倍</u>
  - 完成状态,当前可以运行的线程数大于$P$,最多有$T_1/P$个
  - 非完成状态,当前可以运行的任务数小于$P$,最多有$T_\infty$个
- 每次执行完in-degree=0的线程,$T_\infty$-=1

### 7.3 矩阵乘法

$$
C=AB=
\left[\begin{array}{cc}
A_{11} & A_{12} \\
A_{21} & A_{22}
\end{array}\right]
\cdot
\left[\begin{array}{cc}
B_{11} & B_{12} \\
B_{21} & B_{22}
\end{array}\right]
=
\left[\begin{array}{cc}
A_{11}\cdot B_{11} & A_{11}\cdot B_{12} \\
A_{21}\cdot B_{11} & A_{21}\cdot B_{12} \\
\end{array}\right]x
+
\left[\begin{array}{cc}
A_{12}\cdot B_{21} & A_{12}\cdot B_{22} \\
A_{22}\cdot B_{21} & A_{22}\cdot B_{22} \\
\end{array}\right]
$$

**单进程计算**

- 加法 $A_1(n)=4A_1(n/2)+O(n)\rightarrow A_1(n)=O(n^2)$
- 乘法 $M_1(n)=8M_1(n/2)+O(n^2)\rightarrow M_1(n)=O(n^3)$

**多线程计算（8进程）**

- 加法 $A_\infty(n)=A_\infty(n/2)+O(n)\rightarrow A_\infty(n)=O(\log n)$

- 乘法 $M_\infty(n)=M_\infty(n/2)+O(\log n)\rightarrow M_\infty(n)=O(\log^2n)$

并行度$\bar{P}=O(\frac{n^3}{\log^2n})$

<u>过高的并行度意义不大,有时候降低并行度来节约内存更重要</u>

多进程计算（**4**进程）

- 加法 $A_\infty=O(\log n)$
- 乘法 $M_\infty(n)=2M_\infty(n/2)+O(\log n) \rightarrow M_\infty(n)=O(n)$

### 7.4 并行排序

**单进程计算**

$T_1(n)=2T_1(n/2)+O(n)\rightarrow T_1(n)=O(n\log n)$

**多进程计算**

$T_\infty(n)=T_\infty(n/2)+O(n)\rightarrow T_\infty(n)=O(n) $ <u>瓶颈在merge</u>,可以通过对merge进行4子序列优化达到$O(\log^3n)$

并行度 $\bar{P}=O(\log n)$, 并行度低,<u>对于小规模处理器很有用</u>

**多进程merge**

- 找到A(**大数组**)的中位数在B中的位置,再分别merge A和B的前后两部分
- $T_\infty(n)=T_\infty(\frac{3n}{4})+O(\log n)\rightarrow T_\infty(n)=O(\log^2 n)$
- $T_1(n)=T_1(\alpha\cdot n)+T_1((1-\alpha)n)+O(\log n)\rightarrow T_1(n)=O(n)$
- 总排序时间 $T_\infty=T_\infty(n/2)+O(\log ^2n)\rightarrow T_\infty(n)=O(\log ^3n)$