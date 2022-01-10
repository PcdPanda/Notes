[toc]

[环境配置]([Using RStudio Server in Windows WSL2 – RStudio Support](https://support.rstudio.com/hc/en-us/articles/360049776974-Using-RStudio-Server-in-Windows-WSL2))

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

