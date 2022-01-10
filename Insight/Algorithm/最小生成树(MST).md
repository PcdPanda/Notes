# 图论和Greedy

### 1. Graph

- DAG (有向无环图): Directed Acrylic Graph
- UCG (无向连通图): Undirected Connected Graph
  - $|E|>|V|$

$O(\log|E|)=O(\log|V|)$

**稠密图适合用adjacency matrix**

**稀疏图适合用adjacency list**



### 2. MST 最小生成树 

对于UCG,找出一个连接所有点,且总边长最小的树

最小生成树的子图，也是图自身的最小生成树

**Greedy algorithm的前提： 局部最优解也是全局最优解**

#### 2.1 Prim算法

1. 广度优先遍历所有顶点(用斐波那契heap实现一次遍历的队列)

2. 更新遍历的点$V$的相邻点$V'$($V'$必须未被遍历)的key(key就是$\min{(\text{key}, E(V,V'))}$)

   $\text{Time}=\Theta(V)\cdot\text{Exract Min} + \Theta(E)\cdot\text{Update Key}$
   
   $\text{Time}=\Theta(V\log V+E)$

#### 2.2 Kruskal算法

1. 根据权重排序所有边
2. 用排序好的边和并查集把所有子集连接



### 3. 单源最短路径

存在条件:

- 存在路径
- 路径长度不为负无穷(**不存在负环**)

常用表示

- $\delta(u,v)$: u和v两点间的最短路径权值
- 松弛: $\delta(u, v)'=min(\delta(u,v),\delta(u,x)+w(x,v))$

#### 3.1 Dijkstra 算法(不能有负边)

 1. 初始化所有点的key为$\infty$，原点除外

 2. key为原点到该点的估算距离

 3. 从未遍历的点中找出key最小的node，总耗时($V\log V$  )

 4. 遍历该node,并更新它周围的node的key,总耗时($E\log V$)

    $\text{x.key' } = \min(\text{x.key}, V.key + E(V+x))$

    一共有$|V|$次遍历,每次遍历耗时$\text{degree}\cdot\log V$



#### 3.2 Bellman-Ford 算法（可以有负边，且可以找出负环）

遍历所有边$V$次,每次遍历松弛每一条边(根据三角不等式更新$d(v)'=\min(d(v), d(u) + w(u,v))$)	

$\text{Time}=O(V*E)$

BF算法可以用来解不等式组
$$
\left[\begin{array}{c}
x_1-x_2\leq w_{21}\\
x_2-x_3\leq w_{32}\\
\cdots\\
x_n-x_1\leq w_{1n}
\end{array}\right]
$$
可以把x转化为n个node,w转化为edge的有向图 $w_{xy}:V_y\rightarrow V_x$

可以通过累加等式两边证明**图中如果有负环则无解**

**解法**

1. 添加一个node s,到所有其他node的边长是0
2. 运行BF算法(n+1)次,得到的$\delta(s,i)$就是$x_i$
3. 且$\max(x)-\min(x)$最小

#### 3.3 DAG有向无环图

- 先用拓扑排序(不断提取in-degree最小的node)
- 然后用BF算法



### 4. 多源最短路径

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


#### 4.1 Floyd - Warshall 算法

松弛所有边$V$次,每次通过引入额外一个点松弛

```python
for k in range(0, v):
    for i in range(0, v):
        for j in range(0, v):
            d(i,j,k) = min(d(i,j), d(i,k) + d(k,j))
```

i,j代表路径的起止两点

k代表经过的最大点数

$\text{Time}=O(V^3)$



#### 4.2 Johnson 算法

给每个边重新赋值$w_h(u,v)=w(u,v)+h(u)-h(v)\geq0\rightarrow h(v)-h(u)\leq w(u,v)$

**不能无脑给所有边加上相同权重,因为每条路径的边数不一样**

1. 找到函数$h:V\rightarrow\mathbb{R}$使得所有边$w(u,v)\geq0$
2. 用BF$O(V\cdot E)$找到$h$
3. $h$通常是添加一个虚点$s$($s$到各点的距离为0),则$h(v)=\delta(s,v)$
4. 调用$V$次Dijkstra算法$O(V^2\log V+ VE)$
5. $\delta(u,v)=\delta_h(u,v)-h(u)+h(v)$

