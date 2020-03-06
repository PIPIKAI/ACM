'''
目标网址：https://www.manhuadb.com/
目的：下载漫画
时间：2019-8-6
作者：zzk
'''
import requests
import json
import time
import os
from lxml import etree

def solve():
    #key=input("请输入要搜索的漫画")
    keyword="石纪元"
    file='C:/Users/kiass/Desktop/{}/'.format(keyword)
    if not os.path.exists(file):
        os.mkdir(file)
        print('创建文件夹：', file)
    r_url="https://www.manhuadb.com"
    header={
    "upgrade-insecure-requests": "1",
    "user-agent": "Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Mobile Safari/537.36",
    }
    url="https://www.manhuadb.com/manhua/1408/1608_16466.html"
    response=requests.get(url=url,headers=header)
    data=etree.HTML(response.text)
    tp=data.xpath('//a[@class=" fixed-a-es"]/@href')
    hui_list=tp
    i=1
    for next_hui  in hui_list:
        i=i+1
        if(i<=91):
            continue
        hui_url=r_url+next_hui
        name1="第"+str(i)+"回"
        response=requests.get(url=hui_url,headers=header)
        data=etree.HTML(response.text)
        tp=data.xpath('//*[@id="page-selector"]/option/@value')
        ye_list=tp
        j=1
        file='C:/Users/kiass/Desktop/'+keyword+'/{}/'.format(name1)
        if not os.path.exists(file):
            os.mkdir(file)
            print('创建文件夹：', file)
        toto=len(ye_list)/2
        for next_ye in ye_list:
            if(j>toto):
                break
            ye_url=r_url+next_ye
            fiel_name="第"+str(j)+"页"
            print(fiel_name)
            j=j+1
            print(ye_url)
            
            response=requests.get(url=ye_url,headers=header)
            data=etree.HTML(response.text)
            tp=data.xpath('//*[@id="all"]/div[1]/div[2]/img/@src')
            download_url=r_url+tp[0]
            print(download_url)
            response=requests.get(url=download_url)
    
            print(file+fiel_name+".jpg")
            with open(file+fiel_name+".jpg","wb") as f:
                f.write(response.content)
            
            


    
    
    
#下一话
if __name__ == '__main__':
    solve()