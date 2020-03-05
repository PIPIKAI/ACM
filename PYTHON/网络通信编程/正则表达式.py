# -*- coding: utf-8 -*-
import re

def read_file(name):
	file_name=name.encode('utf-8')
	return open(file_name,'r').read()

# 1、写出中国的手机号码模式字符串。
def get_phonenumbers(content):
	return re.findall(r'1[3-9]\d{9}',content)

#2、匹配所有合法的电子邮件地址(
def get_email(content):
	return re.findall(r'[0-9a-zA-Z_]{0,19}@[0-9a-zA-Z_/.]{1,13}\.[com,cn,net]{1,3}',content)
# 4、匹配所有合法的 Web 网站地址(URLs)
def get_url(content):
	return re.findall(r'[a-zA-z]+://[^\s]*',content)

# 5、匹配所有合法的身份证号码。
def get_IDnumbers(content):
	return re.findall(r'^([1-9])(\d{5})(19|20)(\d{2})((0[1-9])|(1[0-2]))(([0|1|2]\d)|3[0-1])(\d{3})([0-9]|X)$',content)
# 先读入文件
content=read_file('files/people.txt')

print(get_IDnumbers(content))

