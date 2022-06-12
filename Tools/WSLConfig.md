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

### 2. Ngrok

```shell
curl -s https://ngrok-agent.s3.amazonaws.com/ngrok.asc | sudo tee /etc/apt/trusted.gpg.d/ngrok.asc >/dev/null &&
              echo "deb https://ngrok-agent.s3.amazonaws.com buster main" | sudo tee /etc/apt/sources.list.d/ngrok.list &&
              sudo apt update && sudo apt install ngrok   
              
```

### 3. Git

- 修改allow_remote_access=True

```sh
jupyter notebook --generate-config
vim /home/panda/.jupyter/jupyter_notebook_config.py
```

- 配置自动补全

```shell
conda install -c conda-forge jupyter_nbextensions_configurator
conda install -c conda-forge jupyter-resource-usage
jupyter nbextension enable hinterland/hinterland
```

- 配置text wrapping

```json
vim /home/panda/.jupyter/nbconfig/notebook.json

{
  "MarkdownCell": {
    "cm_config": {
      "lineWrapping": true
    }
  },
  "CodeCell": {
    "cm_config": {
      "lineWrapping": true
    }
  }
}
```

- 配置wsl交换空间

```
[wsl2]
memory=10GB
swap=10GB
localhostForwarding=true
```

### 5. Rstudio

```sh
sudo apt-get update
sudo apt-get upgrade -y
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys E298A3A825C0D65DFD57CBB651716619E084DAB9
sudo add-apt-repository 'deb https://cloud.r-project.org/bin/linux/ubuntu focal-cran40/'
sudo apt install -y r-base r-base-core r-recommended r-base-dev gdebi-core build-essential libcurl4-gnutls-dev libxml2-dev libssl-dev
wget https://rstudio.org/download/latest/stable/server/bionic/rstudio-server-latest-amd64.deb
sudo gdebi rstudio-server-latest-amd64.deb
wget https://rstudio.org/download/latest/stable/server/bionic/rstudio-server-latest-amd64.deb
sudo gdebi rstudio-server-latest-amd64.deb
```

