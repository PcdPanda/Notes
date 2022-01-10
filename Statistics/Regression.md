[toc]

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

##### 单变量回归

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

- 找到$R^2$最大的模型找到
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

# 2. 逻辑回归

### 2.1 基本概念

##### 输入输出

- 测试集输入是$k$维的实数向量x,输出是对应的<u>二分类结果</u>$y$,表示该样本为正例的概率 (伯努利分布的$\mu$)

- 训练集的输入是$k$维的实数向量,标签是离散分类结果$\{0,1\}$

- 样本标签的伯努利分布属于canonical exponential family
  $$
  f(y)=\exp[y\ln\frac{p}{1-p}+\ln (1-p)]=\exp(y\theta-\ln(1+e^\theta))
  $$

  - $b'(\theta)=\frac{e^\theta}{1+e^{\theta}}$

  - canonical link:  $g(\mu)=\ln\frac{\mu}{1-\mu}$

##### 决策模型

- 逻辑回归<u>用线性变量$X^T\beta$寻找伯努利变量$Y$落在不同类别的对数概率</u>$\ln\frac{p}{1-p}$
- 用伯努利canonical link作为GLM的link function带入则有$\theta=\ln\frac{p}{1-p}=X^T\beta$
- 根据GLM link function定义,可以得到预测值$y=g^{-1}(X^T\beta)=\frac{1}{1+\exp[-(X^T\beta)]}$

- 在$R$维空间中,寻找一条直线$X^T\beta=0$,基于$x$存在的位置,决定输出

### 2.2 训练和计算流程

本质上是找到最优解$\beta$来表示$\theta$从而最大似然函数

1. 给定$n$个样本$x_i\in\mathbb{R_k}$和分类结果$y_i\in\{0,1\}$
2. 每次分类的对数似然函数为$l(y,x;\beta)=yx^T\beta-\ln(1+\exp(x^T\beta))$

3. 对所有样本进行极大似然估计$l_n(y,x;\beta)=\sum(y_ix_i^T\beta-\ln(1+\exp(x_i^T\beta)))$
4. 使用牛顿法/梯度下降方法求得最优解$\beta^*$



# 3. Generalize Linear Model (GLM)

本质上用线性变换$X^T\beta$来估计$Y$分布的参数$\theta$,从而获得$Y$在特定$X$下的分布

### 3.1 松弛条件

##### Y Canonical Exponential Family

得到的$Y$最终服从canonical exponential family

- $f_\theta(y)=\exp[\frac{y\theta-b(\theta)}{\phi} + c(y,\phi)]$
- 预测结果期望 $E[Y]=b'(\theta)$
- 预测结果方差 $VAR[Y]=b''(\theta)$

##### link function

- $g$将$Y$的均值和线性变化后的$X^TB$连接起来

- $g(\hat{\mu_Y|x})=X^TB$
- 必须单调且可逆
- 尽量使得$g$是$b'$的反函数,即可以通过线性模型获得$Y$的分布参数$\theta=X^T\beta$

### 3.2 计算流程

##### 计算流程

1. 给定数据,假设$y$的均值分布$f_\theta(y)$以及和$X$的关系$g(X^T\beta)$
2. 根据GLM和Canonical的定义$h(X^T\beta)=b'^{-1}(g^{-1}(X^T\beta))$
3. 使用极大似然估计,求导后的似然函数$L=\sum Y_ih(X_i^T\beta)-b(h(X_i^T\beta))$
4. 因为$b$是convex的,所以$L$一定有最大值
5. 使用最优化方法求极值$\beta^*$

$\tilde Y=\left[\begin{array}{c}g'(\mu_1)Y_1&g'(\mu_2)Y_2&\cdots&g'(\mu_n)Y_n  \end{array}\right]^T$

$\tilde\mu=\left[\begin{array}{c}g'(\mu_1)\mu_1&g'(\mu_2)\mu_2&\cdots&g'(\mu_n)\mu_n\end{array}\right]^T$

$W_i=\frac{h'(X_i^T\beta)}{g'(\mu_i)\phi}$

$W=\text{diag}\{W_1,\cdots,W_n\}$

$\beta^{k+1}=(X^TWX)^{-1}X^TW(\tilde Y-\tilde\mu+X\beta^{k})$

##### 牛顿法迭代求极值

1. 假设下一个迭代点$\theta^{k+1}$是最优解,即梯度为0, $\bigtriangledown_L(\theta^{k+1})=0$
2. 对这个迭代点和上一个迭代点的导数进行二阶泰勒展开$\bigtriangledown_L(\theta^{k+1})=\bigtriangledown_L(\theta^{k})+(\theta^{k+1}-\theta^k)H_L(\theta^k)$
3. 带入假设,可以得到迭代方程: $\theta^{k+1}=\theta^k-H_L(\theta^k)^{-1}\bigtriangledown_L(\theta^{k})$
4. 如果二阶导矩阵$H_L$很难计算,则可以用数据点中的fisher information $-I(\theta^k)$代替
5. $\theta^{k+1}=\theta^k+I(\theta^k)^{-1}\bigtriangledown_L(\theta^{k})$

### 3.3 指数拟合

##### 基本定义

- $\hat y=\beta_0e^{X\beta_1}$
- 通过求对数得到$\ln\hat y=\ln\beta_0+X^T\beta_1$

##### 模型选择

- 得到link function $g(y)=\ln y=X^T\beta$

- 选取$y$作为泊松分布,即$b(\theta)=e^\theta,g(\mu)=\ln\mu$

### 3.4 倒数转化拟合

##### 基本定义

- $\hat y=\frac{\alpha x}{h+x}$
- 两边取倒数得到$\frac{1}{\hat y}=\frac{1}{\alpha}+\frac{h}{\alpha}\frac{1}{x}$

##### 模型选择

- 得到link function $g(y)=\frac{ay}{a-y}$
- 选取$y$作为Gamma分布,即$b(\theta)=-\ln(-\theta),g(\mu)=-\frac{1}{\mu}$



