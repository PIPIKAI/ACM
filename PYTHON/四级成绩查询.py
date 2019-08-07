import requests
import random
import lxml
import re
def solve():
    username="145344861195476"
    name="王小明"
    header={
        'Connection': 'keep - alive',
        'Host': 'cache.neea.edu.cn',
        'Referer': 'http://cet.neea.edu.cn/cet',
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3486.0 Safari/537.36',
    }
    http_session = requests.session()
    http_session.headers=header
    #####初始化
    tar_url='http://cache.neea.edu.cn/Imgs.do?'

    data={
        "c": "CET",
        "ik": username,
        "t": random.random(),            
    }
    #获取
    response = http_session.post(tar_url,params=data)
    img_url = re.compile('"(.*?)"').findall(response.text)[0]
    print(img_url)
    response = http_session.get(img_url, stream=True)
    pic = response.content
    with open('1.png', 'wb') as f:
        f.write(pic)
    captcha=input("请输入验证码  :")
    '''
    print(username)
    print(password)
    #response =http_session.get(tar_url,headers=header)
    '''
    


if __name__ == "__main__":
    solve()
    
