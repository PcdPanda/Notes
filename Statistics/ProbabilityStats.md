[toc]

<div STYLE="page-break-after: always;"></div>

# 1. 概率论基础概念

### 1.1 基本计数

##### 排列数 

- 相当于从$m$中取$n$个数,每次取1个不放回 $m*(m-1)*(m-2)\cdots(m-n+1)$
- $m$个数有$m$种排列

$$
P(m,n)=\frac{m!}{(m-n)!}
$$

##### 组合数

- 取$P(m,n)$种排列后,除以$P(n,n)$,因为这算同一种组合

- $C(m,n)=C(m-1,n-1)+C(m-1,n)$ 从$n-1$中取$m$个+从$n-1$取$m-1$个的方法数
  $$
  C(m,n)=\frac{m!}{n!(m-n)!}
  $$

##### 组合数分多组

- 将$m$个数分成$n_1,n_2\cdots n_k$种
- 先取$n_1$然后再连乘得到

$$
C(m, n_1, n_2,\cdots,n_k)=\frac{m!}{n_1!n_2!\cdots n_k!}
$$

### 1.2 概率空间和随机变量

##### 概率空间

- 样本空间 $S$: <u>互斥的各种情况组成的集合</u>

- $F$: 

  - $\sigma-field$: $S$​幂集的子集 
  - $\{a,b\}$​ 代表$a$​或$b$​​​的发生的情况
  - $S-\{a, b\}$ 代表$a$, $b$都不发生的情况

  例如 $F=\{\empty, \{1,2,3,4\}, \{1,2\}, \{3,4\}\}$

##### 单随机变量

- $P:S\rightarrow\mathbb{R}$​

  - 将样本空间映射到实数集
  - $P[A\cup B]=P[A]+P[B]-P[A\cap B]$
- 分布函数
  - 累积分布函数 (cdf) 表示$X<=x$的概率: 
    - 离散变量  $F_X(x)=P[x\leq X]=\sum_{i=0}^X f_X(x)$
    - 连续变量 $F_X(x)=P[x\leq X]=\int_0^X f_X(x)\mathrm{d}x$
  - 概率分布函数 (pdf) 表示$X=x$的概率: $f_X(x)=P[x=X]$

- 条件概率 

  - 相交的结果相同 $P[A\cap B]=P[A|B]\cdot P[B]=P[B|A]\cdot P[A]$


  - 条件概率拆分 $P[A]=P[A|B]+P[A|C]+P[A|D]+\cdots$


  - <u>代入得到贝叶斯定理</u>
    $$
    P[A|B]=\frac{P[B|A]\cdot P[A]}{P[B]}=\frac{P[B|A]\cdot P[A]}{P[B|A]\cdot P[A]+P[B|\neg A]\cdot P[\neg A]}
    $$


- 独立事件

  - 有没有条件都一样$P[A|B]=P[A]$

  - <u>同时发生的概率</u> $P[A\cap B]=P[A]\cdot P[B]$


##### 多随机变量

- 样本为向量$(X,Y,\cdots)$

- 概率密度函数

  - 多维: $f_{x,y}(x,y)=P[X=x\text{ and }Y=y]$

  - 单维:  $f_X(x)=\int_{-\infty}^{\infty} f_{x,y}(x,y)\mathrm{d}y$

- 条件概率和相关性

  - 条件概率 $f_{X|y}(x)=P[X=x|Y=y]=\frac{f_{X,Y}(x,y)}{f_Y(y)}$


  - 条件期望 $E[X|y]=\int x f_{X|y}(x)\mathrm{d}x$


  - 如果变量之间独立分布

    - 期望$E[X+Y]=E[X]+E[Y]$
      - 期望$E[XY]=E[X]E[Y]$
      - $f_{X,Y}(x,y)=f_X(x)f_Y(y)$


##### 随机变量相关性

- 协方差: $Cov[X,Y]=E[(X-E[X])(Y-E[Y])]=E[XY]-E[X]E[Y]$
- 相关系数 ($-1\leq \rho_{XY}\leq1$): 
  - $\rho_{XY}=\frac{Cov[X,Y]}{\sqrt{Var[X]Var[Y]}}$
  - <u>只能说明线性相关性</u>

### 1.3 贝叶斯统计

##### 基本概念

