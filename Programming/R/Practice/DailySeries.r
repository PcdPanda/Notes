library(xts) # 使用xts类前必须先加载库
library(quantmod)
YF_OL_to_AD_XTS <- function(stock_list,start_date,end_date){
    ts_list <- list()
    for (idx in seq(length(stock_list))){
    stock_index = stock_list[idx]
    ts_list[[idx]] <- get(getSymbols(stock_index, verbose = TRUE, src = "yahoo", from=start_date,to=end_date))
    xtsAttributes(ts_list[[idx]]) <- list(RIC=stock_index, GMTOffset=0, EventType="Daily, Measures", Market="US", XTSName=paste0("Yahoo Finance Daily Stock Prices for ",stock_index))
    } 
	return(ts_list)
	}
