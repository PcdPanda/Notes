[toc]

# 1. 基本概念

### 1.1 目标

| 分类 | 翻译 | 识别 | 分析 |
| ---- | ---- | ---- | ---- |

- 识别词性 
- 识别语法
- 识别词组含义 (国家/组织/地点...)

### 2.1 文本分类

给定一个文本,模型将文本映射到匹配空间,对文本进行分配

##### 极大似然估计

假设所有单词出现的概率独立,根据单词出现的似然函数对文本分类

##### 流程

1. 给定每个单词在各种情况下的概率$P[word|class]$
2. 获得文本在不同类别下的似然函数$L[sentence|class]=P[word_1|class]\cdots P[word_{-1}|class]$
3. 选择$L$最大的class

##### Smoothing

- 用于处理没有出现过的单词,给$P[word|class]$设定一个初始值
- $P[word|class]=\frac{|word|}{|class|}\rightarrow \frac{|word|+\alpha}{|class|+\text{vocabulary size}\times\alpha}$

##### 朴素贝叶斯

##### 流程

1. 基于不同结果的先验分布$P[pos],P[neg]$

2. 使用历史结果获得单词出现的似然函数$P[words|class]$

3. 带入使用贝叶斯法则获得结果
   $$
   P[pos|words]=\frac{P[pos]P[words|pos]}{P[pos]P[words|pos]+P[neg]P[words|neg]}
   $$

##### 缺点

- 需要有可靠的<u>先验分布</u>

- 忽视了单词出现的顺序

- <u>单词出现概率其实不独立</u> (用T/F代替计数来缓解)


# 2. 文本预处理

### 2.1 Tokenize

##### 目标

- 将文本拆分成有意义的token
- 移除stop words
- 使用词组来表示token

### 2.2 Build Matrix

- 将文档转换成用数学形式表示的矩阵

### 2.3 TF-IDF

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