'''
钟志锴
'''
import urllib.request
import urllib.parse
import json
from lxml import etree
import sys
headers={
    "User-Agent":" Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Mobile Safari/537.36 ",
}
url="https://www.bilibili.com/read/cv257120"
url_data=etree.HTML(urllib.request.urlopen(url).read().decode("utf-8"))
source=url_data.xpath('/html/body/div[2]/div[5]/p/text()')
for eve_source in source:
    print(eve_source)
