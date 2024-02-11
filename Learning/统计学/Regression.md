- [1. 线性回归](#1-线性回归)
    - [1.1 基本概念](#11-基本概念)
        - [预设条件](#预设条件)
    - [1.2 计算流程](#12-计算流程)
        - [单变量回归](#单变量回归)
        - [多维线性回归](#多维线性回归)
    - [1.3 参数和意义分析](#13-参数和意义分析)
        - [参数估计值分布(已知Y的方差)](#参数估计值分布已知y的方差)
        - [残差估计值分布(均方误差MSE)](#残差估计值分布均方误差mse)
        - [参数估计值分布(未知方差)](#参数估计值分布未知方差)
        - [单个参数估计](#单个参数估计)
        - [参数意义分析](#参数意义分析)
    - [1.4 预测值 $Y$分析](#14-预测值-y分析)
        - [模型预测$Y$分布](#模型预测y分布)
        - [相关系数测试](#相关系数测试)
        - [决定系数测试](#决定系数测试)
    - [1.5 拟合度测试](#15-拟合度测试)
        - [重复测量](#重复测量)
        - [欠拟合](#欠拟合)
        - [模型精简化](#模型精简化)
    - [1.6 模型选取流程](#16-模型选取流程)
        - [拟合目标](#拟合目标)
        - [正向选取](#正向选取)
        - [逆向选取](#逆向选取)
        - [Mallow's $C\_p$检验](#mallows-c_p检验)
- [2. Generalize Linear Model (GLM)](#2-generalize-linear-model-glm)
    - [2.1 Exponential Distribution Family](#21-exponential-distribution-family)
        - [Exponential Family](#exponential-family)
        - [Canonical Exponential Family](#canonical-exponential-family)
        - [Canonical分布族特性](#canonical分布族特性)
    - [2.2 松弛条件](#22-松弛条件)
        - [回归值分布](#回归值分布)
        - [link function ($g$)](#link-function-g)
    - [2.3 计算流程](#23-计算流程)
        - [计算流程](#计算流程)
        - [迭代优化法](#迭代优化法)
    - [2.4 线性(正态分布)回归应用](#24-线性正态分布回归应用)
        - [输出](#输出)
    - [2.2 训练和计算流程](#22-训练和计算流程)
- [3. 指数(泊松)回归](#3-指数泊松回归)
    - [3.1 基本概念](#31-基本概念)
        - [输出](#输出-1)
        - [决策模型](#决策模型)
    - [3.2 训练和计算流程](#32-训练和计算流程)
- [4. 逻辑回归](#4-逻辑回归)
    - [4.1 基本概念](#41-基本概念)
        - [输出](#输出-2)
        - [决策模型](#决策模型-1)
    - [4.2 训练和计算流程](#42-训练和计算流程)


# 1. 线性回归

### 1.1 基本概念

寻找$Y$和$X$之间的线性关系

对于$Y$的均值: $\hat{\mu_Y|x}=\beta_0+\beta_1x$

##### <u>预设条件</u>

- $Var[X]\neq0$,否则是一条垂线

- 残差residual: $=Y-\hat Y=Y-(\beta_0+\beta_1x)$
- <u>残差正态分布</u>$e\sim(0,\sigma^2)$ (使用KL测试)
- $Cov(e, X)=0$
- <u>如果$e$和$X$有关,则对$Y$取对数后拟合</u>

### 1.2 计算流程

##### <u>单变量回归</u>

通过$\min E[Y-(\beta_0+\beta_1)]$对$\beta_0和\beta_1$求导可以得到

1. 最小化$MSE=E[Y-\hat Y]=E[Y-(\beta_0+\beta_1)]$

2. 对$\beta_0$和$\beta_1$求偏导.,联立求解

   - $\hat\beta_1=\frac{Cov[X,Y]}{Var[X]}$

   - $\hat\beta_0=E[Y]-\hat\beta_1 E[X]$


##### 多维线性回归

<u>有$n$组样本,每组样本有$p$个自变量</u>,单变量回归$p=2$

- 数据建模

  - 多变量拟合: 直接把每个自变量的值放入$X$矩阵

  - 多项式拟合: 直接把自变量的每一项计算好,当做多变量代入

- 最小二乘法得到$Y=XB+E$的最优解

$$
\hat B=(X^TX)^{-1}X^TY
$$

### 1.3 参数和意义分析

用实际分布$Y=X^TB+E$代入$\hat B$可以得到$\hat B=B+(X^TX)^{-1}X^TE$

##### 参数估计值分布(已知Y的方差)

如果$E$服从正态分布$(0,\sigma^2I)$,则$\hat{B}$服从正态分布
$$
\hat B\sim\N(B,\sigma^2(XX^T)^{-1})
$$


##### <u>残差估计值分布(均方误差MSE)</u>

可以用$SSE$来估计$Y$的方差$\hat\sigma^2=\frac{SSE}{n-p}$且两者服从$n-p$卡方分布
$$
\chi_{n-p}^2=(n-p)\frac{\hat\sigma^2}{\sigma^2}
$$

##### 参数估计值分布(未知方差)

通过代入上面参数估计值,可以构造$(n-p)$的$T$分布
$$
T_{n-p}=\frac{\hat B-B}{\sqrt{\hat\sigma^2(XX^T)^{-1}}}
$$

##### 单个参数估计 

<u>多维分析中,可以用来判断维度是否有用</u>

定义$c_{jj}=(X^TX)^{-1}_{j,j}$,则可以用$c_{jj}$代入上式构造$T$分布
$$
T_{n-p}=\frac{\hat \beta_j-\beta_j}{\sqrt{\hat\sigma^2c_{jj}}}
$$

##### 参数意义分析

- 单个参数:<u>假定$H_0:\beta_j=0$再使用估计值进行$T$测试</u>
- $p$个参数一起测试:
  1. 把每个参数单独拆分测试,只要reject一个测试,则reject $H_0$
  2. $\alpha=\sum_i^p\alpha_i$
  3. 可以把每个测试的$\alpha_i$设置成$0.05/p$

### 1.4 预测值 $Y$分析

##### 模型预测$Y$分布

给定$x$可以得到$Y$的分布,形成confidence bands和prediction bands

- 已知方差,模型的预测值和真实预测值误差服从正态分布
  $$
  \frac{\hat y-y}{\sigma\sqrt{x^T(X^TX)^{-1}x}}\sim(0,1)
  $$
  
- 未知方差,给定的预测值服从$T$分布
  $$
  T_{n-p}=\frac{\hat y-y}{S\sqrt{x^T(X^TX)^{-1}x}}
  $$

##### 相关系数测试

- 相关系数点估计值 $R=\hat\rho=\frac{\sum(x-\bar x)(y-\bar y)}{\sqrt{\sum(x-\bar x)^2\sum(y-\bar y)^2}}$

- 如果$X,Y$服从双变量正态分布,则可以通过相关系数构造$T$分布
  $$
  T_{n-2}=\frac{R\sqrt{n-2}}{\sqrt{1-R^2}}
  $$

##### 决定系数测试

决定系数越高,拟合越能解释现象</u>
$$
R^2=\frac{\sum(y-\bar y)^2-SSE}{\sum(y-\bar y)^2}
$$


使用决定系数对$p$个参数意义分析, $H_0:\beta_0=\beta_1\cdots\beta_p=0$
$$
F_{p, n-p}=\frac{n-p}{p+1}\frac{R^2}{1-R^2}
$$


### 1.5 拟合度测试

##### 重复测量

- 针对<u>同一个</u>$X_i$重复测量$Y_i$
  - 可以得到$Y_{ij}$的平均值$\bar{Y_i}$
  - $Y_i$内平方差和$\sum(Y_{ij}-\bar{Y_i})^2$
- 针对不同的测试,计算内平方差和$SSE_{pe}$
  - $SSE_{pe}=\sum_i^k\sum_j^n(Y_{ij}-\bar{Y_i})^2$
  - $\frac{SSE_{pe}}{\hat\sigma^2}$服从$\chi_{n-k}^2$的分布

##### 欠拟合

- 欠拟合误差平方和
  - $SSE_{lf}=SSE-SSE_{pe}$
  - $\frac{SSE_{lf}}{\hat\sigma^2}$服从$\chi_{k-2}^2$的分布
- 拟合度测试
  - $F$测试,$H_0$: 拟合非常有意义
  - $F_{k-2, n-k}=\frac{SSE_{lf}/(k-2)}{SSE_{pe}/(n-k)}$

##### 模型精简化

1. 计算有$p$个参数的$SSE_{full}$

2. 计算只有$m$个参数的$SSE_{reduced}$

3. 使用$F$测试比较模型是否可以精简化. $H_0:$模型可以精简化
   $$
   F_{p-m,n-p}=\frac{n-p}{p-m }\frac{SSE_{reduced}-SSE_{full}}{SSE_{full}}
   $$

### 1.6 模型选取流程

##### 拟合目标

- 找到$R^2$最大的模型
- $MSE=\frac{SSE}{n-p}$最小的模型

##### 正向选取

1. 使用one-hot或者indicator等方式处理categorical variable
2. 在上一次模型基础上,添加一个自变量
3. 对每种可选自变量,添加后做测试,选取$R^2$最大的
4. 测试所有拟合参数是否有意义
5. 继续添加下一个自变量,重复步骤2-4
6. 直到拟合参数无意义为止

##### 逆向选取

1. 使用one-hot或者indicator等方式处理categorical variable
2. 在上一次模型基础上,删除一个自变量
3. 对每种可删自变量,删除后做测试,选取$R^2$最大的
4. 测试删除的自变量参数是否有意义
5. 无意义则继续删除下一个自变量,重复2-4
6. 知道拟合参数无法被悬殊位置

##### Mallow's $C_p$检验

1. 生成$k$个模型拟合
2. 计算每个模型的$MSE$,并保留最大的
3. 对于每个模型,计算$C_p=\frac{SSE_p}{MSE_k}+2p-n$
4. 选择$C_p$最小的模型,或者和$p$最接近的模型



# 2. Generalize Linear Model (GLM)

本质上用线性变换$X^T\beta$来估计$Y$分布的参数$\theta$,从而获得$Y$在特定$X$下的分布

### 2.1 Exponential Distribution Family

##### Exponential Family

可以化简指数项和特定函数乘积的分布

| $x$      | $\theta$ | $\eta,T,B,h$       |
| -------- | -------- | ------------------ |
| 随机变量 | 分布参数 | 构造分布的特殊函数 |


$$
f_\theta(x)=\exp[\sum\eta(\theta)T(x)-B(\theta)]h(x)
$$

##### Canonical Exponential Family

指数分布族的子集,$x$前的系数不是$\eta$而是$\theta$自身

| $x$      | $\theta$     | $\phi$                      | $b,c$              |
| -------- | ------------ | --------------------------- | ------------------ |
| 随机变量 | 未知分布参数 | 已知的分布参数,可以当做常数 | 构造分布的特殊函数 |


$$
f_\theta(x)=\exp[\frac{x\theta-b(\theta)}{\phi}+c(x, \phi)]
$$

##### Canonical分布族特性

通过函数$b(\theta)$可以获得关于变量的重要特性

- $E[X]=b'(\theta)$
- $VAR[X]=b''(\theta)\phi$
- <u>因为方差恒大于0,所以$b'(\theta)$单调递增,且$b(\theta)$是凸函数</u>

### 2.2 松弛条件

GLM本质上用线性回归输出值$X^TB$来估计$Y$分布的参数$\hat\theta$,再根据$g$是$b'^{-1}$反函数的性质,用来估计$Y$的输出值

##### 回归值分布

- 服从canonical exponential family: $f_\theta(y)=\exp[\frac{y\theta-b(\theta)}{\phi} + c(y,\phi)]$

- 预测结果期望 $E[Y]=b'(\theta)$
- 预测结果方差 $VAR[Y]=b''(\theta)$

##### link function ($g$)

- 将$Y$的均值和线性变化后的$X^TB$连接起来 $g(\hat{\mu_Y|x})=X^TB$
- <u>是$Y$分布的$b'$反函数,即$g(\mu_Y|x)=X^T\beta$,则单调且可逆</u>

### 2.3 计算流程

##### 计算流程

1. 根据$y$的先验分布模型,构造$\theta=h(X^T\beta)=b'^{-1}(g^{-1}(X^T\beta))$
   - 通常$g$和$b'$互为反函数,则$h(x)=x$
2. 使用极大似然估计,构造对数似然函数$L=\sum f_Y(y;h(X^T\beta))$

3. 因为$b$是convex的,所以$L$一定有最大值

4. 使用最优化方法求极值$\beta^*$

##### 迭代优化法

1. 根据$y$的分布构造矩阵 
   $$
   W=\text{diag}\{W_1,\cdots,W_n\}\quad\text{where}\quad W_i=\frac{h'(X_i^T\beta)}{g'(\mu_i)\phi}
   $$

2. 根据样本生成估计值和实际值
   - 实际值: $\tilde Y=\left[\begin{array}{c}g'(\mu_1)Y_1&g'(\mu_2)Y_2&\cdots&g'(\mu_n)Y_n  \end{array}\right]^T$
   - 估计值: $\tilde\mu=\left[\begin{array}{c}g'(\mu_1)\mu_1&g'(\mu_2)\mu_2&\cdots&g'(\mu_n)\mu_n\end{array}\right]^T$

3. 迭代更新直到收敛
   $$
   \beta^{k+1}=(X^TWX)^{-1}X^TW(\tilde Y-\tilde\mu+X\beta^{k})
   $$

4. 

### 2.4 线性(正态分布)回归应用

##### 输出

- 服从正态分布的$y$的均值
- Canonical 分布特征
- 使用$X^T\beta$来拟合正态分布变量$Y$的分布均值参数$\theta$

| PDF                                                          | $f_\theta$                                                   | $\theta$ | $\phi$     | $b(\theta)$          | $b'(\theta)$ | $c(x,\phi)$                                       |
| ------------------------------------------------------------ | ------------------------------------------------------------ | -------- | ---------- | -------------------- | ------------ | ------------------------------------------------- |
| $\frac{1}{\sqrt{2\pi}\sigma}\exp(-\frac{1}{2}(\frac{x-\mu}\sigma)^2)$ | $\exp(\frac{\theta}{\sigma^2}x-\frac{x^2}{2\sigma^2}-\frac{\theta^2}{2\sigma^2}-\ln\sigma-\ln\sqrt{2\pi})$ | $\mu$    | $\sigma^2$ | $\frac{\theta^2}{2}$ | $\theta$     | $-\frac{x^2}{2\sigma^2}-\ln\sigma-\ln\sqrt{2\pi}$ |

$$
Y(X)=b'(X^T\beta)=X^T\beta
$$

### 2.2 训练和计算流程

1. 给定$n$个样本$x_i\in\mathbb{R_k}$和观测值$y_i\in \Z$
2. 对所有样本进行极大似然估计$l_n(y,x;\beta)=\sum(\frac{yx^T\beta}{\sigma^2}-\frac{y^2}{2\sigma^2}-\frac{(x^T\beta)^2}{2\sigma^2}-\ln\sigma-\ln\sqrt{2\pi})$
3. 导数为$\frac{1}{\sigma^2}(x_iy_i-x_ix_i^T\beta )$
4. 使用牛顿法/梯度下降方法求得最优解$\beta^*$

# 3. 指数(泊松)回归

### 3.1 基本概念

##### 输出

- 服从泊松分布$y$的均值,即到达概率
- Canonical 分布特征

| PDF                                | $f_\theta$                      | $\theta$     | $\phi$ | $b(\theta)$ | $b'(\theta)$ | $c(x,\phi)$ |
| ---------------------------------- | ------------------------------- | ------------ | ------ | ----------- | ------------ | ----------- |
| $\frac{\lambda^x}{x!}e^{-\lambda}$ | $\exp(x\theta-e^\theta-\ln x!)$ | $\ln\lambda$ | $1$    | $e^\theta$  | $e^\theta$   | $-\ln x!$   |

$$
Y(X)=b'(X^T\beta)=e^{X^T\beta}
$$

##### 决策模型

- 指数回归<u>用线性变量$X^T\beta$拟合泊松变量$Y$的对数发生概率$\ln \lambda$
- 在特征空间中,基于$X$的位置预测泊松分布的发生概率,并得到均值

### 3.2 训练和计算流程

1. 给定$n$个样本$x_i\in\mathbb{R_k}$和观测值$y_i\in \Z$
2. 对所有样本进行极大似然估计$l_n(y,x;\beta)=\sum(yx^T\beta-\exp(x^T\beta)-\ln y!)$
3. 导数为$y_ix_i^T-x_i^T\exp(x_i^T\beta)$
4. 使用牛顿法/梯度下降方法求得最优解$\beta^*$

# 4. 逻辑回归

### 4.1 基本概念

##### 输出

- 样本$y$的二分类结果$\{0, 1\}$,服从伯努利分布
- Canonical 分布特征

| PDF              | $f_\theta$                      | $\theta$           | $\phi$ | $b(\theta)$       | $b'(\theta)$              | $c(x,\phi)$ |
| ---------------- | ------------------------------- | ------------------ | ------ | ----------------- | ------------------------- | ----------- |
| $p^x(1-p)^{1-x}$ | $\exp(x\theta-\ln(1+e^\theta))$ | $\ln\frac{p}{1-p}$ | $1$    | $\ln(1+e^\theta)$ | $\frac{1}{1+e^{-\theta}}$ | $0$         |


$$
Y(X)=b'(X^T\beta)=\frac{1}{1+e^{-X^T\beta}}
$$

##### 决策模型

- 逻辑回归<u>用线性变量$X^T\beta$拟合伯努利变量$Y$落在不同类别的对数概率</u>$\ln\frac{p}{1-p}$
- 在特征空间中,寻找一条直线$X^T\beta=0$,基于$x$存在的位置,决定输出

### 4.2 训练和计算流程

1. 给定$n$个样本$x_i\in\mathbb{R_k}$和分类结果$y_i\in\{0,1\}$

2. 对所有样本进行极大似然估计$l_n(y,x;\beta)=\sum(y_ix_i^T\beta-\ln(1+\exp(x_i^T\beta)))$

3. 导数为$[(\frac{1}{1+e^{-\beta x^i}})-y_i]x^i$

4. 使用牛顿法/梯度下降方法求得最优解$\beta^*$
