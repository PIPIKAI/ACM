#coding=utf-8
import datetime
import  os
filename = "钟志锴34号第二题.txt".decode('utf-8')
f_list =open("2.py").readlines()
my_file= open(filename, "w")
my_file.write('#时间：'+str(datetime.datetime.now())+'\n')
for i in f_list:
	my_file.write(i)
