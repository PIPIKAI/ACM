
'''
时间：2019-7-14
目标网址：那啥
采集需求：获得所有源代码
作者：钟志锴
'''
import urllib.request
import json
from lxml import etree
import sys
output=sys.stdout
outputfile=open("D:\\PYTHON\\OUT.txt","a")
sys.stdout=outputfile
type = sys.getfilesystemencoding()
url="https://www.mt126.cc/video.html"
page_source=etree.HTML(urllib.request.urlopen(url).read().decode("utf-8"))
page_total=page_source.xpath('/html/body/div[1]/div[2]/div/div[3]/ul[1]/li[9]/a/text()')[0]
#总页数
page_total=int(page_total.replace(".",""))
for page in range(1,page_total):
    g_url="https://www.mt126.cc/vod-type-id-2-type--area--year--star--state--order-addtime-zb--p-"+str(page)+".html"
    g_page_source=etree.HTML(urllib.request.urlopen(g_url).read().decode("utf-8"))
    content_list=g_page_source.xpath('/html/body/div[1]/div[2]/div/div[2]/ul/li/a/@href') #主义这个地方是li
    for eve_content in content_list:
        content_url="https://www.mt126.cc/"+eve_content  
        try :
            content_page_source=etree.HTML(urllib.request.urlopen(content_url).read().decode("utf-8"))
            title=content_page_source.xpath('/html/body/div[1]/div[1]/div/div[2]/h1/text()')[0]
            print(title + " " +content_url)
        except:
            #可能有广告网站
            continue
