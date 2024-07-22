- [新机器开发环境部署](#新机器开发环境部署)
    - [1. 网络修复](#1-网络修复)
    - [2. 全局设置](#2-全局设置)
    - [3. Git](#3-git)
    - [4. Stable Diffusion](#4-stable-diffusion)
    - [5. Kafka](#5-kafka)
    - [6. Postgresql](#6-postgresql)
    - [7. Clickhouse](#7-clickhouse)
    - [8. MongoDB](#8-mongodb)
    - [9. NodeJs](#9-nodejs)


# 新机器开发环境部署

### 1. 网络修复

```sh
sudo bash -c 'echo -e "[network]
generateResolvConf = false" > /etc/wsl.conf
rm /etc/resolv.conf
echo -e "options timeout:1 attempts:1 rotate
nameserver 1.1.1.1
nameserver 1.0.0.1" > /etc/resolv.conf
chattr -f +i /etc/resolv.conf'
```

### 2. [全局设置](https://learn.microsoft.com/en-us/windows/wsl/wsl-config)

```shell
[boot]
systemd=true  # Enable systemctl

[wsl2]
memory=12GB  # Larger memory
swap=20GB
```

### 3. Git
```shell
# Use Vim as commit editor
export VISUAL=vim
export EDITOR=vim
# Set global user info
git config --global user.email "panchongdan@gmail.com"
git config --global user.name "Panda"
# Add token and import to github
cd ~/.ssh && ssh-keygen
```

### 4. Stable Diffusion
```sh
git clone https://github.com/AUTOMATIC1111/stable-diffusion-webui.git # 下载sd repo
conda env create -f environment-wsl2.yaml -n sd # 创建anaconda环境
cd stable-diffusion-webui && mkdir repositories
# 下载必要repo到目录中
git clone https://github.com/CompVis/stable-diffusion.git repositories/stable-diffusion
git clone https://github.com/CompVis/taming-transformers.git repositories/taming-transformers
git clone https://github.com/sczhou/CodeFormer.git repositories/CodeFormer
git clone https://github.com/salesforce/BLIP.git repositories/BLIP
# 安装必要Python包
pip install transformers diffusers invisible-watermark --prefer-binary
pip install git+https://github.com/crowsonkb/k-diffusion.git --prefer-binary
pip install git+https://github.com/TencentARC/GFPGAN.git --prefer-binary
pip install -r repositories/CodeFormer/requirements.txt --prefer-binary
pip install -r requirements.txt --prefer-binary
pip install -U numpy --prefer-binary
pip install xformers
pip install opencv-python-headless
# 下载模型并设置环境变量
cd /models/Stable-diffusion
wget https://huggingface.co/CompVis/stable-diffusion-v-1-4-original/resolve/main/sd-v1-4.ckpt
echo 'export LD_LIBRARY_PATH=/usr/lib/wsl/lib:$LD_LIBRARY_PATH' >> ~/.bashrc
# 启动
source ~/.bashrc
conda activate sd
python launch.py --skip-version-check
```

### 5. Kafka
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
5. 生成kafka配置文件
    ```sh
    bin/kafka-storage.sh random-uuid
    bin/kafka-storage.sh format -t <uuid> -c config/kraft/server.properties
    ```
6. 添加kafka到service
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

7. 设置目录权限
    ```sh
    sudo chown kafka /opt/kafka
    ```

### 6. Postgresql
1. Install
    ```sh
    sudo apt install postgresql
    sudo service postgresql start
    ```
2. Add user   
Switch to `postgres user` to add users 
    ```sql
    CREATE ROLE panda WITH SUPERUSER LOGIN PASSWORD 'pwd';
    ```
3. Create personal database
`createdb $(whoami)`   


### 7. Clickhouse
1. Install
    ```sh
    sudo apt-get install -y apt-transport-https ca-certificates dirmngr
    GNUPGHOME=$(mktemp -d)
    sudo GNUPGHOME="$GNUPGHOME" gpg --no-default-keyring --keyring /usr/share/keyrings/clickhouse-keyring.gpg --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 8919F6BD2B48D754
    sudo rm -r "$GNUPGHOME"
    sudo chmod +r /usr/share/keyrings/clickhouse-keyring.gpg

    echo "deb [signed-by=/usr/share/keyrings/clickhouse-keyring.gpg] https://packages.clickhouse.com/deb stable main" | sudo tee \
        /etc/apt/sources.list.d/clickhouse.list
    sudo apt-get update
    sudo apt install clickhouse-server clickhouse-client
    ```
2. Add service `/etc/systemd/system/clickhouse-server.service`
    ```sh
    [Unit]
    Description=ClickHouse Database Server
    After=network.target

    [Service]
    Type=simple
    User=clickhouse
    Group=clickhouse
    ExecStart=/usr/bin/clickhouse-server --config=/etc/clickhouse-server/config.xml
    Restart=on-failure

    [Install]
    WantedBy=multi-user.target
    ```
3. Add permission
    ```sh
    sudo chown -R  clickhouse /etc/clickhouse-server
    ```

4. [Create admin user](https://clickhouse.com/docs/en/operations/access-rights)


### 8. MongoDB

1. Follow the [official tutorial](https://www.mongodb.com/docs/manual/tutorial/install-mongodb-on-ubuntu/) to install mongodb
2. Add mongodb as a service `sudo systemctl start mongod`

### 9. NodeJs
1. 添加最新的node源到apt
    ```sh
    curl -fsSL https://deb.nodesource.com/setup_18.x | sudo -E bash -
    ```
2. 使用apt安装node
   ```sh
   sudo apt-get install nodejs -y
   ```
