- [1. Overview](#1-overview)
    - [1.1 目标](#11-目标)
    - [1.2 文本预处理](#12-文本预处理)
        - [Tokenize](#tokenize)
        - [未知单词处理](#未知单词处理)
    - [1.3 TF-IDF](#13-tf-idf)
        - [词频(Term Frequency)](#词频term-frequency)
        - [逆文档频率(Inverse Document Frequency)](#逆文档频率inverse-document-frequency)
        - [TF-IDF](#tf-idf)
- [2. Embedding](#2-embedding)
    - [2.1 Vector Representation](#21-vector-representation)
        - [Overview](#overview)
        - [One-hot Encoding](#one-hot-encoding)
        - [Cosine Similarity](#cosine-similarity)
    - [2.2 SVD降维](#22-svd降维)
        - [Term-Docuemnt Matrix](#term-docuemnt-matrix)
        - [降维流程](#降维流程)
    - [2.3 Word2Vec](#23-word2vec)
        - [降采样](#降采样)
        - [训练流程](#训练流程)
        - [负采样](#负采样)
- [3. 文本分类](#3-文本分类)
    - [3.1 极大似然估计](#31-极大似然估计)
        - [流程](#流程)
        - [Smoothing](#smoothing)
    - [3.2 朴素贝叶斯](#32-朴素贝叶斯)
        - [流程](#流程-1)
        - [缺点](#缺点)
    - [3.3 逻辑回归](#33-逻辑回归)
        - [Overview](#overview-1)
        - [训练流程](#训练流程-1)
    - [3.4 神经网络](#34-神经网络)
        - [RNN](#rnn)
        - [LSTM](#lstm)
    - [3.5 文本主题分类](#35-文本主题分类)
        - [Overview](#overview-2)
        - [LSA (Latent Semantic Analysis)](#lsa-latent-semantic-analysis)
        - [PLSA (Probabilistic Latent Semantic Analysis)](#plsa-probabilistic-latent-semantic-analysis)
        - [LDA (Latent Dirichlet Allocation)](#lda-latent-dirichlet-allocation)
- [4. Part of Speech词性标注](#4-part-of-speech词性标注)
    - [4.1 POS定义](#41-pos定义)
        - [Overview](#overview-3)
        - [POS分类](#pos分类)
        - [Feature](#feature)
    - [4.2 HMM模型](#42-hmm模型)
        - [Definition](#definition)
        - [NLP应用](#nlp应用)
    - [4.3 MEMM模型](#43-memm模型)
        - [Definition](#definition-1)
        - [计算流程](#计算流程)
    - [4.4 CRF模型](#44-crf模型)
        - [特点](#特点)
        - [计算流程](#计算流程-1)
- [5. Language Model](#5-language-model)
    - [5.1 Overview](#51-overview)
        - [Sequence Probability](#sequence-probability)
        - [应用场景](#应用场景)
    - [5.2 n-gram](#52-n-gram)
        - [预测流程](#预测流程)
        - [模型评估 Perplexity](#模型评估-perplexity)
    - [5.3 Smoothing](#53-smoothing)
        - [Naive Smoothing](#naive-smoothing)
        - [模型组合](#模型组合)
        - [Kneser-Ney smoothing](#kneser-ney-smoothing)
        - [Stupid backoff](#stupid-backoff)
    - [5.4 Brown Clustering](#54-brown-clustering)
        - [Overview](#overview-4)
        - [实现步骤](#实现步骤)
        - [实现优化](#实现优化)
- [6. Parsing](#6-parsing)
    - [6.1 Overview](#61-overview)
        - [Context-Free Grammer (CFG)](#context-free-grammer-cfg)
        - [PCFG (Probabilistic Context-free Grammer)](#pcfg-probabilistic-context-free-grammer)
        - [PCFG问题](#pcfg问题)
        - [Lexicalized Annotation优化](#lexicalized-annotation优化)
    - [6.2 CKY算法](#62-cky算法)
        - [Overview](#overview-5)
        - [算法分析](#算法分析)
    - [6.3 Dependency](#63-dependency)
        - [Dependency Tree](#dependency-tree)
        - [Transition-based Parsing](#transition-based-parsing)
        - [Dense优化](#dense优化)
        - [Graph-based Parsing](#graph-based-parsing)
- [7. Machine Translation](#7-machine-translation)
    - [7.1 Sequence to Sequence Model](#71-sequence-to-sequence-model)
        - [Overview](#overview-6)
        - [工作流程](#工作流程)
        - [Problem](#problem)
        - [模型训练](#模型训练)
    - [7.2 Attention Mechanism](#72-attention-mechanism)
        - [Overview](#overview-7)
        - [优化](#优化)
        - [在Seq2Seq模型中的应用](#在seq2seq模型中的应用)
    - [7.3 Transformers](#73-transformers)
        - [Self-Attention](#self-attention)
        - [Encoder/Decoder中应用](#encoderdecoder中应用)
        - [优化总结](#优化总结)
    - [7.4 BERT](#74-bert)
        - [Overview](#overview-8)
        - [Training](#training)


# 1. Overview

### 1.1 目标

| 分类 | 翻译 | 识别 | 分析 |
| ---- | ---- | ---- | ---- |

- 识别词性 (POS)
- 识别语法 
- 识别词组含义 (国家/组织/地点...)

### 1.2 文本预处理

##### Tokenize

- 将文本拆分成有意义的token
- 移除stop words,减小vocabulary set大小
- 使用词组来表示token

- 将文档转换成用数学形式表示的矩阵

##### 未知单词处理

- 增强模型遇到未知单词处理是的鲁棒性
- 将训练集中出现频次较少的一些单词抽样作为\<UNK\> token表示
- 当模型看到输入中有未知单词时,将其视为\<UNK\>单词来预测
- 通常会考虑\<UNK\>的时态,会在前后加上必要的suffix和prefix

### 1.3 TF-IDF

##### 词频(Term Frequency)

- 单词在特定文档中出现的频率
- 标准化$TF=\frac{n(\text{输入单词})}{n(\text{文档总单词数})}$
- 值越高,单词对文档的意义越大

##### 逆文档频率(Inverse Document Frequency)

- 单词在所有文档中出现的频率
- $IDF=\log(\frac{所有文档数量}{包含该词的文档数+1})$
- 值越高,说明单词的信息越少

##### TF-IDF

- 通过计算$TF$和$IDF$的乘积来评价单词对于分类的意义
- <u>单词在特定文档中的出现频率高,且在其他文档中出现的频率低,则说明它适合用来分类</u>
- 将不同文档转换成$TF-IDF$向量,则可以通过预选相似度描述文档间的关系

# 2. Embedding

### 2.1 Vector Representation

##### Overview

- 通过向量来表示单词/categorical data
- 可以通过向量可视化来表现单词之间的联系

##### One-hot Encoding

- 用于Categorical data, 对于$V$种类别,使用长度为$V$的向量来表示每一类
- 每个类别有唯一元素的值为1,其他都为0
- 所有类别之间的距离相等
- 可以组成稀疏矩阵用来降维并提取密度更高的信息

##### Cosine Similarity

- 描述了单词之间的相似度(夹角)
  $$
  cos(x,y)=\frac{x^t y}{\sqrt{|x|^2_2|y|^2_2}}
  $$

- $x$可以是单词的df-idf表示,也可以是word2vec表示

### 2.2 SVD降维

##### Term-Docuemnt Matrix

- 描述了每个单词在每个文档中的出现次数(也可以用tf-idf代替)

  |       | doc1 | doc2 | doc3 |
  | ----- | ---- | ---- | ---- |
  | word1 | 1    | 6    | 3    |
  | word2 | 0    | 0    | 10   |
  | word3 | 2    | 2    | 1    |

- 通过SVD降维可以把单词映射到更少的维度

##### 降维流程

1. 对于Term-Document Matrix $A$进行奇异值分解$A=U\Sigma V^T$
2. 保留$\Sigma$中较大的$k$个奇异值,并从$U$和$V^T$保留对应的前$k$列
3. $U$成为Concept矩阵,描述了每个单词在$k$维度中的表示,每一列是一个concept

### 2.3 <u>Word2Vec</u>

本质上是根据context来推断单词的向量表示,因为只有近似的单词才可以产生相似的context

##### 降采样

- 根据单词的出现频率,从文本中删除(只移除特定instance)
- 单词删除概率$P(w_i)=(\sqrt\frac{c(w_i)}{0.001}+1)\frac{0.001}{c(w_i)}$

##### 训练流程

- 使用onehot编码所有单词,并作为神经网络的输入和输出
- 设定滑动窗口大小$n$
- 对于文档中的每个单词,以滑动窗口中心的单词为input (target word),剩余单词为output (context word),作为样本 (target word, context word, 1)
- 使用2层的神经网络,对样本进行多分类训练,使得(intput, output)的分类概率尽可能偏向于1
- 隐藏层神经元个数就是word2vec embedding单词后的向量维度
- 隐藏层可以作为embedding machine将word转化为vec 

##### 负采样

- 针对每个正样本选取5-20个单词,作为负样本 (target word, negative word, 0)
- 每个单词被选中的概率由出现频率决定$P(w_i)=\frac{c(w_i)^{3/4}}{\sum c(w_i)^{3/4}}$

- 负样本应该和输入不同,分类概率应该尽量偏向于0

# 3. 文本分类

给定一个文本,模型将文本映射到匹配空间,对文本进行分配

### 3.1 极大似然估计

假设所有单词出现的概率独立,根据单词出现的似然函数对文本分类

##### 流程

1. 给定每个单词在各种情况下的概率$P[word|label]$
2. 获得文本在不同类别下的似然函数$L[sentence|label]=P[word_1|label]\cdots P[word_{-1}|label]$
3. 选择$L$最大的class

##### Smoothing

- 用于处理没有出现过的单词,给$P[word|label]$设定一个初始值,否则会导致$L=0$
- $P[word|class]=\frac{|word|}{|label|}\rightarrow \frac{|\text{word出现次数}|+\alpha}{\text{|label中所有单词数量|}+\text{vocabulary size}\times\alpha}$

### 3.2 朴素贝叶斯

##### 流程

1. 基于不同结果的先验分布$P[label],P[\neg label]$

2. 使用历史结果获得单词出现的似然函数$P[words|label]$8

3. 带入使用贝叶斯法则获得结果
   $$
   P[label|words]=\frac{P[words|label]P[label]}{P[words|label]P[label]+P[words|\neg label]P[\neg label]}
   $$

##### 缺点

- 需要有可靠的<u>先验分布</u>
- 忽视了单词出现的顺序
- <u>单词出现概率其实不独立</u> (用T/F代替计数来缓解)

### 3.3 逻辑回归

##### Overview

- 本质上是假定输出服从伯努利分布的广义线性模型
- $Y_n=\sigma(X^T\beta)=\frac{1}{1+e^{-X^T\beta}}$

- 损失函数$L(\beta)=y(\beta\cdot x)+\ln\hat y=y(\beta\cdot x)-\ln(1+\exp^{-\beta\cdot x})$

##### 训练流程

1. 使用tokenizer将document转化为词袋矩阵,并稀疏化
2. 构造模型的权重参数,可以初始化为0
3. 使用SGD等方法训练

### 3.4 神经网络

##### RNN

$$
s_i=g(s_{i-1}W^s+x_iW^x+b)
$$

- 神经网络中间层会记录序列的隐状态
- 隐状态会被保留,并在下一个单词输入的时候用于预测新的隐状态
- 可以保存双向的隐状态,保存未来信息

##### LSTM

- 在隐藏层之外,添加了记忆层,用来保存序列之前的信息

- 通过输入$x_t$,上一次状态$h_t$,遗忘门$\sigma(W_f)$和记忆门$\sigma(W_i)\tanh(W_c)$来处理记忆
  $$
  c_t=\sigma(W_f\begin{bmatrix}[h_{t-1} & x_t]\end{bmatrix})\cdot c_{t-1}+\sigma(W_i\begin{bmatrix}[h_{t-1} & x_t]\end{bmatrix})\tanh(W_c\begin{bmatrix}[h_{t-1} & x_t]\end{bmatrix})
  $$

- 根据更新后的记忆门来更新隐藏层
  $$
  h_t=\tanh(c_t)\sigma(W_o\begin{bmatrix}[h_{t-1} & x_t]\end{bmatrix})
  $$

### 3.5 文本主题分类

##### Overview

- 将文本和单词映射到低维度的topic空间,从而实现单词和文本的各自分类
- 可以用于检索,将文本和单词根据topic联系起来
- 挖掘单词$w$,文档$d$和主题$z$之间的相关性

##### <u>LSA (Latent Semantic Analysis)</u>

- 使用SVD将文档和文本矩阵$A$分解$A=U\Sigma V^T$
- 保留前$k$大的奇异值后再复原得的$A'$,描述了文档和文本间的相关性
- 通过将$A’$的列向量/行向量自乘,可以获得不同文档/文本的相似度
- $U/V$的数值分别代表了每个单词/文档和topic间的相关性
- LSA分类得到的topic很难和实际概念联系起来,可解释性差

##### PLSA (Probabilistic Latent Semantic Analysis)

- PLSA将每篇文档视作基于单词在不同topic上的概率分布
  $$
  P(w,d)=P(d)\sum_{z\in\text{topics}}P(w|z)P(z|d)=\sum_{z\in\text{topics}}P(z)P(d|z)p(w|z)
  $$

- 已知单词和文档出现的概率$P(w,d)$和topic先验分布$p(z)$因此可以使用MLE和EM来估计$P[w|z]$和$p[d|z]$

  1. 计算topic在不同文档和主题下出现的概率
     $$
     P(z|d,w)=\frac{P(z)P(d|z)P(w|z)}{\sum_{z'\in Z}P(z')P(d|z')P(w|z')}
     $$

  2. 用极大似然估计更新单词在主题下出现的概率和主题在文档下出现的概率
     $$
     P(w|z)=\frac{\sum_dn(d,w)P(z|d,w)}{\sum_{d,w'}n(d,w')P(z|d,w')}\\
     P(d|z)=\frac{\sum_wn(d,w)P(z|d,w)}{\sum_{d,w'}n(d,w')P(z|d,w')}
     $$
  
- 容易过拟合,且无法用训练结果给新文档分类

##### <u>LDA (Latent Dirichlet Allocation)</u>

- 对于文本在不同topic下的分类结果,赋予一个多维狄拉克先验分布,从而能够给新文档分类

- 本质是通过Gibbs采样求每篇文档下的topic后验分布,后验分布的期望即每个主题的概率

- 生成文档流程

  1. 根据topic的Dirichlet分布$\vec\alpha$,生成多项分布概率$\vec \theta_z$ (长度为topic数的向量)

  2. 把$\theta_z$作为多项分布的参数,生成每个单词的主题序列$\vec z_m$(长度为单词数的向量)

  3. 根据每个topic下单词的Dirichlet分布$\vec\beta$,生成单词在该topic下的多项分布概率$\vec \varphi_c$ (长度为单词数的向量)

  4.  把$\vec \varphi_c$作为多项分布的参数,生成对应主题中的单词序列$\vec w_m$

  5. 则有文档生成概率
     $$
     p(\vec w_m,\vec z_m,\theta_z,\varphi_z|\vec\alpha,\vec\beta)=\prod_{m=1}^M p(\vec w_m|\vec\varphi_z)p(\vec z_m|\vec\theta_z)p(\vec\theta_z|\vec\alpha)p(\vec\varphi_z|\vec\beta)
     $$

- 训练模型流程

  1. 对文档中的每个单词随机分配主题$z$

  2. 计算每个单词/主题在其他单词主题下的条件概率

  3. <u>基于基于$n_{d,z}$(文档$d$中主题$z$数)和$v_{z,w}$(主题$z$中单词$w$数)构造条件概率对每个单词重新进行采样,采样前要将对应的计数-1</u>(本质是Gibbs采样)
     $$
     p(w=z)=\frac{n_{d,z}+\alpha_z}{\sum_{i}^Zn_{d,i}+\alpha_i}\frac{v_{z,w}+\beta_w}{\sum_i^Wv_{z,i}+\beta_i}=\theta_{d,z}\varphi_{z,w}
     $$

  4. 重复直到收敛,对采样计数获得$p(\vec w_m|\vec\varphi_z)$和$p(\vec z_m|\vec\theta_z)$

# 4. Part of Speech词性标注

### 4.1 POS定义

##### Overview

- 每个单词符合一定的词性(POS),但是没有直接体现在序列中
- 词性是单词的隐含状态,单词词性的概率表现形式$P[word_i|POS_i]$
- 不同的词性之间可以相互转换$P[POS_i|POS_{i-1}]$,可以使用先验分布

##### POS分类

- Close Class: 大小有限的POS,例如代词只有I/he/she/them...
- Open Class: 没有限制的POS,例如不断会有新的形容词出现

##### Feature

- 单词内容和特征(ly结尾,大小写等)
- 前后语境里的单词

### 4.2 HMM模型

##### Definition

- First Order: 只考虑上一个状态的转换,生成序列的的概率
  $$
  P[y_{1:n}]=P[y_1]P[y_2|y_1]P[y_3|y_2]\cdots P[y_n|y_{n-1}]
  $$

- 状态转移矩阵,描述了不同状态之间转移的概率
  $$
  P=\begin{bmatrix}
  P[y_1|y_1] & P[y_2|y_1] &\cdots&P[y_n|y_1]\\
  P[y_1|y_2]& P[y_2|y_2] &\cdots&P[y_n|y_2]\\
  \cdots & \cdots &\cdots &\cdots\\
  P[y_1|y_n]& P[y_2|y_n] &\cdots&P[y_n|y_n]
  \end{bmatrix}
  $$

- Fully Order: 考虑到之前<u>所有状态的</u>转换模型(不好计算) $P[y_{1:n}]=P[y_1]P[y_2|y_1]P[y_3|y_1,y_2]\cdots P[y_n|y_1,y_2\cdots y_{n-1}]$

##### NLP应用

- 需要考虑到每个单词在特定状态下出现的概率

- 找到出现概率最大的马尔科夫链 
  $$
  P[y_{1:n}]=\prod P[y_i|y_{i-1}]P[x_i|y_{i}]
  $$

- <u>Viterbi算法</u>: 通过动态规划,计算$P[y_{1:n}]$时,只需要计算$P[y_{1:n-1}]$结尾是不同POS的最大概率
- 通过训练集中的先验分布和人工标注来获得状态转移矩阵$P$和单词表现概率$P[x_i,y_i]$

### 4.3 MEMM模型

##### Definition

- 获得状态的概率需要同时考虑上一个状态$y_{n-1}$和之前所有观测的观测结果$x_{0:n}$
- 可以直接计算给定观测序列下的概率 $P[y_{1:n}|x_{1:n}]=\prod P[y_i|y_{i-1},x_{1:n}]$
- $f_k:$特征函数,将包含自定义特征的样本映射到1,每个特征的权重为$\lambda_k$



##### 计算流程

1. 假定不同序列的概率为$P[y_{1:n}]$,设立优化目标来最大化Entropy: $\min\sum P[y_{1:n}|x_{1:n}]\log P[y_{1:n}|x_{1:n}]$

2. 基于每个样本设定和特征函数,设定最优化的限制条件 $\sum\hat P[x_{1:n},y_{1:n}]f(x_{1:n},y_{1:n})=\sum\hat P[x_{1:n}]P[y_{1:n}|x_{1:n}]f(x_{1:n},y_{1:n})$

3. 根据归一化设定约束条件$\sum P[y_{1:n}|x_{1:n}]=1$

4. 使用拉格朗日对偶求解最优化问题
   $$
   P[y_{1:n}|x_{1:n}]=\prod\frac{\exp \sum_{k=1}^M\lambda_kf_k(y_n,y_{n-1},x_{1:n})}{Z(y_{i-1},x_{1:n})}\\
   Z(y_{i-1},x_{1:n})=\sum_{y_{1:n}}\exp \sum_{k=1}^M\lambda_kf_k(y_n,y_{n-1},x_{1:n})
   $$

### 4.4 CRF模型

##### 特点

- 不考虑序列的方向,可以利用序列中的未来信息
- 准确率比MEMM更高,但是需要大量计算

##### 计算流程

$$
P[y_{1:n}|x,\beta]=\frac{\exp F(x,y_{1:n})^T\beta}{\sum_{y_{1:n}}\exp F(x,y_{1:n})^T\beta}
$$

- $F$是特征函数矩阵,和MEMM相同

# 5. Language Model

### 5.1 Overview

##### Sequence Probability

- 给定任意单词序列,给出单词序列发生的可能性
- 给定Context,预测下一个出现的单词

##### 应用场景

- Text generating: 搜索引擎/输入法自动填充
- Translation/OCR: 理解文本语义

### 5.2 n-gram

##### 预测流程

- 给定单词$w_i$在$w_{i-1},w_{i-2},\cdots,w_{i-n}$时出现的概率$P[w_i|w_{i-1},w_{i-2}\cdots]=\frac{c(w_i,w_{i-1},w_{i-2}\cdots)}{c(w_{i-1},w_{i-2}\cdots)}$
- 选择出现概率最高的$w_i$

- unigram就是$n=0$,即不考虑任何context
- <u>需要把语句的start和end作为特殊的单词考虑</u>

##### 模型评估 Perplexity

- 给定任意长度为$N$的文本输入,则有perplexity$=\exp(-\frac{1}{N}\sum_{i}^N\log P[w_i] )$

- perplexity越高,说明模型$P[w_i]$越低,表示模型对于输入越惊讶,泛化能力弱

### 5.3 Smoothing

##### Naive Smoothing

- 当单词在训练集中没有出现过时,分布概率不为0,而是平滑的概率
  $$
  P[w_i|w_{i-1},w_{i-2}\cdots]=\frac{c(w_i,w_{i-1},w_{i-2}\cdots)+\alpha}{c(w_{i-1},w_{i-2}\cdots)+\sum_{j=1}^V\alpha_j}
  $$

- 

- 平滑后,模型可能会对经常出现的单词有偏爱

##### 模型组合

- 同时训练不同的$n-gram$模型,并通过组合预测来提高鲁棒性和平滑度

$$
\hat P[w_i|w_{i-2},w_{i-1}]=\lambda_1P[w_i|w_{i-2},w_{i-1}]+\lambda_2P[w_i|w_{i-1}]+\lambda_3P[w_i]\\
\lambda_1+\lambda_2+\lambda_3=1
$$

- 通过grid search或者EM算法来寻找最优的$\lambda_i$

##### Kneser-Ney smoothing

- 当遇到从未出现的组合时,模型可能只会输出最长出现的单词

- 通过添加contiuation probability来优化输出,描述了以$w_i$结尾的ngram种类数和所有ngram种类数的比例
  $$
  P[w_i|w_{i-1},w_{i-2}]=\frac{\max\{c(w_{i-2},w_{i-1},w_{i})-d,0\}}{c(w_{i-2},w_{i-1})}+k_{i-1}\frac{|v\in V: c(v,w_i)>0|}{|a,b\in V: c(a,b)>0|}
  $$

##### Stupid backoff

- 当发现n-gram预测单词出现概率为0时,使用n-1 gram预测,直到不为0为止
- 有大量数据时,表现和KN smoothing相似,但是需要训练多个模型

### 5.4 Brown Clustering

##### Overview

- 给定文本序列,将文本序列单词聚合成不同的cluster
- 先将每个单词单独当做一个cluster,将类似的cluster merge
- context word相近的cluster就是相似的cluster (MLE减小最少的merge方法)

- 考虑序列在当前cluster下出现的概率,第$i$单词的出现概率由cluster概率乘以单词概率$P[W_i|C_i]P[C_i|C_{i-1}]$计算
  $$
  L(S)=P[C_1|Start]P[W_1|C_1]P[C_2|C_1]P[W_2|C_2]\cdots
  $$

- merge完成后,可以用二进制表示每个单词在cluster中的位置作为embedding

##### 实现步骤

1. 将每个单词视为cluster,一共有$|V|$个cluster,复杂度为$O(|V|)$
2. 分别尝试合并两两cluster,更新$P[C_i|C_j]$和$P[W_k|C_i]$并计算MLE,每次复杂度为$O|V^2|$
3. 选择最高的合并方式,复杂度为$O|V^2|$
4. 一共要$O|V^5|$耗时过久

##### 实现优化

1. 在聚合前先计算每个单词的频率,选择频率前$m$高的单词,独自成cluster
2. 对于每个新单词,先构造一个新cluster,一共有$m+1$个cluster,复杂度为$O(|V|)$
3. 在当前的$m+1$个cluster中选取两个合并,cluster的数量回到$m$
4. 因为已有的$m$个cluster不会两两merge,因此原来$O|V^2|$复杂度的操作变成$O|V|$,总复杂度变成$O|V^3|$

# 6. Parsing

### 6.1 Overview

##### Context-Free Grammer (CFG)

- 用递归树结构描述文本中的符号组成有效结构的模式 (将语句元素分组),由4部分组成

  | 非终结符集 $N$         | 终结符集 $\Sigma$ | 产生式集 $R$                               | 初始符号 $S$ |
  | ---------------------- | ----------------- | ------------------------------------------ | ------------ |
  | 词组的抽象表示,如 $NP$ | 具体单词,如 $dog$ | 非终结符的拆分逻辑 $N\rightarrow N/\Sigma$ | 特殊的符号   |

- 可以用来检测语法错误,或分析语句中的语义

##### PCFG (Probabilistic Context-free Grammer)

- 给CFG产生式集R中的每一条拆分逻辑$r\in R$,赋予一定概率$P[r]$

- 用$T,S$来描述解析树结构和文本,寻找在该文本下出现概率最大$P[T,S]$的树$T$

- 每个子树的拆分概率由每一颗子树组成,$A$代表子树父节点,是非终结符,$\beta$是叶结点,为终结符/非终结符
  $$
  P[T,S]=\prod P[\beta|A]
  $$

##### PCFG问题

- <u>PCFG没有考虑单词语义,生成概率有误差</u>
- 假设每一次parse的概率都是independent的,但是实际上不是

##### Lexicalized Annotation优化

- 自顶向下解析时,每个结点同时记录父节点,获得更多dependency信息
- 自顶向上解析时,根据规则父节点保留子节点中的重要单词和parse结果
- 每个结点的信息更多,因此rules会更多,但是准确率会提高

### 6.2 CKY算法

##### Overview

- 自底向上动态规划,先将每个单词分成单独一组然后向上聚合
- 对于每一个单词生成解析的非终结符,再逐个和之前已经生成的结果比较,查看是否可以合并继续生成

##### 算法分析

```python
def CKYparse(words, grammer):
    table = [[set() for i in range(len(words))] for range(len(words))] # 构造返回的table,第i,j元素代表[i,j]单词的解析结果
    for w in range(len(words)): # 遍历每个单词
        for g in grammer[words]: # 遍历单词可能生成语法
            table[w][w].add(g)
        for p in range(w, -1, -1): # 自下向上遍历本单词表格列,查看是否有合并项
            for s in range(p-1, -1, -1): # 遍历另一个单词的解析
                for g1 in table[s][p-1]:
                    for g2 in table[p][w]: # 比较并拼接两条解析
                        if g1 + g2 in grammer:
                            table[s][w].add(g1 + g2)
```

- 时间复杂度为$O(|S|^3\cdot |R|)$
- 可以在表格计算时递归计算概率,从而获得最大概率的解析树
- 可以结合Lexicalized Annotation中的自底向上解析,提高准确率

### 6.3 Dependency

##### Dependency Tree

- 从语义出发,构造的依赖树。忽略单词顺序,描述了单词之间的依赖关系
- 是一个有向无环图,root没有入边,通常动词作为root
- 除root外所有节点只有一条入边

##### Transition-based Parsing

- 使用Stack保存单词,根据Buffer中的内容,Parse器可以进行3三种操作
  - 将Buffer中的单词加入Stack
  - 判定stack[1]依赖于stack[2]并移除stack[2]
  - 判定stack[2]依赖于stack[1]并移除stack[1]

- 训练一个分类器,接受Buffer和Stack,预测正确的Parse操作
- 通过Oracle来根据Parse Tree生成action序列作为训练集

##### Dense优化

- 可以在stack中保存POS/已知dependency等更多信息提高训练准确度
- 使用类似word2vec的思想,将单词/POS/已知dependency压缩,减少输入量

##### Graph-based Parsing

- 有的Parse Tree无法用action序列描述 (Oracle和Transition Parsing无效)

- 用有向边描述单词之间的依赖关系,并给每条边评分,模型的参数为每条边特征的权重

- 每条边的可选特征

  | 起点和终点在语句中的距离 | 起点/终点的词性 | 起点/终点的内容 | 起点和终点的已知依赖关系 |
  | ------------------------ | --------------- | --------------- | ------------------------ |

- 找到MST使得边的得分最高(即分类效果最好) $\arg\max_t score(t,S)=\sum_{e\in t}score(e)$

- 每个edge的score由单词距离,

# 7. Machine Translation

### 7.1 Sequence to Sequence Model

##### Overview

- 输入和输出的长度不同,例如翻译后的单词数不一定相同
- 通过两个模型,encoder将输入编码成隐状态,decoder解码隐状态输出单词,两个模型都可以是RNN
- decoder输出前,遍历所有可能的输出结果(输出向量+隐状态),经过softmax后,生成概率最大结果

##### 工作流程 

1. 训练encoder模型接受序列输入
2. 将第一个encoder模型输出的隐状态作为输入的语义编码$S$
3. 训练第二个decoder模型,接受语义编码,给出翻译结果
4. 对于每个翻译单词$X_t$决定于语义编码和自身的上一个输出$X_t=f(S, S_{t-1})$
5. 当输出终止符时,输出结束

##### Problem

- 需要遍历结果,计算量大
- 容易陷入重复输出(输出向量和隐状态生成相同的结果)
- 不好处理未见过的单词,且隐状态向量的长度限制了输入范围

##### 模型训练

- 模型上一个时刻错误输出$X_{t-1}$,会导致错误的输入和当下错误输出$X_{t}$,产生差错的蝴蝶效应

- Scheduled Sampling: 在训练时,通过一定概率选择上一时刻输出$X_{t-1}$和正确结果$Y_{t-1}$作为该时刻输入

### 7.2 Attention Mechanism

##### Overview

- 通过对于输入中的不同部分添加权重,来模拟attention的过程
- 训练一个向量$V$,作用于输入,再通过softmax函数生成每个点的关注度$P(X)=\sigma(VX)$
- 将关注度作为权重,作用于原输入,关注度较高的向量会因为高权重,扮演重要作用 $X'=P(X)X=\sigma(VX)X$

##### 优化

- 使用不同的$V$和不同的输入方式,例如添加非线性层
- 训练多个$V$进行多层次作用
- 对于整句embedding进行Attention后再对单词进行embedding

##### <u>在Seq2Seq模型中的应用</u>

- decoder不光接受encoder的最终输出,而是保存encoder所有时刻的输出$H$

- decoder在解码时,根据上一次自身的隐状态输出$h_{t-1}$计算和encoder所有输出$H$的注意力,并重新构造隐状态输入$c_{t-1}=\sigma(h_{t-1}\cdot H)H$

- 将新的隐状态输入$c_{t-1}$和上一次的隐状态输出$h_{t-1}$一起作为输入,生成下一个输出$h_{t}=f(c_{t-1}, h_{t-1})$
- 通过注意力机制,可以获得decoder在encoder输入信息中的焦点,提供可视化

### <u>7.3 Transformers</u>

##### Self-Attention

1. 对输入的词向量额外添加位置编码信息
2. 通过训练的三个权重矩阵$W_q,W_k,W_v$,生成对应矩阵$Q=W_qX,K=W_kX,V=W_vX$
3. 使用每个单词$i$自身的Query矩阵$Q_i$和其他所有单词的Key矩阵$K_j$生成$i$单词对$j$单词的注意力,并使用softmax归一化 $e_{ij}=\sigma(\frac{Q_iK_j^T}{\sqrt D})$
4. 使用归一化的结果,对单词的value矩阵$V_i$分配权重,生成新的输入向量
5. 对于新的输入向量,进行残差相加,再通过一层全连接神经网络输出

##### Encoder/Decoder中应用

- Encoder和Decoder可以通过自连接,反复进行self attention操作,但是数量必须相等
- Encoder和Decoder都会对输入单词进行self attention操作
- Encoder最终可以并行的生成每个单词经过self attentation后的向量,并交给decoder作为输出

##### 优化总结

- 对每个单词的原始输入进行权重变换,从而使得$e_{ij}$的结果更均匀,否则$X_iX_i^T$的值会远大于$X_iX_j^T$
- softmax前除以$\sqrt D$可以减小$\sigma$的输入值,从而增加反向传播的梯度

- 可以训练多组$W_q,W_k,W_v$并反复进行self attention来捕获更多信息

### 7.4 BERT

##### Overview

- Bert本质上是使用Transformers机制的encoder,给定单词在句层面,词义层面和位置的embedding信息,可以输出multi attention转化后的单词向量
- 通过在Bert输出结果之后添加网络层,使其应用于不同的NLP任务

##### Training

- MLM非监督学习: 通过给Bert输入单词被Mask后的语句,使模型生成原单词
- NSP非监督学习: 通过给Bert输入两句句子,使模型判断两句句子是否是紧挨着的



