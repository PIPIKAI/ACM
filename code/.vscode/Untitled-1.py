import requests

html = requests.get('http://www.baidu.com').content
print html