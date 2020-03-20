# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
data=pd.read_csv('studentscores.csv')

plt.subplot(2,3,(1))
data_i= data.Hours
data_j= data.Scores

plt.scatter(data_i,data_j)

plt.subplot(2,3,(2))
bins=range(10,101,10)  # bins=1
n=plt.hist(data.Scores,bins)

plt.subplot(2,3,(3))
bins=range(1,101,1)  # bins=1
n=plt.hist(data.Scores,bins)

plt.subplot(2,3,(4))
plt.boxplot(data.Hours)

plt.subplot(2,3,(5))
labels='A','B','C','D','E'
grades=data.Scores
fw=[[0,20],[20,40],[40,60],[60,80],[80,100]]
grade=[]
for i in range(5):
    tp=0
    for j in grades :
        if(j >= fw[i][0] and j <= fw[i][1]):
            tp+=1
    grade.append(float(tp/len(grades)))

size=[grade[ -1],grade[-2], grade[-3], grade[-4],sum(grade[:6])]
explode=(0,0,0,0,0.1)
plt.pie(size , explode, labels , autopct=
 " %1.1f%%", shadow=True, startangle=60)
plt.subplot(2,3,(6))
values = grade
# plt. figure(figsize=(5,3), dpi=100)
bars = plt. bar(labels,values )
patterns =['/','O','*','.','-']
for bar in bars:
    bar.set_hatch(patterns.pop(0))
    
plt.show()