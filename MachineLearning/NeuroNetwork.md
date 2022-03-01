[toc]

# 1. 神经网络结构

### 1.1 Overview

##### Forward

- 网络接受$n$维输入,再经过各个layer的神经元计算,得到输出
- 神经元之间通过线性层和激励函数组成
- 复杂神经网络可以拟合任何函数的输出

##### Error Decomposition

- Approximation Error: 衡量网络输出和真实label之间的差距,通过<u>损失函数衡量</u>
- Estimation Error: 训练集和测试集之间的表现差距,<u>通过可扩展性和过拟合衡量</u>
- Optimization Error: 网络参数训练效率和参数数量过多,<u>通过正则化表现衡量</u>

##### Back Prorogation

- 根据损失函数的梯度和链式法则来更新神经元的权重
- 根据神经网络结构不同,可能会有梯度消失/梯度爆炸问题
- 计算量非常大,需要考虑优化(例如通过sparse矩阵)

### 1.2 激活函数

为神经网络添加非线性层,否则本质上就是线性回归

##### Sigmoid

- 通常用于分类问题,例如逻辑回归

- $\sigma(x)=\frac{1}{1+e^{-x}}$
- $\sigma(x)'=\sigma(x)[1-\sigma(x)]$

##### tanh

##### RELU

# 2. 反向传播

### 2.1 SGD

### 2.2 Moment优化

### 2.3 牛顿法



# 3. 过拟合

### 3.1 正则化

##### L1

- 给损失函数添加了$\frac{1}{2b^2}\sum_j|w_j|$项
- 本质上是添加了模型参数服从标准double exponential distribution的先验分布
- $l'(w)=-\log(L'(w))=-\log(P(y|x,w)P(w))=-\log(P(y|x,w)\prod_j\frac{1}{2b}\exp(-\frac{|w_j|}{b}))=l(w)+\frac{1}{2b^2}\sum_j|w_j|$
- <u>因为是L1-norm,所以更加容易和坐标轴相切,获得稀疏的参数矩阵</u>

##### L2

- 给损失函数添加了$\frac{1}{2\sigma^2}w^Tw$项
- 本质上是添加了模型参数服从零均值正态分布的先验分布
- $l'(w)=-\log(L'(w))=-\log(P(y|x,w)P(w))=-\log(P(y|x,w)\prod_j\frac{1}{\sqrt{2\pi}\sigma}\exp(-\frac{(w-\mu)^2}{2\sigma^2})=l(w)+\frac{1}{2\sigma^2}w^Tw$
- L2正则化不会让参数更加稀疏,但是会让参数的绝对值比较小

### 3.2 训练优化

##### Dropout

- 删除训练过程中经常没有更新,且大小为0的分支

##### Early Stopping

- 在损失函数收敛到过小前,提前结束训练

##### Compressing

- 将更新pattern相似的权重共享参数值,减少权重数量

# 5. 记忆神经网络

### 5.1 RNN

##### Overview

$$
s_i=g(s_{i-1}W^s+x_iW^x+b)
$$

- 隐藏层$s_i$的输入不光为特征$x_i$,还有序列中上一个隐藏层的输出$s_{i-1}$
- 隐藏层保存了word的隐藏状态,可以被视为POS:

- 隐藏层状态被激活后才会被输出$y_i=\sigma(s_iW)$
- 可以附加单词以外的特征作为输入
- 通常使用Relu和tanh作为激励函数$g$

##### BiRNN

- 将隐藏层拆分,分别从前向后$s_i$和从后向前$s_{i-1}$获取隐藏状态
  $$
  s_i=g(s_{i-1}W^s+x_iW^x+b)\\
  s'_i=g(s'_{i+1}W^{s’}+x_iW^x+b)
  $$

- 

- 输出由双向隐藏层的状态共同激活 $y_i=\sigma(s_iW+s_i'W')$

##### Performance

- 随着序列的变长,隐藏层的状态以幂速度衰减,因此使用序列开头的信息
- 梯度的传播也以幂级衰减,因此无法根据距离较远的输出来修改权重

### <u>5.2 LSTM</u>

##### Overview

- 在隐藏层之外,添加了记忆层,用来保存序列之前的信息

- 通过输入$x_t$,上一次状态$h_t$,遗忘门$\sigma(W_f)$和记忆门$\sigma(W_i)\tanh(W_c)$来处理记忆
  $$
  c_t=\sigma(W_f\begin{bmatrix}[h_{t-1} & x_t]\end{bmatrix})\cdot c_{t-1}+\sigma(W_i\begin{bmatrix}[h_{t-1} & x_t]\end{bmatrix})\tanh(W_c\begin{bmatrix}[h_{t-1} & x_t]\end{bmatrix})
  $$

- 根据更新后的记忆门来更新隐藏层
  $$
  h_t=\tanh(c_t)\sigma(W_o\begin{bmatrix}[h_{t-1} & x_t]\end{bmatrix})
  $$

##### Performance

- 可以记住超过200个单词的context 
- 不好处理未见过的单词