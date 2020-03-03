import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import train_test_split

plt.title('draw')
pos=plt.ginput(10) #点击 10个点
p=np.array(pos)
X=p[:,:1]
Y=p[:,1:]
reg=LinearRegression()
reg=reg.fit(X,Y)
plt.scatter(X,Y,color='red')
#可视化回归线
plt.plot(X, reg.predict(X),color='blue' )
plt. show()