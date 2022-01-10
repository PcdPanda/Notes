[toc]

# 1. 数据清洗

### 1.1 Z-score

##### 基本概念

给定$n$个样本,每个样本有$d$维,则可以构造样本矩阵$\mathbb{X}\in\R^{n\times d}$

- 每行是样本 $X_n$
- 每列是字段 $X^d$

- 协方差矩阵$\Sigma\in\R^{d\times d}=E[XX^T]-E[X]E[X]^T=E[X-E[X]]E[X-E[X]]^T$

<u>目标,在每个字段进行Z-score:$z_d=\frac{x_d-\bar x_d}{\sigma_d}$</u>

##### 计算流程

1. 计算每个维度的均值$\bar X=\frac{1}{n}\mathbb{X}^T\mathbb{1}\in\R^d$​

2. 计算各个维度之间的协方差矩阵$S=\frac{1}{n}\mathbb{X}^T\mathbb{X}-\bar X\bar X^T=\frac{1}{n}\mathbb{X}^T(I-\frac{1}n\mathbb{1}\mathbb{1}^T)\mathbb{X}$

3. $H=I-\frac{1}n\mathbb{1}\mathbb{1}^T$是投影矩阵,$H\mathbb{X}$的作用是去除$\mathbb{X}$的均值,使均值为0

4. 因为$H$是投影矩阵,因此$H=H^2\rightarrow S=\frac{1}{n}(H\mathbb{X})^T(H\mathbb{X})$

5. 获得$S$的对角线,就是各个维度的方差$\sigma_1,\sigma_2\cdots\sigma_d$

6. 对$H\mathbb X$进行行变换,去除标准差 
   $$
   A=\left[\begin{array}{ccc}\frac{1}{\sqrt{\sigma_1}} & 0 & \cdots & 0\\
   0 & \frac{1}{\sqrt{\sigma_2}} & \cdots & 0\\
   0 & \cdots & \cdots & 0\\
   0 & \cdots & \cdots& \frac{1}{\sqrt{\sigma_d}}\end{array}\right](I-\frac{1}{n}\mathbb{1}\mathbb{1^T})\mathbb{X}
   $$



# 2. 降维

### 2.1 PCA

##### 基本概念

<u>目标: 通过线性变换$A$,将$d$维的信息,压缩到$r$维,使得$r$个维度方差最大(信息量最大)</u>

对于线性变换$A$和样本$\mathbb X$对应的协方差矩阵$S_{\mathbb X}$,根据$S_\mathbb{X}$的计算,则有

- $S_A=A^TS_{\mathbb X}A$为线性变换后的协方差矩阵
- 协方差矩阵是对称矩阵,可以进行正交特征值分解

##### 计算流程

1. 给定样本矩阵$\mathbb{X}\in\R^{n\times d}$
2. 计算协方差矩阵$S=\frac{1}{n}\mathbb{X}^T(I-\frac{1}n\mathbb{1}\mathbb{1}^T)\mathbb{X}$

3. 对$S$进行特征值分解$S=M\Lambda M^{-1}$
4. 由于$S$是对称矩阵,$M$是正交矩阵$M=Q=(Q^{-1})^T$
5. 对$S$作用$Q$则有$\Lambda=Q^TSQ$
6. $Q$就是变换矩阵$A$(行向量是投影方向),$\Lambda$就是新的协方差矩阵
7. 计算完之后通常用来<u>线性回归</u>

##### 新维度数(k)的选择

- 直接令$k=2/3$,方便可视化
- 对$k$画elbow plot,保留较大的$k$
- 计算$1-\alpha=\frac{\sum_i^k\lambda_i}{\sum_i^d\lambda_i}$

##### Sparse PCA

- 当维度数远超样本数时($d>>n$),传统PCA获得的主成分没有意义
- Sparse PCA不保留方差最大的主成分,而是可解释性最强(坐标最稀疏)的主成分

##### Kernel PCA



