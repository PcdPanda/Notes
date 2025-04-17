# IPOPT

1. Getting system packages
   ```sh
   sudo apt-get install gcc g++ gfortran git patch wget pkg-config liblapack-dev libmetis-dev
   ```
2. Install MUMPS
   ```sh
   git clone https://github.com/coin-or-tools/ThirdParty-Mumps.git
    cd ThirdParty-Mumps
    ./get.Mumps
    ./configure
    make
    sudo make install
   ```
3. 下载ipopt并安装和编译(可能需要sudo权限)
   ```sh
   sudo cd /opt && git clone https://github.com/coin-or/Ipopt.git
   export IPOPTDIR=/opt/Ipopt
   mkdir $IPOPTDIR/build -p
   cd $IPOPTDIR/build
   $IPOPTDIR/configure
   make
   make test
   make install
   ```
4. 安装MUMPS求解器
   ```sh
   git clone https://github.com/coin-or-tools/ThirdParty-Mumps.git
    cd ThirdParty-Mumps
    ./get.Mumps
    ./configure
    make
    sudo make install
   ```
5. 将lib路径添加到.bashrc
   ```sh
   export LD_LIBRARY_PATH=/opt/Ipopt/build/src/.libs/:$LD_LIBRARY_PATH
   export LD_LIBRARY_PATH=/opt/ThirdParty-Mumps/.libs/:$LD_LIBRARY_PATH
   ``` 
6. 用pip安装cyipopt
   ```sh 
   pip install cyipopt
   ```