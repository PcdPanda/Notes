# Kafka
1. 安装java
    ```sh
    wget -O- https://apt.corretto.aws/corretto.key | sudo apt-key add - 
    sudo add-apt-repository 'deb https://apt.corretto.aws stable main'
    sudo apt-get update; sudo apt-get install -y java-11-amazon-corretto-jdk
    ```
2. wget 下载最新的kafka tar并解压放到`/opt/kafka`中
3. 创建kafka用户
    ```sh
    sudo useradd kafka -m
    sudo usermod -aG kafka kafka
    ```
4. 设置日志目录
修改`/opt/kafka/config/kraft/server.properties`重新设置日志目录,例如`/opt/kafka/log`
1. 生成kafka配置文件
    ```sh
    bin/kafka-storage.sh random-uuid
    bin/kafka-storage.sh format -t <uuid> -c config/kraft/server.properties
    ```
2. 添加kafka到service
    ```sh
    [Unit]
    Description=Apache Kafka
    After=network.target

    [Service]
    Type=simple
    User=kafka
    Group=kafka
    ExecStart=/opt/kafka/bin/kafka-server-start.sh /opt/kafka/config/kraft/server.properties
    ExecStop=/opt/kafka/bin/kafka-server-stop.sh
    Restart=on-failure

    [Install]
    WantedBy=multi-user.target
    ```

3. 设置目录权限
    ```sh
    sudo chown kafka /opt/kafka
    ```