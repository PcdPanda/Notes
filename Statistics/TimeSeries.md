# 时间序列分析

### 1. 自相关性

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



### 2. 平稳性

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



### 3. 白噪声

- 完全随机过程，每一个时间点的值都和之前无关,对于interval $T$中,$\mu=0,\sigma=x$,方差为常数
- Ljung-Box检验,计算$m$阶自相关性$Q(m)=n(n+2)\sum_{k=1}^m\frac{\rho_k^2}{n-k}\sim\chi_m^2$

**间隔大于0的自协方差等于0**

```python
import statsmodels.q_stat
```



### 4. 时间序列预测

4.1 先通过acf和pacf进行稳定性分析

```
不平稳就做差分
```

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



### 5. GARCH模型

强调**残差项和方差**同样和之前的数据有关

刻画随时间变化的方差

1. 判断收益率是否平稳,如果平稳,就用ARIMA模型拟合,再获得**残差序列** $\epsilon_t$

   ```python
   from arch.unitroot import ADF
   log_price = np.log(price)
   adf_res = ADF(log_price)
   print(adf_res.summary().as_text())
   ```

   

2. 检验残差序列$\epsilon_t$或原数据的**平方**是否具有自相关性(LB检验)

   ```python
   from arch import arch_model
   am = arch_model(SHret)
   model = am.fit()
   print(model.summary())
   ```

   



