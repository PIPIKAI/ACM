
import requests
from lxml import etree

def main():
	get_url="https://www.kuaikanmanhua.com/web/comic/64550/?tdsourcetag=s_pctim_aiomsg"
	respons=requests.get(get_url)
	data=etree.HTML(respons.text)
	url_list=data.xpath('//div[@class="imgList"]/img/@lazy')
	print(url_list)
	for _ in url_list :
		print(_)
if __name__ == '__main__':
	main()