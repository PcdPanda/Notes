- [1. 时间序列数据](#1-时间序列数据)
    - [1.1 时序数据样本](#11-时序数据样本)
        - [时间序列数据分布表示](#时间序列数据分布表示)
        - [时间序列数据性质](#时间序列数据性质)
        - [白噪音](#白噪音)
    - [1.2 平稳性 (Stationary)](#12-平稳性-stationary)
        - [弱平稳性](#弱平稳性)
        - [强平稳性](#强平稳性)
        - [Ergodicity](#ergodicity)
    - [1.3 趋势](#13-趋势)
        - [定义](#定义)
        - [估计值](#估计值)
        - [均值平稳](#均值平稳)
    - [1.4 自相关性](#14-自相关性)
        - [定义](#定义-1)
        - [方差平稳](#方差平稳)
        - [自方差](#自方差)
        - [自相关系数](#自相关系数)
        - [PACF](#pacf)
    - [1.5 残差检验](#15-残差检验)
        - [ACF检验(Box-Ljung Test)](#acf检验box-ljung-test)
        - [平稳性检验Phillips-Perron Test](#平稳性检验phillips-perron-test)
        - [Jarque-Bera检验正态分布](#jarque-bera检验正态分布)
        - [Shapiro-Wilk Test](#shapiro-wilk-test)
- [2. ARMA模型](#2-arma模型)
    - [2.1 算符表示](#21-算符表示)
        - [Backshift (B)](#backshift-b)
        - [Difference ($\\bigtriangleup$)](#difference-bigtriangleup)
    - [2.2 AR (自回归)模型](#22-ar-自回归模型)
        - [模型定义](#模型定义)
        - [Random Walk](#random-walk)
        - [Random Walk with Drift](#random-walk-with-drift)
        - [1阶因果AR模型收敛性](#1阶因果ar模型收敛性)
        - [线性拟合求参数](#线性拟合求参数)
        - [矩量法求参数(Yule-Walker)](#矩量法求参数yule-walker)
        - [Conditional MLE估计参数](#conditional-mle估计参数)
    - [2.3 MA(移动平均)模型](#23-ma移动平均模型)
        - [模型定义](#模型定义-1)
        - [自相关性](#自相关性)
    - [2.4 ARMA模型](#24-arma模型)
        - [模型定义](#模型定义-2)
        - [因果性分析](#因果性分析)
        - [应用实例](#应用实例)
    - [2.5 ARMA参数估计](#25-arma参数估计)
        - [AIC](#aic)
        - [参数检验](#参数检验)
    - [2.6. ARMA模型衍生](#26-arma模型衍生)
        - [ARSMA模型 (处理周期性)](#arsma模型-处理周期性)
        - [ARIMA模型 (处理差分)](#arima模型-处理差分)
        - [Linear ARIMA模型 (处理趋势)](#linear-arima模型-处理趋势)
- [3. 频域分析](#3-频域分析)
    - [3.1 Spectral Density](#31-spectral-density)
        - [自方差正交分解](#自方差正交分解)
        - [Spectral density function (Periodogram) $\\lambda(\\omega)$计算流程](#spectral-density-function-periodogram-lambdaomega计算流程)
        - [ARMA的Spectrum](#arma的spectrum)
    - [3.2 频域分析应用](#32-频域分析应用)
        - [Loess Smoother](#loess-smoother)
        - [Band pass filter](#band-pass-filter)
        - [Hodrick-Prescott filter](#hodrick-prescott-filter)
- [4. 多状态时序分析](#4-多状态时序分析)
    - [4.1 多变量相关性](#41-多变量相关性)
        - [Sample Cross-correlation Function(CCF)](#sample-cross-correlation-functionccf)
        - [Coherence](#coherence)
    - [4.2 马尔科夫过程](#42-马尔科夫过程)
        - [Assumption](#assumption)
        - [One-step Hidden Process](#one-step-hidden-process)
        - [One-step HMM](#one-step-hmm)
    - [4.3 POMP (Partially Observed Markov Process Model)](#43-pomp-partially-observed-markov-process-model)
        - [Overview](#overview)
        - [Likelihood](#likelihood)
        - [Smoothing](#smoothing)
        - [Filtering](#filtering)
        - [One-step Prediction](#one-step-prediction)
    - [4.4 Linear Gaussian POMP (LG-POMP)](#44-linear-gaussian-pomp-lg-pomp)
        - [General Linear Model](#general-linear-model)
        - [Basic Structural Model (BSM)](#basic-structural-model-bsm)
    - [4.5 POMP Inference](#45-pomp-inference)
        - [HP Filter](#hp-filter)
        - [Kalman Filter](#kalman-filter)
        - [Particle Filter](#particle-filter)


# 1. 时间序列数据

### 1.1 时序数据样本

##### 时间序列数据分布表示

时间序列数据的时间戳间隔可能不一样

- 时间序列索引: $1:N=\{1,2,\cdots,N\}$

- 时间戳: $t_i$,$i\in 1:N$
- $1\sim N$的样本观测值: $y_{1:N}^*$
- $f_{Y_1:N}(y_1,y_2,\cdots,y_N;\theta)$: 描述了时间序列上$N$个连续随机变量的联合分布

##### 时间序列数据性质

- 具有趋势
- 不具有平稳性,需要差分后才有

##### 白噪音

可以服从正态分布/伯努利分布/三角函数等

- 任何时间点的均值都为0 (没有趋势)
- 弱白噪音: 没有自相关性 $\rho_h=0\quad\forall h$
- 强白噪音: 完全不相关

### 1.2 平稳性 (Stationary)

##### 弱平稳性

- 均值和协方差都是常数	
- 当lag相同时,协方差始终相同
- <u>此时自相关系数有意义</u>

##### 强平稳性

- 任意连续$k$个点的数据服从相同的联合分布
- 强平稳可以说明弱平稳
- 几乎无法证明强平稳

##### Ergodicity

- 只有在数据平稳下才有意义
- 随着时间序列发展,均值会收敛到期望$\bar X_n=\frac{1}{n}\sum_{i=1}^n X_i=E(X),\hat\gamma(h)=\gamma(h)$
- 时间序列数据会扩展到可能出现的范围,才能满足期望要求

### 1.3 趋势

##### 定义

$$
\mu_n=\mathbb{E}[Y_n]=\int_{-\infty}^{\infty}y_nf_{Y_n}(y_n;\theta)\mathrm dy_n
$$

- 给定时间点$t_n$,<u>在这个时间点数值的期望</u>

- 趋势可能由联合分布参数$\theta$决定
- 趋势是模型的性质,而不是数据的性质.

##### 估计值

- $\hat \mu_n(y_{1:N}^*)$: 由$N$个时序数据点估计的$t_n$时刻的期望
- 由于是期望,真实样本数据会在上下有波动

##### 均值平稳

- 所有之间点的期望一样,暗示<u>数据没有趋势</u>

- 平稳时趋势的估计值: $\hat\mu_n=\hat\mu=\frac{1}{N}\sum y_n$


### 1.4 自相关性

##### 定义

- 针对一组时序数据,存在不同lag的自方差和自相关系数
- $h$阶自相关系数,<u>描述了数据在时间序列上的联系每个样本和前后间隔$h$个时间点的样本的联系</u>
- 存在自相关性,说明数据在<u>时间序列上有信息可以分析</u>
- 残差间不应该存在自相关性

##### <u>方差平稳</u>

- 两个特定时间点之间的协方差: $\gamma_{m,n}=\mathbb{E}[(Y_m-\mu_m)(Y_n-\mu_n)]$
- 需要考虑<u>时间序列数据上任意点</u>和前后间隔$h$个时间点的样本的关系,只有<u>都相同才说明方差平稳,此时自方差有意义</u>

##### 自方差 

- 只有在方差平稳时才有意义,此时$\gamma_h=\gamma_{n,n+h}\quad\forall n$

- $\gamma_0$: 所有时间点数据的方差,方差平稳时所有时间点的方差都相同

- 自方差估计值

  - 需要<u>有每个时间点的期望/趋势(均值平稳的好处)</u>
  - 需要<u>在每个时间点计算并加权</u>
  - 计算加权的时候,分母一直是$N$

  
  $$
  \hat\gamma_h=\frac{1}{N}\sum_{n=1}^{N-h}(y_n^*-\hat\mu_n)(y_{n+h}^*-\hat\mu_{n+h})
  $$

##### 自相关系数

- 定义和估计值
  $$
  \rho_h=\frac{\gamma_h}{\gamma_0}\qquad\hat\rho_h(y_{1:N})=\frac{\hat\gamma(y_{1:N})}{\hat(Y_{1:N})}
  $$
  
- 描述了自方差的相对剧烈程度(因为当每个时间点自身方差很大时,有一定的自方差也很正常)

- <u>只有在方差平稳时,这个数值才有意义</u>

- 当时间序列很长时,ACF的置信区间会变得很狭窄,这个时候小波动容易造成模型不平稳,因此<u>去极值很重要</u>
- 尾部特征: 截尾(ACF突然变为0)/拖尾(随着$h$增加,ACF逐步变为0)

##### PACF

- 消除了$1\sim(h-1)$阶数据对ACF的影响

- 使用线性回归的参数$\phi_{h,h}$作为估计值
  $$
  X_t=\phi_{0,h}+\phi_{1,h}X_{t-1}+\cdots\phi_{h,h}X_{t-h}\quad t=h+1,\cdots,N
  $$

### 1.5 残差检验

##### ACF检验(Box-Ljung Test)

1. 画出不同阶$h$的自相关系数ACF
2. 和null hypothesis (无自相关性)的置信区间对比,判断模型是否有自相关性($H_0$: 数据无自相关,即$\gamma(h)=0\quad\forall h$)
3. 如果有$h$阶的ACF超过区间,可能有周期/时序相关信息可以捕捉

$$
X_t=\phi_{0,h}+\phi_{1,h}X_{t-1}+\cdots\phi_{h,h}X_{t-h}\quad t=h+1,\cdots,N
$$

##### 平稳性检验Phillips-Perron Test

- 使用ARMA拟合数据来进行检验
- $H_0$:单位圆内存在单位根,数据不平稳
- $H_1:$数据平稳,因此P-value越小越好

##### Jarque-Bera检验正态分布

- 通过样本的偏度$S$和峰度$K$来构造参数检验
  $$
  JB=\frac{n}{6}(S^2+\frac{(K-3)^2}{4})\sim\chi^2_2
  $$

- $H_0$:数据服从正态分布,$JB$值越偏离$\chi^2_2$,说明样本正态分布的概率越小

##### Shapiro-Wilk Test

- 检验样本是否服从假设的正态分布,分布参数决定$\alpha_i$
- $W=\frac{(\sum_{i=1}^n\alpha_ix_i)^2}{\sum_{i=1}^n(x_i-\bar x)^2}$

# 2. ARMA模型

### 2.1 算符表示

##### Backshift (B)

- 将第$n$个数值向前变换$BY_n=Y_{n-1}$
- 可以作为线性变量进行运算

##### Difference ($\bigtriangleup$)

- 计算一阶差分: $\bigtriangleup Y_n=(1-B)Y_n=Y_n-Y_{n-1}$
- 可以反复使用,获得$n$阶差分: $\bigtriangleup^2Y_n=(1-B)^2Y_n=(Y_n-Y_{n-1})-(Y_{n-1}-Y_{n-2})$

### 2.2 AR (自回归)模型 

##### 模型定义

$$
Y_n=\phi_1Y_{n-1}+\phi_2Y_{n-2}+\cdots\phi_{p}Y_{n-p}+\epsilon_n
$$

- 定义函数$\phi(x)=1-\phi_1x-\phi_2x^2-\cdots-\phi_px^p$,则可以用算符简化$\phi(B)Y_n=\epsilon_n,\epsilon_n\sim N(0,\sigma^2)$
- 第$n$个时间点的值,是前$p$个点的线性组合,需要初始化前$p$个值才可以计算
- <u>通常设定模型弱平稳</u>,则$\mathbb{E}[Y_n]=0$

- 方差 $\sigma_Y^2=\frac{\sigma^2}{1-\sum_{i=1}^p\phi_i^2}$

##### Random Walk

- AR模型的$\phi_1=1$特殊形式: $Y_n=Y_{n-1}+\epsilon$
- 一阶差分后可以得到白噪音

##### Random Walk with Drift

- Random Walk的基础上添加了increments: $Y_n=Y_{n-1}+\mu+\epsilon$
- 有效市场假说暗示对数收益率服从random walk with drift

##### 1阶因果AR模型收敛性

对于1阶AR模型$Y_n=\phi Y_{n-1}+\epsilon_n$

- Causal Solution ($Y$由过去决定): $Y_n=\sum_{j=0}^\infty\phi^j\epsilon_{n-j}$
- Non-causal Solution ($Y$由未来决定): $Y_n=\sum_{j=0}^\infty\phi^{-j}\epsilon_{n+j}$
- <u>等比数列比值绝对值小于1才可以收敛</u>

##### 线性拟合求参数

- 假定$Y_t$和$Y_{t-1},\cdots,Y_{t-p}$<u>服从多元正态分布,因此可以直接使用线性回归</u>来最小化$MSE$并估计参数

- 构造自方差矩阵
  $$
  \Sigma_Y=\begin{bmatrix}\gamma(0)&\cdots&\gamma(n-1)\\\cdots&\cdots&\cdots\\\gamma(n-1)&\cdots&\gamma(0)\end{bmatrix}
  $$

- 构造协方差向量
  $$
  \Sigma_{Y_n,Y_{n-p:n-1}}=\begin{bmatrix}\gamma(p),\cdots,\gamma(1)\end{bmatrix}
  $$

- 可以生成预测模型$\hat Y_{t}=\Sigma_{Y_n,Y_{n-p:n-1}}\Sigma_Y^{-1}(Y_{n-p:n-1}-\mu)+\mu$

##### 矩量法求参数(Yule-Walker)

- 基于自方差定义,可以得到方程组
  $$
  \gamma(0)=\sum_{i=1}^p\phi_i\gamma(|i|)+\sigma^2\\
  \gamma(1)=\sum_{i=1}^p\phi_i\gamma(|i-1|)\\
  \cdots\\
  \gamma(p)=\sum_{i=1}^p\phi_i\gamma(|i-p|)
  $$

- 带入自方差估计值$\hat\gamma$求得$\sigma$和$\phi_i$

##### Conditional MLE估计参数

- 对于$X_p,X_{p-1},\cdots X_0$, 有$X_p^2-\alpha_0-\alpha_1X_{p-1}^2-\cdots\alpha_p X_0^2=\epsilon_n\sim N(0,\sigma^2)$,因为残差服从独立正态分布,因此可以计算联合似然函数
  $$
  f(\alpha,\sigma^2|X)=\prod_{i=p+1}^n\frac{1}{\sqrt{2\pi\sigma}}\exp[-\frac{1}{2}(\frac{X_i-\sum_{j=1}^p\alpha_jX_{i-j}}{\sigma})^2]
  $$
  

### 2.3 MA(移动平均)模型

##### 模型定义

$$
Y_n=\epsilon_n+\psi_1\epsilon_{n-1}+\cdots+\psi_q\epsilon_{n-q}
$$

- 定义函数$\psi(x)=1+\psi_1x+\psi_2x^2+\cdots+\psi_qx^q$,则可以用算符简化$Y_n=\psi(B)\epsilon_n$
- 第$n$个时间点的值,是前$q$个残差的线性组合
- 不需要定义初始值$Y_0$,只要有$\epsilon$分布就可以决定$Y_n$
- 使用MA项可以有效拟合时序数据中的自方差

##### 自相关性

- $\sigma_Y^2=\sigma^2\sum_{i=0}^q\psi_i^2,\rho(h)=\sigma^2\sum_{i=0}^{q-h}\psi_i\psi_{i+h}$

- $\gamma(h)=\sigma^2\sum_{i=0}^{q-h}\psi_i\psi_{i+h}$

- 无穷项时,不需要有初始值,只有$\psi_n$就可以决定$Y$的结果,此时自相关系数收敛
  $$
  \gamma_h=\text{Cov}(\sum_{j=0}^\infty \psi_j\epsilon_{n-j},\sum_{k=0}^\infty \psi_k\epsilon_{n+h-k})=\sum_{j=0}^\infty\sum_{k=0}^\infty \psi_j\psi_k\text{Cov}(\epsilon_{n-j},\epsilon_{n+h-k})
  $$
  只有当$k=j+h$的时候$\text{Cov}(\epsilon_k\epsilon_j)=\sigma^2$,否则为0, 因此$\gamma_h=\sum_{j=0}^\infty\psi_j\psi_{j+h}$, 即$\sum_0^{\infty}|\psi_j|<\infty$才有自相关性
  

### 2.4 ARMA模型

##### 模型定义

- AR和MA模型的组合
  $$
  Y_n=\phi_1Y_{n-1}+\phi_2Y_{n-2}+\cdots\phi_{p}Y_{n-p}+\epsilon_n+\psi_1\epsilon_{n-1}+\cdots+\psi_q\epsilon_{n-q}
  $$
  
- 使用算符简化,如果两<u>边可以消元,这说明可以化简为更简单的ARMA模型</u>: $\phi(B)Y_n=\psi(B)\epsilon_n$

- <u>拟合效果往往比单独使用AR或者MA更准确,但是有时候需要去除平均数</u>

- 方差
  $$
  \sigma_Y^2=\frac{1+\sum_{i=1}^q\psi_i^2+2\sum_{i=1}^{\min(p,q)}\psi_i\phi_i}{1-\sum_{i=1}^p\phi_i^2}\sigma_\epsilon^2
  $$
  

##### 因果性分析

- Causality
  - $Y_n$可以由之前的$\epsilon$决定,即$Y_n=\frac{\psi(B)}{\phi(B)}\epsilon_n$
  - 如果$g(x)=\frac{\psi(x)}{\phi(x)}$收敛,则模型Causal
- Invertibility
  - $\epsilon_n$可以由之前的$Y_n$决定,即$\epsilon=\frac{\phi(B)}{\psi(B)}Y_n$
  - 如果$g(x)=\frac{\phi(x)}{\psi(x)}$收敛,则模型Invertible
  - 实际应用中,<u>要尽量使用invertible模型</u>

- 单位根检验: 求解$g(x)$的所有解,如果所有解都在单位圆内,则$g(x)$收敛,即casual/invertible

##### 应用实例

- 通过差分把随机过程转化为ARMA模拟的时序过程

- 把连续过程转化为离散过程,考虑震荡过程例子 

  - $\frac{\mathrm d^2}{\mathrm dt^2}x(t)=-\omega^2x(t)$有解$x(t)=A\sin(\omega t+\phi)$
  - 可以把求导转化为差分,即$(1-B)^2 y_n=-\omega^2 y_n$有解$Y_n=\frac{2Y_{n-1}}{1+\omega^2}-\frac{Y_{n-2}}{1+\omega^2}+\epsilon_n$
  - 求得的解$Y_n$也有$\sin$函数的周期震荡特性,通过ACF Plot来描述信息由于$\epsilon$的丢失速度
  - <u>AR(2)通常可以用来拟合周期震荡的ACF</u>

### 2.5 ARMA参数估计

##### AIC

- $AIC=-2\times l(\hat\theta_{MLE})+2D$,用来权衡AR,MA的参数数量和拟合程度的关系
- 优先选取$AIC$较低的模型,但是需要检验和测试才能证明最优解
- $AIC$计算过程中容易出现numeric error,相邻阶的$AIC$差值应该小于2,否则有数值计算问题

##### 参数检验

- 使用AIC模型获得$p,q$之后,需要做单位根检验,如果AR和MA有非常相近的根,说明可能可以cancel化简为更简单的模型
- 如果MA的存在单位圆内的根,说明模型不是invertible的,不适合使用
- 使用拟合完的模型再次构造数据,并用KDE检验,确认Profile likelihood 估计给出的置信区间是否可靠

### 2.6. ARMA模型衍生

##### ARSMA模型 (处理周期性)

- ARSMA模型只是ARMA模型的特殊情况,可以将$Y_n$之间的关系因式分解
- $s$ 是周期长度,通常不需要估计,而是根<u>据数据性质/ACF挖掘</u>
- 添加了$P,Q$两个参数,描述了$\Phi$和$\Psi$的方程的阶数

$$
\phi(B)\Phi(B^S)(Y_n-\mu)=\psi(B)\Psi(B^S)\epsilon_n
$$

##### ARIMA模型 (处理差分)

- 在数据缺少stationarity的时候,可以通过添加差分项,把数据变为平稳序列
- 通常只需要差分1次就可以获得平稳序列,但是<u> </u>

- 添加了$d,D$参数,描述了模型的差分次数

$$
\phi(B)\Phi(B^s)((1-B)^d(1-B^S)^DY_n-\mu)=\psi(B)\Psi(B^S)\epsilon_n
$$

##### Linear ARIMA模型 (处理趋势)

- 通过添加线性回归项$\beta$,将时间序列中的趋势消除
- 使用LRT来检验$\beta$存在的必要性,之后再通过bootstrap和residual来分析模型表现

$$
\phi(B)\Phi(B^s)((1-B)^d(1-B^S)^D(Y_n-\mu-\beta t_n)=\psi(B)\Psi(B^S)\epsilon_n
$$

# 3. 频域分析

### 3.1 Spectral Density

##### 自方差正交分解

- 对于时间序列数据$Y$,有自方差矩阵$V=\text{Cov}(Y,Y)$,对于第$m$行$n$列的元素,描述了自方差$\gamma_{m-n}$
- 根据谱定理,可以把$V$拆分成正交的特征向量(相互独立的特征分量)$u_n$和特征值$\lambda(\omega)$
- $\omega_n$是每个基的频率,可选范围和时间序列长度相同(即$V$的维度)

$$
u_n=\exp(2\pi i\omega_n t)\\
\lambda(\omega_n)=\sum_{h=-\infty}^\infty\gamma_h\exp(-2\pi i\omega_n h)
$$

##### <u>Spectral density function (Periodogram)</u> $\lambda(\omega)$计算流程

<u>通过对时域的ACF进行离散傅里叶变换,来获得时间序列数据在不同频率下的强度</u>$\lambda(\omega)$

1. 对原时域数据进行离散傅里叶分解,获得每组基的系数 (一共$N$组基)
   - $c_n=\frac{1}{\sqrt N}\sum_{t=1}^N y_t\cos(2\pi\frac{n}{N}t)\quad0\leq n\leq\frac{N}{2}$
   - $s_n=\frac{1}{\sqrt N}\sum_{t=1}^N y_t\sin(2\pi\frac{n}{N}t)\quad1\leq n\leq\frac{N}{2}$
2. 根据定义$\omega_n=\frac{n}{N}$,因此可以基于$C_n$和$S_n$的分布来估计$\lambda(\omega_n)$
   - $C_n$和$S_n$都服从$\N(0, \frac{\lambda(\omega_n)}{2})$的正态分布
   - $C_n^2+S_n^2\approx\lambda(\omega_n)\frac{\chi_2^2}{2}$,因此他们的平方和服从卡方分布
   - 通过求对数,可以对$\lambda(\omega)$进行估计
3. <u>由于样本数有限,且有$\chi_2^2$带来的noise,需要对$\lambda$使用local average来进行平滑</u>
4. $\lambda(\omega)$的置信区间大小相同,不会随$\omega$改变
5. 由于时间序列数据有限,需要使用taper在边界点进行平滑

##### ARMA的Spectrum

- 对于$\text{Var}[\epsilon]=\sigma_2$的ARMA模型,有spectrum
  $$
  \lambda(\omega)=\sigma^2|\frac{\psi(\exp{2\pi i\omega})}{\phi(\exp(2\pi i\omega)}|^2
  $$

- $\epsilon$的spectrum是常数
- 对于$\phi$,如果有接近1的特征值,则$\lambda(w)$会变得非常大

### 3.2 频域分析应用

##### Loess Smoother

- 在时间序列数据的每个时间点,进行线性拟合,再加权生成数据
- 对时间序列数据进行平滑,可以获得trend并过滤高频信号和噪音

##### Band pass filter

- 过滤低频和高频信号,保留中频信号,可以挖掘数据中有意义的周期性信息
- 使用谐波,即频率互相为整数倍的信号,可以找到不同频率间的共振

##### Hodrick-Prescott filter

- 通过调整拟合误差和拟合曲线的二阶差分(二阶差分描述了拟合的平滑度)的占比$\lambda$,来调整平滑效果
  $$
  s_{1:N}=\arg\min_{s_{1:N}}\{\sum_{n=1}^N(y_n-s_n)^2+\lambda\sum_{n=2}^{N-1}(s_{n+1}-2s_n+s_{n-1})^2\}
  $$
  

# 4. 多状态时序分析

### 4.1 多变量相关性

##### Sample Cross-correlation Function(CCF)

- $\gamma_{XY}(h)$描述了变量和另一个变量lag $h$阶的协方差$\text{Cov}(X_{n+h}, Y_n)$
- $\gamma_{XY}$是不对称的,因此变化到频域之后是复数
- 转化协方差可以获得CCF

$$
\hat\rho_{xy}(h)=\frac{\sum_{n=1}^{N-h}(x_{n+h}-\bar x)(y_n-\bar y)}{\sqrt{\sum_{n=1}^N(x_n-\bar x)^2\sum_{n=1}^N(y_n-\bar y)^2}}=\frac{\text{Cov}(X_{n+h}, Y_n)}{\sigma_X\sigma_Y}=\text{Corr}(X_{n+h}, Y_n)
$$



##### Coherence

- Cross-Spectrum是$\gamma_{XY}(h)$的傅里叶变化: $\lambda_{XY}(\omega)=\sum_{h=-\infty}^\infty\exp(-2\pi i\omega h)\gamma_{XY}(h)$

- Coherency: 对Cross-Spectrum进行标准化. 因为$\gamma_{XY}$不对称,因此存在复角,且复角和$\lambda_{XY}$相同
  $$
  \rho_{XY}(\omega)=\frac{\lambda_{XY}(\omega)}{\sqrt{\lambda_{XX}(\omega)\lambda_{YY}(\omega)}}
  $$

- Coherence $|\rho_{XY}|$描述了$X$和$Y$在不同频率分量$\omega$上的相似度
- Phase $\angle\rho_{XY}$描述了$X$和$Y$在$\omega$分量下的phase差 (例如$\angle\rho_{XY}=\pi$说明$\omega$分量的波峰交替出现)

### 4.2 马尔科夫过程

##### Assumption

- 系统可能有$K$种状态$X_k$在,且系统在$t$时刻的状态$X_t$只和之前的状态$X_{1:t-1}$有关,即对于一阶过程有: $f(x_{t}=X_k|x_{1:t-1})=f(x_{t}=X_k|x_t=X_{t-1})$
- 初始状态可能未知,用向量$X\in\mathbb{R^K}$表示在各状态的概率

##### One-step Hidden Process

- 不同状态间有一定概率转换,常用的一阶转换概率通过状态转移矩阵(马尔科夫矩阵)$M\in\mathbb{R}^{K\times K}$描述
  $$
  M_t=\begin{bmatrix}f(x_{t+1}=X_1|x_t=X_1)&f(x_{t+1}=X_1|x_t=X_2)&\cdots f(x_{t+1}=X_1|x_t=X_k)
  \\\cdots\\
  f(x_{t+1}=X_k|x_t=X_1)&f(x_{t+1}=X_k|x_t=X_2)&\cdots f(x_{t+1}=X_k|x_t=X_k)
  \end{bmatrix}
  $$

- 马尔科夫矩阵的每列和为1,乘积$X_{t+k}=M^kX_t$,代表转换了$k$次状态

- 对于特定隐状态序列$x_{0:N}$,出现的概率为转换概率累乘, 通过极大似然估计可以获得最大概率的状态
  $$
  f_{X_{0:N}}(x_{0:N})=f_{X_0}(x_0)\prod_{n=1}^N f_{X_n|X_{n-1}}(x_n|x_{n-1})
  $$

##### One-step HMM

- 观测值$y_n$只和当前状态$x_n$有关,即$f_{Y_n|X_n}(y_n|x_n)=f_{Y_n|X_{0:N},Y_{1:n-1},Y_{n+1:N}}(y_n|x_{0:N},y_{1:n-1},y_{n+1:N})$

- 状态转移矩阵和观测矩阵都和时间$n$无关,即$M$和$f_{Y|X}(y,x)$是常数

### 4.3 POMP (Partially Observed Markov Process Model)

##### Overview

- 马尔科夫状态状态$X$无法测量,即$x_t$无法测量,只能给出概率分布

- 对于每种状态$X_k$,会输出特定的观测值$Y_i$,且在$t$时刻可以测量$y_t=Y_?$

- 状态转移后的结果,和输出的观测结果都会有一定误差

- 通过观测分布函数描述了观测值和隐状态及其他时刻观测值的关系 (可能和未来也有关系)
  $$
  f_{Y_n|X_{0:N},Y_{1:n-1},Y_{n+1:N}}(y_n|x_{0:N},y_{1:n-1},y_{n+1:N})
  $$

- 是一种描述各种Markov Process的广义模型,主要研究4种问题,可以描述整个POMP过程,且各个过程之间可以互相递归求解

##### Likelihood

- 描述<u>观测序列</u>出现的概率$f_{Y_1:N}(y_{1:N};\theta)$,使用极大似然估计获得参数$\hat\theta$

- 使用One-step Prediction和观测矩阵可以递归计算
  $$
  f_{Y_t|Y_{1:t-1}}(y_t|y_{1:t-1})=\int f_{Y_t|X_t}(y_t|x_t)f_{X_{t}|Y_{1:t}}(x_{t}|y_{1:t})\mathrm d x_t=\prod_{t=1}^T f_{Y_t|Y_{1:t-1}}(y_t|y_{1:t-1};\theta)
  $$

##### Smoothing

- 基于所有的观测值,<u>回溯过去</u>某一个时点的状态概率分布 (分析趋势) $f_{X_{t}|Y_{1:N}}(x_{t}|y_{1:N})$
- 需要基于观测分布递归计算
  - 通过向后回溯计算过去分布: $f_{Y_{t:T}|X_t}(y_{t:T}|x_t)=\prod_{i=t}^N f_{Y_i|X_t}(y_i|x_t)$
  - 通过递归计算观测值未来分布: $f_{Y_{n:N}|X_n}(y_{n:N}|x_n)=\int f_{Y_{n:N}|X_{n+1}}(y_{n:N}|x_{n+1})f_{X_n|X_{n-1}}(x_{n|x_{n-1}})\mathrm d x_{n}$

$$
f_{X_{t}|Y_{1:T}}(x_{t}|y_{1:T})=\frac{f_{X_{t}|Y_{1:t-1}}(x_{t}|y_{1:t-1})\cdot f_{Y_t|X_t(y_{t:T}|x_t})}{f_{Y_{t:T}|Y_{1:t-1}}(y_{t:T}|y_{1:t-1})}
$$

##### Filtering

- 已知过去的观测值$Y_{1:t}$,获得<u>当前</u>的状态概率分布$f_{X_{t}|Y_{1:t}}(x_{t}|y_{1:t})$
- 通过贝叶斯分析和<u>Likelihood估计的序列概率</u>,可以递归计算

$$
f_{X_{t}|Y_{1:t}}(x_{t}|y_{1:t})=\frac{f_{X_t|Y_{1:t-1}}(x_t|y_{1:t-1})\cdot f_{Y_t|X_t,Y_{1:t-1}}(y_t|x_t,y_{1:t-1})}{f_{Y_t|Y_{1:t-1}}(y_t|y_{1:t-1})}
$$



##### One-step Prediction

- 已知过去的观测值$Y_{1:t}$,预测<u>下一个时</u>点的状态概率分布$f_{X_{t+1}|Y_{1:t}}(x_{t+1}|y_{1:t})$
- 可以通过递归计算,即状态转换概率和<u>filtering结果</u>的乘积

$$
f_{X_{t+1}|Y_{1:t}}(x_{t+1}|y_{1:t})=\int f_{X_{t+1}|X_t}(x_{t+1}|x_t)\cdot f_{X_{t}|Y_{1:t}}(x_{t}|y_{1:t})\mathrm dx_t
$$

### 4.4 Linear Gaussian POMP (LG-POMP)

##### General Linear Model

- 隐状态$X_n$为一阶过程,且通过马尔科夫矩阵$\mathbb A_t\in\mathbb R^{d_X\times d_X}$转换
- 观测值$Y_n$为隐状态的线性输出,输出概率通过$\mathbb B_t\in\mathbb R^{d_Y\times d_X}$

- 观测状态和隐状态每次转换后还会有误差,通过误差矩阵$\mathbb U_t\in\mathbb R^{d_X\times d_X}$和$\mathbb V_t\in\mathbb R^{d_Y\times d_Y}$描述

- 通常我们考虑稳定变化,即$\mathbb{A,B,U,V}$和$t$无关
  $$
  X_t=\mathbb A_tX_{t-1}+\epsilon_t\quad\epsilon_t\sim N(0,\mathbb{U}_n)\\
  Y_t=\mathbb B_tX_{t-1}+\eta_t\quad\eta_t\sim N(0,\mathbb{V}_n)
  $$

##### Basic Structural Model (BSM)

- 将观测序列$Y_n$拆分成Level: $L_n$和Seasonal Component: $S_n$两部分
  - $Y_n=L_n+S_n+\epsilon_n$
  - $S_t=-\sum_{k=1}^TS_{n-k}+\eta_n$
- Level $L_n$的变化通过 Trend $T_n$ 描述 ($T_n$并不是观测序列的趋势,而是Level的变化率)
  - $L_n=L_{n-1}+T_{n-1}+\xi_n$
  - $T_n=T_{n-1}+\eta_n$

### 4.5 POMP Inference

##### HP Filter

- 对于给定观测序列$Y_t$,假设$Y_t$的平滑输出$X_t$是序列的隐状态
- 状态转换方程: $X_t=2X_{t-1}-X_{t-2}+\epsilon_t\quad \epsilon_t\sim N(0,\frac{\sigma^2}{\lambda})$
- 可以通过重新构造$\tilde X_t=\begin{bmatrix}X_t\\X_{t-1}\end{bmatrix}$使$\tilde X_t$变成1阶关系

- 观测方程: $Y_t=X_t+\eta_t\quad\eta_t\sim N(0,\sigma^2)$

- 通过极大似然估计$X_t$求得平滑隐状态 (等效于HP滤波最小误差输出)
  $$
  \arg\max_{x_{1:T}} \log f_{X_{1:T},Y_{1:T}}(x_{1:T},y_{1:T};\sigma,\lambda)=-\frac{1}{2\sigma^2}\sum_{t=1}^T(y_t-x_t)^2-\frac{\lambda}{2\sigma^2}\sum_{t=3}^T(\bigtriangleup^2x_t)^2+C
  $$

##### <u>Kalman Filter</u>

- 观测值只和当前状态有关,即$P[Y_t|X_t,U_t,X_{t-1}]=P[Y_t|X_t],P[Y_t|X_{t-1},U_t]=P[Y_t]$
- 常用于控制论,根据观测状态$y_{t}$,控制操作$u_t$,上一个隐状态分布$x_{t-1}$来获得当前隐状态分布$f_{X_t|Y_t,X_{t-1},U_t}(x_t|y_t,x_{t-1},u_{t-1})$服从正态分布

$$
P[X_t|Y_t,X_{t-1},U_t]=\frac{P[X_t,Y_t,X_{t-1},U_t]}{P[Y_t,X_{t-1},U_t]}=\frac{P[Y_t|X_t,U_t,X_{t-1}]P[X_t|X_{t-1},U_t]}{P[Y_t|X_{t-1},U_t]}=\frac{P[Y_t|X_t]P[X_t|X_{t-1},U_t]}{P[Y_t]}
$$

- <u>线性变换模型转换方程</u>

  |          | $\mu^P_t$                                       | $\Sigma_t^P$                                                 | $\mu_t^F$                                                    | $\Sigma_t^F$                                                 |
  | -------- | ----------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
  | 定义     | 隐状态预测分布均值$\mathbb{E}[X_{t+1}|Y_{1:t}]$ | 隐状态预测分布方差                                           | <u>隐状态filter均值</u> $\mathbb{E}[X_{t}|Y_{1:t}]$          | 隐状态filter方差                                             |
  | 转换方程 | $\mathbb A_{t+1}\mu_t^F(y_{1:t})$               | $\mathbb A_{t+1}\Sigma_t^F\mathbb A_{t+1}^T+\mathbb U_{t+1}$ | $([\Sigma_t^P]^{-1}+\mathbb B_t^T\mathbb V_t^{-1}\mathbb B_t)^{-1}$ | $\mu_t^Py_{1:t-1}+\Sigma_t^F\mathbb B_t^T\mathbb V_t^{-1}(y_t-\mathbb B_t\mu_t^Py_{1:t-1})$ |

##### <u>Particle Filter</u>

- 已知状态转换概率模型$p(x_n|x_{n-1};\theta)$和观测概率模型$p(y_n|x_n;\theta)$<u>计算POMP时间序列数据隐状态的似然函数,通过比较不同$\theta$下的似然函数来选择参数</u>
  $$
  L(\theta)=\prod_{n=1}^Np(y_n^*|y_{1:n-1}^*;\theta)=\prod_{n=1}^N\int p(y_n^*|x_n;\theta)p(x_n|y^*_{1:n-1};\theta)\mathrm dx_n
  $$

- Prediction Formula: 基于之前观测状态$Y_{1:n-1}$获得下一个隐状态$X_n$的概率
  $$
  p(x_n|y_{1:n-1}^*;\theta)=\int p(x_n|x_{n-1};\theta)p(x_{n-1}|y_{1:n-1}^*;\theta)\mathrm dx_{n-1}
  $$

- Filtering Formula: 基于观测状态$Y_{1:n}$获得当前隐状态$X_n$的概率
  $$
  p(x_n|y_{1:n}^*;\theta)=\frac{p(x_n,y_n,y_{1:n-1};\theta)}{p(y_n,y_{1:n-1};\theta)}=\frac{p(y_n|x_n;\theta)p(x_n|y_{1:n-1};\theta)}{\int p(y_n|x_n;\theta)p(x_n|y_{n-1};\theta)\mathrm dx_n}
  $$

- 对于每个$x_n$相互迭代Prediction和Filtering可以分别计算两个概率
  1. Prediction: 基于步骤3(如果$n=0$可以根据预设初始值)预测$J$个$n$时刻的预测(Prediction)样本$x_{n,j}^P$
  2. Filtering: 基于$t=n$时刻的真实观测值$Y_t$,在预测状态下出现的概率,对每个预测状态计算权重$w_{t,j}=p(y_t|x_{t,j}^P;\theta)$,并根据权重重新采样获得$x_{t,j}^F$
  3. 根据采样获得的$x_{t,j}^F$进行状态转换,获得$J$个对下一个时刻的预测$x_{t+1,j}^P$
  4. 使用观测值$y_n$在$J$个采样状态$x_{n,j}$下的出现频率,可以对$p(y^*_n|y^*_{1:n-1};\theta)$进行估计$\hat l_n(\theta)\approx\frac{1}{J}\sum p(y^*_n|x_{n,j}^P)$
  5. 将所有时间点的似然函数相加,就是总序列的似然函数$\hat L(\theta)=\sum\log \hat l_n(\theta)$

- 基于反复的Particle Filtering来对参数$\theta$进行迭代式的极大似然估计
- 每次迭代后,会对$\theta$<u>添加扰动项</u>,类似遗传算法,再使用新的参数来进行估计

- 迭代流程:
  1. 预设迭代次数$M$和粒子数量$J$,针对每一个粒子生成一个模型参数$\theta_j$
  2. 使用模型参数$\theta_j$生成$J$个预测样本$x_{0,j}^F$
  3. 进入时间序列,对每个参数$\theta_j$施加扰动项获得新的参数$\theta_j'$
  4. 基于参数$\theta_j'$进行$t=n$时刻粒子滤波
  5. 基于粒子滤波中获得的权重,对对应的参数$\theta_j'$重新采样$J$个参数
  6. 时间序列采样完成后,减小扰动幅度,从2重新开始
