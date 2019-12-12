#coding=utf-8
import os
import re
import keyword
import difflib
def eaqul_rate(str1,str2):
	# 返回相似度
	return difflib.SequenceMatcher(None, str1, str2).quick_ratio()
def deal_string(s):
	# 处理字符串
	s=s.replace('+',' ').replace(':',' ').replace('.',' ').replace('!',' ').replace('-',' ').replace('*',' ').replace('/',' ').replace('(',' ').replace(')',' ').replace('=',' ').replace('<',' ').replace('>',' ')
	for hs in has_list:
		if hs in s and hs != None:	
			s=s.replace(hs,' ')
	# 最后让多个的空格变成一个空格
	return re.sub(' +', ' ', s) 
def deal_that(a_path):
	s=""
	fa= open(a_path, "r").readlines() # a 文件
	for i in fa:
		# 去掉import 的那行
		if 'import' in i : 
			continue
		s=s + i			
	# 去掉换行和tab
	return deal_string(s.replace('\t',' ').replace('\n',' ')) 
def get_res(path):
	res =dict()
	f_list = os.listdir(path)
	for x in f_list:
		for y in f_list:
			if x==y:
				continue
			x_path=path+'\\'+x
			y_path=path+'\\'+y
			x_list=os.listdir(x_path)
			y_list=os.listdir(x_path)
			for x_filename in x_list:
				for y_filename in y_list:
					if (x_filename == y_filename and x_filename[-3:]==".py"): # a 文件和 b 文件 名字相同时 且为 .py 的文件
						a_path=x_path+"\\"+x_filename
						s1=deal_that(a_path)
						b_path=y_path+"\\"+y_filename
						s2=deal_that(b_path)
						p=eaqul_rate(s1,s2) #相似度
						res.setdefault(a_path,p)
	return res
def out_ans(res):
	j=0
	for w in sorted(res, key=res.get, reverse=True): #排序输出
		if j>=3:
			break
		j=j+1
	  	print w, res[w]
def main():	
	path ="D:\\test" 
	res =get_res(path)
	out_ans(res)
	raw_input()				

if __name__ == '__main__':
	has_list=list(dir(__builtins__)) +list(keyword.kwlist) # python 内建函数名和内建变量 和关键字
	main()
