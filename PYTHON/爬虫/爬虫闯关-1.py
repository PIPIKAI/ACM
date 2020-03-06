import requests
from lxml import etree
import re
url="http://www.heibanke.com/lesson/crawler_ex00/"
now_url=url
while 1:
	data=requests.get(now_url).text
	id=re.findall(r'\d{5}',data)[1]
	now_url=url+id
	print(now_url)