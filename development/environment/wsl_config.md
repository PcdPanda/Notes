- [新机器开发环境部署](#新机器开发环境部署)
    - [1. 网络修复](#1-网络修复)
    - [2. 全局设置](#2-全局设置)
    - [3. Git](#3-git)
    - [4. Jupyter Notebook自动启动](#4-jupyter-notebook自动启动)


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
# /etc/wsl.conf
[boot]
systemd=true  # Enable systemctl
```

```shell
# "C:\Users\panch\.wslconfig"
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
配置.git/hooks/pre-commit
```shell
files=$(git diff --name-only --diff-filter=d HEAD | grep -E '\.pyi?$')
if [ -n "$files" ]; then
    echo ">>> Running format-python"
    format-python $files
    git add $files
fi
```


### 4. Jupyter Notebook自动启动
1. 设置service
```shell
Description=Jupyter Notebook (quant env)
After=network.target

[Service]
Type=simple
User=panda
ExecStart=/bin/bash -c "source /home/panda/.bashrc && /home/panda/miniconda3/bin/conda run -n quant jupyter lab --no-browser --port=8888"
WorkingDirectory=/home/panda
Restart=always

[Install]
WantedBy=default.target
```
2. 注意在`.bashrc`里要把变量export放在开头,确保非交互式脚本环境变量可以生效

3. 设置windows任务
打开 任务计划程序 → “创建任务”
名称：WSL Auto Start
勾选：使用最高权限运行（确保 WSL 能启动 systemd 服务）
“在用户登录时” 或 “计算机启动时” 操作：启动程序 程序/脚本：`wsl`
去掉“仅在使用交流电时启动”等限制 可勾选“如果失败，重新启动任务”

4. 配置自动导入,编辑`~/.ipython/profile_default/startup/ipython_stub.py`
    ```Python
    class LazyStub(object):
        """
        A stub object that initializes itself upon first access.
        The stub also replaces itself with the real object in
        the IPython namespace.
        """
        def __init__(self, varname, preexec, evalstr):
            self.varname = varname  # Variable name for the stub
            self.preexec = preexec  # Code to be executed before initializing object
            self.evalstr = evalstr  # Code to be evaluated to get object
            self.obj = None

        def _getobj(self):
            obj = object.__getattribute__(self, 'obj')
            if not obj:
                preexec = object.__getattribute__(self, 'preexec')
                evalstr = object.__getattribute__(self, 'evalstr')
                varname = object.__getattribute__(self, 'varname')

                ip = get_ipython()
                ip.ex(preexec)
                obj = ip.ev(evalstr)
                setattr(self, 'obj', obj)
                ip.push({varname: obj})
            return obj

        def __getattribute__(self, item):
            obj = object.__getattribute__(self, '_getobj')()
            return getattr(obj, item)

    def lazy_obj(varname, preexec, evalstr):
        ip = get_ipython()
        stub = LazyStub(varname, preexec, evalstr)
        ip.push({varname: stub})

    lazy_obj('mktlib', 'from pcdtrade.data.market import MarketLib', 'MarketLib()')
    ```

