- [1. 账户和配置](#1-账户和配置)
    - [1.1 SSH登录](#11-ssh登录)
        - [初始化](#初始化)
        - [配置免密登录](#配置免密登录)
        - [ssh配置](#ssh配置)
    - [1.2 自定义环境配置](#12-自定义环境配置)
        - [Alias:](#alias)
        - [Path: 定义二进制路径](#path-定义二进制路径)
        - [Crontab](#crontab)
    - [1.3 单用户进程和会话管理](#13-单用户进程和会话管理)
        - [进程管理](#进程管理)
        - [任务管理](#任务管理)
        - [tmux多路复用](#tmux多路复用)
- [2. 常用Shell语法](#2-常用shell语法)
    - [2.1 执行逻辑](#21-执行逻辑)
        - [运行和检查脚本](#运行和检查脚本)
        - [if判断](#if判断)
        - [循环](#循环)
        - [脚本间逻辑嵌套](#脚本间逻辑嵌套)
    - [2.2 变量](#22-变量)
        - [用户输入](#用户输入)
        - [字符串](#字符串)
    - [2.3 Data Wrangling](#23-data-wrangling)
        - [文件索引/输出](#文件索引输出)
        - [文件编辑](#文件编辑)
        - [sed 正则表达式匹配](#sed-正则表达式匹配)
        - [指令间输出转换](#指令间输出转换)
- [3.文件系统](#3文件系统)
    - [3.1 文件/目录的创建和编辑](#31-文件目录的创建和编辑)
        - [相关指令](#相关指令)
        - [重要目录](#重要目录)
    - [3.2 远程文件同步](#32-远程文件同步)
- [4. Vim](#4-vim)
    - [4.1 模式切换](#41-模式切换)
        - [文件打开和关闭](#文件打开和关闭)
    - [4.2 光标控制](#42-光标控制)
        - [移动光标](#移动光标)
        - [快捷移动](#快捷移动)
        - [查找](#查找)
    - [4.3 文件编辑](#43-文件编辑)
        - [逻辑操作](#逻辑操作)
        - [单词级编辑](#单词级编辑)
        - [行级编辑](#行级编辑)
- [5. 哈希加密和Git](#5-哈希加密和git)
    - [5.1 Linux加密](#51-linux加密)
        - [Hash Function](#hash-function)
        - [Key Derivation Function](#key-derivation-function)
        - [非对称加密](#非对称加密)
        - [对称加密和非对称加密结合](#对称加密和非对称加密结合)
    - [5.2 git数据模型](#52-git数据模型)
        - [blob (文件)](#blob-文件)
        - [tree (目录)](#tree-目录)
        - [commit (快照)](#commit-快照)
    - [5.3 Git常用命令](#53-git常用命令)
        - [初始化和配置](#初始化和配置)
        - [查看状态](#查看状态)
        - [提交管理](#提交管理)
        - [远端操作](#远端操作)
- [6. 开发基本技能](#6-开发基本技能)
    - [6.1 系统状态监控](#61-系统状态监控)
    - [6.2 Makefile](#62-makefile)
    - [6.3 测试](#63-测试)


# 1. 账户和配置

### 1.1 SSH登录

##### 初始化

```sh
sudo apt-get install openssh-server # 安装ssh
service ssh start # 启动ssh
ssh [-p port] cdpan@192.168.1.1 # 进行ssh登录
```

##### 配置免密登录

```sh
ssh-keygen -t rsa # 在登录机和目标机创建~/.ssh目录,并生成公钥和私钥
# --------------------------
cat .ssh/id_rsa.pub >> ~/.ssh/authorized_keys # 将登录机公钥添加到目标机authorized_keys中
chmod 600 ~/.ssh/authorized_keys
chmod 700 -R ~/.ssh # 配置公钥私钥权限
```

##### ssh配置

```sh
~/.ssh/config

Host cdpan # 登录机器名
	HostName 192.168.1.1 # 登录机器IP
	Port 22 # ssh端口
	User cdpan # 登录账户
	IdentifyFile ~/.ssh/id_rsa # 登录账户私钥
```

### 1.2 自定义环境配置

在.bash_profile/.bashrc中可以加入bash命令,在进入shell时预运行,起到环境变量的作用

##### Alias:

```sh
alias ll="ls -lah" #  自定义命令ll
```

##### Path: 定义二进制路径

```sh
export PATH={PATH}:$PATH # 自定义环境变量路径
```

##### Crontab

```sh
service cron status # 确认crontab一打开
sudo service cron start
sudo vim /etc/rsyslog.d/50-default.conf # 开启日志
crontab -l # 打印定期任务
crontab -e # 编辑定期任务

*    *    *    *    *
-    -    -    -    -
|    |    |    |    |
|    |    |    |    +----- 星期中星期几 (0 - 6) (星期天 为0)
|    |    |    +---------- 月份 (1 - 12) 
|    |    +--------------- 一个月中的第几天 (1 - 31)
|    +-------------------- 小时 (0 - 23)
+------------------------- 分钟 (0 - 59)

00 03 * * 1-5 find /home "*.xxx" -mtime +4 -exec rm {} \;  每周一至周五3点钟，在目录/home中，查找文件名为*.xxx的文件，并删除4天前的文件
```

### 1.3 单用户进程和会话管理

##### 进程管理

| Ctrl+C   | Ctrl+Z   | Ctrl+D                         | Ctrl+L       | Ctrl+\                    |
| -------- | -------- | ------------------------------ | ------------ | ------------------------- |
| 停止程序 | 挂起程序 | 输入EOF符号,通常会退出terminal | 清空terminal | 退出程序,并将程序状态保存 |

##### 任务管理

- jobs: 查看当前用户开启的进程
- nohup [command] &: 可以将程序放在后台,并将输出打印到nohup文件
- fg/bg [%job_number]: 把后台暂停的进程放到前台/后台运行

##### tmux多路复用

| tmux+ls                    | tmux [new -s 会话名 -n 窗口名] | tmux at [-t 会话名]  | tmux kill-session [-t 会话名] |
| -------------------------- | ------------------------------ | -------------------- | ----------------------------- |
| 查看当前正在运行的tmux会话 | 创建新会话并起名               | 连接到当前存在的会话 | 关闭会话                      |

- ctrl B: 之后加控制命令,可以操作当前会话

| c          | w                           | d            | ,              | Ctrl+D       |
| ---------- | --------------------------- | ------------ | -------------- | ------------ |
| 创建新窗口 | 列出当前所有窗口,并进行切换 | 挂起当前窗口 | 重命名当前窗口 | 退出当前窗口 |

# 2. 常用Shell语法

### 2.1 执行逻辑

##### 运行和检查脚本

```sh
#! /bin/bash
shellcheck test.sh # 检查shell的语法
```

##### if判断

##### 循环

##### 脚本间逻辑嵌套

- AND 第一句运行返回True才运行第二句

  ```sh
  false && echo hello # 不输出
  false && echo hello # hello
  ```

- OR 第一句运行返回False才运行第二句

  ```sh
  false || echo hello # hello
  true || echo hello # 不输出
  ```

- 分号,分隔不同语句,都会运行

  ```sh
  false;true;echo hello # hello
  ```

### 2.2 变量

##### 用户输入

| $$        | $!              | $?                   | $#           | $0                       | $@       | $(var)      |
| --------- | --------------- | -------------------- | ------------ | ------------------------ | -------- | ----------- |
| 脚本的PID | 上一个进程的PID | 上一次程序运行的结果 | 输入参数数量 | 第一个参数(通常为脚本名) | 所有参数 | var为变量名 |

##### 字符串

- 双引号和单引号,双引号会翻译变量

  ```sh
  echo "abc$path" # abc
  echo 'abc$path' # abc$path
  ```

- **通配符** ？匹配一个字符, *匹配任意个字符

### 2.3 Data Wrangling

##### 文件索引/输出

| grep \{str\}   | less \{\}                   | head/tail           | wc [-l行数] [-c 字节数] [-w 单词数] |
| -------------- | --------------------------- | ------------------- | ----------------------------------- |
| 输出匹配字符串 | 打开实现一个类似vim的浏览器 | 显示文件的开头/结尾 | 文件计数                            |

##### 文件编辑

- sort [-n 根据数值排序]:  排序文件
- uniq [-c 显示重复行出现次数]:  删除重复行
- paste [-s 按列操作] [-d 分隔符]: 粘贴文件内容

##### sed 正则表达式匹配

匹配文件中内容并替换,需要有3个斜杠

```sh
cat tmp.py | sed -E 's/{匹配内容}/{替换内容}/[g]'
```

- 默认每行匹配并替换一次
- g代表每行反复匹配

##### 指令间输出转换

- awk: 拆分文件中的空格,并对列进行操作

- xargs: 每一行作为管道输入并进行操作



# 3.文件系统

### 3.1 文件/目录的创建和编辑

##### 相关指令

```sh
cd - # 跳转到上次访问的目录
vim xxx.py # 用编辑器创建文件
touch test{1,2}/gogogo{1,2,3}.py # 在test1, test2下分别创建3个gogogo1,2,3.py文件
du -h [-s] # 查看文件大小[总和]
lsof # 显示打开文件
find {指定路径名} -name "*.py" [-path "~/cdpan/test"] # 按照路径名/文件名,在指定路径查找文件
```

##### 重要目录

- /sys/ 存放内核和驱动配置
- /dev/shm 放共享内存
- /var/log 放日志

### 3.2 远程文件同步

```sh
rsync [option] [src_path] [dest_path] # 两个path既可以是本地,也可以是远端

# 使用实例
rsync -avz ~/test.py cdpan@192.168.1.94:~/test.py
```

option说明

| z        | v          | a                               |
| -------- | ---------- | ------------------------------- |
| 启用压缩 | 过程可视化 | 保留用户权限且递归(**基于uid**) |

# 4. Vim

### 4.1 模式切换

| mode   | normal | control      | insert         | replace  | visual line        | visual block       |
| ------ | ------ | ------------ | -------------- | -------- | ------------------ | ------------------ |
| 切换键 | 默认   | :            | i              | r        | v (shift + v)      | v (ctrl + v)       |
| 功能   |        | 打开控制命令 | 编辑和插入数据 | 覆盖数据 | 按行选中数据并复制 | 按块选中数据并复制 |

##### 文件打开和关闭

-  退出: q!
-  保存并退出: wq!

### 4.2 光标控制

##### 移动光标

| h    | i    | j    | k    |
| ---- | ---- | ---- | ---- |
| 左   | 上   | 下   | 右   |

##### 快捷移动

| w/b          | e              | 0/$           | ^                        | L/M/H                      | Ctrl+U/D    | GG/g                |
| ------------ | -------------- | ------------- | ------------------------ | -------------------------- | ----------- | ------------------- |
| 前后跳跃单词 | 移动到单词结尾 | 移动到行首/尾 | 移动到该行第一个非空字符 | 移动到页面最下方/中间/上方 | 向上/下翻页 | 移动到文件末尾/开头 |

##### 查找

| f/F + {}            | t/T + {}                         | / + {}       |
| ------------------- | -------------------------------- | ------------ |
| 在本行中向后/前查找 | 在本行中向前/后查找到前/后的字符 | 在全文中查找 |

### 4.3 文件编辑

##### 逻辑操作

| u    | Ctrl+r   | .                      |
| ---- | -------- | ---------------------- |
| 撤销 | 恢复撤销 | 重复上一次insert的内容 |

##### 单词级编辑

| d+e                | d+w/b           | c                              | x      | r    | yw                 | p    |
| ------------------ | --------------- | ------------------------------ | ------ | ---- | ------------------ | ---- |
| 删除光标到单词末尾 | 向前/后删除单词 | 和d作用相同,完成后进入插入模式 | delete | 替换 | 复制当前到单词末尾 | 黏贴 |

##### 行级编辑

| enter          | O/o                       | dd/cc      | yy         |
| -------------- | ------------------------- | ---------- | ---------- |
| 换行并创建新行 | 立即在光标上/下方创建新行 | 删除一整行 | 复制一整行 |

- 修饰符操作
  - d + i + []:删除当前方括号包含内容,圆括号同样适用
  - d + a + []:删除当前括号**及其包含的内容**

# 5. 哈希加密和Git

### 5.1 Linux加密

##### Hash Function

- 将无限空间的输入映射到有限空间,例如256 bits (SHA-256)
- 根据结果无法找出输入
- 碰撞的概率极低
- 计算hash值的速度很快

##### Key Derivation Function

- 计算hash值非常慢,适合用于密码验证,**防范暴力攻击**
- 结合对称加密,计算密码的hash值,再进行加密/解密

##### 非对称加密

- rsa: 生成公钥,私钥加密文件
  - 密文=encrypt(公钥,明文)
  - 明文=decrypt(私钥,密文)

- 电子签名
  - 密文=encrypt(私钥+明文)
  - 验证签名=verify(密文,公钥)

非对称加密的问题: <u>**无法验证公钥是否有效,且运行速度慢**</u>

##### 对称加密和非对称加密结合

1. 随机生成对称加密的key: sk
2. 使用sk对明文进行加密(耗时短)
3. 加密者使用公钥pk对sk进行加密,得到sk'(因为sk很小,所以耗时短)
4. 解密者用私钥pk对sk'解密获得sk
5. 解密者用sk进行对称解密密文

### 5.2 git数据模型

分三种数据类型:

##### blob (文件)

```python
class file:
    content: bytes # 一串二进制
```

##### tree (目录)

```python
class tree:
    map: Dict[str, str] # 一个字典,从字符串(文件名)映射到**目录/文件的hash
```

##### commit (快照)

```python
class commit:
    parent: List[str] # 包含了父commit的sha-1值
    author: str # 提交者
    msg: str # 提交信息
    snapshot: str # 提交的根目录tree的SHA-1值
```

每个对象的存储路径为它的SHA-1值

git用引用来指向SHA-1值,并在上传时附加引用

### 5.3 Git常用命令

##### 初始化和配置

```sh
git init # 初始化git目录
git config --global credential.helper store # 配置存储模式
git config --global user.email "panchongdan@foxmail.com" # 配置email
git config --global user.name "Chongdan Pan" # 配置用户名
git config --global https.proxy https://127.0.0.1:41091 # 设置代理
git config --global http.proxy http://127.0.0.1:41091 # 设置代理
git config --global --unset http.proxy # 还原设置
```

##### 查看状态

```sh
git status # 查看当前git状态
git log [--all] [--graph]# 查看log
git cat-file -p <hash> # 根据hash值查看commit/blob/tree的内容
git branch # 查看当前分支
```

##### 提交管理

```sh
git add * [-A] # 暂存文件,并生成hash,以此可以知道文件是否有修改
git diff <file> # 查看文件改动
git stash # 删除暂存的文件
git commit -m "xxx" # 提交commit
git checkout [-b] <branch> # 转换[新建]分支
git merge <branch> # 合并分支到当前分支
git merge [--abort] [--continue] # 终止merge,conflict后继续merge
```

##### 远端操作

```sh
git remote # 列出远端
git remote add <name> <url> # 添加一个远端,name通常为origin
git clone <url> [-b <branch>] # 下拉特定分支
git pull origin <branch> # 下拉分支
git push origin <branch> # 上传分支
```

# 6. 开发基本技能

### 6.1 系统状态监控

- strace {command}: 显示堆栈调用
- time {command}:显示耗时
  - real: 总耗时,包括网络IO
  - user: 用户态时间
  - sys: cpu内核态时间
- htop: 查看当前系统状态

### 6.2 Makefile

make会在目录下找makefile,可以用来build各种库

例如需要先构造png再构造latex pdf

```makefile
paper.pdf: paper.tex plot-data.png # 构造目标paper.pdf,需要tex和png(dependency)
		pdflatex paper.tex # 构造指令,pdflatex paper.tex
		echo hello # 可以有附加指令.前面的缩进必须是tab
		
plot-%.png: %.dat plot.py # 构造plot-data.png的方式
		./plot.py -i $*.dat -o $@ # $*代表%匹配的dat名(data.dat), $@对应输出名(plot-data.png)
```

### 6.3 测试

- unit test: 对于每个部分单独进行测试
- integration test: 结合所有部分一起测试
- regression test: 将每次遇到的bug加入到测试,regression test内容会不断变多
- 构造mock data

