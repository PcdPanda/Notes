# python量化投资

### 1. matplotlib画图

**plt.bar/plt.hbar** 

绘制柱状图(针对value)



**plt.hist**

绘制直方图,针对区间



**plt.boxplot**

绘制箱型图



**plt.pie**

绘制饼图



### 2. 描述数据

1. **np函数**mean, median, mode, percentile  

2. range(最大值和最小值差), MAD(平均绝对误差,只统计绝对值),std

3. **VaR**,给定置信概率所得到的最大亏损

4. **pandas**提供了cum相关的接口,可以用来计算累积值

5. **ffn**包可以用来计算最大回撤,收益率等指标

   

### 3. 投资组合理论(详见资产配置模型)

1. 资产定价模型

   $\mathbb{E}(R_q)=R_f+\beta_{qm}[\mathbb{E}(R_m)-R_f]$

   $\beta_{qm}=\frac{\sigma(R_q, R_m)}{\sigma^2(R_m)}$

   1.1 计算日无风险利率(通常用国债)

   1.2 计算资产组合和市场收益率(通常用大盘收益率)

   1.3 用OLS拟合alpha和beta

2. Markowitz模型,获得资产分配比

   **很容易受历史波动和样本区间的影响**

   2.1 获取历史收益率和协方差

   2.2 作为输入获得最优资产配置比

3. Black Litterman模型,考虑了**投资者的主观观点**

   3.1 看法矩阵

   ​	对5个资产有3个观点

   	- A的收益率为15%
   	- B的收益率比D高5%
   	- B和C的收益率比A低%6

   $$
   P=\left[\begin{array}1 
   1 & 0 &0&0&0\\
   0&1&0&-1&0\\
   1&-1/2&-1/2&0&0
   \end{array}\right]
   $$

   

   3.2 看法向量
   $$
   q=[15\%,5\%,6\%]^T
   $$

4. 三因子模型

   - 市场收益率(大盘)

   - 市值因子SMB(做多小盘股)
   - 账面市值比因子B/M(做多高BM的标的(**即P/B低**))

   **线性拟合前对各因子做散点图可视化相关性**





### 6. 时间序列分析

1. 自相关性

   同一变量在不同时间点的关系

   shift N个时间点,计算协方差和**自相关系数**

   ```python
   from statsmodels.tsa import stattools
   from statsmodels.graphics.tsaplots import *
   
   acf = stattools.acf(data) # 计算自相关性
   pacf = stattools.pacf(data) # 计算偏自相关性
   plot_acf(data, lags=30)
   ```

   - 时间序列数据通常很难具有自相关性,但是**时间序列的函数通常具有相关性(abs, mean, var)**
   - **波动率具有持续性**

2. 平稳性

   - 强平稳性:任意相同长度的区间里，$f$的分布相同
   - 弱平稳性:任意相同长度的区间里，$f$的均值$\mu$相同，且任意阶$l$的**自**协方差相等

   时间序列的分布与时间无关

   **判断平稳性方法**

   - 直接常规plot，看是否围绕平均值波动

   - **画出acf和pacf查看是否快速收敛至0** 

   - 单位根检验

     定义Operator $L:L^m(x_t=x_{t-m})$

     例如 $x_t=x_{t-2}+\epsilon_t$可以用$1=L^2+0$表示。  常数和$\epsilon$都为0

     如果存在解$L=0$就说明序列不平稳

     如果所有解$L$的绝对值$|L|>1$,说明序列平稳                                                      

3. 白噪声

   - 完全随机过程，每一个时间点的值都和之前无关,对于interval $T$中,$\mu=0,\sigma=x$,方差为常数
   - Ljung-Box检验,计算$m$阶自相关性$Q(m)=n(n+2)\sum_{k=1}^m\frac{\rho_k^2}{n-k}\sim\chi_m^2$

   **间隔大于0的自协方差等于0**

   ```python
   import statsmodels.q_stat
   ```

4. **时间序列预测**

   4.1 先通过acf和pacf进行稳定性分析

   ​	不平稳就做差分

   4.2 移动平均模型

   - 简单移动平均

     均线值作为预测值

   - 加权移动平均

     前不同时刻的值权重不同

   - 指数加权移动平均

     $\hat{x_t}=\alpha x_{t-1}+(1-\alpha)\hat{x_t}\rightarrow\hat{x_t}=\alpha x_{t-1}+\alpha(1-\alpha)x_{t-2}+\alpha(1-\alpha)^2x_{t-3}$

     $\alpha$**在0.05~3效果好**

   4.3 **ARMA建模**

   如果选择ARMA就需要计算**AIC value**

   | 模型      | ACF                    | PACF          |
   | --------- | ---------------------- | ------------- |
   | AR(p)     | 几何/震荡拖尾          | p阶结尾       |
   | MA(q)     | q阶截尾(q阶后快速收敛) | 几何/震荡拖尾 |
   | ARMA(p,q) | 几何/震荡拖尾          | 几何/震荡拖尾 |

   4.4 判断模型残差是否符合白噪声

   不是白噪声说明模型可以优化

5. **GARCH模型**