- 适合小样本
- 先验分布: 
  - 数据分布$P(D|\theta)$
  - 参数分布$p(\theta)$
    - 初始先验分布应该对于$\theta$没有偏见 (可以使用uniform distribution)
    - 如果无法积分为1(如果$\theta$的范围是一条直线),则是improper prior
- 后验分布: 
  - 先验分布+样本后$P(D|\beta)$更新得到的分布
  - 后验分布期望$\int\theta P(\theta|D)\mathrm{d}\theta$
- 贝叶斯置信范围: $P[\theta\in Reg|D]=1-\alpha$

##### 计算流程

1. 选取一个数据的分布模型$P(x|\theta)$
2. 选取一个参数的分布函数$p(\theta)$
3. 使用贝叶斯定理计算$\theta$后验分布

$$
P(\theta|D)=\frac{P(D|\theta)p(\theta)}{\int P(D|\theta)p(\theta)\mathrm{d}\theta}
$$

4. 如果更新后分布模型没变,只改变了参数,则模型是conjugate prior

##### Jeffrey prior

基于MLE和Fisher Information得到的先验分布

$p_J(\theta)\propto\sqrt{\det I(\theta)}$

### 1.4 偏离上限分布

##### 切比雪夫不等式

给定偏离上限.从方差定义出发,再通过不等式获得
$$
P[(X-\mu)>\sqrt{K}] <= \frac{\sigma^2}{K}
$$

##### 霍夫丁不等式

已知样本均值$\bar{X}$和数据的上下限范围$[a, b]$,可以给出数据分布的upper bound是正态分布
$$
P[|\bar{X}-\mu|\geq\varepsilon]\leq2e^{-\frac{2n\varepsilon^2}{(b-a)^2}}
$$

### 1.5 中心极限定理

##### 随机变量和<u>服从正态分布</u>

- 参数

  - $j$:随机变量个数, **12-20是最合理的**
  - $Y=X_1+X_2\cdots X_j$

- 分布
  $$
  Z=\frac{Y-\sum\mu_j}{\sqrt{\sum\sigma_j^2}}
  $$



- $E[Y]=\sum\mu$
- $Var[Y]=\sum\sigma_j^2$

##### 变量转换后依然服从正态分布

