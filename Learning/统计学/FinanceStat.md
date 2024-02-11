- [1. Preliminaries](#1-preliminaries)
    - [1.1 收益率](#11-收益率)
        - [收益率](#收益率)
        - [分红收益率](#分红收益率)
        - [随机游走](#随机游走)
    - [1.2 Tail Probabilities](#12-tail-probabilities)
        - [Tail Probability](#tail-probability)
        - [Heavy Tail](#heavy-tail)
    - [1.3 Value at Risk (VaR)](#13-value-at-risk-var)
        - [风险资产 (VaR)](#风险资产-var)
    - [1.4 Expected Shortfall (ES)](#14-expected-shortfall-es)
        - [Shortfall Distribution](#shortfall-distribution)
        - [Expected Shortfall](#expected-shortfall)
- [2. Distribution Inference](#2-distribution-inference)
    - [2.1 Density Estimation](#21-density-estimation)
        - [Kernel-Based Estimation](#kernel-based-estimation)
        - [Bandwidth $b$](#bandwidth-b)
        - [Kernel-Based Estimation Property](#kernel-based-estimation-property)
    - [2.2 Test of Normality](#22-test-of-normality)
        - [Shapiro-Wilk test](#shapiro-wilk-test)
        - [Jarque-Bera](#jarque-bera)
    - [2.3 Pareto Distribution Property](#23-pareto-distribution-property)
        - [General Pareto Distribution](#general-pareto-distribution)
        - [Pickands-Balkema-de-Hann Theorem](#pickands-balkema-de-hann-theorem)
    - [2.4 Tail Estimation](#24-tail-estimation)
        - [Overview](#overview)
        - [估计流程](#估计流程)
        - [多变量Tail Dependence](#多变量tail-dependence)
- [3. Portfoilo Management](#3-portfoilo-management)
    - [3.1 Portfoilo基本性质](#31-portfoilo基本性质)
        - [双资产管理](#双资产管理)
        - [Copula模型应用](#copula模型应用)
    - [3.2 风险资产模型](#32-风险资产模型)
        - [定义](#定义)
        - [风险资产收益率/方差估计](#风险资产收益率方差估计)
    - [3.3 模型最优化](#33-模型最优化)
        - [无风险资产混合投资](#无风险资产混合投资)
        - [最大化Portfolio夏普比率流程](#最大化portfolio夏普比率流程)
    - [3.4 混合资产定价模型 (CAPM)](#34-混合资产定价模型-capm)
        - [Capital Market Line(CML)](#capital-market-linecml)
        - [$\\beta$和Security Market Line (SML)](#beta和security-market-line-sml)
        - [资产收益率拟合](#资产收益率拟合)
    - [3.5 风险分析](#35-风险分析)
        - [风险计算](#风险计算)
        - [Portfoilo风险](#portfoilo风险)
    - [3.6 三因子模型](#36-三因子模型)
        - [模型定义](#模型定义)
        - [计算流程](#计算流程)
- [4. ARCH (Augo-Regressive Conditional Heteroskedasticity)](#4-arch-augo-regressive-conditional-heteroskedasticity)
    - [4.1 ARCH模型](#41-arch模型)
        - [定义](#定义-1)
        - [性质](#性质)
        - [参数估计](#参数估计)
    - [4.2 GARCH模型](#42-garch模型)
        - [定义](#定义-2)
        - [Garch(1,1)](#garch11)
        - [Half-Life of Volatility](#half-life-of-volatility)
    - [4.3 GARCH模型变种](#43-garch模型变种)
        - [结合ARMA模型生成的综合模型](#结合arma模型生成的综合模型)
        - [APARCH Model](#aparch-model)
- [5. Stochastic Volatility](#5-stochastic-volatility)
    - [5.1 模型定义](#51-模型定义)
        - [特点](#特点)
        - [优点](#优点)
        - [缺点](#缺点)
    - [5.2 Teh Volatility Model](#52-teh-volatility-model)
        - [定义](#定义-3)
        - [性质](#性质-1)
    - [5.3 Breto Model](#53-breto-model)
    - [5.4 Hetson Model](#54-hetson-model)
- [6. Arbitrage](#6-arbitrage)
    - [6.1 Basic Idea](#61-basic-idea)
        - [Assumption](#assumption)
        - [风险](#风险)
    - [6.2 资产间套利(Co-Integration)](#62-资产间套利co-integration)
        - [双资产套利](#双资产套利)
        - [多资产套利](#多资产套利)
    - [6.3 跨期套利](#63-跨期套利)

# 1. Preliminaries

### 1.1 收益率

##### 收益率

在收益率很小的情况下,$R_t$和$r_t$非常接近,且$r_t$始终小于$R_t$

- 净收益率 $R_t=\frac{P_t}{P_{t-k}} - 1=e^{r_t}-1$
- 对数收益率 $r_t=\ln\frac{P_t}{P_{t-k}}=\ln(1+R_t)=\ln P_t-\ln P_{t-k}$

##### 分红收益率

本质上就是在当日价格之上添加分红金额

- 分红收益率 $R_t=\frac{P_t+D_t}{P_{t-1}}$
- 分红对数收益率$r_t=\ln\frac{P_t+D_t}{P_{t-1}}$

##### <u>随机游走</u>

- 使用对数收益率,且每个节点的收益率符合i.i.d

- 用中心极限定理,可以得<u>到区间对数收益率分布</u>
  $$
  r_t(k)=\sum_{i=1}^k r_t\sim N(\sum\mu_t, (\sum\sigma_t)^2)
  $$

  - $\mu_t$: $t$时刻的漂移 

- 几何随机游走: 带入区间收益率可以得到价格的分布
  $$
  P_t=P_0\exp(r_t(k))
  $$

### 1.2 Tail Probabilities

##### Tail Probability

给定$x$,随机变量大于$x$的概率(描述了风险)

- $P[X\geq x]=1-F(x)=\int_x^\infty f(x)\mathrm{d}x$
- 通常和指数分布比较,是否是heavy tail

##### Heavy Tail

Tail定义了特殊分布在<u>极端值时出现的概率</u>,如果概率比<u>指数分布</u>大,则为heavy tail
$$
\int_{-\infty}^{\infty}e^{\beta x}\mathrm dF(x)=\infty\quad \text{for all}\quad \beta>0\rightarrow\lim_{x\rightarrow\infty}\frac{\text{Pr}[X>x]}{\text{Pr}[X_{\text{exp}>x}]}=\infty\quad\text{for all}\quad \beta>0
$$

- 通过Q-Q Plot来比较真实数据分布的tail和理想分布
- $f(x)\rightarrow0$的速度,决定了tail的厚度, 多项式tail>指数tail>正态分布tail

### 1.3 <u>Value at Risk (VaR)</u>

##### <u>风险资产 (VaR)</u>

<u>描述了暴露在给定风险下亏损的资产量下限(只有$q$概率亏损超过 VaR$_t$)</u>

| $t$  | $P_t$        | $q$      | $F$        |
| ---- | ------------ | -------- | ---------- |
| 时间 | $t$ 时刻资产 | 亏损概率 | 收益率分布 |

- <u>Absolute VaR</u>
  $$
  \text{P}[\text{VaR}_t<P_t-P_{t+\bigtriangleup t}]=q
  $$

- <u>Relative VaR</u>
  $$
  \text{P}[R_t<-\tilde{\text{VaR}}_t]=q
  $$

  - 本质上是<u>收益率分位数的相反数,亏损率的逆分位数</u>
  - $\tilde{\text{VaR}}=\frac{\text{VaR}}{P_t}$

### <u>1.4 Expected Shortfall (ES)</u>

##### Shortfall Distribution

<u>给定资产分布,描述了亏损超过$\text{VaR}_q$时的分布</u>
$$
\Theta_{X_q}(x)=\text{P}[-X\leq x|X\leq-\text{VaR}_q]=\frac{q-F(-x)}{q}
$$
当收益率分布对称时,$F(-x)=1-F(x)$,则有$F_{X_q}=\frac{F(x)-(1-q)}{q}$

##### <u>Expected Shortfall</u>

<u>描述了当亏损超过$\text{VaR}_q$时,期望的亏损值</u>
$$
ES_q=E[-X|X\leq-\text{VaR}_q]=-\frac{1}{q}\int_{x<-\text{VaR}_q}xf(x)\mathrm d x
$$

- 对于正态分布,有$ES_q=\mu+\sigma\cdot\frac{f[F^{-1}(q)]}{q}$
- 对于拉普拉斯分布,有$ES_q=-\mu+\frac{1}{\lambda}(1-\ln2q)$
- 对于帕累托分布,有$ES_q=\mu+\sigma[\frac{(1-q)^{-1/\alpha}}{1-1/\alpha}+\alpha((1-q)^{-1/\alpha}-1)]$

# 2. Distribution Inference

### 2.1 Density Estimation

##### Kernel-Based Estimation

- 给定若干个离散样本$x_i$,构造平滑分布
  $$
  \hat f_b(x)=\frac{1}{n}\sum_{i=1}^nK_b(x-x_i)
  $$

- $K_b$: kernel function,<u>可以是任何density function,方差必须是1</u>

- 本质上是样本的平滑分布,$b$越大,越平滑

##### Bandwidth $b$

- 描述了平滑分布对于离散样本信息的利用程度
- $b$越大,拟合离$K_b$分布越接近,越平滑
- $b$越小,拟合离样本分布越接近,但容易过拟合

##### Kernel-Based Estimation Property

- 期望: $E[\hat f_b(x)]=\frac{1}{n}\sum_{i=1}^n E[K_b(x-x_i)]$
  - 如果$x_i$是iid则有$E[\hat f_b(x)]=(K_b*f)(x)$

- 方差: $Var[\hat f_b(x)]=\frac{1}{n}\sum_{i=1}^n Var[K_b(x-x_i)]$

### 2.2 Test of Normality

##### <u>Shapiro-Wilk test</u>

- 关注分布的Tail,适合金融数据使用

- 将样本从小到大排序,构造$x_1,x_2,\cdots x_n$

- 基于$x$构造协方差矩阵$V$

- 基于$x$构造期望向量$m=\begin{bmatrix}m_1&m_2\cdots m_n\end{bmatrix}$
  $$
  W=\frac{(m^TV^{-1}x)^2}{\sum(x_i-\bar x)^2(m^TV^{-1}V^{-1}m)}
  $$

- 通过蒙特卡洛模拟来检验

##### Jarque-Bera

- 通过样本的偏度$S$和峰度$K$来构造参数检验
  $$
  JB=\frac{n}{6}(S^2+\frac{(K-3)^2}{4})\sim\chi^2_2
  $$

- $JB$值越偏离$\chi^2_2$,说明样本正态分布的概率越小

### 2.3 Pareto Distribution Property

##### General Pareto Distribution

| 参数                | 随机变量$X$         | PDF                                                          | CDF                                                   | 期望                            | 方差                                          |
| ------------------- | ------------------- | ------------------------------------------------------------ | ----------------------------------------------------- | ------------------------------- | --------------------------------------------- |
| $\alpha,x_m,\sigma$ | 和最低值$x_m$的比值 | $f_X(x)=\frac{1}{\sigma}(1+\frac{x-x_m}{\alpha\sigma})^{-\alpha - 1}$ | $F_X(x)=1-(1+\frac{(x-x_m)}{\alpha\sigma})^{-\alpha}$ | $x_m+\frac{\sigma}{1-1/\alpha}$ | $\frac{\sigma^2}{(1-1/\alpha)^2(1-2/\alpha)}$ |

帕累托分布具有<u>特别厚的多项式尾部</u>,适合用来估计条件概率

##### <u>Pickands-Balkema-de-Hann Theorem</u>

- 对于绝大部分分布$f(x)$的条件概率分布,都可以转化为帕里托分布,具有polynominal tail
  $$
  1-F(x)=P[X>u+x|X>u]=\frac{P[X>u+xa(u)]}{P[X>u]}\rightarrow (1+\frac{x}{\alpha})^{-\alpha}\quad(u\rightarrow\infty)
  $$

- 很难计算$a(u)$的值,但是可以用QQ plot判断是否符合Pareto Distribution并分析tail

### 2.4 <u>Tail Estimation</u> 

##### Overview

- KDE不适合估计Tail的分布,因为缺少数据

- 使用条件概率来估计Tail分布
  $$
  P[X\geq x]=P[X\geq x|X\geq x_m]P[X\geq x_m]
  $$

- 使用KDE估计$P[X\geq x_m]$的值,使用Pareto估计$P[X\geq x|X\geq x_m]$

##### 估计流程

1. Plot ECDF分布的Tail (只能使用daily return而不是log return)
2. 使用shape plot画出GPD的$\hat\xi$和threshold $u$的关系
3. threshold要尽量大,但是shape parameter要尽量稳定
4. 通过Tail plot检验threshold选取的质量
5. 计算$\tilde{VaR_q}=GPD^{-1}[1-\frac{q}{1-ECDF(x_m)}]$
6. 基于GPD期望的性质,可以得到$ES=\tilde{VaR_q}+\frac{\hat\sigma+\hat\xi(\tilde VaR_q-x_m)}{1-\hat\xi}$

##### 多变量Tail Dependence

- Lower Dependency (描述左下角): $\lambda_l=\lim_{q\rightarrow0}P[F_1(X_1)\leq q|F_2(X_2)\leq q]$
- Upper Dependency (描述右上角): $\lambda_u=\lim_{q\rightarrow 1}P[F_1(X_1)\geq q|F_2(X_q)\geq q]$
- Gaussian Copula: $\lambda_u=\lambda_l=0$
- T-Copula: $\lambda_u=\lambda_l=2F_{t,\nu+1}[-\sqrt{\frac{(\nu + 1)(1-\rho)}{1+\rho}}]$

# 3. Portfoilo Management

### 3.1 Portfoilo基本性质

##### 双资产管理

给定双资产组成的Portfolio $V=n_1P_1+n_2P_2$

- 权重向量$w=\begin{bmatrix}\frac{n_1P_1}{n_1P_1'+n_2P_2'}&\frac{n_2P_2}{n_1P_1'+n_2P_2'}\end{bmatrix}$

- 收益率$R=\frac{V'}{V}=\frac{n_1P_1'+n_2P_2'}{n_1P_1+n_2P_2}$,通过$R$来计算$VaR$和Expected Shortfall

- 对于双资产Portfolio $V=wR_1+(1-w)R_2$,则<u>通过分散投资不相关资产来最小化风险</u>
  $$
  w=\frac{\sigma^2_2-\rho_{12}\sigma_1\sigma_2}{\sigma_1^2+\sigma_2^2-2\rho_{12}\sigma_1\sigma_2}
  $$

##### <u>Copula模型应用</u>

1. 对每个asset估计marginal distribution $\hat F_P$
2. 使用QQ plot判断$\hat F_p$的估计准确度,注意tail
3. 计算asset之间的spearman相关系数
4. 用$\hat F_p$生成概率并带入copula模型

5. 绘制copula的等高线,分析估计质量
6. 从copula生成模拟数据,并获得不同权重时的$VaR$


### 3.2 风险资产模型

##### 定义

| 资产收益率向量                                  | 资产收益率期望                                         | 收益率协方差矩阵       |
| ----------------------------------------------- | ------------------------------------------------------ | ---------------------- |
| $R=\begin{bmatrix}R_1\cdots R_N\end{bmatrix}^T$ | $E[R]=\begin{bmatrix}\mu_1\cdots \mu_N\end{bmatrix}^T$ | $\text{Cov}(R)=\Sigma$ |

已知上述条件,找到最合适的权重向量$W=\begin{bmatrix}w_1\cdots w_N\end{bmatrix}^T$在收益率最大的情况下最小化风险

- 最小化标准差: $\min w^T\Sigma w$
- 最大化收益率: $w^T\mu=\mu^*$
- 权重和为1: $w^TI=1$
- 可能还有分散投资,不能做空等附加条件
- 生成的结果为<u>有效边界: 在固定资产的方差$\sigma$的情况下,可以获得的最大收益$\mu$</u>

##### 风险资产收益率/方差估计

- 使用经验数据对资产间的收益率和协方差进行估计,但是<u>会引入bias</u>
- 使用Bootstrap对样本收益率,方差和最优夏普率进行估计,置信区间是$[2\hat\theta-q_U,2\hat\theta-q_L]$ 

### 3.3 模型最优化

##### 无风险资产混合投资

- 在资产组合中引入了收益率为$\mu_f$的无风险资产
- 需要最大化夏普比率:描述了额外收益$E(R)-\mu_f$和风险$\sigma$的比值,<u>最大化夏普比率等于寻找切线</u>

$$
\frac{E(R)-\mu_f}{\sigma}
$$

- 令风险资产权重为$w$则有
  - 收益率$\mu=\mu_f+w(\mu_p-\mu_f)$
  - 方差$\sigma=w\sigma_p$

##### <u>最大化Portfolio夏普比率流程</u>

1. 根据无风险资产收益率$\mu_f$,最大化风险资产的夏普比率
   $$
   w_T=\frac{v_1\sigma_2^2-v_2\rho_{12}\sigma_1\sigma_2}{v_1\sigma_2^2+v_2\sigma_1^2-(v_1+v_2)\rho_{12}\sigma_1\sigma_2}\quad(v_1=\mu_1-\mu_f,v_2=\mu_2-\mu_f)
   $$

2. 根据$w_T$获得风险资产标准差$\sigma_T,\mu_T$

3. 根据给定的风险/收益率约束,获得风险资产占比
   - 给定风险约束,则风险资产总占比权重 $w=\frac{\sigma_{target}}{\sigma_T}$
   - 给定收益率目标,则获得风险资产总比权重$w=\frac{\mu_{target}-\mu_f}{\mu_T-\mu_f}$

4. 每个风险资产的比重为$w\cdot w_T$

### 3.4 <u>混合资产定价模型 (CAPM)</u>

##### Capital Market Line(CML)

- 通过无风险收益率和波动率描述资产收益率

- 说明了夏普率相等,即增加风险资产配比时,超额收益永远和风险成正比
  $$
  \mu_R=\mu_f+\frac{\mu_M-\mu_f}{\sigma_M}\sigma_R\leftrightarrow\frac{\mu_M-\mu_f}{\sigma_M}=\frac{\mu_R-\mu_f}{\sigma_R}
  $$

- 给定$\text{VaR}_q$和收益率$\mu_m$的$q$分位数获得配比资产$w$
  $$
  P((1-w)\mu_f+w\mu_m\leq-\tilde{VaR}_q)=q\\
  P(\mu_m\leq\frac{(w-1)\mu_f-\tilde{VaR}_q}{w})=q\\
  w=\frac{\tilde{VaR}_q+\mu_f}{\mu_f-\Phi_q}
  $$

##### $\beta$和Security Market Line (SML)

- 对于任意资产,$\beta_R$的定义和估计值分别有
  $$
  \beta_R=\frac{\text{Cov}(R,R_M)}{\sigma_M^2}
  $$

- 通过$\beta$可以给任意资产定义Security Market Line: $\mu_R-\mu_f=\beta_R(\mu_M-\mu_f)$

- 通过对数据做线性回归,可以估计$\hat\beta_R$,并带入到SML中估计收益率
  $$
  \hat\beta_R=\frac{\sum_{t=1}^T(R_t-\bar R)(R_{Mt}-\bar R_M)}{\sum_{t=1}^T(R_{Mt}-\bar R_M)^2}
  $$

- 和1做对比$\beta_R$越大,则风险越高

##### 资产收益率拟合

- 通过线性回归,可以对$i$资产收益率进行拟合
  $$
  \mu_i-\mu_f=\alpha_i+\beta_i(\mu_m-\mu_f)+\epsilon_i
  $$

- 在CAPM假设成立的情况下,$\alpha_i$应该为0,如果$\alpha_i$大于0,则说明$\mu_i$被低估了
- 通过分析$\beta_i$的$R^2$,可以验证收益率的来源是市场还是误差

### 3.5 风险分析

##### 风险计算

- 对于资产$i$,则有$\sigma_i^2=\beta_i^2\sigma_M^2+\sigma_\epsilon^2$
  - 市场系统性风险: $\beta_i^2\sigma_M^2$,可以通过对冲减少
  - 非市场风险: $\sigma_\epsilon^2$,可以通过分散投资减少
- 对于市场协方差,则有$\sigma_{iM}^2=\beta_i\sigma_M^2$
- 对于任意资产$i,j$则有$\sigma_{ij}^2=\beta_i\beta_j\sigma^2_M$

##### Portfoilo风险

- 给定权重为$w$的portoilo,则可以重新计算风险
- $\beta_P=\sum_{i=1}^Nw_i\beta_i$
- 通过分散投资减少非市场风险: $\epsilon_P^2=\sum_{i=1}^Nw_i\epsilon_i^2$

### 3.6 三因子模型

##### 模型定义

- 通过添加其他参数作为回归项,来解释标的的收益率

$$
\mu_i-\mu_f=\alpha_i+\beta_{i1}(\mu_m-\mu_f)+\beta_{i2}\cdot \text{SMB}+\beta_{i3}\cdot\text{HML}+\epsilon_i
$$

- $\text{SMB}$: 小市值公司收益率更高
- $\text{HML}$: 低市净率的公司收益率更高

##### 计算流程

1. 根据流通市值,将标的分成1:1的大市值(B)和小市值(S)组
2. 根据BM(市净率倒数)数据将标的按照3:4:3分成(H/M/L)三组
3. 通过市值加权计算每组中的平均收益率
4. 通过收益率计算因子
   - $\text{SMB}=\frac{1}{3}(\mu_{SL}+\mu_{SM}+\mu_{SH})-\frac{1}{3}(\mu_{BL}+\mu_{BM}+\mu_{BH})$
   - $\text{HML}=\frac{1}{2}(\mu_{SH}+\mu_{BH})-\frac{1}{2}(\mu_{SL}+\mu_{BL})$

# 4. ARCH (Augo-Regressive Conditional Heteroskedasticity)

### 4.1 ARCH模型

##### 定义

- $X_n$是误差大小$\sigma_n$和白噪音$\epsilon_n$的乘积 $X_n=\sigma_n\epsilon_n$
- $\epsilon_n\sim N(0,1)$,因此$E(\epsilon^2)=1$
- $\sigma_n$是时间序列数据,决定了误差的绝对值 $\sigma_n^2=\alpha_0+\sum_{j=1}^p\alpha_jX_{n-j}^2$ $\alpha_0>0,\alpha_j\geq 0$
- $\epsilon_n$是均值为0,方差为1的白噪声
- $\alpha_0$决定了$X_n$的下界

##### 性质

- 自激发:当前$X_n$较大时,之后的$X_{n+p}$都容易较大
- 令$V_n=\sigma_n^2(\epsilon_n^2-1)$则有$E[V_n]=0$,且<u>$V_n$是白噪音</u>
- 根据定义$X_n^2=(\alpha_0+\sum_{i=1}^p\alpha_iX_{n-i}^2)\epsilon_n^2=\alpha_0+\sum_{i=1}^p\alpha_iX_{n-i}^2+V_n$ ,<u>因此$X_n^2$是AR(p)过程</u>
- 当$n\rightarrow\infty$,可以得到$E[X_n^2]=\frac{\alpha_0}{1-\sum_{i=1}^p\alpha_i}$

##### 参数估计

- MLE估计太困难,因此使用condition MLE来估计$\alpha_j$的值

- 对于$X_n=\sqrt{\alpha_0+\sum_{i=1}^p\alpha_iX_{n-i}^2}\epsilon_n$,服从均值为$0$,方差为$\alpha_0+\sum_{i=1}^p\alpha_iX_{n-i}^2$的正态分布,因此可以用来计算似然函数,并对参数进行估计
  $$
  L(\alpha_0,\alpha_1|x)=-\frac{1}{2}\sum_{j=p+1}^n\log ^{}[2\pi(\alpha_0+\sum_{i=1}^p\alpha_iX_{j-i}^2)]-\frac{1}{2}\sum_{j=p+1}^n\frac{X_j^2}{\alpha_0+\sum_{i=1}^p\alpha_iX_{j-i}^2}
  $$
  
- 通过最大化所有项的$f$可以得到对$\alpha$的估计值

### 4.2 <u>GARCH模型</u>

##### 定义

- 给$X_n$添加了均值,$X_n=\mu_n+\sigma_n\epsilon_n$

- 误差绝对值由之前的两项组成,包括了之前的波动率项
  $$
  \sigma_n^2=\alpha_0+\sum_{i=1}^p\beta_i\sigma_{n-i}^2+\sum_{j=1}^q\alpha_j (X_{n-j}-\mu_{n-j})^2
  $$
  
- 可以更好地处理Heavy Tail问题

##### <u>Garch(1,1)</u>

- 实际应用最常见,且通常先去除均值$\mu$

- Garch(1,1)中$X_n^2$服从<u>ARMA(1,1)模型</u>,且残差是$V_n=\sigma_n^2(\epsilon_n^2-1)$的白噪声,$\alpha_1+\beta_1$是会决定波动率性质
  $$
  X_n^2=\sigma_n^2\epsilon_n^2=\sigma_n^2+V_n=\alpha_0+\alpha_1\sigma_{n-1}^2+\beta_1X_{n-1}^2+V_n=\alpha_0+(\alpha_1+\beta_1)\sigma_n^2-\beta_1V_{n-1}+V_n\\
  \sigma_{X_n^2}=\frac{1+\beta_1^2-2(\alpha_1+\beta_1)\beta_1}{1-(\alpha_1+\beta_1)^2}\sigma_\epsilon^2\\
  \rho(h)=(\alpha_1+\beta_1)^{|h|-1}\frac{\alpha_1[1-(\alpha_1+\beta_1)\beta_1]}{1+\beta_1^2-2(\alpha_1+\beta_1)\beta_1}
  $$

- 当时间序列趋向于无穷时,方差会收敛于特定值
  $$
  \sigma_\infty^2\rightarrow\frac{\alpha_0}{1-\alpha_1-\beta_1} (\alpha_1+\beta_1<1)
  $$

- 给定$n$时刻的$\sigma$,则可以估计$h$时刻后的$\sigma_{n+h}$期望 ($\alpha_1+\beta_1$)决定了偏向$\sigma_n^2$还是$\sigma_\infty^2$
  $$
  E(\sigma_{n+h}^2|\sigma_{1:n})=\sigma_\infty^2+(\alpha_1+\beta_1)[E(\sigma_{n+h-1}^2)-\sigma_\infty^2]=(\alpha_1+\beta_1)^{h-1}\sigma_n^2+[1-(\alpha_1+\beta_1)^{h-1}]\sigma_\infty^2
  $$

##### Half-Life of Volatility

- 波动率之差恢复到之前一半的耗时$k$
  $$
  |E(\sigma_{n+k}^2|\sigma_{1:n})-\sigma_\infty^2|\leq\frac{1}{2}|\sigma_{n+1}^2-\sigma_\infty^2|
  $$

- 对于Gacrh(1,1),可以通过带入预测式求解$(\alpha_1+\beta_1)^{k-1}\leq\frac{1}{2}$
- $\alpha_1+\beta_1$越大,说明作用持续时间越久,衰减期越长

### 4.3 GARCH模型变种

##### <u>结合ARMA模型生成的综合模型</u>

- 观测值服从ARMA模型$X_n=\sum_{i=1}^p\psi_i X_{n-i}+\sum_{j=1}^q\phi_j\epsilon_{n-j}+\epsilon_n$ (通常只有AR部分)
- 残差波动服从Garch模型$\epsilon_n=\sigma_n\delta_n,\sigma_n^2=\alpha_0+\sum_{i=1}^p\alpha_i\sigma_{n-i}^2+\sum_{j=1}^q\beta_j\epsilon_{n-j}^2$
- 分步估计法: 先用ARMA模型拟合,再用Garch模型拟合残差,结果可能不准确,但泛化能力更强
- 联合估计法: 直接估计所有参数,理论上更准确,但结果鲁棒性不强

##### APARCH Model

- 模型定义
  $$
  \sigma_t^\delta=\alpha_0+\sum_{i=1}^p\alpha_i(|X_{t-i}|-\gamma_iX_{t-i})^\delta+\sum_{j=1}^q\beta_j\sigma_{t-j}^\delta
  $$

- $\delta$: power parameter,决定了波动率的幂,对于GARCH来说是2
- $\gamma$: leverage parameter,<u>决定了模型的不对称性</u>,对于GARCH来说是0

# 5. Stochastic Volatility

### 5.1 模型定义

##### 特点

- 波动率是随机的,和表现出来的收益率无关,即$\sigma$不会再由$X$决定
- 通常使用马隐模型中的隐状态和显状态来描述模型
- 使用MCMC采样来获得模型的似然函数

##### 优点

- 可以描述更多更复杂的波动率表现
- 估计准确度高,似然函数大

##### 缺点

- 参数更多,模型更复杂,稳定性可能不好
- 计算困难,没有直接计算似然函数的方式

### 5.2 Teh Volatility Model

##### 定义

- $X_n$符合AR过程
  $$
  X_n=\alpha_0+\sum_{i=1}^p\alpha_1X_{n-i}+\epsilon_n
  $$

- 残差(白噪音)的波动率服从SV模型
  $$
  \epsilon=\sqrt{h_n}\delta_n\qquad \delta_n\sim N(0,1)\\
  \log(h_n)=\beta_0+\sum_{i=1}^p\phi_i\log(h_{n-i})+\sum_{j=1}^q\psi_j\nu_{n-j}+\nu_n
  $$

##### 性质

- $h_n$的对数服从ARMA(p,q)模型
- $h_n$不再由$X_{n-1}$或者$\epsilon_{n-1}$决定,而是使用新的独立随机项

### 5.3 Breto Model

### 5.4 Hetson Model

# 6. Arbitrage

### 6.1 Basic Idea

##### Assumption

- 找到价格平稳的资产组合
- 当价格过高或者过低时,根据均值回归,存在套利机会

- 有限时间内,总可以找到做空或者做多的机会

##### 风险

- 基本面风险: 当公司发生基本面变化时,价格不再平稳
- 流动性风险: 当发现套利机会时,却无法成交,或者成交成本很高
- 噪音风险: 可能因为散户等因素影响,导致套利逻辑失效
- 执行风险: 套利可能无法完美执行,受到交易时间差,滑点等因素影响

### 6.2 资产间套利(Co-Integration)

##### 双资产套利

- 对于时间序列$Y_1$和$Y_2$,可以找到$\lambda$使得$Y_1-\lambda Y_2$是平稳的
- 使用线性回归找到$\lambda$,<u>再通过Phillips-Ouliaris检验平稳性</u>

##### 多资产套利

- 给定$d$个资产$Y_t=\begin{bmatrix}Y_{1,t}&Y_{2,t}&\cdots&,Y_{d,t}\end{bmatrix}$
- 找到分配矩阵$A\in\R^{r\times d}$使得$X_t=AY_t^T$是平稳的
- 即矩阵自方差(Cross Auto Covariance) $\text{Cov}(X_t,X_{t+h})$只由$h$决定

### 6.3 跨期套利



