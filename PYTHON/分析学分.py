import requests
from lxml import etree
import re
import json
get_url="http://hnist.fanya.chaoxing.com/portal/schoolCourseInfo/columnCourse?columnId=16231&pageNum=1"
page_num=5
header={
	"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.169 Safari/537.36",
}
respons=requests.get(url=get_url,headers=header)
data=etree.HTML(respons.text)
url_list=data.xpath('//div[@class="clearfix"]/dl/dt[1]/a/@href') 
for menu_url in url_list:
	respons=requests.get(url=menu_url,headers=header)
	data=etree.HTML(respons.text)
	video_url_list=data.xpath('//a[@class="wh wh1"]/@href')
	for sg_url in video_url_list:
		now_url="http://mooc1.chaoxing.com"+sg_url
		respons=requests.get(url=now_url,headers=header)
		data=etree.HTML(respons.text)
		zsg_url=data.xpath('//*[@id="ext-gen1039"]/iframe')
		dd=requests.get(now_url).json()
		
		#next_url="http://cs.ananas.chaoxing.com/support/"+zsg_url+".srt"
		print(dd)
		break
	break
	


