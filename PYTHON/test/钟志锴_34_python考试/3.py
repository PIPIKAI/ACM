#coding=utf-8
import os
import time
from math import ceil
def secondsToStr(seconds):
    x = time.localtime(seconds)  
    return time.strftime("%Y-%m-%d %X", x)  
path ="D:\\test"  
filename="统计1.csv".decode('utf-8')
my_file= open(filename, "w")

f_list = os.listdir(path)
for x in f_list:
	f_path=path+'\\'+x+'\\1.py'
	file_info = os.stat(f_path) #获取文件属性信息
	my_file.write('目录名：'+x+'\n')
	my_file.write('size:'+str(ceil(file_info.st_size/1024))+'\n')
	my_file.write('make_time:'+str(secondsToStr(file_info.st_ctime))+'\n')
	my_file.write('change_time:'+str(secondsToStr(file_info.st_mtime))+'\n')
