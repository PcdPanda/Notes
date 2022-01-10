[toc]

# 1. 凸优化基本概念

### 1.1 目标函数

在有约束条件的情况下,求函数的最小值
$$
\min_x\quad f_0(x)\\
\mathrm{s.t.}\quad f_i(x)\leq 0\\
h_i(x)=0
$$

### 1.2 仿射集和凸集

##### 仿射集

$y=\theta_1 x_1+\theta_2 x_2\cdots \theta_n x_n\quad\mathrm{s.t.}\quad\sum_{i=1}^n\theta_i=1$

两个点可构成线,三个点可构成面,四个点构成体

<u>仿射独立: 任何一个点不在其他点的仿射集中</u>

##### 凸集

$y=\theta_1 x_1+\theta_2 x_2\cdots \theta_n x_n\quad\mathrm{s.t.}\quad\sum_{i=1}^n\theta_i=1\quad\forall\theta_i\geq0$

是仿射集的子集,但是位于顶点中央

当$x$连续时,令$p(x_i)=\theta_i$,可以把$p$转化为概率

##### 凸包

给定任意集合,包含该集合的最小凸集

##### 内点

$x$存在邻域,是凸包的子集 ($x$不在凸集的边上)

### 1.3 常见凸集

##### 半空间和超平面

$a$是平面的法向量,$x_0$在平面的分界线上

$\{x:a^T(x-x_0)\leq 0\}$ 

##### 多面体

$a_i$限制了多面体的方向,$c_i$

$\{x: a_i^T(x-x_i)\leq0,c_i^Tx=d_i\}$

##### 单纯形

包含任何仿射独立点的凸包

##### 凸锥

$y=\theta_1 x_1+\theta_2 x_2\cdots \theta_n x_n\quad\mathrm{s.t.}\quad\forall\theta_i\geq0$

必定包含原点

##### 分离超平面

对于两个不相交的凸集,一定存在超平面${x:a^Tx=b}$使得凸集在它的两侧

##### 支撑超平面

### 1.4 保凸函数



# 2. 解决方法

### 单纯形法

### 椭球法

### 内点法