$$
Z=\frac{\sqrt{n}(g(X_n)-g(\mu))}{g'(\mu)^2\sigma^2}
$$

### 1.6 连续变量转换

$Y=g(X)$, $g$**必须是单调的**

$F_Y(y)=P[Y<=y]=P[X<=g^{-1}(y)]=F_x(g^{-1}(y))$

$f_Y(y)=\frac{\mathrm{d}F_y}{\mathrm{d}y}=\frac{\mathrm{d}F_Y}{\mathrm{d}x}\frac{\mathrm{d}x}{\mathrm{d}y}=f_X(g^{-1}(y))g^{-1}{'}$

### 1.7 Distribution Family

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

##### 常见分布的转换

| 分布名                  | 伯努利分布                         | 泊松分布                           | 正态分布                                                     |
| ----------------------- | ---------------------------------- | ---------------------------------- | ------------------------------------------------------------ |
| $f(x)$                  | $p^x(1-p)^{1-x}$                   | $\frac{\lambda^x}{x!}e^{-\lambda}$ | $\frac{1}{\sqrt{2\pi}\sigma}\exp(-\frac{1}{2}(\frac{x-\mu}\sigma)^2)$ |
| 化简后分布$f_\theta(x)$ | $\exp(x\ln\frac{p}{1-p}+\ln(1-p))$ | $\exp(x\ln\lambda-\lambda-\ln x!)$ | $\exp(\frac{\mu}{\sigma^2}x-\frac{x^2}{2\sigma^2}-\frac{\mu^2}{2\sigma^2}-\ln\sigma-\ln\sqrt{2\pi})$ |
| 转化后参数$\theta$      | $\ln\frac{p}{1-p}$                 | $\ln\lambda$                       | $\mu$                                                        |
| $\phi$                  | $1$                                | $1$                                | $\sigma^2$                                                   |
| $b(\theta)$             | $\ln(1+e^\theta)$                  | $e^\theta$                         | $\frac{\theta^2}{2}$                                         |
| $c(x,\phi)$             | $0$                                | $-\ln x!$                          | $-\frac{x^2}{2\sigma^2}-\ln\sigma-\ln\sqrt{2\pi}$            |

##### Canonical分布族特性

通过函数$b(\theta)$可以获得关于变量的重要特性

- $E[X]=b'(\theta)$
- $VAR[X]=b''(\theta)\phi$
- <u>因为方差恒大于0,所以$b'(\theta)$单调递增,且$b(\theta)$是凸函数</u>

<div STYLE="page-break-after: always;"></div>

# 2. 离散分布

### 2.1 伯努利变量

投一次硬币,正面概率为$p$

正面则$X=1$, 反面则$X=0$

| 参数 | 期望 | 方差     |
| ---- | ---- | -------- |
| $p$  | $p$  | $p(1-p)$ |

$$
f_X(1)=p\text{ (X=1反面)}\\
f_X(0)=1-p\text{ (X=0反面)}
$$

### 2.2 二项分布

投**$n$**次相同的硬币,正面概率为$p$

$X$ 记录正面的次数

| 参数  | 期望 | 方差      |
| ----- | ---- | --------- |
| $n,p$ | $np$ | $np(1-p)$ |

$$
f_X(x)=C_n^xp^x(1-p)^{(n-x)}
$$

### 2.3 几何分布

投相同的硬币,正面概率为$p$

$X$ 记录第<u>一次获得正面的</u>投币次数

| 参数 | 期望          | 方差              |
| ---- | ------------- | ----------------- |
| $p$  | $\frac{1}{p}$ | $\frac{1-p}{p^2}$ |

$$
f_X(x)=(1-p)^{x-1}p
$$

### 2.4 帕斯卡分布

投相同硬币,正面概率为$p$,**需要获得$r$次成功**

$X$记录需要获得$r$次成功的投币次数

| 参数  | 期望          | 方差                 |
| ----- | ------------- | -------------------- |
| $r,p$ | $\frac{r}{p}$ | $\frac{r(1-p)}{p^2}$ |

$$
f_X(x)=C_{r-1}^{x-1}p^r(1-p)^{x-r}
$$

### 2.5 超几何

在$N$个球中有$r$个红球,取$n$次球,其中的红球数量

当$N$很大时,近似二项分布 $\frac{r}{N}\approx p$

| 参数    | 期望           | 方差                                       |
| ------- | -------------- | ------------------------------------------ |
| $r,n,N$ | $n\frac{r}{N}$ | $n\frac{r}{N}\frac{N-r}{N}\frac{N-n}{N-1}$ |

$$
f_X(x)=\frac{C_r^xC_{N-r}^{n-x}}{C_N^n}
$$

### 2.6 泊松分布

经过$t$时间才第一次发生事件的概率是$k$,则$t$时刻内发生$X$次事件的概率

当$k$很小时泊松分布可以近似为二项分布, $k=p,t=n,\lambda=np$

| 参数              | 期望      | 方差      |
| ----------------- | --------- | --------- |
| $k,t(\lambda=kt)$ | $\lambda$ | $\lambda$ |

$$
f_X(x)=\frac{\lambda^x}{x!}e^{-\lambda}
$$

<div STYLE="page-break-after: always;"></div>

### 2.7 多项分布

类似于二项分布,但是每次结果不是非0即1,而是有$k$种可能性

这种情况下,每种结果有各自的期望

| 参数                    | 期望   | 方差          | 协方差     |
| ----------------------- | ------ | ------------- | ---------- |
| $n,k,p_1,p_2\cdots p_k$ | $np_i$ | $np_i(1-p_i)$ | $-np_ip_j$ |

$$
f_{X_1X_2\cdots X_k}(x_1,\cdots,x_k)=\frac{n!}{x_1!x_2!\cdots x_k!}p_1^{x_1}\cdots p_k^{x_k}
$$

<div STYLE="page-break-after: always;"></div>

# 3. 连续分布

### 3.1 <u>正态分布</u>

由多个独立变量决定的变量, 0.68, 0.95, 0.997的数据在1,2,3$\mu\pm\sigma$中

当$n$足够大时,正态分布和二项分布很相似

| 参数         | 期望  | 方差       |
| ------------ | ----- | ---------- |
| $\mu,\sigma$ | $\mu$ | $\sigma%2$ |

$$
f_X(x)=\frac{1}{\sqrt{2\pi}\sigma}e^{-\frac{1}{2}(\frac{x-\mu}{\sigma})^2}
$$

### 3.2 Gamma Distribution 

##### Gamma函数 

- $\Gamma(n)=\int_0^\infty t^{n-1}e^{-t}\mathrm{d}t=(n-1)\Gamma(n-1)=(n-1)!$

<u>beta分布和chi square分布的通式</u>

| 参数            | 期望          | 方差            |
| --------------- | ------------- | --------------- |
| $\alpha, \beta$ | $\alpha\beta$ | $\alpha\beta^2$ |

$$
f_{\alpha,\beta}(x) = \frac{1}{\Gamma(\alpha)\beta^\alpha}x^{\alpha-1}e^{-x/\beta}
$$

### 3.3 Weibull Distribution

描述风险率$\varrho(t)=\alpha\beta t^{\beta-1}$

$R(t)=e^{-\int_0^t\varrho(x)\mathrm{d}x}=e^{-at^{\beta}}$

$f(t)=\alpha\beta t^{\beta-1}e^{-\alpha t^\beta}$

| 参数            | 期望                                 | 方差                                       |
| --------------- | ------------------------------------ | ------------------------------------------ |
| $\alpha, \beta$ | $\alpha^{-1/\beta}\Gamma(1+1/\beta)$ | $\alpha^{-2/\beta}\Gamma(1+2/\beta)-\mu^2$ |

$$
f(x)=\alpha\beta x^{\beta-1}e^{-\alpha x^\beta}
$$

##### 可靠性分析

对于单个部件:

- 失败率$f$,在$t$时刻损坏的概率:

  ​	$f=\lim_{\bigtriangleup t\rightarrow0}\frac{P[t\leq X\leq t+\bigtriangleup t]}{\bigtriangleup t}=\frac{\mathrm{d}F}{\mathrm{d}t}$

- 可靠度$R$,到$t$时刻依然可用的概率

  $R(t)=1-\int_0^t f(t)\mathrm{d}t=1-F(t)$

- 风险率$\varrho(t),t$时刻前没损坏,且刚好在$t$时刻损坏的概率

  $\varrho(t)=\lim_{\bigtriangleup t\rightarrow0}\frac{P[t\leq X\leq t+\bigtriangleup t|t\leq X]}{\bigtriangleup t}=\frac{f(t)}{R(t)}=\frac{-R(t)'}{R(t)}$

### 3.4 指数分布

已知事件在单位时间内发生的概率是$\frac{1}{\beta}$,在$x$时刻第1次发生的概率, 通过泊松分布得到

相当于特殊情况下的gamma和weibull分布

| 参数                          | 期望    | 方差      |
| ----------------------------- | ------- | --------- |
| 参数 $\beta$(等同于$\lambda$) | $\beta$ | $\beta^2$ |

$$
f_X(x)=\frac{1}{\beta}e^{-x/\beta}
$$

##### <u>指数分布无记忆性</u>

$P[t\geq x]=e^{-x/\beta}\rightarrow P[t\geq K+x|t\geq K]=\frac{e^{-(x+K)/\beta}}{e^{-K/\beta}}=e^{-x/\beta}$

### 3.5 Chi-Square Distribution

描述$n$个标准正态分布变量<u>平方和的分布</u>,相当于$\alpha=n/2,\beta=2$的gamma 分布

卡方分布变量的和也服从卡方分布,但是自由度不一样

| 参数 | 期望 | 方差 |
| ---- | ---- | ---- |
| $n$  | $n$  | $2n$ |

$$
\chi_n^2=\sqrt{\sum Z^2}
$$

$$
f_{\chi_n^2}= \frac{1}{\Gamma(n/2)2^{n/2}}x^{n/2-1}e^{-x/2}
$$

### 3.6 T-Distribution

描述标准正态分布变量和$n$度卡方分布变量联合关系

| 参数     | 期望 | 方差                      |
| -------- | ---- | ------------------------- |
| $n$ | 0    | $\frac{n}{n-2}$ |

$$
T_n=\frac{Z}{\sqrt{\chi_n^2/n}}
$$

$$
f_{T_n}(t)=\frac{1}{\sqrt{2\pi}}\frac{2\sqrt{n}}{2^{n/2}n(n/2)}\int_0^{\infty}e^{-(t^2+n)y^2/2}(\sqrt n y)^{n-1}y\mathrm{d}y
$$

<div STYLE="page-break-after: always;"></div>

### 3.7 F-Distribution

描述两个不同自由度Chi-square Distribution变量的关系

| 参数                 | 期望                          | 方差                                                     |
| -------------------- | ----------------------------- | -------------------------------------------------------- |
| $\gamma_1, \gamma_2$ | $\frac{\gamma_2}{\gamma_2-2}$ | $\frac{\gamma_1-2}{\gamma_1}\frac{\gamma_2}{\gamma_2+2}$ |

$$
F_{\gamma_1,\gamma_2}=\frac{\chi_{\gamma_1}^2/\gamma_1}{\chi_{\gamma_2}^2/\gamma_2}\\
f_{\gamma_1,\gamma_2}(x)=\gamma_1^{\gamma_1/2}\gamma_2^{\gamma_2/2}\frac{\Gamma(\frac{\gamma_1+\gamma_2}{2})}{\Gamma(\frac{\gamma_1}{2})\Gamma(\frac{\gamma_2}{2})}\frac{x^{\gamma_1/2-1}}{(\gamma_1 x+\gamma_2)^{(\gamma_1+\gamma_2)/2}}
$$

<div STYLE="page-break-after: always;"></div>

# 4. 统计和参数估计

### 4.1 统计基础概念

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

### 4.2 置信区间和重要参数估计值

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

### 4.3 Max Likelihood Estimation (MLE)

##### 总变差TV (Total Variation)

- 描述了两个概率分布的差异 (不相交的面积)
- 对称且始终大于0
- $TV=\frac{1}{2}\int_{-\infty}^{\infty}|f(x)-g(x)|\mathrm{d}x$

##### KL散度

- 描述了两个概率分布熵的期望差,但是<u>不对称</u>
- $KL(f,g)=\int_{-\infty}^{\infty}f(x)\log\frac{f(x)}{g(x)}\mathrm{d}x\rightarrow E[\log f(x)]-E[\log g(x)]$

##### 似然函数 (Likelihood Function)

- 使用样本代替$KL$散度中的$g$,并用真实分布代替$f$,所以$E[log f(x)]$是个常数

  $KL(f,g)=c-\frac{1}{n}\sum\log g(x)$

- 最小化散度等效于最大化$\sum\log g(x)\rightarrow g(x_1)\cdot g(x_2)\cdots g(x_n)\rightarrow L(X_n;\theta)=\prod p(x;\theta)$

- <u>Fisher Information</u>: 
  - $I(\theta)=Var[(\log L(x;\theta))']=-E[(\log L(x;\theta))'']$
  - <u>定义了似然函数的峰度,越大说明MLE估计越准确</u>

##### 似然函数估计流程

1. 建立数据的分布模型即$g_\theta(x)$

2. 根据sample获得联合似然函数,如抛硬币获得结果为(正，正，反，正),则得到似然函数

   $L(X_1=1,X_2=1,X_3=0,X_4=1;p)=g_p(1)\cdot g_p(1)\cdot g_p(0)\cdot g_p(1)$

3. 对似然函数求对数后求导寻找最大值

   $\ln(L)=3\ln(p)+ln(1-p)$

   $\ln(L)'=\frac{3}{p}-\frac{1}{1-p}=0$

4. 导数为0获得极值

   $p=\frac{3}{4}$

5. <u>计算Fisher Information判断MLE的准确度,越大越准确</u>

   $I(\theta)=Var[(\log L(\theta))']=-E[(\log L(\theta))'']$

6. 极大似然估计值$\hat{\theta}$的分布

$$
\sqrt{n}I(\hat\theta)^{1/2}(\hat\theta-\theta)\sim(0,1)\\
n(\hat{\theta}-\theta)^TI(\hat\theta)(\hat{\theta}-\theta)\sim\chi_n^2
$$

### 4.4 Method of Moments

##### 矩量  (Moment)

- 矩量是围绕特定中心的次方值,<u>是个需要计算的常数</u>
  $$
  E[X^n, c]=\int_{-\infty}^{\infty}(x-c)^nf_X(x)\mathrm{d}x
  $$

- 通过<u>矩量母函数</u>计算原点矩$(c=0)$,本质上定义了随机变量的分布
  $$
  m_X(t)=E[e^{tX}]\rightarrow E[X^n]=\frac{\mathrm{d^n}m_X(t)}{\mathrm{d}t^n}|_{t=0}
  $$

- 期望 (一阶原点矩)

  - $E[X]=\int_{-\infty}^{\infty}xf_X(x)\mathrm{d}x$

- 方差 (二阶中心距)$\sigma^2=E[(x-E[X])^2]=E[X^2]-(E[X])^2$

##### WAT Theorem: 

- 任何连续函数可以用$N$阶多项式无限逼近

##### 计算流程

1. 根据模型得到moment和分布参数的关系式
   - $\psi^{-1}(m_1(\theta),m_2(\theta)\cdots)\rightarrow\theta$
   
2. 通过样本$n$,得到样本中的$k$个moment估计值$\hat{m}$

3. 回带估计值$\hat m$,计算得到参数估计值$\hat{\theta}$
   
   - $\hat m_n=[m_1(\hat\theta),m_2(\hat\theta),\cdots,m_k(\hat\theta)]$
   
   - $\psi^{-1}(\hat m_k)\rightarrow\theta$
   
4. $\hat\theta$的分布
   $$
   \sqrt{n}(\hat\theta_n-\theta)\sim N(0, [\bigtriangledown\psi^{-1}]^T Cov[\hat m_n][\bigtriangledown\psi^{-1}])
   $$

##### 配合MLE使用

1. 先使用Moment来找到合理的$\hat\theta$
2. 以$\hat\theta$出发,通过MLE在附近寻找局部最值,通常就是全局最值

<div STYLE="page-break-after: always;"></div>

# 5. 应用分析和检验

### 5.1 检验基本概念

##### Fisher Test

1. 提出需要reject的null hypothesis $H_0$ (例如全体的均值$\theta\geq\theta_0$)

2. **抽样并计算P-value**: 

   - 在给定$\theta\geq \theta_0$时获得sample的可能性 (**注意upper bound,不一定是样本,还有更糟糕的样本**)
   - 如果P-value比较低,则reject $H_0$
   - 本质上是用$P[D|H_0]$代替$P[H_0|D]$,但在$P[D]$**<u>概率很小的情况下非常不可靠</u>**

##### <u>Decision Theory</u>

- Hypothesis

  - $H_0$: Null hypothesis (和要证明的相反)
  - $H_1$: Alternative hypothesis (如果$H_0$被reject了就接受$H_1$)

- Test的有效性 ($\alpha$和$\beta$都要尽量低)

  - $\alpha$ (Type1 Error): 
    - 错误reject$H_0$的概率 $P[\neg H_0|H_0^*]$
    - 通常需要$\alpha\leq 5\%$
  - $\beta$ (Type2 Error): 
    - 错误reject$H_1$的概率  $P[H_0|\neg H_0^*]$
    - 需要尽量小,但没有上限
  - Power: $1-\beta$:正确接受$H_1$的概率

- $\alpha,\beta,n,\delta, \sigma$的关系恒定
  $$
  n\approx\frac{(z_{\alpha/2}+z_\beta)^2\sigma^2}{\delta^2}
  $$

### 5.2 检验流程

1. 给定

   - $\theta_0$:需要测试的参数
   - $\alpha:$ (level) 通常是5%
   - $\delta: H_1$的范围
   - $\beta:$ 想要控制Type 2 Error rate
2. 根据$\alpha$设定critical region式子中可能包含样本大小$n$
3. 根据$d=\frac{|\theta-\theta_0|}{\sigma}$在OC curve上寻找$n$和$\beta$的关系
4. 获取样本得到的结果,计算P-Value

   - 获得当前样本或者更差样本的概率

   - $P[D|H_0]$
5. P-Value$\leq\alpha$,就reject $H_0$并接受$H_1$

##### P-Value

P-Value=$P[D|H_0]=\frac{P[H_0|D]P[D]}{P[H_0|D]P[D]+P[H_0|\neg D]P[\neg D]}$

- 反应了假设下出现数据的概率,但是不能说明假设自身的概率,如果$P[D]$本来就很小,可能会导致$P[D|H_0]$失真
- <u>计算的时候需要把更差的样本一并考虑</u>

### 5.3 接受率分析

通过抽样调查判断样本中的缺陷率

##### 假设

- $H_0:n_d\leq n_0$缺陷率低
- $H_1: n_d>n_1$缺陷率高

##### 错误率

- $\alpha: P[H_1|H_0^*]$ 生产者风险(实际风险率没有样本这么高,消费者应该接受)
- $\beta:P[H_0|H_1^*]$ 消费者风险(实际风险率比样本高,消费者不应该接受)

### 5.4 单样本检验

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

### 5.5 多样本检验

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

### 5.6 分布检验(goodness of fit)

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
   

### 5.7 ANOVA (方差分析)

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



