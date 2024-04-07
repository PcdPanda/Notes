- [Volatility Trading](#volatility-trading)
    - [1. Measure Volatility](#1-measure-volatility)
        - [1.1收盘波动率](#11收盘波动率)
        - [1.2Parkinson Volatility](#12parkinson-volatility)
        - [1.3 Rogers, Satchell, and Yoon Volatility](#13-rogers-satchell-and-yoon-volatility)
        - [1.4 Yang and Zhang Volatility](#14-yang-and-zhang-volatility)
    - [2. 波动率估计](#2-波动率估计)
        - [2.1 价格复权](#21-价格复权)
        - [2.2 价格频率选择](#22-价格频率选择)
        - [2.3 计算隐含波动率](#23-计算隐含波动率)
        - [2.4 波动率锥](#24-波动率锥)
        - [2.5 波动率微笑](#25-波动率微笑)
    - [3. Delta对冲](#3-delta对冲)
        - [3.1 对冲delta的频率](#31-对冲delta的频率)
        - [3.2 估计交易成本](#32-估计交易成本)
        - [3.3 Hedge仓位选择](#33-hedge仓位选择)
        - [3.4 dynamic hedge的问题](#34-dynamic-hedge的问题)
    - [4. 仓位控制](#4-仓位控制)
        - [4.1 Kelly Criterion](#41-kelly-criterion)
        - [4.2 非二元凯利准则](#42-非二元凯利准则)
        - [4.3 Browne Strategy](#43-browne-strategy)
    - [5. 交易分析](#5-交易分析)
        - [5.1 重要参考指标](#51-重要参考指标)
        - [5.2 交易观察](#52-交易观察)
        - [5.3 交易心态分析](#53-交易心态分析)

# Volatility Trading
### 1. Measure Volatility
##### 1.1收盘波动率
- 用传统收盘收益率的标准差作为收益率,容易计算
- 没有使用日内特征,并且收敛速度慢
##### 1.2Parkinson Volatility
- 给定$h_i,l_i$作为$N$个区间中第$i$个区间的最高/低价,则有区间波动率估计值
$$\sigma^2=\frac{1}{4N\ln2}\sum_{i=1}^N(\ln\frac{h_i}{l_i})^2$$
- 适合纯粹的GBM过程,在有竞价和价格条约的时候,会低估波动率
##### 1.3 <u>Rogers, Satchell, and Yoon Volatility</u>
- 额外考虑到了收盘$c_i$和开盘$o_i$
$$\sigma^2=\frac{N-1}{N}\sigma^2_{rs}$$
$$\sigma_{rs}^2=\frac{1}{N-1}\sum_{i=1}^N\ln\frac{h_i}{c_i}\ln\frac{h_i}{o_i}+\ln\frac{l_i}{c_i}\ln\frac{l_i}{o_i}$$
- 和Parkinson Volatility一样,在有价格条约时低估波动率
- 可以处理价格中的趋势,并且估计值更准
##### 1.4 Yang and Zhang Volatility
- 在没有jump的时候,估计值比前几个更好,本质是其他波动率的加权平均
$$\sigma^2=\sigma_o^2+k\sigma_c^2+(1-k)\sigma_{rs}^2$$
$$\sigma_o^2=\frac{1}{N-1}\sum_{i=1}^N\ln(\frac{o_i}{c_{i-1}})^2$$
$$\sigma_c^2=\frac{1}{N-1}\sum_{i=1}^N\ln(\frac{c_i}{o_{i-1}})^2$$
$$k=\frac{0.34(N-1)}{2N}$$
- 充分使用了价格中的信息,同样不好处理价格条约
### 2. 波动率估计
##### 2.1 价格复权
- 向前复权价格因子: $f=1-\frac{\text{Dividend}}{\text{Price}}$
- 作为系数乘以分红前的价格,使之前的价格符合当前状况
##### 2.2 价格频率选择
1. 选择15-30分钟的区间长度作为参考区间开始分析
2. 计算日内波动率占比$r$,等于用日内开盘和收盘差计算的波动率除以收盘价计算的波动率
3. 忽略隔夜波动率,将第一个区间的收益率作为$R_0=\frac{c_0}{o_0}$来计算日内波动率
4. 使用2的系数结合3的日内波动率计算总波动率
##### 2.3 </u>计算隐含波动率</u>
- 使用相同maturity但是strike不同的期权计算波动率,再通过delta作为权重
- 使用Corrado-Su公式计算给定期限的隐含波动率,偏度和峰度
$$C_{\text{actual price}}=C_{BS}+\mu_3Q_3+(\mu_4-3)Q_4$$
$$Q_3=\frac{1}{6}P_{\text{underlying}}\sigma\sqrt T[(2\sigma\sqrt T-d_1)\text{Pdf}(d_1)+\sigma^2T\text{Cdf}(d_1)]$$
$$Q_4=\frac{1}{24}P_{\text{underlying}}\sigma\sqrt T[(d_1^2-1-3\sigma\sqrt Td_2)\text{Pdf}(d_1)+\sigma^3\sqrt{T^3}\text{Cdf}(d_1)]$$
##### 2.4 <u>波动率锥</u>
- 在某个时间点对于未来波动率分布的估计,波动率存在负的autocorrelation,因此是mean-aversion过程
- 可以使用过去的数据拟合得到
- <u>隐含波动率会比估计/历史真实波动率更高以防未知事件发生</u>
- <u>远期隐含波动率</u>计算$T_1$到$T_2$区间中的波动率
$$\sigma_{12}^2=\frac{\sigma^2T_2-\sigma_1^2T_1}{T_2-T_1}$$
- <u>最重要的隐含波动率是ATM的期权隐含波动率</u>
##### 2.5 <u>波动率微笑</u>
- 市场上的人用OTM期权来作为未知事件的保险,导致需求更大
- 股票市场中可能发生的M&A适合用OTM期权对冲
- 做市商的调仓和对冲行为会增加波动率
- 在极端行情下,股票间的相关性会上升,因此波动率也更大
### 3. Delta对冲
##### 3.1 对冲delta的频率
- 基于固定时间周期/underlying价格变化: Hedge的频率越高,PnL曲线越平滑
- 通常使用delta band对冲,可以使用utility function构造,band的宽度和risk aversion有关
- Zakamouline Hedge Approximation: 通过市场信息构造delta band,和基于utility function模拟的最优band类似,但是计算简单
##### 3.2 <u>估计交易成本</u>
- 市场影响$F(n)$: 定义为交易对log mid price的变化量, 市场影响和交易量的平方根成正比: $F(n)=\alpha\sqrt n$
$$\ln P=\sum_{i}^N\text{sign}(n_i)F(|n_i|)$$
- 如果知道了标的单位时间的交易量和波动率,就可以反推出$\alpha=\frac{\sigma_t}{\sqrt{\mu_t}}$
##### 3.3 Hedge仓位选择
- 基于于过去实现的波动率对冲,会让PnL曲线很毛躁,但是终值确定性更高
- 基于隐含波动率对冲,可以让PnL曲线更平滑,但是终值方差更大
##### 3.4 dynamic hedge的问题
- 价格是离散变化的,因此不可能完全对冲delta
- 只靠dynamic hedge无法解决price jump的问题
### 4. <u>仓位控制</u>
##### 4.1 <u>Kelly Criterion</u>
- 对于二元博弈,如果盈利为$w$,亏损为$l$,胜率为$p$则最优投注为
$$f=\frac{pw-(1-p)l}{wl}$$
- 使用凯利准则投注依然会带来很大的不确定性,PnL波动会很大,但是长期来看是最优的
- 投注大于$f$时带来的损失会大于小于$f$,因此实际操作中会更保守,例如$f/2$
##### 4.2 <u>非二元凯利准则</u>
- 最优投注
$$f=\frac{r}{\sigma^2}$$
- 期望增长率为
$$GR=(f-\frac{f^2}{2})\frac{r^2}{\sigma^2}$$
- 在达到$B$前回撤到$A$的概率
$$P(A,B)=\frac{1-A^{1-2/f}}{B^{1-2/f}-A^{1-2/f}}$$
- 预期终止时间
$$\frac{1}{GR}\log\frac{B^{P(A,B)}}{A^{P(A,B)-1}}$$
##### 4.3 <u>Browne Strategy</u>
- 适合快速增长财富,在未来$T$时间内最快实现$R$收益率的投注额
$$f=\frac{1}{\sigma\sqrt T}Re^{-rT}\text{Pdf}[\text{Cdf}^{-1}(R\exp^{rT})]$$
- 实现目标的概率为
$$\text{Cdf}[\text{Cdf}^{-1}(R\exp^{rT})+\frac{\mu-r}{\sigma}\sqrt T]$$
### 5. 交易分析
##### 5.1 重要参考指标
- 平均每天利润,费前利润,各项成本
- 盈亏天数和占比
- 最大/累计亏损和盈利
- 最大回撤时间和大小
- 夏普/索提诺卡玛比率
- 附带尾部风险调整的Omega比例
##### 5.2 交易观察
- 确定多少收益率算成功/待观察/失败
- 除非有极其异常的情况发生,否则没必要调整交易策略
- 使用CPR和Hurst exponent衡量可持续性
##### 5.3 交易心态分析
- 过度自信: 认为失败是运气不好,而成功是自己能力出众,对自己的能力评估不合理
- 过分相信直觉: 对于某些情况过分肯定,并且只看到符合自己观点的内容
- 损失厌恶: 亏损时不愿意平仓,而是寄希望于情况反转  
- 短视和代表性记忆: 只会记得最近发生的特殊事件,而忘记一般事件的发生频率
