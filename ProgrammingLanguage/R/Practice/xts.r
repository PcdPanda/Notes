library(xts) # 使用xts类前必须先加载库

as.Date(c("2015-1-1", "2015-1-3")) # 创建index对象

seq(as.Date("2019-8-1"), length = 5, by = "days") # 生成序列化时间
seq(as.Date("2019-8-1"), length = 5, by = "weeks") # 每周生成一个
Sys.Date() - 1:10 # 显示过去十天的日期

dates <- (Sys.Date() - 1) + 1:10 # 显示包括今天和未来9天一共10天的日期
class(dates) # 输出类名

xts(x = 1:10, order.by = Sys.Date() - 1:10) # 以过去10天为index生成time series
values <- rnorm(5) # 生成5个随机标准正态分布的数

# 用序列化时间创建矩阵
dates <- seq(as.Date(Sys.Date()), length = 5, by = "year") # 长度为5,间隔为年
values <- xts(x = values, order.by = dates)
coredata(values) # 获取xts数据的值,去除index
index(values) # 获取xts数据的index
str(values) # 获取矩阵的格式

# 从矩阵中提取时间
first(values, "1 month") # 获取第一天
last(values, "3 year") # 最后三年
first(last(values, "1 week"), "3 day") # 获取最后一周的前三天
start(values) - end(values) # 第一天和最后一天相减 

values3 <- xts(x = rnorm(20), order.by = seq(as.Date("2017-10-5"), length = 20, by = "months"))
values3
values3["2019-01-05"] <- 0
values3["2019-02-05"] <- NA #变成na
values3["2019-01/2019-05"] # 获得2019年1月到5月的数据
values3["/2019-05"] # 获得2019年5月前的所有数据
tclass(values3) # 获得矩阵index的数据类型
tzone(values3)
periodicity(values3) # 获得数据的周期
nmonths(values) # 获得数据占用的月份
nyears(values3) # 获得数据占用的年份
.index(values3) # 获得数字类型的index

