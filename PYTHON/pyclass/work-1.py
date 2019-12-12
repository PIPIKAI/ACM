#coding=utf-8
import os
path ="C:\\WINDOWS"  
f_list = os.listdir(path)
my_file= open("out.txt", "w")
my_file.write(path+'\n')
for i in f_list:
	my_file.write('    '+i+'\n')