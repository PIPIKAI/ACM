'''
时间：2019-7-15
目标网址：https://tieba.baidu.com/
目的：实现贴吧自动签到
作者：钟志锴
'''
import requests
import urllib.request
import urllib.parse
import json
import time
import ssl
import re

url="https://tieba.baidu.com/index.html"
#用ssl关闭验证的方法
ssl._create_default_https_context=ssl._create_unverified_context
#记录cookie header
headers={
    "Cookie":"BAIDUID=99D67641F1E998EAE96AEF4A284D18A1:FG=1; BIDUPSID=99D67641F1E998EAE96AEF4A284D18A1; PSTM=1535705142; TIEBA_USERTYPE=7d05dbf8efb17571173ee454; bdshare_firstime=1535723210401; TIEBAUID=f9630f1ef66c86c570fc056a; __cfduid=d95b463800f4592334258196f281288b51540136785; MCITY=-220%3A; BDORZ=B490B5EBF6F3CD402E515D22BCDA1598; IS_NEW_USER=402bc3095c59727e2a74f445; Hm_lvt_7d6994d7e4201dd18472dd1ef27e6217=1563186740,1563187638; rpln_guide=1; SEENKW=%E6%B9%96%E5%8D%97%E7%90%86%E5%B7%A5%E5%AD%A6%E9%99%A2; CLIENTWIDTH=888; CLIENTHEIGHT=898; BDUSS=lZaTEVYdkxiaS13R1A4cmhMaFNxRlFJVmVWelN3bUdCUUNjT2MwZWZZb2xEbFJkSVFBQUFBJCQAAAAAAAAAAAEAAABsY0YxMjAxM2JyZWFraW5nAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACWBLF0lgSxdd; STOKEN=488f8bf0c5be74b135399fb454ef7d9d0cc582e66bf0ce0059ed233c931b974b; Hm_lvt_98b9d8c2fd6608d564bf2ac2ae642948=1563109630,1563112698,1563186590,1563326086; Hm_lpvt_98b9d8c2fd6608d564bf2ac2ae642948=1563326095; 826696556_FRSVideoUploadTip=1",
    "User-Agent": "Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Mobile Safari/537.36"
}
respons=requests.get(url=url , headers=headers)
#print(respons.text)
if respons.status_code==200:
    json=respons.json()
    print(json)
else :
    print("no")
    '''
url_data=urllib.request.urlopen(urllib.request.Request(url=url",headers=headers)).read().decode("utf-8")
forum_list=re.findall('"forum_id":(.*?),"forum_name":"(.*?)"',url_data)
for eve_forum in forum_list:
   print(eve_forum[1].encode('latin-1').decode("unicode-escape"))
kw="帝国3"
forum_url="http://tieba.baidu.com/f?kw="+urllib.parse.quote(kw) #解决中文编码问题

#找tbs
forum_data=urllib.request.urlopen(urllib.request.Request(url=forum_url,headers= headers)).read().decode("utf-8")
tbs_data=re.findall("'tbs': \"(.*?)\"",forum_data)
#a=forum_data.find('tbs')
print(tbs_data)

#Form data

url="http://tieba.baidu.com/sign/add"
post_data={
    "ie": "utf-8",
    "kw": kw,
    "tbs": tbs,
}
data=urllib.parse.urlencode(post_data).encode("utf-8")
post_req = urllib.request.Request(url=url,data=data,headers=headers)
print(urllib.request.urlopen(post_req).read().decode("utf-8"))
'''
