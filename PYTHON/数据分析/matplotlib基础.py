# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt

X=np.linspace(-np.pi,np.pi,256,endpoint=True) # 
C,S=np.sin(X) , np.cos(X)

# 设置 x和Y轴显示的坐标
plt.xticks([-np.pi,-np.pi/2,0,np.pi/2,np.pi],[r'$-\pi$',
           r'$-\pi/2$',r'$0$',r'$\pi/2$',r'$\pi$'])
plt.yticks([-1,- 1/2,0,1/2,1])
# 设置框框
ax=plt.gca()
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.spines['left'].set_position(('data',0)) #移到数值为0的位置
ax.spines['bottom'].set_position(('data',0))


plt.subplot(2,1,1) #(行，列，第几个)
plt.plot(X, C, color="blue", linestyle='-', label='cos')

plt.subplot(2,1,2)
plt.plot(X, S, color="red", linestyle='-', label='sin')

plt.legend(loc='upper left',frameon=True) # 坐标系
plt.show()