'''
时间：2019-7-14
目标网址：http://www.e5a5x.com/
采集需求：获得所有源代码
作者：钟志锴
'''
import urllib.request
import urllib.parse
import json
from lxml import etree
import sys
url="http://www.e5a5x.com/e5a5x/web3/B1/list_34_1.html"
page_source=etree.HTML(urllib.request.urlopen(url).read().decode("gb2312"))
page_total=page_source.xpath('/html/body/div/div/div[3]/div/span/strong[1]/text()')[0]
print(page_source)

content_list=page_source.xpath('/html/body/div/div/div[3]/ul[2]/li/a/@href') #主义这个地方是li
for eve_content in content_list:
    content_url="http://www.e5a5x.com/"+eve_content
    content_page_source=etree.HTML(urllib.request.urlopen(content_url).read().decode("gb2312"))
    title=content_page_source.xpath('//*[@id="page_content"]/div[2]/div[1]/div[1]/div[1]/h3/font/text()')[0]
    url_time=content_page_source.xpath('//*[@id="page_content"]/div[2]/div[1]/div[1]/div[2]/div/ul/li[6]/div[2]/text()')[0]
    url_time=url_time[2:10].replace('-','')
    download_url="http://down.e5a5x.com/uploads/soft/"+url_time+"/"+urllib.parse.quote(title) +".zip"
    print(title+".zip")
    #print(download_url)
    with open(title+".zip","wb") as f:
        f.write(urllib.request.urlopen(download_url).read())
