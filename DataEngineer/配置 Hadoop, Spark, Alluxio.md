#  配置 Zookeeper, Hadoop, Spark, Alluxio

### 1. 配置节点host和节点间ssh

#### 1.1 配置节点信息

1. 设置节点域名和ip,假设主节点叫hadoop1,其余子节点为hadoop2,hadoop3

   ```sh
   # vim /etc/hosts
   192.168.2.94 hadoop1
   192.168.2.85 hadoop2
   192.168.2.86 hadoop3
   ```

2. 在所有节店创建hadoop账户,并在根目录下生成rsa密钥对

   ```sh
   ssh-keygen -t rsa
   cat .ssh/id_rsa.pub >> authorized_keys # 将主节点的id_rsa.pub中的内容,放到所有节点的authorized_keys中
   chmod 700 .ssh
   chmod 600 .ssh/authorized_keys # 设置权限
   ```

3. 测试是否可以从主节点中免密ssh到其他节点

   ```sh
   ssh -p 12312 127.0.0.1 # ssh自己
   ssh -p 12312 hadoop2 # ssh其他节点
   ssh -p 12312 hadoop3
   ```

4. 修改每个节点根目录下的.bashrc,配置环境变量

   ```sh
   # ~/.bashrc
   
   # zookeeper
   export ZK_HOME=/shared/zookeeper
   export PATH=$ZK_HOME/bin:$PATH
   
   # hadoop部分
   export HADOOP_HOME=/shared/hadoop
   export PATH=$JAVA_HOME/bin:$HADOOP_HOME/bin:$HADOOP_HOME/sbin:$PATH
   
   # spark 部分
   export SPARK_HOME=/home/cdpan/spark
   export PATH=$SPARK_HOME/bin:$PATH
   
   # alluxio部分
   export ALLUXIO_HOME=/shared/alluxio
   export PATH=$ALLUXIO_HOME/bin:$PATH
   ```



### 2. Zookeeper

