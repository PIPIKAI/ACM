# -*- coding: utf-8 -*-
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
# 读入数据
train_data=pd.read_csv('optdigits.tes')
totol_train= train_data[:200][:]
y_train= totol_train['0.29'].values
x_train=totol_train.drop(columns = ['0.29']).values
#图像二值化
th=8
x_train[x_train < th]=0
x_train[x_train >= th]=1

# 显示图像
plt.figure(tight_layout=True )
km = KMeans(n_clusters=10)
km.fit(x_train)
labels =km.labels_
ans =[]
for label in range(0,10):
    num =np.sum(labels == label)
    plt.figure(tight_layout=True )
    j=0
    print("class = "+str(label),end='')
    ans.append([])
    for i in range(0,200):
        if(labels[i]==label):
            image=x_train[i,:].reshape(8,8)
            plt.subplot(7,6,j+1)
            plt.imshow(image,cmap='gray')
            plt.title(y_train[i])
            plt.axis('off')
            ans[label].append(y_train[i])
            j+=1
    plt. show()
i=0
for array in ans:
    a1=max(array, key=array.count)
    right =array.count(max(array, key=array.count))
    print("类 ",i,"出现做多的数字是",a1,"出现",right,"次 正确率为：",right/len(array))
    i+=1

     


