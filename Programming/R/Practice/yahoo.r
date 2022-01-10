library(xts) # 使用xts类前必须先加载库
ts2 <- readRDS("AD_example.rds") # 读取rds文件
length(ts2) # 获得ts2的长度
ts2_1 <- ts2[[1]]
ts2_2 <- ts2[[2]]
range(index(ts2_1)) # 获得ts2[1]的下标范围
labels(coredata(ts2_1[0])) # 获得每个列的名字

xtsAttributes(ts2_1)$RIC
xtsAttributes(ts2_1)$GMTOffset
xtsAttributes(ts2_1)$EventType
xtsAttributes(ts2_1)$Market
xtsAttributes(ts2_1)$XTSName # 获得各个不同的属性