1. 下载zookeeper 3.7.0版本并发送至服务器解压

   [Index of /dist/zookeeper/zookeeper-3.5.8 (apache.org)](https://archive.apache.org/dist/zookeeper/zookeeper-3.5.8/)

2. 重命名/shared/zookeeper/conf/zoo_sample.cfg,并修改临时保存目录

   ```sh
   tar -xvf zookeeper-3.7.0.tar.gz zookeeper
   mv zoo_sample.cfg zoo.cfg
   ```
   
3. 配置zoo.cfg

   ```sh
   #zoo.cfg
   dataDir=/shared/zookeeper/tmp
   clientPort=2181
   server.1=hadoop1:2888:3888:participant;0.0.0.0:2181
   server.2=hadoop2:2888:3888:participant;0.0.0.0:2181
   server.3=hadoop3:2888:3888:participant;0.0.0.0:2181
   ```

4. 在上述dataDir目录下创建myid文件,并在其中输入上述server后和ip相对应的数字

   ```sh
   mkdir -p /shared/zookeeper/tmp
   echo 1 > /shared/zookeeper/tmp/myid # hadoop1
   echo 2 > /shared/zookeeper/tmp/myid # hadoop2
   echo 3 > /shared/zookeeper/tmp/myid # hadoop3
   chmod -R 777 /shared/zookeeper
   ```

   

### 3. Hadoop

1. 下载3.2.2版本并传至服务器解压

   [Apache Hadoop](https://hadoop.apache.org/releases.html)

2. 配置hadoop/etc下文件

   - 查找jdk路径

     ```sh
     ls -la /usr/bin |grep java 
     ```

   - 在/hadoop-env.sh, /yarn-env.sh中添加JAVA_HOME环境变量和ssh端口

     ```sh
     export JAVA_HOME=/usr/local/software/jdk1.8.0_271、
     export JRE_HOME=/usr/local/software/jdk1.8.0_271/jre
     export HADOOP_SSH_OPTS="-p 12312"
     ```

   - 配置core-site.xml

     ```xml
     <configuration>
         <property>
             <name>hadoop.tmp.dir</name>
             <value>/shared/hadoop/tmp</value> # 储存临时文件的目录
         </property>
      <property>
             <name>fs.defaultFS</name>
          <value>hdfs://hadoop1:50090</value> # 主节点(name node IP)
         </property>
     </configuration>
     ```

   - 配置hdfs_site.xml 副本和secondary node配置

     ```xml
     <configuration>
         <property> # 配置备份节点
             <name>dfs.secondary.http.address</name>
             <value>hadoop3:50090</value>
        </property>
      <property>
             <name>dfs.replication</name> # 设置副本数
          <value>2</value>
         </property>
     </configuration>
     ```

   - 配置mapred-site.xml map reduce 计算节点

     ```xml
     <configuration>
         <property>
             <name>mapreduce.framework.name</name>
             <value>yarn</value> 
         </property>
       </configuration>
     ```

   - 配置yarn-site.xml 资源管理节点

     ```xml
     <configuration>
         <property>
                 <name>yarn.nodemanager.aux-services</name>
                 <value>mapreduce_shuffle</value>
         </property>
         <property>
                 <name>yarn.resourcemanager.hostname</name>
              <value>hadoop1</value>  # 配置resource manager节点
         </property>
     </configuration>
     ```

   - 配置dfs启动权限

     ```sh
     # 添加hdfs权限 vim sbin/start-dfs.sh sbin/stop-dfs.sh 在顶部空白位置添加
     HDFS_DATANODE_USER=root
     HDFS_DATANODE_SECURE_USER=hdfs
     HDFS_NAMENODE_USER=root
     HDFS_SECONDARYNAMENODE_USER=root
     ```



### 4. Alluxio

#### 4.1 下载和安装

用2.5.0-3 Release版本

https://downloads.alluxio.io/downloads/files/2.5.0-3/alluxio-2.5.0-3-bin.tar.gz

```sh
tar -xzvpf alluxio-2.5.0-3-bin.tar.gz
mv alluxio-2.5.0-5-bin/* /shared/alluxio # 将alluxio复制到shared下
```

#### 4.2 配置alluxio和hdfs缓存关系


```sh
# /shared/alluxio/conf/alluxio-site.properties
alluxio.master.hostname=hadoop1
alluxio.underfs.address=hdfs://hadoop1:50090/
alluxio.worker.ramdisk.size=62GB # 配置ramdisk大小
alluxio.zookeeper.enabled=true
alluxio.zookeeper.address=hadoop1:2181,hadoop2:2181,hadoop3:2181
alluxio.zookeeper.session.timeout=120s
alluxio.master.journal.folder=hdfs://hadoop1:50090/alluxio/journal/
alluxio.master.journal.type=UFS
```

#### 4.3 配置ssh端口

- 替换文件夹下的所有ssh为ssh -p 12312

#### 4.4 挂载缓存并设置权限

```sh
sudo /shared/alluxio/bin/alluxio-mount.sh Mount # 挂载缓存
mkdir /mnt/ramdisk/alluxioworker
sudo chmod 777 -R /mnt/
```

#### 4.5 配置master和workers信息

```sh
# /shared/alluxio/conf/masters
hadoop1
hadoop2
hadoop3
```

```sh
# /shared/alluxio/conf/workers
hadoop1
hadoop2
hadoop3
```



   ### 5. Spark

#### 5.1 下载和安装

1. 下载3.1.1版本,支持Hadoop 3.2

   https://mirrors.bfsu.edu.cn/apache/spark/spark-3.1.1/spark-3.1.1-bin-hadoop3.2.tgz

2. 解压并放入/shared目录

   ```sh
   tar -xzf spark-3.1.1-bin-hadoop3.2.tgz
   mv spark-3.1.1-bin-hadoop3.2.tgz /shared/spark
   ```


#### 5.2 conf配置

 1. 类似hadoop,配置子节点,并将workers.template设置成works,并改名。

 2. 设置spark-env.sh

    ```sh
    export SPARK_MASTER_HOST=hadoop1 # 设置主节点ip
    export SPARK_MASTER_PORT=7077 # 设置主节点通信端口
    export SPARK_MASTER_WEBUI_PORT=8089 # webUI端口
    export SPARK_SSH_OPTS="-p 12312" # 设置ssh端口
    export LD_LIBRARY_PATH=$HADOOP_HOME/lib/native:$LD_LIBRARY_PATH # 设置hadoop库路径
    export SPARK_LOCAL_DIRS=$SPARK_HOME/tmp # 设置临时文件目录
    ```

#### 5.3 配置alluxio缓存

```sh
# vim /shared/spark/conf/spark-defaults.conf
spark.driver.extraClassPath /shared/alluxio/client/alluxio-2.5.0-3-client.jar
spark.executor.extraClassPath /shared/alluxio/client/alluxio-2.5.0-3-client.jar
```

### 6. kafka

1. 从官网下载2.8.0版本并解压

   https://mirrors.tuna.tsinghua.edu.cn/apache/kafka/2.8.0/kafka_2.13-2.8.0.tgz

2. 修改config/server.properties

   ```sh
   broker.id=0 # broker id,每个节点不同
   log.dirs=/shared/kafka/tmp/kafka-logs # 日志写入目录,需要有权限
   zookeeper.connect=server94:2181, server85:2181, server86:2181 # zookeeper用的节点 ip
   num.partitions=3 # 数据分片
   ```

3. 修改kafka log中的meta properties

   ```sh
   # /kafka/logs/kafka-logs
   cluster.id=AIcIjKA0SPiftH_Lx3z0og
   version=0
   broker.id=1
   ```

4. 在每个节点运行/bin/kafka-server

   ```sh
   bin/kafka-server-start.sh  config/server.properties
   ```

   

### 7. 集群启动和监控

1. 在hadoop1(主节点的文件中设置各个子节点)

   - 设置hadoop的子节点(DataNode)

     ```sh
     # vim /shared/hadoop/etc/hadoop/workers
     hadoop2
     hadoop3
     ```

   - 设置spark的子节点

     ```sh
     # vim /shared/spark/conf/workers
     hadoop2
     hadoop3
     ```

   - 设置alluxio的子节点

     ```sh
     # vim /shared/alluxio/conf/workers
     hadoop2
     hadoop3
     ```

2. 将所有安装好的文件分发到各个节点

   ```sh
   # hadoop2节点示例
   scp -P 12312 -r /shared/hadoop hadoop2:~
   scp -P 12312 -r /shared/spark hadoop2:~
   scp -P 12312 -r /shared/alluxio hadoop2:~
   scp -P 12312 -r /shared/zookeeper hadoop2:~
   ```

3. 在所有节点,将文件放入共享环境,并改变权限

   ```sh
   cp -rf ~/hadoop /shared/
   cp -rf ~/spark /shared/
   cp -rf ~/alluxio /shared/
   cp -rf ~/zookeeper /shared/
   
   chmod -R 777 /shared/hadoop
   chmod -R 777 /shared/spark
   chmod -R 777 /shared/alluxio
   chmod -R 777 /shared/zookeeper
   ```

4. 在主节点格式化

   ```sh
   # hadoop1
   hadoop namenode -format # 格式化hadoop
   alluxio format # 格式化alluxio
   ```

5. 启动所有组件

   ```sh
   zkServer.sh start # 启动zookeeper,每个结点都需要启动,如果已经启动了最好再重启一下
   /shared/hadoop/sbin/start-all.sh # 启动hadoop
   /shared/spark/sbin/start-all.sh # 启动spark
   /shared/alluxio/bin/alluxio-start.sh all SudoMount # 启动alluxio
   ```

6. 通过GUI查看是否正确启动主节点和子节点
   - **hdfs**: hadoop1:9870
   - **spark**: hadoop1:8089
   - **alluxio**: hadoop1:19999

7. 查看zookeeper工作状态

   ```sh
   zkServer.sh status
   ```

   