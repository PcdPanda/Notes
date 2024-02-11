- [1. 统计和参数估计](#1-统计和参数估计)
    - [1.1 统计基础概念](#11-统计基础概念)
        - [总体和样本](#总体和样本)
        - [参数和估计](#参数和估计)
        - [样本重要特性](#样本重要特性)
        - [样本可视化](#样本可视化)
    - [1.2 置信区间和重要参数估计值](#12-置信区间和重要参数估计值)
        - [置信区间](#置信区间)
        - [容许区间](#容许区间)
        - [全体方差/均值估计](#全体方差均值估计)
- [2. Max Likelihood Estimation (MLE)](#2-max-likelihood-estimation-mle)
    - [2.1 分布误差](#21-分布误差)
        - [总变差TV (Total Variation)](#总变差tv-total-variation)
        - [KL散度](#kl散度)
        - [JS散度 (Jensen Shannon Divergence)](#js散度-jensen-shannon-divergence)
        - [似然函数](#似然函数)
    - [2.2 估计流程](#22-估计流程)
        - [似然函数估计流程](#似然函数估计流程)
        - [Fisher Information](#fisher-information)
    - [2.3 Likelihood Ratio Test](#23-likelihood-ratio-test)
        - [Nest Hypotheses](#nest-hypotheses)
        - [Wilks approximation](#wilks-approximation)
        - [Information Criterion](#information-criterion)
    - [2.4 Profile Likelihood Estimation](#24-profile-likelihood-estimation)
        - [估计逻辑](#估计逻辑)
        - [Profile Likelihood Estimation 估计流程](#profile-likelihood-estimation-估计流程)
- [3. Kernel Density Estimation](#3-kernel-density-estimation)
    - [3.1 Overview](#31-overview)
        - [使用场景](#使用场景)
        - [Bandwidth $b$](#bandwidth-b)
    - [3.2 Application](#32-application)
        - [Kernel-Based Estimation](#kernel-based-estimation)
        - [Kernel-Based Estimation Property](#kernel-based-estimation-property)
- [4. Moments Estimation](#4-moments-estimation)
    - [4.1 Overview](#41-overview)
        - [矩量](#矩量)
        - [WAT Theorem:](#wat-theorem)
    - [4.2 估计流程](#42-估计流程)
        - [计算流程](#计算流程)
        - [配合MLE使用](#配合mle使用)
- [5. Bootstrap](#5-bootstrap)
    - [5.1 Overview](#51-overview)
        - [适用场景](#适用场景)
        - [核心思想](#核心思想)
    - [5.2 实际应用](#52-实际应用)
        - [估计流程](#估计流程)
        - [置信区间](#置信区间-1)
- [6.(MCMC) Markov Chain Monte Carlo](#6mcmc-markov-chain-monte-carlo)
    - [6.1 蒙特卡洛法](#61-蒙特卡洛法)
        - [Overview](#overview)
        - [蒙特卡洛积分](#蒙特卡洛积分)
        - [蒙特卡洛抽样](#蒙特卡洛抽样)
    - [6.2 马尔科夫链](#62-马尔科夫链)
        - [Overview](#overview-1)
        - [连续平稳马尔科夫链](#连续平稳马尔科夫链)
        - [细致平稳分布 (Detail Balance)](#细致平稳分布-detail-balance)
    - [6.3 MCMC抽样](#63-mcmc抽样)
        - [算法流程](#算法流程)
        - [Reject Sampling](#reject-sampling)
        - [M-H采样](#m-h采样)
        - [Gibbs Sampling](#gibbs-sampling)
- [7. 贝叶斯统计](#7-贝叶斯统计)
    - [7.1 基本概念](#71-基本概念)
        - [优势](#优势)
        - [先验分布](#先验分布)
        - [后验分布](#后验分布)
    - [7.2 估计流程](#72-估计流程)
        - [Jeffrey prior](#jeffrey-prior)
        - [计算流程](#计算流程-1)
        - [分母处理方法](#分母处理方法)
        - [共轭分布](#共轭分布)
- [8. Hypothesis Test](#8-hypothesis-test)
    - [8.1 Fisher Test](#81-fisher-test)
        - [Null Hypothesis](#null-hypothesis)
        - [P-Value](#p-value)
    - [8.2 Decision Theory](#82-decision-theory)
        - [Hypothesis](#hypothesis)
        - [Error](#error)
        - [Power](#power)
    - [8.3 检验流程](#83-检验流程)
        - [决策步骤](#决策步骤)
    - [8.4 接受率分析](#84-接受率分析)
        - [假设](#假设)
        - [错误率](#错误率)
- [9. 样本检验](#9-样本检验)
    - [9.1 单样本检验](#91-单样本检验)
        - [均值T-test](#均值t-test)
        - [方差 Chi-Square Test](#方差-chi-square-test)
        - [中位数测试](#中位数测试)
        - [Rank Test](#rank-test)
        - [特征检验](#特征检验)
        - [多项分布检验 Pearson Test](#多项分布检验-pearson-test)
        - [特征独立性检验](#特征独立性检验)
    - [9.2 多样本检验](#92-多样本检验)
        - [检验均值差(已知方差)](#检验均值差已知方差)
        - [F-Test(检验方差比值)](#f-test检验方差比值)
        - [Pooled T-test(未知方差检验均值差)](#pooled-t-test未知方差检验均值差)
        - [特征检验](#特征检验-1)
- [10. 样本分布检验](#10-样本分布检验)
    - [10.1 拟合度检验(goodness of fit)](#101-拟合度检验goodness-of-fit)
        - [KS-Test (已知总体分布参数)](#ks-test-已知总体分布参数)
        - [$\\chi^2$ 检验](#chi2-检验)
    - [10.2 ANOVA (多总体方差分析)](#102-anova-多总体方差分析)
        - [基本定义](#基本定义)
        - [误差分析](#误差分析)
        - [估计值分布](#估计值分布)
        - [F检验](#f检验)
        - [方差检验](#方差检验)
        - [均值检验](#均值检验)


<div STYLE="page-break-after: always;"></div>

# 1. 统计和参数估计

### 1.1 统计基础概念

##### 总体和样本

- population: 所有物体,每个物体都是i.i.d,服从相同的分布
- sample: 
  - 从总体中抽样获得的物体,<u>不能超过总体数量的5%</u>
  - 样本的重要特性 (最值/分位数/众数/平均值/方差/偏度/峰度)

##### 参数和估计

- parameter $(\theta)$: 分布的参数,是一个未知的常数

- estimator $(\hat\theta)$: 
  - 通过样本得到对$\theta$的估计公式
  - 因为样本不同,estimator自己也会有期望和方差
- 衡量estimator的表现:
  - Bias: $\theta-E[\hat\theta]$
  - MSE: $E[(\hat\theta-\theta)^2]=Bias^2+Var[\hat\theta]$

##### 样本重要特性

| 平均值 | 中位数 | 众数 | 中位数 | 分位数 |
| ------ | ------ | ---- | ------ | ------ |

##### 样本可视化

| 茎叶图 | 分位图 (考虑用倒数) | 柱状图 | 箱型图 | 小提琴图 |
| ------ | ------------------- | ------ | ------ | -------- |

### 1.2 置信区间和重要参数估计值

##### 置信区间

- 通过sample和计算得到的estimator得到的区间
- 通过$(1-\alpha)\%$来描述可靠性,有$1-\alpha$的真实$\theta$落在该区间内

##### 容许区间

- 给定区间覆盖的总体范围$\delta$
- 总体落入区间的概率$\alpha$
- 可以获得样本大小$n\approx\frac{1}{2}+\frac{1+\delta}{1-\delta}\cdot\frac{\chi_{\alpha, 4}^2}{4}$

##### 全体方差/均值估计

| 参数               | 计算公式                            | 期望       | 分布                                           | 置信区间                                                     | 方差                    |
| ------------------ | ----------------------------------- | ---------- | ---------------------------------------------- | ------------------------------------------------------------ | ----------------------- |
| 样本均值(已知方差) | $\bar X=\frac{1}{n}\sum X$          | $\mu$      | $\frac{\sqrt{n}(\bar X-\mu)}{\sigma}\sim(0,1)$ | $\bar{X}\pm \frac{z_{0.025}\cdot\sigma}{\sqrt{n}}$           | $\frac{\sigma}{n}$      |
| 样本方差(正态分布) | $S^2=\frac{1}{n-1}\sum(X-\bar X)^2$ | $\sigma^2$ | $\frac{(n-1)S^2}{\sigma^2}\sim\chi^2_{n-1}$    | $[0,\frac{(n-1)S^2}{\chi_{(1-\alpha)/2}^2}]\cap[\frac{(n-1)S^2}{\chi_{\alpha/2}^2}, \infty)$ | $\frac{2\sigma^4}{n-1}$ |
| 样本均值(未知方差) | $\bar X=\frac{1}{n}\sum X$          | $\mu$      | $\frac{\bar{X}-\mu}{S/\sqrt{n}}\sim T_{n-1}$   | $\bar{X}\pm t_{\alpha/2,n-1}\frac{S}{\sqrt{n}}$              | $\frac{\sigma}{n}$      |



# 2. Max Likelihood Estimation (MLE)

### 2.1 分布误差

##### 总变差TV (Total Variation)

- 描述了两个概率分布的差异 (不相交的面积)
- 对称且始终大于0
- $TV=\frac{1}{2}\int_{-\infty}^{\infty}|f(x)-g(x)|\mathrm{d}x$

##### KL散度

- 描述了两个概率分布熵的期望差,但是<u>不对称</u>
- $KL(f,g)=\int_{-\infty}^{\infty}f(x)\log\frac{f(x)}{g(x)}\mathrm{d}x\rightarrow E[\log f(x)]-E[\log g(x)]$

##### JS散度 (Jensen Shannon Divergence)

- 通过对称的方式描述了两个分布的差异
- $JSD(f, g)=0.5KL[f, 0.5(f+g)]+0.5KL[g,0.5(f+g)]$

##### <u>似然函数</u>

- 使用样本代替$KL$散度中的$g$,并用真实分布代替$f$,所以$E[log f(x)]$是个常数

  $KL(f,g)=c-\frac{1}{n}\sum\log g(x)$

- 最小化散度等效于最大化$\sum\log g(x)\rightarrow g(x_1)\cdot g(x_2)\cdots g(x_n)\rightarrow L(X_n;\theta)=\prod p(x;\theta)$

### 2.2 估计流程

##### 似然函数估计流程

1. 建立数据的分布模型即$g_\theta(x)$

2. 根据sample获得联合似然函数,如抛硬币获得结果为(正，正，反，正),则得到似然函数

   $L(X_1=1,X_2=1,X_3=0,X_4=1;p)=g_p(1)\cdot g_p(1)\cdot g_p(0)\cdot g_p(1)$

3. 对似然函数求对数后求导寻找最大值

   $\ln(L)=3\ln(p)+ln(1-p)$

   $\ln(L)'=\frac{3}{p}-\frac{1}{1-p}=0$

4. 导数为0获得极值

   $p=\frac{3}{4}$

##### Fisher Information

- <u>当参数服从正态分布时,可以作为标准差有效估计参数的置信区间</u>

- $I(\theta)=Var[(\log L(x;\theta))']=-E[(\log L(x;\theta))'']$

- 基于估计值 $\hat\theta_{mle}$ 分布,<u>越大说明MLE的估计准确概率越高</u>
  $$
  \sqrt n(\theta_{mle}-\theta)\sim N(0, I(\theta)^{-1})
  $$
  

### 2.3 Likelihood Ratio Test

##### Nest Hypotheses

- 给定有$D$个参数$\Theta\in\mathbb{R}^D$的模型,只考虑有限参数对于似然函数的贡献

- 给定两个嵌套的参数集合$\Theta_0\subset\Theta_1$,维度是$D_0<D_1\leq D$
- 给定两个hypotheses: $H_0:\theta\in\Theta_0,H_1:\theta\in\Theta_1$

##### Wilks approximation

- 在$H_0$成立时,则有
  $$
  \sup_{\theta\in\Theta_1} \mathscr{l}(\theta)-\sup_{\theta\in\Theta_0} \mathscr{l}(\theta)\approx\frac{1}{2}\chi^2_{D_1-D_2}
  $$

- 如果P-Value过小,说明$H_1$成立,即$D_1$新加的参数很有意义

##### <u>Information Criterion</u>

- $AIC=-2\times l(\hat\theta_{MLE})+2D$
- $BIC=-2\times l(\hat\theta_{MLE})+D\log n$
- 通过卡方分布,可以得到$AIC$和$BIC$的分布,并通过$AIC$或$BIC$的指标选取模型,越低越好
- 在参数数量$D$和似然函数中$l(\hat\theta_{MLE})$权衡 (矩阵参数中的每一个变量要单独)算作$D$)

### 2.4 <u>Profile Likelihood Estimation</u>

##### 估计逻辑

- 基于Likelihood Ratio Test,如果$\sup_{\theta\in\Theta_1} \mathscr{l}(\theta)-\sup_{\theta\in\Theta_0} \mathscr{l}(\theta)>\frac{1}{2}\chi^2_{D_1-D_2}$, 则可以拒绝$H_0$ (即说明$\Theta_0$不够用)
- 因此在不可以拒绝$H_0$的区间里,可以认定$\theta$有效

##### Profile Likelihood Estimation 估计流程

1. 选取参数$\theta$中的第$d$个参数$\theta_d$,固定$\theta_d$,修改其他变量进行极大似然估计 $l_d^{\text profile}(\theta_d)=\max_{\theta'\in\R^D:\theta'_d=\theta_d}l(\theta')$
2. 基于Wilks's theorem,获得对于$\theta_d$的95%置信区间 $\{\theta_d: l(\hat\theta)-l_d^{\text profile}(\theta_d)<\frac{1}{2}\chi_{\alpha,\bigtriangleup D}\}$
3. Profile Likelihood和常规MLE可以给出相同的最优解,但是<u>通常置信区间更好</u>
4. <u>PLE适合在似然函数非二次时适用</u>
5. 完成后通过simulation (bootstrap)来检验置信区间

# 3. Kernel Density Estimation

### 3.1 Overview

##### 使用场景

- 给定若干个离散样本,估计样本的概率分布函数$\hat f_b(x)$
- 无法直接获得$\hat f_b(x)$的分布模型和分布参数,但是可以通过plot来猜测
- 通常极值的样本较少,因此不适合估计tail

##### Bandwidth $b$

- 描述了平滑分布对于离散样本信息的利用程度
- $b$越大,拟合离$K_b$分布越接近,越平滑
- $b$越小,拟合离样本分布越接近,但容易过拟合

### 3.2 Application

##### Kernel-Based Estimation

- 给定若干个离散样本$x_i$,构造平滑分布
  $$
  \hat f_b(x)=\frac{1}{n}\sum_{i=1}^nK_b(x-x_i)
  $$

- $K_b$: kernel function,可以是任何density function

- 本质上是样本的平滑分布,$b$描述了平滑性

##### Kernel-Based Estimation Property

- 期望: $E[\hat f_b(x)]=\frac{1}{n}\sum_{i=1}^n E[K_b(x-x_i)]$ (对于不同的$x_i$求积分算期望)
  - 如果$x_i$是iid则有$E[\hat f_b(x)]=(K_b*f)(x_i)$

- 方差: $Var[\hat f_b(x)]=\frac{1}{n}\sum_{i=1}^n Var[K_b(x-x_i)]$

# 4. Moments Estimation

### 4.1 Overview

##### 矩量

给定分布PDF: $f_X(x;\theta)$,则有

- 矩量母函数$m_X(t)=E[e^{tX}]$
- $k$阶零矩 $m_k(X)$

$$
m_k(x)=E[X^k]=\int x^kf(x;\theta)\mathrm d x=\frac{\mathrm d^km_k(X)}{\mathrm dt^k}|t=0
$$

##### WAT Theorem: 

- 任何连续函数可以用$N$阶多项式无限逼近
- 样本分布的PDF,可以用$k$个矩量来逼近

### 4.2 估计流程

##### 计算流程

1. 根据模型得到moment和分布参数的关系式

   - $\psi^{-1}(m_1(\theta),m_2(\theta)\cdots)\rightarrow\theta$

2. 通过样本$n$,得到样本中的$k$个moment估计值$\hat{m}$

3. 回带估计值$\hat m$,计算得到参数估计值$\hat{\theta}$

   - $\hat m_n=[m_1(\hat\theta),m_2(\hat\theta),\cdots,m_k(\hat\theta)]$

   - $\psi^{-1}(\hat m_k)\rightarrow\theta$

4. $\hat\theta$ 的分布 (无偏估计)
   $$
   \sqrt{n}(\hat\theta-\theta)\sim N(0, [\bigtriangledown\psi^{-1}]^T Cov[\hat m_n][\bigtriangledown\psi^{-1}])
   $$

##### 配合MLE使用

1. 先使用Moment来找到合理的$\hat\theta$
2. 以$\hat\theta$出发,通过MLE在附近寻找局部最值,通常就是全局最值

# 5. Bootstrap

### 5.1 Overview

##### 适用场景

- 模型非常复杂,参数很难估计/检验
- 模型的假设不确定
- 有意义的数据量有限

##### 核心思想

- 把sample作为已知参数的总体
- 从sample中resample,从resample的结果找到估计误差

### 5.2 实际应用

##### <u>估计流程</u>

1. 从真实的population中获取sample
2. 把获得的sample当做population,并从中多次重复抽样构造子样本 (with replacement)
3. 在每个子样本中对$\theta$进行估计
4. 分析子样本估计值$\hat\theta^*$针对sample中估计值$\hat\theta$的bias和MSE
5. 将误差带入到sample的点估计值,获得置信区间

##### 置信区间

1. 计算子样本参数估计值$\hat\theta^*$和真实样本参数估计值$\hat \theta$的误差的分位值$\delta_l,\delta_u$
2. 将误差分位值视作全体样本参数$\theta$和真实样本参数估计值$\hat\theta$误差的分位值
3. 带入误差分位值,则有$\theta\in[\hat\theta+\delta_l,\hat\theta+\delta_u]=[2\hat\theta-\hat\theta^*_u,2\hat\theta-\hat\theta^*_l]$

# 6.(MCMC) Markov Chain Monte Carlo

### 6.1 蒙特卡洛法

##### Overview

- 设计方法来构造大量符合特定模型生成的样本
- 在已知模型结构的情况下,可以根据样本接受/拒绝的频率,获得模型的参数
- 在已知模型参数,但是不好计算特征的情况下,可以根据样本来估计期望等参数

##### 蒙特卡洛积分

- 通过抽样平均方法求解$\int_{a}^bf(x)\mathrm dx$的积分

- 假定$x$在$[a,b]$区间服从$p(x)$的分布
- 则根据积分定义,可以有$\int_{a}^bf(x)\mathrm dx=\int_{a}^b\frac{f(x)}{p(x)}p(x)\mathrm dx\approx\frac{1}{N}\sum_{i=1}^N\frac{f(x_i)}{p(x_i)}$

##### 蒙特卡洛抽样

- 对于已知,但是不好构造的分布$p(x)$,通过抽样使得结果逼近真实的概率分布$p(x)$
- 通过蒙特卡洛抽样获得的结果,可以有效对期望,方差等分布参数进行估计

### 6.2 马尔科夫链

##### Overview

- 对于$t$时刻状态向量$X_t$,存在不变一阶马尔科夫矩阵$P$,使得下一次状态为$X_{t+1}=PX_t$
- $P$的每一列和为1,代表从第$i$个状态转换到$j$的概率
- 平稳的马尔科夫链,经过有限步之后,会收敛于所有列相同的矩阵$\lim_{t\rightarrow\infty}P^t=\begin{bmatrix}\pi&\pi\cdots\end{bmatrix}$
- $\pi$是$P$特征值为1的特征向量,描述了马尔科夫链的最终稳态,且元素和为1

##### 连续平稳马尔科夫链

- 可以将离散列向量$\pi$连续化,$\pi(x)$即代表$x$在稳态分布出现的概率
- 同时可以将马尔科夫矩阵连续化,即每个元素是状态转移概率$P(x_{t+1}|x_t)$
- 给定稳态分布$\pi(x)$,需要找到使得服从$\pi(x^*)=\int P(x^*|x)\pi(x)\mathrm dx$的$p$,即以$\pi(x)$为特征向量的马尔科夫转换矩阵
- <u>假设$x$已经服从平稳分布$\pi(x)$则无论经过几次转换,每次结果都服从平稳分布,因此以$x$作为采样点就可以构造蒙特卡洛采样</u>

##### <u>细致平稳分布 (Detail Balance)</u>

- 给定一个分布$p(x)$,则从分布中的任意两点,以不同顺序获取的概率相同
- 对于任意$x_1,x_2$有$p(x_1)P(x_2|x_1)=p(x_2)P(x_1|x_2)$
- 对于满足$p(x)$细致平稳分布的转移矩阵$P$,则$p(x)$即$p$的稳态$\pi(x)$

### 6.3 MCMC抽样

##### 算法流程

1. 给定需要采样的分布$p(x)$
2. 找到满足和$p(x)$满足细致平稳分布的状态转移概率$P(x^*|x)$
3. 给定任意的目标稳态分布$p(x)$和转移方程$P(x^*|x)$,可以通过<u>构造采样率</u>$\alpha(x^*,x)$使得$P'(x^*|x)=P(x^*|x)\alpha(x^*,x)$，满足平稳分布
4. 在对$P(x)$进行burn-in操作后,开始采样,此时采样的数据即服从稳态$\pi(x)$的分布,也是$p(x)$的分布

##### Reject Sampling

1. 构造一个方便采样的proposed distribution $p(x)$

2. 生成一个常数$c$,使得$cq(x)\geq p(x)$
3. 从$q(x)$的分布中随机采样一个数字$x$
4. 新样本的接受率为$\frac{p(x)}{cq(x)}$
5. <u>如果$q(x)$和$p(x)$的分布相差很多,则接受率非常低</u>

##### <u>M-H采样</u>

1. 给定需要采样的分布$p(x)$和<u>任意马尔科夫转移分布</u>$P(x^*|x)$,构造接受率$\alpha(x,x^*)=\min\{1,\frac{p(x^*)P(x|x^*)}{p(x)P(x^*|x)}\}$
2. 基于$p(x)P(x^*|x)\alpha(x,x^*)$构造的转移概率为$p(x^*)P(x|x^*)\min\{\frac{p(x)P(x^*|x)}{p(x^*)P(x|x^*)},1\}=p(x^*)P(x|x^*)\alpha(x^*,x)$即满足细致平稳分布
3. 如果没有接受,就回到上一个点重新采样
4. 用尽量使用$p(x)$的性质构造$P$,以提高采样率

##### <u>Gibbs Sampling</u>

- <u>本质是接受率恒为1的M-H采样,大幅提高在高维空间中采样的效率</u>

- 当多维分布$p(X)$很难采样,但是每个维度的条件分布很好采样的场合使用,使用条件分布$p(x_i|x_1,x_2\cdots x_n)$作为状态转移分布$P(x)$

  1. $\alpha_{t+1}\sim P(\alpha|\beta_t,\gamma_t,\cdots)$

  2. $\beta_{t+1}\sim P(\beta|\alpha_{t+1},\gamma_t,\cdots)$
  3. $\gamma_{t+1}\sim P(\gamma|\alpha_{t+1},\beta_{t+1},\cdots)$

- 对于采样结果$X_t=[\alpha_t,\beta_t,\gamma_t,\cdots]$,每个维度的采样,都会依赖于上其他维度的采样结果,此时满足平稳分布
  $$
  p(\alpha_1,\beta_1,\gamma_1)P(\alpha_2|\beta_1,\gamma_1)=P(\alpha_1|\beta_1,\gamma_1)p(\beta_1,\gamma_1)P(\alpha_2|\beta_1,\gamma_1)=p(\alpha_2,\beta_1,\gamma_1)P(\alpha_1|\beta_1,\gamma_1)
  $$

# 7. 贝叶斯统计 

### 7.1 基本概念

##### 优势

- <u>当样本数量非常小时适用,用来更新已有认知</u>
- 可以获得整个参数的分布,而不仅仅是一个值

##### 先验分布

- 数据分布模型$P(D|\theta)$
- 参数分布$p(\theta)$
  - 初始先验分布应该对于$\theta$没有偏见 (可以使用uniform distribution)
  - 如果无法积分为1(如果$\theta$的范围是一条直线),则是improper prior

##### 后验分布

- 先验分布+样本后$P(D|\beta)$更新得到的分布
- <u>后验分布期望</u>: $\hat\theta=E[\theta]=\int\theta P(\theta|D)\mathrm{d}\theta$

- 贝叶斯置信范围: $P[\theta\in Reg|D]=1-\alpha$

### 7.2 估计流程

##### Jeffrey prior

$$
\pi_J(\theta)\propto\sqrt{\det I(\theta)}
$$

- 基于MLE和Fisher Information得到的先验分布,不会受到prior $p(\theta)$选择的影响

##### 计算流程

1. 选取一个数据的分布模型$P(x|\theta)$
2. 选取一个参数的分布函数$p(\theta)$
3. 使用贝叶斯定理计算$\theta$后验分布 (通过凑项数找参数)

$$
P(\theta|D)=\frac{P(D|\theta)P(\theta)}{\int P(D|\theta)P(\theta)\mathrm{d}\theta}
$$

4. 如果更新后<u>分布模型</u>没变,只改变了参数,则模型是conjugate prior

##### 分母处理方法

- 通过数值方法模拟计算
- 直接抛弃,不影响找$\hat\theta$

##### <u>共轭分布</u>

- 如果后验$P(\theta|D)$和$P(\theta)$形式相同,则似然函数$P(D|\theta)$和先验分布$P(\theta)$互相共轭
- 不需要计算分布,也可以判断是否共轭,且根据似然函数挑选合适的先验分布可以大大简化计算

<div STYLE="page-break-after: always;"></div>

# 8. Hypothesis Test

### 8.1 Fisher Test

##### Null Hypothesis

- 需要reject的hypothesis $H_0$和对应参数$\theta_0$  (例如全体的均值$\theta\geq\theta_0$)
- Reject $H_0$的level of significance $\alpha$

##### P-Value

$$
\text{P-Value}=P[D|H_0]=\frac{P[H_0|D]P[D]}{P[H_0|D]P[D]+P[H_0|\neg D]P[\neg D]}
$$

- 在给定$\theta\geq \theta_0$时获得sample的可能性 (**注意upper bound,不一定是样本,还有更糟糕的样本**)
- 如果P-value小于$\alpha$,则reject $H_0$

- 反应了假设下出现数据的概率,但是不能说明假设自身的概率,如果$P[D]$本来就很小,可能会导致$P[D|H_0]$失真

- <u>计算的时候需要把更差的样本一并考虑</u>

### 8.2 <u>Decision Theory</u>

##### Hypothesis

- $H_0$: 和Fisher Test相同的Null hypothesis (和要证明的相反)
- $H_1$: Alternative hypothesis (如果$H_0$被reject了就接受$H_1$)

##### Error

Test的有效性 ($\alpha$和$\beta$都要尽量低)

- $\alpha$ (Type1 Error 和Fisher相同,但是会被固定): 
  - 错误reject$H_0$的概率 $P[\neg H_0|H_0^*]$
  - 通常需要$\alpha\leq 5\%$
- $\beta$ (Type2 Error): 
  - 错误reject$H_1$的概率  $P[H_0|\neg H_0^*]$
  - 需要尽量小,但没有上限

##### Power

- Power: $1-\beta$:<u>正确接受$H_1$的概率</u>

- $\alpha,\beta,n,\delta, \sigma$的关系恒定
  $$
  n\approx\frac{(z_{\alpha/2}+z_\beta)^2\sigma^2}{\delta^2}
  $$

### 8.3 检验流程

##### 决策步骤

1. 给定

   | $\theta_0$     | $\alpha$         | $\delta$    | $\beta$                   |
   | -------------- | ---------------- | ----------- | ------------------------- |
   | 需要测试的参数 | (level) 通常是5% | $H_1$的范围 | 想要控制Type 2 Error rate |

2. 根据$\alpha$设定critical region式子中可能包含样本大小$n$

3. 根据$d=\frac{|\theta-\theta_0|}{\sigma}$在OC curve上寻找$n$和$\beta$的关系

4. 获取样本得到的结果,计算P-Value

   - 获得当前样本或者更差样本的概率

   - $P[D|H_0]$
   
5. P-Value$\leq\alpha$,就reject $H_0$并接受$H_1$

### 8.4 接受率分析

通过抽样调查判断样本中的缺陷率

##### 假设

- $H_0:n_d\leq n_0$缺陷率低
- $H_1: n_d>n_1$缺陷率高

##### 错误率

- $\alpha: P[H_1|H_0^*]$ 生产者风险(实际风险率没有样本这么高,消费者应该接受)
- $\beta:P[H_0|H_1^*]$ 消费者风险(实际风险率比样本高,消费者不应该接受)

# 9. 样本检验

### 9.1 单样本检验

##### 均值T-test

1. 计算样本均值$\bar X$和样本方差$S^2$
2. 判断$T_{n-1}=\frac{\bar{X}-\mu_0}{S/\sqrt{n}}$在T分布下出现的P-Value
3. 使用$d=\frac{|\delta|}{\sigma}$在OC曲线上查看$\beta$和$n$的关系

##### 方差 Chi-Square Test

1. <u>确认样本是否符合正态分布</u>
2. 计算样本方差$S^2$
3. 判断$\chi_{n-1}=\frac{(n-1)S^2}{\sigma_0^2}$出现的P-Value
4. 使用$\lambda=\frac{\sigma}{\sigma_0}$判断$\beta$和$n$的关系

##### 中位数测试

1. 给定$H_0$,假定中位数的关系$M_0$
2. 把所有符合$M_0$的样本标识为1,小于的标识为0
3. 计算标识为1的数量$I$
4. 通过二项分布计算P-Value$=P[Q<=I]$

##### Rank Test

1. 给定$H_0$,假定特定rank数的关系$M_0$
2. 将大于$M_0$和小于$M_0$的数,使用全局排序分组求和得到
   - $W_+=\sum_{R_i>0}R_i$
   - $W_-=\sum_{R_i<0}|R_i$
3. 根据$W_+,W_{-}$和中位数得出的二项分布计算P-Value

##### 特征检验

1. 给定$H_0$,假定特征存在的概率$p_0$
2. 根据中心极限定理,样本$\frac{\hat{p}-p_0}{\sqrt{np(1-p)}}\sim(0,1)$
3. 因为$p$未知,所以必须要有足够大的$n$才可以用$\hat p$代替$p$
4. 给定$d$(可接受误差),得到样本大小$n=\frac{z_{\alpha/2}}{4d^2}$
5. 用$\hat p$计算P-Value

##### 多项分布检验 Pearson Test

对于$k$种情况的多项分布,则样本应符合$k-1$的Chi-Square分布

$\sum_i^k \frac{(X_i-np_i)^2}{np_i}\sim\chi_{k-1}^2$

##### 特征独立性检验

对于两种特征,分别有$c,r$种情况,如果独立则样本应符合$(r-1)(c-1)$的Chi-Square分布

$\chi_{(r-1)(c-1)}^2=\sum_{i=1}^r\sum_{j=1}^c\frac{(O_{ij}-E_{ij})^2}{E_{ij}}$

### 9.2 多样本检验

##### 检验均值差(已知方差)

1. 两个样本的均值各自服从正态分布 $\frac{\bar X-\mu}{\sigma^2/\sqrt n}\sim(0,1)$
2. 根据中心极限定理,做差后依然服从正态分布 $Z=\frac{\bar X_1-\bar X_2-(\mu_1-\mu_2)}{\sqrt{\sigma_1^2/n_1+\sigma_2^2/n_2}}\sim(0, 1)$
3. 给定$H_0: \mu_1-\mu_2=\mu_0$,并得到P-value
4. 使用$d=\frac{|\mu_1-\mu_2|}{\sqrt{\sigma_1^2+\sigma_2^2}}$在OC曲线上找到$\beta$和$n$的关系

##### F-Test(检验方差比值)

1. 确认两个样本都符合正态分布
2. 两个样本方差联合服从F分布 $F_{n_1-1,n_2-1}=\frac{S_1^2}{S_2^2}$
3. 给定$H_0:\frac{\sigma_1}{\sigma_2}$和$f_{\alpha,n_2-1,n_1-1}$的关系 (通常希望两者相等)
4. 使用$\lambda=\frac{\sigma_1}{\sigma_2}$判断在OC curve上样本大小和$\beta$的关系

##### Pooled T-test(未知方差检验均值差)

- 方差相等
  1. 使用F-Test检验方差相等
  2. 如果相等,则可以计算联合方差 $S_p^2=\frac{(n_1-1)s_1^2+(n_2-1)s_2^2}{n_1+n_2-2}$
  3. 相等,则两个方差的分布可以相加,构造$\chi_{n_1+n_2-2}=\frac{(n_1+n_2-2)S_p^2}{\sigma^2}$
  4. 带入$Z$可以生成$T$分布$t_{n_1+n_2-2}=\frac{\bar X_1-\bar X_2-(\mu_1-\mu_2)}{\sqrt{S_p^2(1/n_1+1/n_2)}}$
  5. 使用$d=\frac{|\mu_1-\mu_2|}{2\sigma}$在OC curve上寻找$\beta$和样本大小$n^*$的关系
  6. 因为$n^*$代表了两个样本,所以实际样本大小$n=(n^*+1)/2$
- 方差不等
  1. 计算自由度$\gamma=\frac{(S_1^2/n_1+S_2^2/n_2)^2}{\frac{(S_1^2/n_1)^2}{n_1-1}+\frac{(S_2^2/n_2)^2}{n_2-1}}$向下取整
  2. 构造$T$分布$t_\gamma=\frac{\bar X_1-\bar X_2-(\mu_1-\mu_2)}{\sqrt{S_1^2/n_1+S_2^2/n_2}}$

##### 特征检验

1. 用样本权重代替总比例 $\hat{p}=\frac{n_1\hat{p_1}+n_2\hat{p_2}}{n_1+n_2}$
2. 用$\hat p(1-\hat p)$代替方差$\sigma^2$,得到$Z=\frac{\hat p_1-\hat p_2}{\sqrt{\hat p(1-\hat p)(\frac{1}{n_1}+\frac{1}{n_2})}}$
3. 计算P-Value

# 10. 样本分布检验

### 10.1 拟合度检验(goodness of fit)

通过样本构造cdf: $F_n(x)=\frac{1}{n}\sum\mathbb I(X\geq x)\rightarrow F_X(x)$

把每个样本当做伯努利变量,则根据中心极限定理求和
$$
\sqrt n(F_n(x)-F_X(x))\sim(0, F_X(x)(1-F_X(x)))
$$
极端情况下方差为0 $x=\pm\infty\rightarrow F_X(x)(1-F_X(x))=0$

##### KS-Test (已知总体分布参数) 

1. 提出对于cdf的假设$H_0:F=F_0$
1.  <u>如果$F_0$是正态分布,则可以用估计值代替参数带入,否则必须用确定值</u>
2. 计算样本cdf和假设cdf之间的最大差$Z_n=\max\sqrt n|F_n(x)-F_0(x)|$ (<u>每个sample要上一个sample点计算两次</u>)
3. 计算$P[Z_n>q_\alpha|F_0]$

##### $\chi^2$ 检验

1. 给定模型分布假设$H_0: F=F_0$

2. 通过MLE获得参数估计值$\hat\theta$ (如果结果分布是连续的,可以通过分箱离散化)

3. 回带$\hat\theta$获得分布函数$p(\hat\theta)$并和样本分布$p$对比

4. 构造卡方分布 $K$是样本集,$d$是$\theta$的参数个数 (和多项分布Pearson检验类似)
   $$
   \chi^2_{K-d-1}=\sum^K_i\frac{O_i-E_i}{E_i}=\sum\frac{(\hat p_i-p_i(\hat\theta))^2}{p_i(\hat{\theta})}
   $$
   

### 10.2 ANOVA (多总体方差分析)

##### 基本定义

对于$k$个具有相同分布和方差的<u>总体</u>,判断是否有相同的均值

| $T_{i\cdot}$       | $\bar{Y_i\cdot}$   | $T_{\cdot\cdot}$ | $Y_{\cdot\cdot}$ | $\mu$          |
| ------------------ | ------------------ | ---------------- | ---------------- | -------------- |
| 每个总体样本的总和 | 每个总体样本的均值 | 所有样本的总和   | 所有样本的均值   | 总体均值的加权 |

假设总体均值之间的误差为$\alpha_i$,则$Y_{ij}=\mu_i+E_{ij}=\mu+\alpha_i+E_{ij}$

$H_0:\mu_1=\mu2\cdots\mu_k\rightarrow\alpha_1=\alpha_2=\cdots\alpha_k=0$

##### 误差分析

- 总误差: $SS_{Tot}=\sum_i^k\sum_j^{n_i}(Y_{ij}-Y_{\cdot\cdot})^2=SS_{Tr}+SS_E$
- 总体均值误差: $SS_{Tr}=\sum_{i}^kn_i(\bar{Y_i}-\bar Y_{\cdot\cdot})^2$ ($SSR$)
- 总体内误差: $SS_E=\sum_i^k\sum_j^{n_i}(Y_{ij}-Y_{i\cdot})^2$

如果总体均值差距很大,则$SS_{Tr}$应该明显大于$SS_E$

##### 估计值分布

- 总体内误差服从卡方分布
  - $\chi_{N-k}^2=\frac{SS_E}{N-k}$
  - $\frac{E[SS_E]}{N-k}=\sigma^2$
- $H_0$成立时,总体均值误差分布
  - $\chi_{k-1}^2=\frac{SS_{Tr}}{\sigma^2}=\frac{(k-1)MS_E}{\sigma^2}$

##### F检验

如果$H_0$成立,则均方误差之间服从$F$分布
$$
F_{k-1,N-k}=\frac{SS_{Tr}/(k-1)}{SS_E/(N-k)}
$$

##### 方差检验

计算$B$和$Q$服从$\chi_{k-1}^2$分布
$$
\chi_{k-1}^2=\frac{(N-k)\ln MS_E-\sum_i^k(n_i-1)\ln S_i^2}{1+\frac{1}{3(k-1)}(\sum_i^k)\frac{1}{n_i-1}-\frac{1}{N-k}}
$$

##### 均值检验

类似Pooled T-test,但是使用$MS_E$作为方差
$$
T_{N-k}=\frac{\bar Y_{i\cdot}-\bar Y_{j\cdot}}{\sqrt{MS_E(\frac{1}{n_i}+\frac{1}{n_j})}}
$$
T-test一次只能对比两个总体,因此全局对比的$\alpha'=1-(1-\alpha)^m$



