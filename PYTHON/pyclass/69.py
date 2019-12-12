
import urllib.request
import urllib.parse
import json
from lxml import etree
import sys
url="www.69p33.xyz"
respons=urllib.request.urlopen(url).read().decode("gb2312")
page_source=etree.HTML(respons)
# page_total=page_source.xpath('/html/body/div/div/div[3]/div/span/strong[1]/text()')[0]
print respons

