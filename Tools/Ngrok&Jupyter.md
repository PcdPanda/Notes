# 新机器开发环境部署

- wsl必须先降级到1版本

```sh
ngrok http -subdomain=jupyter 8888
ngrok http -subdomain=vscode 8080
```

- 安装ngrok

```shell
curl -s https://ngrok-agent.s3.amazonaws.com/ngrok.asc | sudo tee /etc/apt/trusted.gpg.d/ngrok.asc >/dev/null &&
              echo "deb https://ngrok-agent.s3.amazonaws.com buster main" | sudo tee /etc/apt/sources.list.d/ngrok.list &&
              sudo apt update && sudo apt install ngrok   
              
```

- 修改allow_remote_access=True

```sh
jupyter notebook --generate-config
vim /home/panda/.jupyter/jupyter_notebook_config.py
```

- 配置自动补全

```shell
conda install -c conda-forge jupyter_nbextensions_configurator
jupyter nbextension enable hinterland/hinterland
```

