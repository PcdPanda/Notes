# git和区块链的关系

### 1. 常用的数字加密方法

- 对称加密:
  - AES
  - 速度快,风险大
  - 密文短

- 非对称加密

  - 安全性高,加密解密速度慢

  - 密文长

  - RSA

    1. 寻找两个不相同的大质数$p,q$, 并计算乘积$N=p\cdot q$
    2. 计算N的欧拉函数值 $r=\varphi(N)=\varphi(p)\varphi(q)=(p-1)(q-1)$​
    3. 随便选择1个小于$r$且 和$r$ 互质的整数$e$

    4. 计算d,使得$ed\equiv1\mod r$​
    5. 获得公钥$(N,e)$和私钥$(N,d)$
    6. 用公钥$(N,e)$对密文$M$进行加密,获得密文$C=M^e\mod N$

    7. 用私钥$(N,d)$对密文$C$解密,获得明文$M=C^d \mod N$​、

  - 数字签名算法

    1. 私钥+密文 $\rightarrow$ 明文
    2. 公钥+明文 $\rightarrow$ 验证明文是否有效

- 哈希函数

  - 无法根据结果找到输入
  - 碰撞概率极低,可以用来验证是否为同一个输入
  - 计算速度快

  - SHA-256 

    ```sh
    cat 123|sha256sum
    e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855
    ```

### 2. git

git管理三种数据类型对象,且不直接保存对象,而是对象的SHA-1值,作为对象的引用地址

- commit (快照)

  ```python
  class commit:
      parent: List[str] # 包含了父commit的sha-1值
      author: str # 提交者
      msg: str # 提交信息
      snapshot: str # 提交的根目录tree的SHA-1值
  ```

  - 通过日志查看当前commit

    ```sh
    git log 
    # commit 6efdeb44c0ddd9cbec402a9fc55370e28e3fa73e (HEAD -> develop, origin/develop)
    # Author: panda <panda@chongdanpan@probquant.com>
    # first commit
    ```

  - 查看commit的内容

    ```sh
    git cat-file -p 6efdeb44c0ddd9cbec402a9fc55370e28e3fa73e # 查看commit对应的内容
    # tree 9a0307cd34a9c20329aa2967a756e96b63f0d88e
    # parent 924c3396e3dfcf848afac87ebcf20e8fb786beb5
    # author panda <panda@chongdanpan@probquant.com> 1627126874 +0800
    # committer panda <panda@chongdanpan@probquant.com> 1627126874 +0800
    # first commit
    ```

- tree (目录)

  ```python
  class tree:
      map: Dict[str, str] # 一个字典,从字符串(文件名)映射到**目录/文件的hash
  ```

  - 查看tree的内容

    ```sh
    git cat-file -p 9a0307cd34a9c20329aa2967a756e96b63f0d88e
    # 100644 blob 7225b8cb7419308fd5798dcb5deb1cb535f56b1c    .gitignore
    # 100644 blob 5deb633a456e3165e182645ec1444289b92ca8b2    LICENSE
    # 100644 blob e69de29bb2d1d6434b8b29ae775ad8c2e48c5391    README.md
    # 100755 blob d4fcb8d2ed33558fee88cb5eee5b74ebfa6e62c8    build.sh
    # 100644 blob 6fce1696f12ed44c0da9b11bb249541590867881    main.py
    ```

- blob (常规文件)

  ```python
  class blob:
      content: bytes # 一串二进制
  ```
  
  - 查看blob内容
  
    ```sh
    git cat-file -p 7225b8cb7419308fd5798dcb5deb1cb535f56b1c
    # *.py
    # __pycache__
    ```

### 3. 区块链

1. 数字签名 (所有节点都必须verify signature)

   <img src="C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210727235151671.png" alt="image-20210727235151671" style="zoom: 80%;" />

2. proof of work

   ![image-20210727235346435](C:\Users\PANDA\AppData\Roaming\Typora\typora-user-images\image-20210727235346435.png)