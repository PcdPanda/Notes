# linux基础

### 1. 文件和目录

#### 1.1 文件夹权限

- r 显示目录下文件
- w 在目录下创建/删除文件(可以修改文件中的内容)
- x 进入目录

#### 1.2 重要目录

```sh
cd - # 跳转到上次访问的目录
```

- /sys/ 存放内核和驱动配置
- /dev/shm 放共享内存
- /var/log 放日志

#### 1.3 创建和查找文件

```sh
vim xxx.py # 用编辑器创建
touch test{1,2}/gogogo{1,2,3}.py # 在test1, test2下分别创建3个gogogo1,2,3.py文件
find {指定路径名} -name "*.py" [-path "~/cdpan/test"] # 按照路径名/文件名,在指定路径查找文件
du -h [-s] # 查看文件大小[总和]
lsof # 显示打开文件
```

#### 1.4 定义全局环境

在.bashrc中可以加入bash命令,在进入shell时预运行,起到环境变量的作用

1. alias: 自定义命令

   ```sh
   alias ll="ls -lah"
   ```

2. path: 定义二进制路径

   ```sh
   export PATH={PATH}:$PATH

#### 1.5 远程传输文件和rsync同步

```sh
rsync [option] [src_path] [dest_path] # 两个path既可以是本地,也可以是远端

# 使用实例
rsync -avz ~/test.py cdpan@192.168.1.94:~/test.py
```

option说明

- z: 启用压缩
- v: 过程可视化
- a: 保留用户权限且递归(**基于uid**)



### 2. bash脚本

```sh
#! /bin/bash
shellcheck test.sh # 检查shell的语法
```

#### 1. $变量

- ```sh
  echo $$ # shell的PID
  ```

- ```sh
  echo $! #上一个进程的PID
  ```

- ```sh
  echo $? # 上一次进程的运行结果
  	# 1 为 false
  	# 0 为 true
  ```

- ```sh
  echo $# # 脚本输入的参数数量
  ```

- ```sh
  echo $0 # 脚本的一个参数(通常是脚本名)
  ```

- ```sh
  echo $@ # 以列表形式列出所有参数
  ```

- ```sh
  echo $(pwd) # 打印命令执行结果 /home/cdpan
  ```


#### 2. 字符串

- 双引号和单引号,双引号会翻译变量

  ```sh
  echo "abc$path" # abc
  echo 'abc$path' # abc$path
  ```

- **通配符** ？匹配一个字符, *匹配任意个字符

#### 3. 逻辑嵌套语句

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

  

### 3. 进程和会话管理

- ctrl
  - crtl + C: 停止程序
  - ctrl + Z: 挂起程序
  - ctrl + D: 输入EOF符号,通常会退出terminal
  - ctrl + L: 清空terminal
  - ctrl + \: 退出程序,并将程序状态保存
  
- job
  - jobs: 查看当前用户开启的进程
  - nohup [command] &: 可以将程序放在后台,并将输出打印到nohup文件
  - fg/bg [%job_number]: 把后台暂停的进程放到前台/后台运行

- tmux实现linux窗口的**多路复用**
  - tmux ls: 查看当前正在运行的tmux会话
  - tmux [new -s 会话名 -n 窗口名]: 创建新会话并起名
  - tmux at [-t 会话名]: 连接到当前存在的会话
  - tmux kill-session [-t 会话名]: 关闭会话
  - ctrl B: 之后加控制命令,可以操作当前窗口
    - c: 创建新窗口
    - w: 列出当前所有窗口,并进行切换
    - d: 挂起当前窗口
    - ,: 重命名当前窗口
    - $/ctrl D: 退出当前窗口
  
- 程序debug和监控

  - strace {command}: 显示堆栈调用
  - time {command}:显示耗时
    - real: 总耗时,包括网络IO
    - user: 用户态时间
    - sys: cpu内核态时间
  - **<u>debug工具</u>**
    - c++: gdb/valgrind/perf
    - python -m: cProfile, memory_profiler
  - htop

- crontab定期任务,每个用户有自己的crontab任务

  ```sh
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



### 4. ssh

#### 4.1 初始化

```sh
sudo apt-get install openssh-server # 安装ssh
service ssh start # 启动ssh
ssh [-p port] cdpan@192.168.1.1 # 进行ssh登录
```

#### 4.2 配置免密登录

```sh
ssh-keygen -t rsa # 在登录机和目标机创建~/.ssh目录,并生成公钥和私钥
# --------------------------
cat .ssh/id_rsa.pub >> ~/.ssh/authorized_keys # 将登录机公钥添加到目标机authorized_keys中
chmod 600 ~/.ssh/authorized_keys
chmod 700 -R ~/.ssh # 配置公钥私钥权限
```

#### 4.3 ssh配置

```sh
~/.ssh/config

Host cdpan # 登录机器名
	HostName 192.168.1.1 # 登录机器IP
	Port 22 # ssh端口
	User cdpan # 登录账户
	IdentifyFile ~/.ssh/id_rsa # 登录账户私钥
```



