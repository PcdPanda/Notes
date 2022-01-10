library(xts)

# exercise 1
ex_matrix <- matrix(data = seq_len(9), nrow = 3, ncol = 3, byrow = TRUE)
idx <- seq(as.Date("2019-05-08"), length = 3, by = "day")
xts1 <- xts(x = ex_matrix, order.by = idx)
str(xts1)
ex_matrix[2, ]
ex_matrix[3, ]

# exercise 2
data <- rnorm(5)
dates <- seq(as.Date("2016-01-01"), length = 5, by = "day")
smith <- xts(x = data, order.by = dates)
bday <- as.POSIXct("1899-05-08")
hayek <- xts(x = data, order.by = dates, born = bday)

# exercise
hayek_core <- coredata(hayek)
class(hayek_core)
hayek_index <- index(hayek)
hayek_index

# exercie 4

dates <- seq(as.Date("2016-01-01"), length = 5, by = "day")
ts_a <- xts(x = data, order.by = dates)
ts_b <- xts(x = data, order.by = as.POSIXct(dates))
ts_a[index(ts_b)]
ts_b[index(ts_a)]