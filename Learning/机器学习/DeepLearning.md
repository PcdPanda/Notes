- [1. 神经网络基础](#1-神经网络基础)
    - [1.1 神经元](#11-神经元)
        - [常规神经元](#常规神经元)
        - [激励神经元](#激励神经元)
    - [1.2 深度的意义](#12-深度的意义)
        - [神经元位置](#神经元位置)
        - [逻辑神经网络分类器](#逻辑神经网络分类器)
        - [实数神经网络拟合器](#实数神经网络拟合器)
    - [1.3 神经网络误差](#13-神经网络误差)
        - [模型泛化误差 Model Generalization Error](#模型泛化误差-model-generalization-error)
        - [模型训练误差 Model Training Error](#模型训练误差-model-training-error)
        - [损失函数](#损失函数)
- [2. 神经网络优化xxx](#2-神经网络优化xxx)
    - [2.1 梯度下降](#21-梯度下降)
        - [梯度下降收敛速率](#梯度下降收敛速率)
        - [反向传播](#反向传播)
        - [随机梯度下降 SGD](#随机梯度下降-sgd)
        - [批梯度下降](#批梯度下降)
        - [批归一化 Batch Normalization](#批归一化-batch-normalization)
    - [2.2 优化器改进](#22-优化器改进)
        - [牛顿法(参数归一化)](#牛顿法参数归一化)
        - [二阶导近似](#二阶导近似)
        - [自适应学习率](#自适应学习率)
        - [局部最优点](#局部最优点)
        - [鞍点 (RMSProp)](#鞍点-rmsprop)
    - [2.3 正则化](#23-正则化)
        - [参数正则化](#参数正则化)
        - [样本平滑](#样本平滑)
        - [Dropout](#dropout)
        - [Connection优化](#connection优化)
        - [训练避免过拟合](#训练避免过拟合)
- [3. 计算机视觉](#3-计算机视觉)
    - [3.1 卷积神经网络 CNN](#31-卷积神经网络-cnn)
        - [神经网络架构](#神经网络架构)
        - [预处理](#预处理)
        - [卷积层](#卷积层)
        - [池化层](#池化层)
        - [反向传播](#反向传播-1)
    - [3.2 图像神经网络优化](#32-图像神经网络优化)
        - [VGG](#vgg)
        - [Highway Network](#highway-network)
        - [Resnet](#resnet)
        - [Dense Net](#dense-net)
    - [3.3 GNN (Graph Neuro Network)](#33-gnn-graph-neuro-network)
        - [模型参数和定义](#模型参数和定义)
        - [模型运行流程](#模型运行流程)
- [4. 时序神经网络](#4-时序神经网络)
    - [4.1 时间序列问题](#41-时间序列问题)
        - [问题输入](#问题输入)
        - [训练标签和输出](#训练标签和输出)
        - [构造序列标签并训练](#构造序列标签并训练)
    - [4.2 循环神经网络](#42-循环神经网络)
        - [RNN](#rnn)
        - [LSTM (Long Short Term Memory)](#lstm-long-short-term-memory)
        - [GRU (Gated Recurrent Units)](#gru-gated-recurrent-units)
    - [4.3 Distributional Representation](#43-distributional-representation)
        - [Dimensional Reduction](#dimensional-reduction)
        - [Word Embedding](#word-embedding)
    - [4.4 Transformer](#44-transformer)
        - [Attention](#attention)
        - [Self-Attention](#self-attention)
        - [Transformer 结构](#transformer-结构)
        - [CV应用](#cv应用)
- [5. 生成神经网络](#5-生成神经网络)
    - [5.1 (Variational) Auto Encoder](#51-variational-auto-encoder)
        - [Auto Encoder](#auto-encoder)
        - [VAE](#vae)
    - [5.2 生成对抗网络 GAN](#52-生成对抗网络-gan)
        - [网络结构](#网络结构)
        - [损失函数](#损失函数-1)
        - [GAN训练问题](#gan训练问题)
        - [GAN扩展](#gan扩展)
    - [5.3 Hopfield](#53-hopfield)
        - [网络结构](#网络结构-1)
        - [Hebbian Learning](#hebbian-learning)
        - [梯度下降训练](#梯度下降训练)
    - [5.3 玻尔兹曼机](#53-玻尔兹曼机)
        - [网络结构](#网络结构-2)
        - [取值方法](#取值方法)
        - [训练网络](#训练网络)
        - [网络扩展](#网络扩展)
        - [限制玻尔兹曼机优化](#限制玻尔兹曼机优化)
- [6. 强化学习](#6-强化学习)
    - [6.1 Q-learning](#61-q-learning)
        - [强化学习框架](#强化学习框架)
        - [Q-learning步骤](#q-learning步骤)
        - [Deep Q-learning](#deep-q-learning)
    - [6.2 Upper Confidence Bound](#62-upper-confidence-bound)
        - [算法思路](#算法思路)
        - [算法步骤](#算法步骤)


# 1. 神经网络基础

### 1.1 神经元

##### 常规神经元

| 名字 | Perceptron                          | Linear Unit              | Radial Basis Function Unit                            |
| ---- | ----------------------------------- | ------------------------ | ----------------------------------------------------- |
| 介绍 | 跃阶输出的线性神经元                | 将输入线性组合后的神经元 | 计算输入值到指定点的距离的神经元,适合拟合高维连续函数 |
| 输出 | $y=I(WX+b>0)$                       | $y=WX+b$                 | $y=\exp(-\beta||X-W||^2)$                             |
| 导数 | $\delta(WX+b)$,基于错误样本调整权重 | $X$和$1$                 | $-y||X-W||^2$和$-2\beta(X-W)y$                        |

##### 激励神经元

| 名字 | Threshold                   | Softmax (Sigmoid)            | Tanh                                  | ReLU                               |
| ---- | --------------------------- | ---------------------------- | ------------------------------------- | ---------------------------------- |
| 介绍 | 输入超过阈值时输出          | 平滑化threshold,描述激励概率 | 中心为0,导数比更大,收敛快,适合回归    | 输入为正时输出,梯度不饱和,适合分类 |
| 输出 | $y=\mathrm I(x>0)$          | $y_i=\frac{1}{1+\exp(-x)}$   | $y=\frac{e^x - e^{-x}}{e^x + e^{-x}}$ | $y=\max(0, x)$                     |
| 导数 | $x=0$时无穷大,其他时刻为$0$ | $y(1-y)$                     | $1-y^2$                               | $\mathrm I(x>0)x$                  |

### 1.2 深度的意义

##### 神经元位置

- Depth: 距离输入节点的距离
- Layer: Depth相同的节点组成的神经元集合

##### 逻辑神经网络分类器

1. 通过threshold unit可以构造And/Or/Majority逻辑门
2. 基于逻辑门,配合DNF表,一个隐藏层配合$2^{N-1}$个神经元就可以模拟任意具有$N$个输入的逻辑函数
3. <u>在逻辑函数相同时,深度网络的神经元数量为$O(N)$,而单层网络神经元数量为$O(2^N)$</u>,因此深度网络可以大量减少神经元数量

4. 将每个神经元的分类输出作为一个超平面,则通过And门可以使其拟合任意图形,此时神经元数量$O(\frac{N^D}{(D-1)!})$,有$D$个维度
5. 通过神经网络决策边界组成的凸包数量/VC维度来衡量神经网络复杂度容量

##### 实数神经网络拟合器

1. 单隐藏层神经网络,可以用无数个线性感知机来拟合任何维度实数函数
2. 需要使用渐进式的激励函数来使得深层神经元可以获得浅层神经元信息

### 1.3 神经网络误差

##### 模型泛化误差 Model Generalization Error

| Bias                                            | Variance                                                 | Irreducible Error                                            |
| ----------------------------------------------- | -------------------------------------------------------- | ------------------------------------------------------------ |
| 模型输出的期望值和真实标签之差 $Bias=E(f(X)-y)$ | 模型自身对特征微小变化的敏感度 $Var=E(f(X)^2)-E(f(X))^2$ | 由数据自身噪声带来的误差,不可消除,例如相同特征的数据却有不同标签 |

$$
\text{Model Generalization Error}=\text{Bias}^2+\text{Variance}+\text{Irreducible Error}
$$

有时候Variance和Bias无法兼得,例如有时感知机的线性分类效果比神经网络更好,因为Bias更低但Variance更大

##### 模型训练误差 Model Training Error

| Approximation Error                                 | Estimation Error                     | Optimization Error                            |
| --------------------------------------------------- | ------------------------------------ | --------------------------------------------- |
| 模型的表达能力限制带来的误差,即使参数完美也有的限制 | 由于训练集有限带来的模型参数估计误差 | 模型参数和训练集上最优参数的差,用损失函数表示 |

$$
\text{Model Training Error}=\text{Approximation Error}+\text{Estimation Error}+\text{Optimization Error}
$$

##### 损失函数

- 通过在训练集上计算模型预测值和标签之间的偏差,来近似经验误差,不同的问题有不同的定义方法
- 理想的损失函数是strongly convex的,且距离最小值越远,梯度绝对值越大

| Mean Square Error(回归问题)               | Cross Entropy (多分类问题)                                   |
| ----------------------------------------- | ------------------------------------------------------------ |
| $L=\frac{1}{2}||f(X,W)-y||^2$             | $L=-\sum p(y_i)\log f(X,W)_i$,在极值点值为0                  |
| $\frac{\partial L}{\partial f}=2f(X,W)-y$ | $\frac{\partial L}{\partial f_{i}}=-\frac{1}{N}\sum_{n=1}^{N} \frac{y_{ni}}{f_{ni}}$,导数更大,且在最小值点值不为0 |

# 2. 神经网络优化

### 2.1 梯度下降

##### 梯度下降收敛速率

- 参数收敛速率: 模型参数和最优点误差的衰减比例 $R=\frac{|f(W^{k+1})-f(W^*)|}{|f(W^k)-f(W^*)|}$

- 误差收敛速率: 模型误差$\epsilon$和迭代次数$T$的关系

  | 损失函数 | Strongly Convex二阶导有上限 | 动量法             | Generic Convex   | Lipschitz Smooth Convex |
  | -------- | --------------------------- | ------------------ | ---------------- | ----------------------- |
  | 收敛速率 | $O(e^{-T})$                 | $O(\frac{1}{T^2})$ | $O(\frac{1}{T})$ | $O(\frac{1}{\sqrt T})$  |

##### 反向传播

1. 寻找合适的损失函数,并对所有权重进行求导$\frac{\partial L}{\partial W}=\sum\frac{\partial L}{\partial y_i}\frac{\partial y_i}{\partial W}$ (如果导数不存在,可以用subgrident,即和函数值增长方向相同即可)
2. 使用反向传播法法更新权重$W'=W-\eta\frac{1}{N}\sum_{n=1}^N\frac{\partial L}{\partial W}(f(X_n;W), y_n)$
3. 重复2直到导数几乎为0收敛

##### 随机梯度下降 SGD

1. 计算所有训练集上的Loss再更新收敛太慢,可以逐个样本更新
2. 因为样本存在随机性,因此收敛速率可能会变慢
   - Strongly Convex: $\epsilon=O(\frac{\log T}{T})$
   - Generic Convex: $\epsilon=O(\frac{\log T}{\sqrt T})$

3. 通过参数更新平滑化可以进一步提高收敛速率,通常$\gamma\approx3$

   - $w_t=(1-\frac{\gamma+1}{t+\gamma})w_{t-1}+\frac{\gamma+1}{t+\gamma}w_t$

   - Strongly Convex: $\epsilon=O(\frac{1}{T})$
   - Generic Convex: $\epsilon=O(\frac{1}{\sqrt T})$

##### 批梯度下降

1. 对随机梯度下降和常规梯度下降进行中和,选择大小为$B$的批,来计算并更新参数,使得收敛速率为$O(\frac{1}{\sqrt{BT}+T})$
2. 每次迭代可以对Loss进行平滑,以减少batch variance带来的影响
3. 通常$B$都设置地尽量大,但不会严重影响训练时间,一般为可以使用的内存大小

##### 批归一化 Batch Normalization

1. 每个batch中的样本分布可能和总体不同,导致梯度计算可能有很大误差,通常可以通过在网络中添加若干个batch norm层来解决问题

2. Batch Norm层会对输入进行归一化,使得输出是经过Z-score之后的结果

3. 由于Bath Norm添加了不同样本的相关性,梯度计算起来更加复杂,假设输入是$x_i$输出是$y_j$
   $$
   \frac{\partial y_j}{\partial x_i}=\begin{cases}\frac{1}{\sqrt{\sigma^2+\epsilon}}-\frac{1}{B\sigma^2+\epsilon}-\frac{(x_i-\mu)^2}{B(\sigma^2+\epsilon)^{2/3}}&i=j\\-\frac{1}{B\sigma^2+\epsilon}-\frac{(x_i-\mu)(x_j-\mu)}{B(\sigma^2+\epsilon)^{2/3}}&i\neq j\end{cases}
   $$

4. Batch Norm层会记录该层的方差和均值,供测试集归一化使用

### 2.2 优化器改进

##### <u>牛顿法(参数归一化)</u>

1. 牛顿法使用二次曲面对损失函数的局部平面近似 $L(W^*;X)=L(W;X)+(W^*-W;X)\frac{\partial L}{\partial W}+\frac{1}{2}(W^*-W;X)^2\frac{\partial^2L}{\partial W^2}$

2. 每个参数的局部近似曲线不同,因此最优学习率$\eta_{opt}=(\frac{\partial^2L}{\partial w^2})^{-1}$也不同,由于学习率太大($\eta>\eta_{opt}$)会无法收敛,因此个别参数最低学习率限制了整体学习率

3. 对二次曲面进行归一化,如参数曲面近似为$L(W^*;X)=\frac{1}{2}W^{*T}\frac{\partial^2L}{\partial W^2}W^*+W^{*T}b+c$

4. 通过计算$\frac{\partial^2L}{\partial W^2}$可以对所有参数进行归一化更新(最优学习率为1,且不能大于2)

$$
W'=W-\eta(\frac{\partial^2L}{\partial W^2})^{-1}\frac{1}{N}\sum_{n=1}^N\frac{\partial L}{\partial W}(f(X_n;W), y_n)^T
$$

##### 二阶导近似

- 牛顿法计算二阶导矩阵的逆耗时太长,参数太多,因此需要使用近似法估计$\frac{\partial^2L}{\partial W^2})^{-1}$
- Quickprop: 不直接计算$\frac{\partial^2L}{\partial W^2}$,而是通过对各个参数的局部一阶导作差近似二阶导$\frac{\partial^2L}{\partial w^2}\approx\frac{w'-w}{L'(w')-L'(w)}$

##### 自适应学习率

- 参数平面无法用二次曲面完美模拟,$\eta_{opt}$不是合适的学习率,需要降低
- Rprop:每个模型参数$w$学习率独立,如果梯度更新方向不变,就放大学习率$\eta'=\alpha\eta$,否则就减小学习率并回到上一个参数点计算$\eta'=\beta\eta$

##### 局部最优点

1. 有时陷入局部最优点无法突破,使用动量可能可以突破局部点,(通常$\beta\approx0.9$)
2. 使用动量更新参数$W'=W+M$
3. 基于梯度再一次更新参数$W''=W'-\eta\frac{\partial L(W+M;X)}{\partial W}$
4. 将梯度平滑后加入下一次动量$M'=\beta M-(1-\beta)\eta\frac{\partial L(W+M;X)}{\partial W}$

##### 鞍点 (RMSProp)

1. 在特定参数方向上已经是局部最优,但是陷入震荡,反而在其他方向上没有下降,通过设置方差权重可以突破鞍点

2. 加权计算梯度更新的方差$E[\frac{\partial^2L}{\partial w^2}]_t=\gamma E[\frac{\partial^2L}{\partial w^2}]_{t-1}+(1-\gamma)E[\frac{\partial^2L}{\partial w^2}]_t$ (通常$\gamma\approx0.9$)
3. 针对每个参数梯度的方差,调整参数的更新量$w_{k+1}=w_k-\frac{\eta}{E[\frac{\partial^2L}{\partial w^2}]_t+\epsilon}\frac{\partial L}{\partial w}$

### 2.3 正则化

##### 参数正则化

将模型参数的大小加入损失函数,通过限制模型参数的绝对值,来使模型的输出更加平滑,不会因为一个特征而突变

| 正则化方式          | 表达式                           | 特点                     | 假设                     |
| ------------------- | -------------------------------- | ------------------------ | ------------------------ |
| $l1$ 正则化 (Lasso) | $\lambda\sum|w_k|$               | 倾向于使参数为0删除特征  | 参数服从拉普拉斯先验分布 |
| $l2$ 正则化 (Ridge) | $\frac{\lambda}{2}\sum||w_k||^2$ | 倾向于保留特征使参数变小 | 参数服从正太先验分布     |

##### 样本平滑

- 手动对样本添加噪音
- 标签平滑化: 将样本的类别进行平滑,使其不满足一个类别

##### Dropout

1. 训练每次迭代的时候,有$1-\alpha$的概率关闭特定神经元,迭代完成后打开
2. 本质上实现bagging,让神经网络的输出是若干个不同网络的平均值
3. 训练完成后,打开所有神经元,并使其参数变成$\alpha$

##### Connection优化

- 将更新pattern相似的权重共享参数值,减少权重数量
- 删除持续不动的连接
- 给连接添加噪音

##### 训练避免过拟合

- Early Stopping: 设置validation data并检测在validation set的表现,在validation set上表现不提高时可以停止
- 梯度剪裁: 给梯度添加上限,确保不会导致梯度过高(通常上限为5)

# 3. 计算机视觉

### 3.1 卷积神经网络 CNN

##### 神经网络架构

- Shift Invariance: 通过扫描整个图像,无论特征在什么位置出现,都可以发现. 网络越深,对卷积核尺寸的大小要求越低
- <u>Scan</u>: 过滤器扫描之前生成的所有通道(图层),累加后生成新的图层,给下一层使用,如果有$C$个卷积核,就会生成$C$个通道
- <u>Receptive Fields</u>: 过滤器和池化器在输入图像上对应的尺寸范围,层数越深的过滤器感受野越大
- Nondistribution: 按深度递进,每次只扫描卷积核当前覆盖区域,并直接向前传播到终点,优点是可以并行扫描不同区域
- <u>Distribution</u>: 按网络层递进,每次扫描完所有图层的所有像素,再输出给下一层扫描,优点是参数少,速度快,并且可以共享输出,适合深度网络

##### 预处理

- 像素调整: 将图像转变为正方形,并且可以保存在GPU里
- 填充: 补充图像边界缺失的像素点来扩充输入,通常放在卷积层前<u>使得之后的输出大小和输入一致</u>,当卷积核是奇数时,对称填充,否则非对称
- 上采样: 本质就是使用小于1的步长$S$,在图像间隙中填充像素
- 降采样: 通过提高过滤器/池化层移动步长,来忽略图像中的一些像素,以压缩参数数量和图像大小,步长通常为1或2

##### 卷积层

- 通过正方形过滤器扫描图层生成线性组合,本质就是卷积操作,通常有$2^n$个过滤器
- 用边长为$L$的过滤器以$S$为步长扫描边长为$R$的输入图层,则输出边长为$\lfloor\frac{R-L}{S}\rfloor+1$
- 通常网络中越深的卷积层,过滤器越多,边长越小,生成的图层也越多
- 卷积层输出之后通常会<u>通过Relu激励后再向后传导</u>

##### 池化层

- 针对每个过滤器的输出进行池化降采样,从而降低图像分辨率的效果,池化前通常不会填充上采样

- 无参数池化

  | Max Pooling                                             | Mean Pooling                              | Global  Pooling                   |
  | ------------------------------------------------------- | ----------------------------------------- | --------------------------------- |
  | 最常用,池化区域最大值作为输出,保留最强特征,适合分类任务 | 池化区域平均值作为输出,适合平滑图像和特征 | 将整个图层池化成向量,提取全局特征 |

- 参数池化

  | P-norm Pooling                     | Spatial Pyramid Pooling            | Adaptive Pooling / Dynamic Pooling |
  | ---------------------------------- | ---------------------------------- | ---------------------------------- |
  | 在池化区域计算P范数,适合处理异常值 | 将不同尺寸的输入图层池化成相同尺寸 | 自适应池化区域大小                 |

##### <u>反向传播</u>

- 对输入图层$X_j$的梯度可以表示为将过滤器上下左右反转之后对输出图层梯度$\frac{\mathrm dL}{\mathrm dY_i}$进行填充后卷积的结果,不同过滤器可以同时并行操作
- 对过滤器$F_n$的梯度可以表示为将输入图层$X$作为卷积核,对输出图层梯度$\frac{\mathrm dL}{\mathrm dY_i}$直接进行卷积的结果,不同图层$X$可以同时并行操作

- Max Pooling的梯度,如果是对应输入是最大值,则梯度为1,否则为0,Mean Pooling则梯度为$\frac{1}{L^2}$

### 3.2 <u>图像神经网络优化</u>

##### VGG

- 使用统一大小的卷积核(3\*3)和池化层(2\*2),专注于提高深度来提高挖掘特征的能力
- 模型结构简单但是尺寸大,训练速度慢,适合预训练用于特征提取

##### Highway Network

- 借鉴LSTM中的门思路,添加Transform Gate和Carry Gate非线性门缓解梯度消失
- $y=H(x,W_H)\cdot T(x, W_T)+x\cdot C(x, W_C)$,有时候$C(x,W_C)=1-T(X,W_T)$起到权重控制作用

##### Resnet

- 因为神经网络中的非线性激励函数,使得网络无法拟合$F(x)=x$的简单恒等映射函数,因此网络越深可能导致表现越差
- 添加残差块,使得$y_i$中本来就包含输入$x_i$模型$y_i=F(x_i, W_i)+x_i=\sigma[x_i+W_2(\sigma(W_1x_i))]$,使得网络具备恒等映射的能力,确保了深度网络不会出现性能下降
- 有时候由于$y$和$x$的维度不一致,需要采用降采样等手段匹配

##### Dense Net

- 扩展残差块,每个模块的输入不仅仅考虑当前的$x$,会将之前所有的$x$一起作为输入,即$y_i=\sigma(\sum_{j=1}^{i-1}W_{ij}x_j+W_2(\sigma(W_1x_i)))$
- 可以减少卷积核数量,并将之前提取的特征直接应用到后层中
- 深层的神经网络可能输入参数会很大,因此可能需要降采样

### 3.3 GNN (Graph Neuro Network)

##### 模型参数和定义

- 聚合函数: 必须顺序无关,例如avg/max/sum等,用于聚合结点周围的所有点生成信息
- 聚合权重矩阵: 用于处理聚合后的结果,更新每个节点的特征,每一层都可以有独立的
- 激励函数: 添加非线性特征,例如RELU,$\tanh$等

##### 模型运行流程

1. 将输入转化为graph,例如image可以理解为每个像素和周围4个点相连的图
2. 第$k$层使用聚合函数$A_k$聚合每个结点周围的的节点特征: $m_k=A_k(h_{k-1}^i,\cdots,h_{k-1}^j)$
3. 使用权重向量结合聚合后结果生成新的字节点特征: $h_k=\tanh[W_k\cdot(h_{k-1},m_k)]$
4. 反复迭代1,2步骤,最后再通过权重向量和sigmoid等函数结合任务要求输出结果

# 4. 时序神经网络

### 4.1 时间序列问题

##### 问题输入

- 只能依赖过去信息,不能使用将来信息: 同声传译
- 可以使用双向信息: 机器翻译

##### 训练标签和输出

- 输出单一结果: 文本分类,通常只在最后一个时间点上计算梯度和损失

- 输出整个序列:
  - 例如文本生成/机器翻译等任务,不光在每个时间点上生成输出,还要使用自身之前的输出来作为输入继续输出
  - 在每个时间点上都需要根据标签计算梯度和损失

##### <u>构造序列标签并训练</u>

1. 对标签序列的顺序进行限制
2. 使用神经网络的序列输出作为概率,结合Viterbi动态规划找到概率最大的标签序列用于计算梯度
3. 神经网络真正输出结果时,先找到若干可行的输出序列,再使用剪枝算法,找到相对合理的输出
4. 容易被神经网络第一次输出限制,陷入局部最优点
5. 可以通过倒置输入序列,保留原输出来提高模型的泛化能力,避免过拟合

### 4.2 循环神经网络

##### RNN

$$
h_t=f_h[W_xx_t+W_hh_{t-1}]\\
y_t=f_y[W_yh_t]
$$

- 使用$h(t)$来保存隐状态,可以记录无限长的序列信息
- 可以通过堆叠模块来实现双向/深层信息流
- 训练时损失$L$在信息路径上反向传播,本质是累乘$W_x'$,如果序列太长可能会有梯度爆炸/消失问题
- 常用$\tanh$作为激励函数$f_h$,因为梯度更大,记忆力更强,但通常不超过10个周期

##### LSTM (Long Short Term Memory)

通过添加遗忘/输入/输出门来控制隐状态,可以有效解决信息遗忘过快的问题

| 1. 遗忘门使用过去信息计算遗忘权重             | 2. 输入门使用过去信息计算新信息权重           | 5. 输出门使用新信息来决定总结程度    |
| --------------------------------------------- | --------------------------------------------- | ------------------------------------ |
| $f_t=\sigma(W_f\cdot[c_{t-1}, h_{t-1}, x_t])$ | $i_t=\sigma(W_i\cdot[c_{t-1}, h_{t-1}, x_t])$ | $o_t=\sigma(W_o[c_t, h_{t-1}, x_t])$ |

通过单元状态$c$来储存网络中的信息,隐状态$h$来记录信息输出的结果,起总结作用

| 3. 计算新信息                       | 4. 使用遗忘和输入门更新信息 | 6. 使用输出门总结信息   |
| ----------------------------------- | --------------------------- | ----------------------- |
| $c'_t=\tanh(W_c\cdot[h_{t-1},x_t])$ | $c_t=f_tc_t+i_tc_t'$        | $h_t=o_t\cdot\tanh c_t$ |

##### GRU (Gated Recurrent Units)

合并遗忘门和输入门进行统一控制

| 1. 使用过去状态和新输入来决定怎样处理新信息 | 3. 使用过去状态和新输入决定控制门    |
| ------------------------------------------- | ------------------------------------ |
| $o_t=\sigma(W_o[h_{t-1}, x_t])$             | $f_t=\sigma(W_f\cdot[h_{t-1}, X_t])$ |

合并单元状态和隐状态,统一记忆信息流

| 2. 计算新信息并处理                    | 4. 基于控制门结果生成新信息        |
| -------------------------------------- | ---------------------------------- |
| $h_t'=\tanh(W[o_t\cdot h_{t-1}, x_t])$ | $h_t=(1-W_h)h_{t-1}+W_h\cdot h_t'$ |

### 4.3 Distributional Representation 

##### Dimensional Reduction

- 使用one-hot对每个单词进行编码维度太大,且无法描述近义词之间的关系
- 通过无监督训练神经网络生成状态压缩矩阵,使得单词的维度降低

##### Word Embedding

- 训练输入是one-hot的单词向量,并通过权重矩阵将onehot向量压缩
- 压缩后获得输出,标签是单词周围出现的其他单词,因此相似的单词压缩后应该也相似 (周围通常是5个单词)
- 使用没有出现的单词作为负样本,来提高训练速度 (通常有5-20个负样本)

### 4.4 Transformer

##### Attention

1. 对当前的输入进行编码,获得对应的query状态$q_t=W_qx_t$
2. 在模型接受序列时,在每个时点都保留隐状态$h_{t-i}$
3. 训练权重向量,将隐状态编码成key向量和value向量,<u>可以有多组</u>: $k_{t-i}=W_kh_{t-i},v_{t-i}=W_vh_{t-i}$
4. 定义距离函数$d$,描述key和query之间的距离,并以此计算每个隐状态的权重$w_{t-i}=\frac{\exp(d(k_t-i), q_t)}{\sum\exp(d(k_t-i), q_t)}$
5. 使用权重结合编码后的value向量生成新的隐状态$c=\sum w_{t-i}v_{t-i}$

##### Self-Attention

1. 将输入中的每个元素,扩展成向量,并添加大小为$d$的位置编码元素,位置编码需要保证shift-invariance性质
   $$
   P_t=\begin{bmatrix}\sin\omega_1t\\\cos\omega_1t\\\cdots\\\sin\omega_{d/2}t\\\cos\omega_{d/2}t\\\end{bmatrix}\\
   \omega_l=\frac{1}{10000^{2l/d}}\\
   P_{t+\Delta t}=\text{diag}(\begin{bmatrix}\cos\omega_l\Delta t&\sin\omega_l\Delta t\\-\sin\omega_l\Delta t&\cos\omega_l\Delta t\end{bmatrix})P_t
   $$
   
2. 使用$W_q,W_k,W_v$计算生成每个元素的query, key, value向量,可以根据不同的$W$生成多组

3. 将生成后的向量扩展,作为新的输入,并传入到全连接神经网络进行降维,降维后得到新的输入

##### Transformer 结构	

1. encoder对输入位置编码后进行反复的self-attention机制,生成长度相同的序列
2. 训练新$W_q,W_k$用于对encode后的隐状态计算权重
3. decoder接受上一个decoder的输出值作为输入,添加位置编码后,对之前的输入进行self-attention
4. 更新后输入后结合encoder后生成的隐状态聚合并传入全连接神经网络作为输出

##### CV应用

- Spatial Attention: 对图层的不同位置构造隐状态矩阵,用来反映结果对特定位置的注意力
- Channel Attention: 对不同的channel构造隐状态的矩阵,用来反映输出对特定特征/色彩的注意力

# 5. 生成神经网络

### 5.1 (Variational) Auto Encoder

##### Auto Encoder

- 完全对称的神经网络,先通过Encoder将数据压缩到低维再通过Decoder还原,Encoder和Decoder共享权重
- Encoder将数据从非线性空间映射到线性空间,可以将Decoder更换成其他模型进行分类等操作
- 损失函数为$L=E[\text{div}||x-w^Txw||^2]$,通过优化KL散度,单层自编码器的本质是PCA降维,多层自编码器是非线性PCA

##### VAE

1.  获得输入样本$X$,基于神经网络encoder权重$W_x$生成隐变量$z$分布的参数$[\mu_z, \sigma_z]=W_xX$
2.  通常假设$z$服从各项同性标准正态分布,则基于$X$之后的条件分布也是标准正态分布,因此将神经网络生成的分布和$z$真实分布的$KL$散度作为损失之一$L_{kl}$
3.  从标准正态分布随机采样向量$\omega$提供随机性,配合生成的隐变量分布参数采样$\hat z=\mu_z+\omega\sigma_z$
4.  decoder对通过隐变量解码,还原生成的图片$\hat X=W_z\hat z$
5.  计算生成图片和原始图片的损失$L_x=Div(\hat X-X)$并和$L_{kl}$一起最小化

### 5.2 生成对抗网络 GAN

##### 网络结构

- 判别模型$D$: 给定真实数据$X$和生成的数据$\hat X$,使得分类成功率尽量准确

- 生成模型$G$: 给定隐变量$Z$用于生成数据$\hat X$,使得分类成功率尽量低

##### 损失函数

- 令真实样本标签为$1$,伪造样本为$0$,则尽可能提高生成模型的能力,使得最优的判别模型的分类准确率都很低

$$
\min_G\max_D E_X\log D(X)+E_Z\log(1-D(GZ))
$$

- 当判别函数$D$达到最优时,$D(X)=\frac{P_X(X)}{P_X(X)+P_G(X)}$,此时生成器直接最小化真实图像分布$P_X(X)$和生成分布$P_G(X)$的JSD距离
  $$
  \min_G KL[P_X,0.5(P_X+P_G)]+KL[P_G,0.5(P_X+P_G)]
  $$

##### GAN训练问题

| 模型问题 | 问题描述                                                     | 解决方案                                          |
| -------- | ------------------------------------------------------------ | ------------------------------------------------- |
| 模型崩溃 | 训练陷入局部最优,生成模型每次都只生成相同的图像,尽管生成器每次都能欺骗判别器 | 成批训练,使得判别器不会被欺骗                     |
| 梯度消失 | 判别器太优秀,损失函数过大,此时JSD梯度几乎为0,导致生成器更新梯度消失 | 将一部分真实标签变为0-1之间来模糊判别器或梯度剪裁 |
| 无法收敛 | 生成器和判别器的参数一直震荡                                 | 对参数添加动量项来平滑训练过程                    |

##### GAN扩展

| 模型名字        | 模型描述                                                     | 使用场景                |
| --------------- | ------------------------------------------------------------ | ----------------------- |
| Conditional GAN | 预先给定数据的标签,用来根据标签生成数据                      | 给定数字,生成对应的图像 |
| Lap GAN         | 在不同分辨率下训练GAN,高分辨率的生成器用低分辨率的生成结果作为输入 | 生成高分辨率图像        |
| BiGAN           | 训练编码器用于给定数据生成编码,训练生成器用于给定编码生成数据,编码和数据一起给判别器分辨 | 同时训练编码和生成能力  |
| CycleGAN        | 训练两个生成模型,用于将两个不同领域的数据相互转换,再分别训练一对匹配的判别器来确保转换质量 | 在不同领域转换图像      |

### 5.3 Hopfield

##### 网络结构

- 图状神经网络,两两神经元$i$和$j$之间通过权重$w_{ij}$连接
- 神经元的值为0/1,由周围所有神经元的值决定$y_i=\text{sign}(\sum_{j\neq i}w_{ji}y_j+b_i>0) $

- 通过定义能量$E=-y^TWy$可以证明网络一定会收敛在$E$的局部最小值,局部最小值是对称的

##### Hebbian Learning

1. 有$N$个结点的网络可以生成约$0.15N$种模式
2. 对于每种模式$p$,通过累加每条边的权重$w_{ij}=\sum_p y_i^py_j^p\rightarrow W=\sum_p y_py_p^T-PI$
3. 网络本质上讲模式映射到最近的晶格上,但因为对称性和模式干扰,可能出现$O(\exp(N))$个局部最优

##### 梯度下降训练

1. 根据模式权重随机选择一种需要记忆的模式向量$y_p$
2. 通过$y_p$初始化网络并记录2-4步后的收敛状态$y_v$,此时$y_v$大概率是不需要的局部最优
3. 可以在收敛时通过添加噪音来跳过局部最优
4. 通过梯度下降更新权重矩阵$W'=W+\alpha(y_py_p^T-y_vy_v^T)$

### 5.3 玻尔兹曼机

##### 网络结构

- 在Hopfield基础上引入参数$T$来描述网络的热度,并构建状态$s$的分布$p_T(s)\propto\exp(-\frac{1}{kT})\rightarrow p_T(s)=\frac{\exp(-E(s))}{\sum_S\exp(-E(s))}$
- 当$T=0$时,模型等价于Hopfield,否则存在随机变化

- 对于单个节点$i$,值为1的概率取决于其他节点的线性激发值$P(s_i=1)=\frac{1}{1+\exp(-\sum w_{ij}s_j-b_i)}$

- 对于整个网络,获得$s$的概率为$P(y_s)\propto\exp(-\frac{-E(y_s)}{T})$

##### 取值方法

- 持续降温,对最后几次多次网络变化取平均值作为网络的当前值
- 计算当前网络状态的概率分布$P(y_s)$,当概率不再持续上升,则说明网络到稳态

##### 训练网络

1. 针对$i$和$j$的权重,计算所有状态在$ij$上的均值$\bigtriangleup w_{ij}=\frac{1}{N}\sum_Ss_is_j$
2. 让网络从随机状态开始自然演化$m$次,并计算均值$\bigtriangleup w_{ij}=w_{ij}-\frac{1}{M}\sum_{S}s_i's_j'$
3. 更新网络网络权重$w_{ij}'=w_{ij}+\eta\bigtriangleup w_{ij}$

##### 网络扩展

1. $N$个结点的网络智能保存$N$种状态,因此可以增加$K$个结点,但是训练和输出时不用考虑这$K$个结点的值

2. 很对每个要记忆的模式$S_p$,固定$V$个结点值,让网络的剩余$K$个结点随机演化,获得联合状态$H_p$,可以重复多次获得$K$个$H$
3. 放开所有节点的约束,完全随机演化,重新获得$M$个状态$S_m'$
4. 采用上述第三步方法更新$w_{ij}'=w_{ij}+\eta[\frac{1}{PK}\sum_Ss_is_j-\frac{1}{M}\sum_{S'}s_i's_j']$

##### 限制玻尔兹曼机优化

- 同种节点之间不会连接,只有原始节点和增加的节点之间互相连接
- 可以大幅减少获得状态的迭代步数,通常4步即可,并且可以减少模型大小

# 6. 强化学习

### 6.1 Q-learning

##### 强化学习框架

- 状态空间和行动: 状态空间为$S$,基于模型从行动空间中$A$选取的行动$a$,有一定概率从$s_i$转化到$s_j$,状态转换具有马尔科夫性质

- 收益: 基于不同的状态$s$和不同的行动$a$,可以基于收益函数$R$获得不同的收益$R(s,a)$
- 目标: 基于状态$S$,采取最优的行动$a$,使得期望折现后的期望收益最大$\max E(\sum \gamma^tR_t)$

##### Q-learning步骤

1. 定义学习率$\eta$和函数$Q$,$Q$接收$s,a$作为输入,一开始都初始化为0
2. 模型基于$Q$函数中的值和当前的状态$s$,选择对应收益最高的$a$
3. 每次操作后,更新$Q$函数,$Q(s,a)'=(1-\eta)Q(s,a)+\eta(R+\gamma Q(s,a))$
4. 当$Q$收敛后训练完成

##### Deep Q-learning

- 当$S$和$A$的空间太大时,导致$Q$函数更新很慢,因此可以训练神经网络来估计$Q$
- 模型使用神经网络预测的$Q$做出选择,再根据实际获得的收益来更新神经网络的参数,提高预测精度

### 6.2 Upper Confidence Bound

##### 算法思路

- Exploration: 尽可能通过尝试不同的行动$a$,来获得更多关于$R$的信息
- Exploitation: 尽可能选择$R$更高的$a$来获得当下的收益
- 在所有行动$A$中选择置信区间上沿最高的$a$,来平衡Exploration和Exploitation

##### 算法步骤

1. 对于每个选项$a_i$,初始化平均收益$\mu_i=0$和累计选择次数$m_i=0$,并定义学习率$\alpha$
2. 在第$t$个周期,对于每个选项,计算ucb值$\mu_i+\alpha\sqrt{2\ln t/m_i}$
3. 选择ucb最高的选项,并获得收益$R_i$
4. 更新$m_i$和平均收益$\mu_i$

