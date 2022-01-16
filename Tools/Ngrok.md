# Ngrok部署wsl内网服务

wsl必须先降级到1版本

```sh
ngrok http -subdomain=jupyter 8888
ngrok http -subdomain=vscode 8080
```

安装

```shell
curl -s https://ngrok-agent.s3.amazonaws.com/ngrok.asc | sudo tee /etc/apt/trusted.gpg.d/ngrok.asc >/dev/null &&
              echo "deb https://ngrok-agent.s3.amazonaws.com buster main" | sudo tee /etc/apt/sources.list.d/ngrok.list &&
              sudo apt update && sudo apt install ngrok   
              
```

allow remote access
