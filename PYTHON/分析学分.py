import requests
import selenium.webdriver
from lxml import etree
import re
import time
import json
header={
	"User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.100 Safari/537.36",
}
get_url="http://mooc1.chaoxing.com/nodedetailcontroller/visitnodedetail?courseId=204415925&knowledgeId=143079422"
# respons=requests.get(url=get_url,headers=header)
# data=etree.HTML(respons.text)
# pt=data.xpath('')
# print(pt)
driver = selenium.webdriver.Chrome()
driver.get(get_url)
time.sleep(4)
driver.switch_to_default_content() 
frame = driver.find_elements_by_tag_name('iframe')[0]  
driver.switch_to_frame(frame) 
tp=driver.find_element_by_xpath('//div[@id="video"]/button')
print(tp)