- [1. 数据清洗](#1-数据清洗)
    - [1.1 Z-score](#11-z-score)
        - [基本概念](#基本概念)
        - [计算流程](#计算流程)
- [2. 降维](#2-降维)
    - [2.1 PCA](#21-pca)
        - [基本概念](#基本概念-1)
        - [计算流程](#计算流程-1)
        - [新维度数(k)的选择](#新维度数k的选择)
        - [Sparse PCA](#sparse-pca)
        - [Kernel PCA](#kernel-pca)
    - [2.2 SVD](#22-svd)
        - [基本概念](#基本概念-2)
        - [缺点](#缺点)
- [3. Expectation Maximation (EM)](#3-expectation-maximation-em)
    - [3.1 K-Means](#31-k-means)
        - [Overview](#overview)
        - [算法步骤](#算法步骤)
        - [初始化优化](#初始化优化)
    - [3.2 EM算法](#32-em算法)
        - [Overview](#overview-1)
        - [算法步骤](#算法步骤-1)
    - [3.3 GMM模型](#33-gmm模型)
        - [Overview](#overview-2)
        - [计算步骤](#计算步骤)
- [4. Annotation](#4-annotation)
    - [4.1 Annotation Guideline](#41-annotation-guideline)
        - [Pipeline步骤](#pipeline步骤)
        - [Guideline](#guideline)
    - [4.2 Inter-annotator Agreement](#42-inter-annotator-agreement)
        - [Agree Annotation Percentage](#agree-annotation-percentage)
        - [Cohen's Kappa](#cohens-kappa)
        - [Fleiss' Kappa](#fleiss-kappa)
        - [Krippendorff's $\\alpha$](#krippendorffs-alpha)


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

### 2.2 SVD

##### 基本概念

- 使用$A=U\Sigma V^T$通过将信息矩阵分解,根据特征值大小,可以对输入内容进行分类
- $U$中的每一列可以表示一个cluster,将类似的term汇总
- $\Sigma$中的奇异值表示了每个cluster的信息含量,越大说明越有意义
- $U\Sigma$描述了每一个term在cluster中的位置,再通过$V^T$转换到元空间

##### 缺点

- 可解释性差
- 训练复杂度高$O(mn)$
- 新增维度时,需要重新训练

# 3. Expectation Maximation (EM)

### 3.1 K-Means

##### Overview

- 是EM算法的硬聚类/精简模式

- 给定$N$个$D$维向量$\{x_1,\cdots,x_n\}$,将向量聚合到$K$个cluster中,即最小化每个点到对应质心的距离 ($r_{nk}$是indicator变量)
  $$
  \min\sum_{n=1}^N\sum_{k=1}^Kr_{nk}||x_n-\mu_k||^2
  $$

- $K$需要预先指定,是模型的超参数

- 模型结果容易收到初始随机点位置的影响,且可能陷入局部最优解

##### 算法步骤

1. 随机生成$K$个点,作为每个cluster的质心
2. 遍历所有向量$x_n$,每个向量分配到随机的cluster质心中,即更新$r_{nk}$
3. 更新每个cluster质心的位置，即更新$\mu_k=\frac{\sum r_{nk}x_n}{\sum_nr_{nk}}$
4. 回到第二步直到质心收敛

##### 初始化优化

1. 随机生成第一个cluster执心
2. 给所有数据点$x$计算到最近最近质心的距离,并分类
3. 从数据点$x$中随机选取作为下一个cluster质心,$x$到最近质心的距离越远,被选中的概率越高
4. 重复2-3直到生成$K$个质心

### 3.2 EM算法

##### Overview

- 未知隐变量参数$\theta_i$基于样本的分布$p(\theta_i|X_i)$ (即未知样本是哪个参数产生的)

- 通过样本在假定变量参数$\hat\theta_i$下出现的概率作为子样本,并使用子样本来更新隐变量参数$\hat\theta_i$

- 可以使用K-means的初始化优化来初始化隐变量参数$\theta_i$

- 可能陷入局部最优解,同样需要先知道隐变量的数量$K$ (即质心数量)

- 令$z_k$代表$\theta_k$出现的概率,本质上通过更新参数,使得当前结果出现的似然函数最大化
  $$
  \arg\max_\theta \sum_{n=1}^N\sum_{k=1}^Kp(z_k|x_n;\theta)\log p(x_n|z_k;\theta)
  $$

##### 算法步骤

1. 随机生成$k$个的隐变量参数$\hat\theta_k$
2. 对于每个样本,计算不同隐变量在样本下出现的概率$p(z_k|x_n)=\frac{p(x_n|z_k)p(z_k)}{\sum p(x_n|z_i)p(z_i)}$ (通常不同$z_k$出现概率相同,因此可以抵消)
3. 基于$p(z_k|x_n)$重新分配观测值$p(z_k,x_n)$,进行极大似然估计,更新变量参数$\theta'$

### 3.3 GMM模型

##### Overview

- 给定$N$个样本点$x_n$,每个样本来自于$K$个正态分布中的一种$N\sim(\mu_k,\sigma_k)$
- 使用EM算法来计算$k$个正态分布的参数以及属于$k$的概率$p(z_k|x_i)$

##### 计算步骤

1. 随机生成$K$个正态分布的参数$\mu_k$和$\sigma_k$

2. 计算每个样本在$k$分布下的概率 $p(x_i,k_i)=\frac{1}{\sqrt{2\pi\sigma_k}}\exp(-\frac{(x_i-\mu_k)^2}{2\sigma_k^2})$

3. 假设$p(k)$都相同,则可以计算样本服从$N(\mu_k,\sigma_k)$的概率$p(z_k|x_i)$

4. 使用$p(z_k|x_i)$作为$k$模型的观测权重,并使用极大似然估计更新$\mu_k$和$\sigma_k$
   $$
   \mu_k'=\frac{\sum_{n=1}^{N}p(z_k|x_n)x_n}{\sum_{n=1}^{N}p(z_k|x_n)}\\
   \sigma_k'=\frac{\sum_{n=1}^{N}p(z_k|x_n)(x_n-\mu_k)(x_n-\mu_k)^T}{\sum_{n=1}^{N}p(z_k|x_n)}\\
   $$
   

# 4. Annotation

### 4.1 Annotation Guideline

##### Pipeline步骤

1. 设计guideline
2. 不同人进行标注
3. 比较标注结果并进行裁决
4. 优化guideline并迭代

##### Guideline

- 明确项目和模型目标
- 明确需要标注的对象和标注逻辑
- 尽量让不同人的标注结果统一

### 4.2 Inter-annotator Agreement

通过agreement可以衡量guideline的优劣

##### Agree Annotation Percentage

- 直接计算标注者达成一致的百分比
- 当样本分布不均匀时,无法区分达成一致是概率原因还是真实标注原因

##### Cohen's Kappa

- 计算标注一致百分比$p_o=\frac{\#\text{Agree}}{\#\text{Sample}}$
- 计算对于每一种分类结果,$n$个人都相同标注结果的概率 $p_e=\sum_{j=1}^K P[A_1=R_j,A_2=R_j\cdots A_n=R_j]$

- 计算cohen's kappa,数值越高说明rich high agreement
  $$
  \kappa=\frac{p_o-p_e}{1-p_e}
  $$

##### Fleiss' Kappa

- 对于每个样本,扩展到有$n$个人进行标注,在$K$种选项中进行分类. 对于第$j$种结果,有$n_{ij}$个人获得相同评价 
  $$
  P_i=\frac{1}{n(n-1)}\sum_{j=1}^K n_{ij}(n_{ij}-1)
  $$

- 平均所有样本的标注结果获得$P_o=\frac{1}{N}\sum_{i=1}^NP_i$
- 计算第$j$类被选中的概率$p_j=\frac{1}{Nn}\sum_{i=1}^Nn_{ij}$
- 汇总所有碰巧被选中的概率$P_e=\sum_{j=1}^Kp_j^2$

##### Krippendorff's $\alpha$

- $\alpha=1-\frac{D_0}{D_e}$
- $D_o,D_e$分别描述了观测的和期望的不一致量
- 可以应用于连续标注,而不仅仅离散
- 结果大于0.9说明非常可靠





