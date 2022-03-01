[toc]

[环境配置](https://support.rstudio.com/hc/en-us/articles/360049776974-Using-RStudio-Server-in-Windows-WSL2)

# 1. 基本操作

### 1.1 项目管理

##### 修改工作区

```R
setwd("MyDir")
```

##### 包管理

```R
install.packages("PackageName", repos="url") # 安装包
library("Package") # 导入包
```

### 1.2 基本数据结构

##### 向量

```R
v1 <- c(1,2,3) 
v2 <- c(3:5) # 切片生成向量[3,4,5]
```

### 1.3 面板数据

##### 时间戳

```R
ts <- as.Date(df$Date, format="%m/%d/%Y")
```

### 1.4 Plot

##### 绘制子图

```R
par(mfrow=c(2,2))
plot(SP500wk,xlab=’week’,ylab=’closing price’,type=’l’) # line plot
boxplot(SP500wk_lreturn) # boxplot
hist(SP500wk_lreturn,xlab=’wkly log returns’,breaks=25,main=’SP500 weekly log returns’) #直方图
```

