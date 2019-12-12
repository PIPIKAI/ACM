#coding=utf-8
import datetime
import  os
f1 = "吴文涛xx号第二题.txt"
f1=f1.decode('utf-8')
f2 =open("2.py").readlines()
f3= open(f1, "w")
f3.write('#时间：'+str(datetime.datetime.now())+'\n')
for i in f2:
	f3.write(i)
