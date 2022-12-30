# The aim of this code is to analyse which of these materials will be the most suitable for engineering
# purposes. This is done by using the tidyverse library, using statistical data and reading plots


library(tidyverse)
x = read.csv("MPEA_dataset.csv")


#Data frame with data from the MPEA dataset that will be used for data visualization and analysis#
y <- data.frame( Temp = x$PROPERTY..Test.temperature.....circ.C., 
                 Type = x$PROPERTY..Single.Multiphase, 
                 YS =x$PROPERTY..YS..MPa. ,
                 Grain_Size = x$PROPERTY..grain.size....mu.m.,
                 Synthesis_method = x$PROPERTY..synthesis.method,
                 Phase = x$PROPERTY..Type.of.phases)

hist(x$PROPERTY..YS..MPa.) #histogram for the yield srength#

boxplot(x$PROPERTY..YS..MPa.)
mean(x$PROPERTY..YS..MPa., na.rm = TRUE)

# Plot to visualize the relationship between temperature and Yield Strength #
ggplot(y, aes(Temp,YS,colour = Type)) + geom_point(alpha = 0.5) + geom_smooth(method = lm, se = F)

#Plot to visualize the relationship between grain size and Yield Strength #
ggplot(y, aes(Grain_Size,YS,colour = Type)) + geom_point(alpha = 0.5) +  facet_wrap(~Type)

#Plot to visualize the relationship between temperature and Grain size#
ggplot(y, aes(Temp,Grain_Size,colour = Type)) + geom_point(alpha = 0.5) +  facet_wrap(~Synthesis_method)


trial = x
nrow(trial)
is.na(trial$PROPERTY..YS..MPa.[i])
#filtering to remove rows with NA in the Yield Strength column
trial2 = trial[!is.na(trial$PROPERTY..YS..MPa.),]

#check to see if the mean returns any NA values without filtering for NA's
mean(trial2$PROPERTY..YS..MPa.)

trial3 = trial2[trial$PROPERTY..YS..MPa. >= mean(trial2$PROPERTY..YS..MPa.),]


#Material selecting function
Selecter<- function(Dataset){
  l = 0
  Yield_strength <- readline("Enter the Yield strenght: ")
  Elastic_modulus <- readline("Enter the Youngs Modulus: ")
  Dataset_filtered = Dataset[!is.na(trial$PROPERTY..YS..MPa.),]
  
  for (l in 1:nrow(Dataset_filtered)){
    if((Dataset_filtered$PROPERTY..YS..MPa.[l]>=Yield_strength) &&
      (Dataset_filtered$PROPERTY..ROM.Young.modulus..GPa.[l] >= Elastic_modulus)){
      print(Dataset_filtered[l,])
      l = l +1
    }else{
      l = l+ 1
    }
  }
}



