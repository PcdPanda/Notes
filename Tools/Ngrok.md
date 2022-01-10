# Ngrok部署wsl内网服务

wsl必须先降级到1版本

```sh
ngrok http -subdomain=jupyter 8888
ngrok http -subdomain=vscode 8080
```

