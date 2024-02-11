- [1. 向量空间](#1-向量空间)
    - [1.1 空间定义](#11-空间定义)
        - [向量空间](#向量空间)
        - [子空间](#子空间)
        - [正交](#正交)
        - [投影](#投影)
    - [1.2 线性独立](#12-线性独立)
        - [线性独立](#线性独立)
        - [维度](#维度)
    - [1.3 矩阵向量空间](#13-矩阵向量空间)
        - [基本空间](#基本空间)
        - [其他空间](#其他空间)
- [2. 矩阵和线性变换](#2-矩阵和线性变换)
    - [2.1 矩阵乘法](#21-矩阵乘法)
        - [左乘(行变换) $EA$](#左乘行变换-ea)
        - [右乘(列变换) $AB$](#右乘列变换-ab)
        - [点乘 $RC$](#点乘-rc)
        - [向量乘 $CR$](#向量乘-cr)
        - [块相乘](#块相乘)
    - [2.2 矩阵方程](#22-矩阵方程)
        - [高斯消元法和pivot](#高斯消元法和pivot)
        - [解的数量](#解的数量)
        - [最小二乘法](#最小二乘法)
    - [2.3 矩阵的逆](#23-矩阵的逆)
        - [存在条件](#存在条件)
        - [基本性质](#基本性质)
        - [长方形矩阵的逆](#长方形矩阵的逆)
    - [2.4 行列式](#24-行列式)
        - [基本性质](#基本性质-1)
        - [计算方式](#计算方式)
    - [2.5 特征值和特征向量](#25-特征值和特征向量)
        - [基本定义和计算流程](#基本定义和计算流程)
        - [性质](#性质)
- [3. 重要特殊矩阵](#3-重要特殊矩阵)
    - [3.1 基本矩阵 $E$](#31-基本矩阵-e)
        - [行排序矩阵](#行排序矩阵)
        - [行相加矩阵](#行相加矩阵)
    - [3.2 投影矩阵](#32-投影矩阵)
    - [3.4 伴随矩阵](#34-伴随矩阵)
        - [使用伴随矩阵求逆](#使用伴随矩阵求逆)
        - [克莱姆法则](#克莱姆法则)
    - [3.5 对称矩阵](#35-对称矩阵)
        - [特征值分解](#特征值分解)
        - [正定矩阵](#正定矩阵)
- [4. 矩阵分解](#4-矩阵分解)
    - [4.1 LDU分解](#41-ldu分解)
    - [4.2 QR分解](#42-qr分解)
        - [分解流程(施密特正交)](#分解流程施密特正交)
    - [4.3 特征值分解](#43-特征值分解)
        - [分解性质 (常用于矩阵的幂)](#分解性质-常用于矩阵的幂)
    - [4.4 SVD分解](#44-svd分解)
        - [基本概念](#基本概念)
        - [计算方法](#计算方法)
        - [性质](#性质-1)
- [5. 矩阵求导](#5-矩阵求导)
    - [5.1 重要矩阵](#51-重要矩阵)
        - [梯度](#梯度)
        - [海森矩阵(Hessian)](#海森矩阵hessian)
        - [雅各比矩阵(Jacobian)](#雅各比矩阵jacobian)
    - [5.2 标量对矩阵求导](#52-标量对矩阵求导)
        - [标量对向量求导](#标量对向量求导)
        - [标量对矩阵求导](#标量对矩阵求导)
    - [5.3 向量对矩阵求导](#53-向量对矩阵求导)
- [6. 线性代数应用](#6-线性代数应用)
    - [6.1 图论](#61-图论)
    - [6.2 级数](#62-级数)
        - [幂级数](#幂级数)
        - [指数级数](#指数级数)
        - [傅里叶级数](#傅里叶级数)
    - [6.3 解微分方程](#63-解微分方程)
        - [常规求解流程](#常规求解流程)
        - [指数级数求解流程](#指数级数求解流程)
        - [特征值分析](#特征值分析)
    - [6.4 马尔科夫转换](#64-马尔科夫转换)
        - [定义](#定义)
        - [性质](#性质-2)
    - [6.5 信号压缩](#65-信号压缩)
        - [基本概念](#基本概念-1)
        - [傅里叶基(JPEG)](#傅里叶基jpeg)
        - [小波基 (wavelet)](#小波基-wavelet)


# 1. 向量空间

### 1.1 空间定义

##### 向量空间 

对于任意$u,v\in\mathbb{V}$

- 相加封闭 $u+v\in\mathbb{V}$
- 乘以标量封闭 $\alpha u\in\mathbb{V}$

<u>过原点的直线，平面都是向量空间</u>

##### 子空间

过原点的直线是平面的子空间 

- 向量空间的子集
- 具有向量空间的性质
- 子空间的<u>交集是向量空间,并集不一定是</u>

##### 正交

- 向量正交: $xy^T=0\rightarrow xx^T+yy^T=(x+y)(x+y)^T$
- 空间正交: $\forall x\in X,y\in Y, xy^T=0$

##### 投影

- $b$在$a$上的投影分量: $a\frac{a^T b}{a^Ta}=Pb$
- $b$和$a$的正交分量: $b-a\frac{a^T b}{a^Ta}=(I-P)b$

### 1.2 线性独立

##### 线性独立

- $\alpha_1v_1+\alpha_2v_2\cdots a_nv_n=0$只有$\alpha_1=\alpha_2\cdots=\alpha_n=0$成立

- 线性独立的向量不能通过其他向量的线性组合获得
- 基:一组线性独立的向量,线性组合是整个空间

##### 维度

- $\dim(S)$: 空间中,一组基里的向量个数
- $\dim(A)+\dim(B)=\dim(A\cap B)+\dim(A\cup B)$ (假设$A,B$分别是两个平面)

### 1.3 矩阵向量空间

给定矩阵$A\in\R^{m\times n}$

##### 基本空间

- 列空间$C(A)$
  - 矩阵列组成的空间
  - 维度为rank

- 行空间$C(A^T)$
  - 矩阵行组成的空间
  - 维度为rank
- 左零空间$N(A)$
  - $Ax=0$所有$x$组成的空间
  - 和行空间正交
  - 维度为$n-r$
- 右零空间$N(A^T)$
  - $xA=0$所有$x$组成的空间
  - 和列空间正交
  - 维度为$m-r$

##### 其他空间

- 三角矩阵(upper/lower)
- 对角矩阵(diagonal)

任何矩阵可以表示为三角矩阵和对角矩阵的线性组合

# 2. 矩阵和线性变换

### 2.1 矩阵乘法

##### 左乘(行变换) $EA$

- $E$的每一行对$A$的各行进行线性组合
- 常见于高斯消元

##### 右乘(列变换) $AB$

- $B$的每一列对$A$的各列重新进行线性组合
- 常见于解矩阵方程

##### 点乘 $RC$

- $R$中的每一行和$C$中的每一列逐个点乘

##### 向量乘 $CR$

- $C$中的第每一列和$R$中的每一行相乘
- 将所有相乘的结果相加

##### <u>块相乘</u>

- 把矩阵拆分成若干个子矩阵,把每个子矩阵当做矩阵元素相乘

### 2.2 矩阵方程

求解$Ax=b$

<u>本质是求$A$列向量的线性组合,$b$必须在$A$的列空间中</u>

##### 高斯消元法和pivot

1. 通过乘以对应的$E$矩阵下面的行减去上面的行,使其变成**U**（upper triangle)

$$
Ax=B\\
\left[\begin{array}{ccc}
1 & 2 & 1\\
3 & 8 & 1\\
0 & 4 & 1
\end{array}\right]
\rightarrow
\left[\begin{array}{ccc}
1 & 2 & 1\\
0 & 2 & -2\\
0 & 4 & 1
\end{array}\right]
\rightarrow
\left[\begin{array}{ccc}
1 & 2 & 1\\
0 & 2 & -2\\
0 & 0 & 5
\end{array}\right]
$$

2. <u>消元完成后,每行的第一个非0元素就pivot,数量和rank相等</u>
3. 自底向上回带计算$x$
4. 时间复杂度为$O(n^3)$

##### 解的数量

- $A$的行和列都满秩,则只有一个解
- $A$只有列满秩,即$\text{rref}(A)=\left[\begin{array}{c}I \\F  \end{array}\right]$,则1个解或无解
- $A$只有行满秩,即$\text{rref}(A)=\left[\begin{array}{c}I &F  \end{array}\right]$,则1个解或无数解
- 如果$A$无满秩,则无解或者无数解

##### 最小二乘法

当$b$不在$A$的列空间时,$x$无解

本质是求$b$在$A$列空间的投影

1. 确认$A$各列线性独立,否则$A^{T}A$可能不可逆
2. 两边乘以$A$的列空间投影矩阵$P=A(A^TA)^{-1}A^T$
3. $Ax=Pb$
4. 两边乘以$A^T$
5. 解$A^TAx=A^Tb$
6. $x=(A^TA)^{-1}A^{T}b$

### 2.3 矩阵的逆

求解$AA^{-1}=I$

<u>本质是求矩阵$A$的逆变换</u>

##### 存在条件

- 矩阵是方阵,且$m=n=r$
- 矩阵的行列式不为0

##### 基本性质

- 交换律:$AA^{-1}=A^{-1}A=1$
- 转置$(A^{-1})^T=(A^T)^{-1}$
- 乘法求逆$(AB)^{-1}=B^{-1}A^{-1}$
- 行列式$\det A^{-1}=\frac{1}{\det A}$
- 特征值$\lambda_{A^{-1}}=\frac{1}{\lambda_A}$

##### 长方形矩阵的逆

- 列满秩时,存在左逆 $(A^TA)^{-1}A^T$
- 左逆右乘,构造投射到列空间的投影矩阵$P=A(A^TA)^{-1}A^T$
- 行满秩时,存在右逆$A^T(AA^T)^{-1}$
- 右逆左乘,构造投射到行空间的投影矩阵$P=A^T(AA^T)^{-1}A$

### 2.4 行列式

##### 基本性质

- $\det(AB)=\det(A)\det(B)\rightarrow\det{A^{-1}}=\frac{1}{\det A}$

- 交换行后,行列式取反$\det EA=-\det A$

  - 有同行/同列的矩阵,行列式为0: $\det A=-\det A=0$

- 基本行变换之后,行列式不变: $\det(EA)=\det E\det A=\det A$

- <u>当行列式只相差一行/一列时,可以相加相减</u>
  $$
  \det\left|\begin{array}{cc}
  a+a' & b+b'\\
  c & d
  \end{array}\right|=
  \left|\begin{array}{cc}
  a & b\\
  c & d
  \end{array}\right|
  +
  \left|\begin{array}{cc}
  a' & b'\\
  c & d
  \end{array}\right|
  $$
  
- 矩阵行列式描述了矩阵变换对于<u>面积/体积的缩放比例</u>

##### 计算方式

- 从每列取一个元素乘积后求和
  - $\det(A)=\sum_{n!}\pm a_{1x_1}a_{2x_n}\cdots a_{nx_n}$
  - 一共有$n!$排列

- 取一行或者一列,每个元素乘以起余子式求和
- $LDU$分解: $\det A=\det L\det D\det U=\det D=\prod \text{pivot}$

### 2.5 特征值和特征向量

<u>本质上描述了方阵线性变换拉伸的方向和强度</u>

##### 基本定义和计算流程

对于方阵$A\in\R^{n\times n}$存在等式$Ax=\lambda x$

1. 解方程$\det(A-\lambda I)x=0$
2. 构造1元$n$次方程
3. 得到$n$个特征值$\lambda$和特征向量$v$
   - 特征值可能相同
   - 相同的特征值可能意味着缺少特征向量,除非$A-\lambda I$不满秩

##### 性质

- $\tr A=\sum\lambda_A$
  - 三角矩阵的特征值就是对角线
- $\det A=\prod \lambda_A$
  - 不可逆矩阵的特征值必然包含0

- <u>特征值平移</u>
  - $A=B+xI\rightarrow\lambda_b=\lambda_a+x$
  - $A$和$B$的特征向量相同

# 3. 重要特殊矩阵

### 3.1 基本矩阵 $E$

在高斯消元法中用来左乘,对矩阵进行行变换

##### 行排序矩阵

- 交换行$E=\left[\begin{array}{ccc}0 & 0 & 1\\1 & 0 & 0\\0 & 1 & 0\end{array}\right]$
- 转置后可以进行逆操作: $E^T=E^{-1}$

##### 行相加矩阵

- 将第三行乘以2添加到第一行上$E=\left[\begin{array}{ccc}1 & 0 & 2\\0 & 1 & 0\\0 & 0 & 1\end{array}\right]$
- $\det E=1$

### 3.2 投影矩阵

给定向量$a$,对应的投影矩阵$P$可以将任意向量投影到$a$直线上

- $P=\frac{aa^T}{a^Ta}$
- 投影矩阵的列空间是直线$a$,因此$r=1$
- 反复投影的结果相同,因此$P^n=P$
- 当$Ax=b$无法找到解时,可以找到$b$在$C(A)$的投影,从而求$Ax=Pb$

### 3.4 伴随矩阵

给定矩阵$A\in\R^{n\times n}$,则有伴随矩阵$C\in\R^{n\times n}$

每个元素是$A$的代数余子式
$$
C=\left[\begin{array}{cccc}
c_{11} & c_{12}& \cdots & c_{1n}\\
c_{n1} & c_{22}& \cdots & c_{2n}\\
\cdots & \cdots & \cdots\\
c_{n1} & c_{n2}& \cdots & c_{nn}\\
\end{array}\right]
$$

##### 使用伴随矩阵求逆

- 伴随矩阵和原矩阵满足$AC^T=\det A I$
- 代数余子式和非对应行相乘时为0,因为相当于计算一个有相等行的矩阵的行列式
- $A^{-1}=\frac{C^T}{\det A}$

##### 克莱姆法则

- 使用伴随矩阵和行列式,可以快速求解$Ax=b$
- 根据伴随矩阵定义,$B_i$是用$b$来代替$A$的第$i$列

$$
Ax=b\rightarrow x=A^{-1}b=\frac{1}{\det A}C^Tb=\frac{1}{\det A}\left[\begin{array}{ccc}
c_{11} & \cdots & c_{n1}\\
c_{12} & \cdots & c_{n2}\\
\cdots & \cdots & \cdots\\
c_{1n} & \cdots & c_{nn}\\
\end{array}\right]
\left[\begin{array}{c}
b_1 \\
b_2\\
\cdots \\
b_n
\end{array}\right]=
\left[\begin{array}{c}
\frac{\det B_1}{\det A} \\
\frac{\det B_2}{\det A}\\
\cdots \\
\frac{\det B_n}{\det A}
\end{array}\right]
$$

### 3.5 对称矩阵

给定一个方阵$A\in\R^{n\times n},A^T=A$

##### 特征值分解

- 所有特征值都是实数
- 所有特征向量都正交: $A=Q\Lambda Q^{T}$

- 可以拆分成$n$个投影矩阵的和,每个投影矩阵投影到一个特征向量上
- pivot符号和特征值一样

##### 正定矩阵

- 所有pivot/特征值都大于0
- 所有子行列式大于0
- $x^TAx>0$

# 4. 矩阵分解

### 4.1 LDU分解

将矩阵拆解为三角矩阵的积

1. 通过高斯消元法,使用基本矩阵转换需要被分解的矩阵为$E_k\cdots E_2E_1PA=U'$
2. 如果中间需要换行,则$P$矩阵为换行矩阵
3. 通过变换将$U'$的对角变为1,则变换矩阵为$D$且$U'=DU$
4. 变换矩阵的逆矩阵是$L=E_1^{-1}E_2^{-1}\cdots E_k^{-1}$
5. 最终结果$PA=LU\rightarrow A=P^{T}LU$

### 4.2 QR分解

给定任意方阵$A$,可以拆分为$QR$

- $Q$:标准正交矩阵
- $R$: 上三角矩阵

##### 分解流程(施密特正交)

从$a_1,a_2\cdots a_n$个线性独立向量,构造标准正交基

每个向量减去在其他向量方向上的投影
$$
q_1=\frac{a_1}{|a_1|}\\
q_2=(a_2-\frac{q_1q_1^T}{q_1^T q_1}a_2)/|a_2| \\
\cdots\\
q_n=(a_n-\frac{q_1q_1^T}{q_1^T q_1}a_n-\frac{q_2q_2^T}{q_2^T q_2}a_n\cdots)/|a_n|
$$

### 4.3 特征值分解

<u>给定一个可逆的$A\in\R^{n\times n}$,且有$n$个线性独立的特征向量$S=\left[\begin{array}{ccc}x_1&\cdots &x_n\end{array}\right]$</u>

可以构造特征值对角矩阵
$$
S^{-1}AS=S^{-1}\left[\begin{array}{ccc}
\lambda_1x_1&\cdots &\lambda_nx_n
\end{array}\right]=\Lambda=
\left[\begin{array}{cccc}
\lambda_1&\cdots& \cdots &0\\
0&\lambda_2 & \cdots &0\\
0&\cdots & \cdots&0\\
0&\cdots & \cdots&\lambda_n
\end{array}\right]\\
$$

##### 分解性质 (常用于矩阵的幂)

- $A=S\Lambda S^{-1}$
- $A^{n}=S\Lambda^nS^{-1}$
- 特征值决定矩阵的稳定性,绝对值大于1的部分会不断拉伸,小于1的部分会不断缩减

### 4.4 SVD分解

##### 基本概念

对于任意矩阵$A=U\Sigma V^T$ $(A\in\mathbb{R^{m\times n}}, U\in\mathbb{R^{m\times m}}, \Sigma\in\mathbb{R^{m\times n}}, V\in\mathbb{R^{n\times n}})$

- $U,V$是正交矩阵
- $V$是$A$行空间的正交基,$U$是列空间的正交基
- $\Sigma$是对角线为奇异值的对角矩阵

##### 计算方法

1. 计算$AA^T$和$A^TA$
   - $AA^T=U\Sigma V^{-1}(U\Sigma V^{-1})^T=U\Sigma\Sigma^TU^{-1}$
   - $A^TA=(U\Sigma V^{-1})^TU\Sigma V^{-1}=V\Sigma^T\Sigma V^{-1}$
2. 因为$AA^T$和$A^TA$都是对称矩阵,所以可以分解为$Q\Lambda Q^T$,且$Q$是正交基
3. $\Sigma=\Lambda^{1/2}$
4. $AA^T$得到列正交矩阵$U$,$A^TA$得到行正交矩阵$V$

##### 性质

$v_{r+1},v_{r+2}\cdots v_{n}$是零空间中的标准正交基

$u_{r+1},u_{r+2}\cdots u_{m}$是左零空间的标准正交基

# 5. 矩阵求导

### 5.1 重要矩阵

给定$f(\vec x)$,导数矩阵说明了$f$在$\vec x$的性质 

##### 梯度

- 函数值上升最快的方向

  $\bigtriangledown f(\vec x)=\begin{bmatrix}\frac{\partial f}{\partial x_1}\\\frac{\partial f}{\partial x_2}\\\cdots\\\frac{\partial f}{\partial x_n}\end{bmatrix}$

##### 海森矩阵(Hessian)

- $f$在$\vec x$处的二阶导,标志梯度的每个分量变化速度快慢

  $\frac{\partial^2f(\vec x)}{\partial \vec x\partial \vec x^T}=\begin{bmatrix}\frac{\partial^2f}{\partial x_1^2}&\frac{\partial^2f}{\partial x_1\partial x_2}&\cdots&\frac{\partial^2f}{\partial x_1\partial x_n}\\\frac{\partial^2f}{\partial x_2\partial x_1}&\frac{\partial^2f}{\partial x_2^2}&\cdots&\cdots\\\cdots&\cdots&\cdots&\cdots\\\frac{\partial^2f}{\partial x_nx_1}&\cdots&\cdots&\frac{\partial^2f}{\partial x_n^2}\end{bmatrix}$

##### 雅各比矩阵(Jacobian)

- <u>矩阵函数</u>$f\in\R^{n\times m}$在$\vec{x}$的导数
- $\textbf{J(f)}=\begin{bmatrix}\frac{\partial f_1}{\partial x_1}&\cdots&\frac{\partial f_1}{\partial x_n}\\\cdots & \cdots&\cdots\\\frac{\partial f_m}{\partial x_1}&\cdots&\frac{\partial f_m}{\partial x_n}\end{bmatrix}$



### 5.2 标量对矩阵求导

标量对自变量$X$中的每个元素求导,得到的向量/矩阵$f'$和自变量$X$<u>的维度</u>一致

<u>导数只有转置以后才可以乘以</u>$X$

##### 标量对向量求导

- 根据梯度$\bigtriangledown f(x,y)=\frac{\partial f}{\partial x}\mathrm dx + \frac{\partial f}{\partial y}\mathrm dy$

- 用向量$X$表示$(x,y)$,则有$f(X)'=\frac{\mathrm df^T}{\mathrm dX}\mathrm dX$
- 已知标量为两个矩阵的乘积
  - $\frac{\partial \beta^Tx}{\partial x}=\beta$
  - $\frac{\partial x^Tx}{\partial x}=2x$
  - $\frac{\partial x^TAx}{\partial x}=(A+A^T)x$

##### 标量对矩阵求导

1. 令$X$为矩阵,各列为向量,则有$f(X)’=\sum_{i=0}^c\frac{\mathrm df^T}{\mathrm dX_c}\mathrm dX_c$

2. 根据矩阵内积定义 $\tr(A^TB)=\sum_{i,j}A_{ij}B_{ij}$ (所有元素乘积求和)
3. $f(X)'=\tr(\frac{\mathrm d f^T}{\mathrm dX}\mathrm d X)$

### 5.3 向量对矩阵求导

把列向量的每个元素视为标量,再求导分解
$$
\frac{\partial Y}{\partial X}=\begin{bmatrix}
\frac{\partial y_1}{\partial x_1} & \frac{\partial y_1}{\partial x_2} & \cdots & \frac{\partial y_1}{\partial x_n}\\
\cdots & \cdots & \cdots & \cdots\\
\frac{\partial y_m}{\partial x_1} & \frac{\partial y_m}{\partial x_2} & \cdots & \frac{\partial y_m}{\partial x_n}
\end{bmatrix}
$$


# 6. 线性代数应用

### 6.1 图论

给定每条边的势能差,可以计算每个点势能

每行代表一条边,每列代表一个顶点

给定4个点,5条边的图
$$
A=
\left[\begin{array}{cccc}
-1 & 1 & 0 & 0\\
0 & -1 & 1 & 0\\
-1 & 0 & 1 & 0\\
-1 & 0 &  0 & 1\\
0 & 0 & -1 & 1
\end{array}\right]
$$

$x$ 描述了每个顶点的势能

$$
Ax=
\left[\begin{array}{cccc}
-1 & 1 & 0 & 0\\
0 & -1 & 1 & 0\\
-1 & 0 & 1 & 0\\
-1 & 0 &  0 & 1\\
0 & 0 & -1 & 1
\end{array}\right]
\left[\begin{array}{c}
v_1\\
v_2\\
v_3\\
v_4
\end{array}\right]
\rightarrow
\left[\begin{array}{c}
v_2-v_1\\
v_3-v_2\\
v_3-v_1\\
v_4-v_1\\
v_4-v_3
\end{array}\right]=
\left[\begin{array}{c}
0\\
0\\
0\\
0\\
0
\end{array}\right]
$$



$y$描述了每条边之间的通量
$$
A^Ty=
\left[\begin{array}{ccccc}
-1 & 0 & -1 & -1 & 0\\
1 & -1 & 0 & 0 & 0\\
0 & 1 & 1 & 0 & -1\\
0 & 0 & 0 & 1 & 1
\end{array}\right]\left[\begin{array}{c}
i_1\\
i_2\\
i_3\\
i_4\\
i_5
\end{array}\right]
\rightarrow
\left[\begin{array}{c}
-i_1-i_3-i_4\\
i_1-i_2\\
i_2+i_3-i_5\\
i_4+i_5
\end{array}\right]=
\left[\begin{array}{c}
0\\
0\\
0\\
0
\end{array}\right]
$$
$\dim{y}$描述了通量中的环的数量

### 6.2 级数

##### 幂级数

通过等比数列求和可以得到

$(I-At)^{-1}=I+At+(At)^2+(At)^3+\cdots+(At)^n$

根据$At$的大小分析$(I-At)^{-1}$是否收敛

##### 指数级数

- $e^{At}=\sum_{x=1}^\infty\frac{(At)^x}{x!}$
- $e^{At}=Se^{\Lambda t}S^{-1}$

利用特征值分解特性

$\sum_{x=1}^\infty\frac{(At)^x}{x!}=\sum_{x=1}^\infty\frac{(S\Lambda S^{-1})^xt^x}{x!}=S\sum_{x=1}^\infty\frac{(\Lambda x)^x}{x!}S^{-1}=Se^{\Lambda t}S^{-1}$

##### 傅里叶级数

已知$f(x)=a_0+a_1\cos x+b_1\sin x+a_2\cos2x+b_2\sin2x\cdots$

定义函数为基, basis=${1, \cos x, \sin x\cdots}$

$f\cdot g=\int_0^{2\pi} f(x)g(x)\mathrm{d}x$

通过点积求系数$a_1=\frac{\int_0^{2\pi}f(x)\cos x\mathrm{d}x}{f_0^{2\pi}\cos^2x\mathrm{d}x}$

### 6.3 解微分方程

给定矩阵$A$,求解$\frac{\mathrm{d}u}{\mathrm{d}t}=Au$

##### 常规求解流程

1. 获得$A$的n个特征值$\lambda_1,\lambda_2\cdots\lambda_n$和对应<u>线性独立</u>的特征向量$v_1,v_2\cdots v_n$
2. 通过特征向量,反向构造$u=\sum_i^nc_if_i(t)v_i$
3. 根据$A$的特征值,可以得到$\sum_i^nc_i\frac{\mathrm{d}f_i(t)v_i}{\mathrm{d}t}=\sum_i^nc_i\lambda_if_i(t)v_i$
4. 解得每个$f_i(t)=e^{\lambda_it}$
5. 通过初始条件$u(0)=\sum c_iv_i$可以求得每个$c_i$
6. $u=\sum_i^nc_ie^{\lambda_i t}v_i$

##### 指数级数求解流程

1. $u=Ce^{At}=CSe^{\Lambda t}S^{-1}$
2. 对$A$进行奇异值分解可以得到$\Lambda,S$
3. 代入初始条件$t=0$则$C=u(0)$
4. $u=u(0)Se^{\Lambda t}S^{-1}$

##### 特征值分析

- 只需要考虑$\lambda_i$的实部
- $\lambda_{max}>0$,则$u$最终不稳定
- $\lambda_{max}=0$则$u$最终收敛于对应的$c_iv_i$

- 小于0的$\lambda_i$的项最终会消失

### 6.4 马尔科夫转换

##### 定义

- 每列的和为1
- 每个元素$e_{ij}\geq0$,表示状态转换的概率

$$
A=\left[\begin{array}{ccc}
0.1&0.01&0.3\\
0.2&0.99&0.3\\
0.7&0   &0.4\\
\end{array}\right]
$$

##### 性质

- $A^n$还是马尔科夫矩阵 (因为每列和为1)
- $\det (A-I)=0$
  - 每一列的和为0,则列之间线性相关$\sum c_i=0$

- 最大的特征值为1,其他特征值$|\lambda|<1$
  - 求解$(A-I)v=0$,则可以得到对应的特征向量
  - 对应的$v$决定了稳态

### 6.5 信号压缩

##### 基本概念

对于一个4bit的信号,有默认标准基
$$
\left[\begin{array}{c}
1\\0\\0\\0
\end{array}\right]
\left[\begin{array}{c}
0\\1\\0\\0
\end{array}\right]
\left[\begin{array}{c}
0\\0\\1\\0
\end{array}\right]
\left[\begin{array}{c}
0\\0\\0\\1
\end{array}\right]
$$
<u>基的数量决定了表示信号需要的参数$c,c$应尽可能稀疏</u>

##### 傅里叶基(JPEG)

相比默认基,<u>傅里叶基体现的信息更丰富(例如可以表示一片区域的颜色)</u>

出现次数少的基,可能系数非常小,使参数更加稀疏
$$
\left[\begin{array}{c}
1\\1\\1\\1
\end{array}\right]
\left[\begin{array}{c}
1\\i\\-1\\-i
\end{array}\right]
\left[\begin{array}{c}
1\\-1\\1\\-1
\end{array}\right]
\left[\begin{array}{c}
1\\-i\\-1\\i
\end{array}\right]
$$

1. 将512\*512像素拆分成8\*8像素的block,再用64个参数$c$和对应的基表示
2. 设定阈值,过滤系数很小的基(压缩),得到稀疏向量$\hat c$
3. 用系数和对应的基还原 $\hat{x}=\sum\hat{c}v$
4. 视频文件还可以在时序上做压缩

##### 小波基 (wavelet)

- 每个基1和-1的数量相同
- <u>基之间两两正交</u>
- 还原速度快

$$
W=\left[\begin{array}{c}
1\\1\\1\\1
\end{array}\right]
\left[\begin{array}{c}
1\\1\\-1\\-1
\end{array}\right]
\left[\begin{array}{c}
1\\-1\\0\\0
\end{array}\right]
\left[\begin{array}{c}
0\\0\\1\\-1
\end{array}\right]
$$

1. 给定图像$P$,通过基变换$Wc=P\rightarrow c=W^{-1}P$
2. $W$是正交矩阵,且每列的模长为2,因此可以转换为标准正交$Q=\frac{W}{2}$
3. 根据标准正交性质$W^{-1}=(2Q)^{-1}=\frac{1}{2}Q^T=\frac{W^T}{4}$
4. 可以立刻计算$c=\frac{W^T}{4}P$,还原速度快
