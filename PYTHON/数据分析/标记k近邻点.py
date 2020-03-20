# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
import math
def distance(i,index):
    return math.sqrt((X[index]-X[i])**2+(Y[index]-Y[i])**2) 
X=np.random.randint(0,10,10)
Y=np.random.randint(0,10,10)
plt.xlim(0,10)
plt.ylim([0,10])
plt.scatter(X,Y,color='red')
# 随机选择点点下标
index=np.random.choice(10,1)
plt.scatter(X[index],Y[index],color='blue')
dist=[]
for i in range(0,10):
    dist.append(distance(i,index))
dist=np.sort(dist)
K=3
The_KnearsX= []
The_KnearsY= []
The_Knears=[]
for i in range(0,K+1):
    for j in range(0,10):
        if(distance(j,index) == dist[i] and j != index and j not in The_Knears):
            The_KnearsX.append(X[j])
            The_KnearsY.append(Y[j])
            The_Knears.append(j)
            break
plt.scatter(The_KnearsX,The_KnearsY,color='green',s=300,alpha='0.3')
print(index)
plt.show()

