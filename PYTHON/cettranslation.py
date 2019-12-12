# _*_ coding:utf-8 _*_
import requests
import pymysql
import json
import time
import os
from lxml import etree

def updata(t,s):
	sql="INSERT INTO ARTICLE(title,ARTICLES) VALUES ('%s','%s')" % (t, s)
	try:
		# 执行sql语句
		print(t)
		cursor.execute(sql)
		# 提交到数据库执行
		db.commit()
	except:
		# 如果发生错误则回滚
		print(1)
		db.rollback()

	# 关闭数据库连接
def pa():
	url="https://cet6.koolearn.com/20191105/830297.html"
	titie_list=list()
	ch_list=list()
	en_list=list()
	response=requests.get(url)
	response.encoding = 'utf-8'
	data=etree.HTML(response.text)
	tp=data.xpath('//div[@align="center"]/a/@href')
	for p_url in tp:
		response=requests.get(p_url)
		response.encoding = 'utf-8'
		data=etree.HTML(response.text)
		title=data.xpath('//h1[@class="xqy_core_tit"]/text()')
		ch=data.xpath('//div[@class="xqy_core_text"]/p/text()')
		s=""
		for pas in ch:
			s=s+str(pas)+'\n'
		
		updata(str(title[0]),s)

		
def deal_that(s):
	return str(s)
def aa():
	path="sql/"
	f_list = os.listdir(path)
	for i in range(1,110):
		f_path=path+str(i)
		t=deal_that(f_path+'/titie.txt')
		c=deal_that(f_path+'/ch.txt')
		h=deal_that(f_path+'/en.txt')
		print (c)
	
			
def main():
	pa()
	

if __name__ == '__main__':
	db = pymysql.connect("localhost","root","1234","vote" )
	print('连接上了!')
	cursor = db.cursor()
	main()
	# test()
	db.close()