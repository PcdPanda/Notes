# 自组织表

**LRU算法可以参考MTF算法,即下列的交换算法**

### 1. 自组织表

有一个链表$L$,可以执行两种操作

- 对其中的元素进行随机访问  $O(n)$
- 交换相邻元素$O(1)$

<u>离线操作</u>: 知道用户所有访问的顺序和请求

<u>在线操作</u>:不知道用户的下一个请求

<img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210422225314017.png" alt="image-20210422225314017" style="zoom:50%;" />

#### 目标: 最小化在线操作的代价

- 每次操作后，按照每个元素访问概率排序

  判断访问概率的方法：经验法(根据过去的访问次数),把**访问的数据交换到最前**,消耗$O(n)$,**对于热点数据特别有用**

  <img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210422225338122.png" alt="image-20210422225338122" style="zoom:50%;" />

### 2. 竞争分析(不需要统计分析)

竞争性: 对于**任意输入**$S$,在线操作消耗**和最优离线方法是同阶的**
$$
C_a(S)\leq\alpha C_{opt}(S) + k
$$

通过势能法来计算算法$a$和$opt$间的距离

​	$\Phi:\{L_i\}\rightarrow\mathbb{R}$

​	$\Phi(L_i)=2|\{x,y\},x\prec_{a}y\text{ and }y\prec_{opt}x|$

势能=两个算法当前顺序相反的元素数的两倍,初始为0

最优解和当前**算法解差距越大**,可以**储存的势能越大**

$\Delta\Phi(i)\leq|A-B|+t_{opt}$

对于每次操作$c_i\leq4\hat{c_i}$

$\sum c_i\leq \sum \hat{c_i}+\Delta\Phi(i)\leq\sum \hat{c_i}-\Phi(L_s)$



### 3. 2阶竞争

把访问的数据直接放到最前,而不是交换,复杂度为$O(1)$

