- [新机器开发环境部署](#新机器开发环境部署)
    - [1. 网络修复](#1-网络修复)
    - [2. 全局设置](#2-全局设置)
    - [3. Git](#3-git)


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
