'''
时间：2019-8-15
目标网址：博客园
目的：刷博客访问数
作者：zzk
'''
import requests
from lxml import etree
import json
import time
import re
import random
headers={
        "user-agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36",
}
def now_num():
    url="https://www.cnblogs.com/37kiazz73/"
    respons=requests.get(url=url,headers=headers)
    data=etree.HTML(respons.text)
    blog_list=data.xpath('//a[@class="postTitle2"]/@href')
    num_list=data.xpath('//div[@class="postDesc"]/text()')
    for _ in num_list:
        _=re.findall("阅读.+\) ",_,re.S)#当前的阅读数
        if(_):
            print(_)
def get_ip():
    respons=requests.get(url="https://www.xicidaili.com/nt",headers=headers)
    data=etree.HTML(respons.text)
    proxy_list=data.xpath('//tr[@class]/td[2]/text()')
    dk_list=data.xpath('//tr[@class]/td[3]/text()')
    k=random.randint(1,100)
    #随机从ip池中选出一个ip
    return [proxy_list[k], dk_list[k] ]

def changeIP():
    url="http://ip.chinaz.com/getip.aspx"
    pro=get_ip()
    proxie="http://"+pro[0]+":"+pro[1]
    proxies = {
    "http": proxie,
    "https": proxie,
    }
    return proxies

def get_adress():
    proxies=changeIP()
    print(proxies)
    response = requests.get(
        url="https://en.ipshu.com/myip_location.php?lang=zh-hans",
        proxies=proxies,
        headers=headers,
    )
    print(response.text)

def do():
    try:
        get_adress()
    except requests.exceptions.ConnectionError as e:
        print('Error', e.args)

while (1):
    do()


    

    
    








# for _ in blog_list:
#     tp=requests.get(url=_,headers=headers)
#     data=etree.HTML(tp.text)
#     print(tp.url)
#     nmb=data.xpath('//*[@id="post_view_count"]/text()')[0]
#     print(nmb)
#     time.sleep(1)