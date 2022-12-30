#importing the tidyverse and dplyr libraries to get access to functions

library(tidyverse)
library(dplyr)
k = read.csv("BeachesData.csv")


#while loop to create a list with the beach ecoli values
i=4
while(i<=49){
  df <- cbind(df,k[,i])
  i = i+5
}
df <- df[,-1]
nf = df


# While loop to get the names of the beaches in a vector called collect
i=3
collect <- c()
cout <- 1
collect
while(i<=49){
  collect[cout] <- k[1,i]
  i = i+5
  cout = cout +1
}

#checking to see if the vector was able to collect
collect

# numbering the rows and naming the columns
rownames(nf) <-(1:nrow(nf))
colnames(nf) <- collect

#checking to see if it worked
head(nf)

#removing the NA rows and making a data frame with the remaining rows
nf2 <- nf[rowSums(is.na(nf)) == 0, ]
nf3 = as.data.frame(nf2)

#creating a vector of the sample Ranges day by day
i = 1
range_collect = c(1:nrow(nf3))
while(i<=nrow(nf3)){
  range_collect[i] = max(as.numeric(unlist(nf3[i,]))) - min(as.numeric(unlist(nf3[i,])))
  i = i+1
}

#checking to see if the vector was established 
range_collect
row_days <- as.numeric(rownames(nf3))
#Taking the mean to get the rbar values
R_bar = mean(range_collect)
LCL_R = 0.223*R_bar
UCL_R = 1.777*R_bar

#Making a dataframe with the means, ranges and days
R <- data.frame(Days = row_days, Ranges = range_collect, Means = mean_collect )

#plotting the Rbar control chart
ggplot() +
  geom_line(data = R, mapping = aes(x=Days, y=Ranges), color='blue')+
  geom_point(data = R, mapping = aes(x=Days, y=Ranges), color='blue')+
  geom_hline(yintercept = R_bar, linetype = 'solid', color = 'red')+
  geom_hline(yintercept = LCL_R, linetype = 'solid', color = 'green')+
  geom_hline(yintercept = UCL_R, linetype = 'solid', color = 'green')


#creating a vector of the sample means day by day
i = 1
mean_collect = c(1:nrow(nf3))
while(i<=nrow(nf3)){
  mean_collect[i] = mean(as.numeric(unlist(nf3[i,])))
  i = i+1
}
#checking to see if the vector was established 
mean_collect

#Taking the mean to get the xbar values
X_bar = mean(mean_collect)
UCL_M = X_bar+(0.308*R_bar)
LCL_M = X_bar-(0.308*R_bar)

#plotting the Xbar control chart
ggplot() +
  geom_line(data = R, mapping = aes(x=Days, y=Means), color='blue')+
  geom_point(data = R, mapping = aes(x=Days, y=Means), color='blue')+
  geom_hline(yintercept = X_bar, linetype = 'solid', color = 'red')+
  geom_hline(yintercept = LCL_M, linetype = 'solid', color = 'green')+
  geom_hline(yintercept = UCL_M, linetype = 'solid', color = 'green')

