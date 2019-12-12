#coding=utf-8
import os
import time
from math import ceil
def secondsToStr(seconds):
    x = time.localtime(seconds)  
    return time.strftime("%Y-%m-%d %X", x)  
path ="D:\\test"  
filename="统计2.csv".decode('utf-8') # 保存每个同学的和每个同学的相似度
my_file= open(filename, "w")
student=dict()
res=dict()
f_list = os.listdir(path)
for x in f_list:
	for i in xrange(1,5):
		f_path=path+'\\'+x+'\\'+str(i)+'.py'
		file_info = os.stat(f_path) #获取文件属性信息
		
		name=x+str(i)
		student.setdefault(name+'size',str(ceil(file_info.st_size/1024)))
		student.setdefault(name+'maketime',secondsToStr(file_info.st_ctime))
		student.setdefault(name+'changetime',secondsToStr(file_info.st_mtime))
for x in f_list:
	for y in f_list:
		f_path=path+'\\'+x
		p=0
		if x!=y:
			for i in xrange(1,5):
				
				name1=x+str(i)
				name2=y+str(i)
				if(student[name1+'size']==student[name2+'size']):
					p=p+1
				if(student[name1+'maketime']==student[name2+'maketime']):
					p=p+1
				if(student[name1+'changetime']==student[name2+'changetime']):
					p=p+1
			my_file.write(x+'  with  '+y + '相似度：')
			my_file.write(str(p)+'\n')
			res.setdefault(f_path,p)
j=0
for w in sorted(res, key=res.get, reverse=True): #排序输出
	if j>=3:
		break
	j=j+1
  	print w, res[w]