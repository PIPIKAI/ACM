#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 25 08:06:11 2020

@author: zhongzhikai
"""
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

# 读入数据
train_data=pd.read_csv('Digit/train.csv')
y_train= train_data['label'].values
x_train= train_data.drop(columns = ['label']).values
x_test=pd.read_csv('Digit/x_test.csv').values
y_test=pd.read_csv('Digit/y_test.csv')['Label'].values

# 图像二值化
th=128
x_train[x_train < th]=0
x_train[x_train >= th]=1
x_test[x_test < th]=0
x_test[x_test >= th]=1

# 显示图像
print("显示训练集前十个图像")
plt.figure(tight_layout=True )
for i in range(0,10):
    image=x_train[i,:].reshape(28,28)
    plt.subplot(2,5,i+1)
    plt.imshow(image,cmap='gray')
    plt.title(y_train[i])
    plt.axis('off')
plt.show()
# 特征选择 28*28 -> 14*14 ->? 7*7
rows = [i*28+j for i in range(0,28,2) for j in range(28)]
x_train = x_train[:,rows]
x_train = x_train[:,::2]
x_test = x_test[:,rows]
x_test = x_test[:,::2]

#模型的训练和调参数
print('开始训练')
from sklearn.model_selection import cross_val_score
from sklearn.neighbors import KNeighborsClassifier
k_range = np.arange(1,46)
k_score= pd.read_csv('data.txt',sep='\t')['score'].values

for k in k_range:
    knn=KNeighborsClassifier(n_neighbors=k ,weights='uniform')
    score=cross_val_score(knn, x_train , y_train ,cv= 5)
    k_score.append(np.mean(score))
    print(k_score[-1])

# n_neighbors - accuracy 曲线图

vmax = np.max(k_score)
kmax= k_range[np.argmax(k_score)]
plt.plot(k_range, k_score)
plt.xlabel('n_neighbors')
plt.ylabel('accuracy')
plt.scatter([kmax],[vmax],color='red')
plt.show()
print('kmax=',kmax,'vmax=',vmax)
# 用最好的k值来训练
knn = KNeighborsClassifier(n_neighbors=kmax)
knn.fit(x_train,y_train)
y_pred=knn.predict(x_test)
print('测试集预测正确率:')
print(knn.score(x_test,y_test))

print("显示测试集前十个图像")
plt.figure(tight_layout=True )
for i in range(0,10):
    image=x_test[i,:].reshape(14,14)
    plt.subplot(2,5,i+1)
    plt.imshow(image,cmap='gray')
    plt.title(y_pred[i])
    plt.axis('off')
plt.show()