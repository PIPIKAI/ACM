import requests
from lxml import etree
import json
def solve():
    username="14173903380"
    password="079011"
    captcha=""
    tar_url="http://uia.hnist.cn/sso/login?service=http%3A%2F%2Fuia.hnist.cn%2Fj_spring_cas_security_check"
    img_url="http://bkjw.hnist.cn/img/captcha.jpg"
    http_session = requests.session()
    header={
        "User-Agent": "Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Mobile Safari/537.36",
    }
    img_response = http_session.get(img_url, stream=True)
    response =http_session.get(tar_url,headers=header)
    pic = img_response.content
    with open('1.png', 'wb') as f:
        f.write(pic)
    #captcha=input("请输入验证码  :")
    lt_data=etree.HTML(response.text)
    lt=lt_data.xpath('//*[@id="credentials"]/div[5]/input[1]/@value')
    data={
        "username": "14173903380",
        "password": "MDc5MDEx",
        "lt": lt,
        "_eventId": "submit",
    }
    response = http_session.post(tar_url,data=data)
    #进入
    r1_cookie=response.cookies.get_dict()
    header2={
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3",
        "Accept-Encoding": "gzip, deflate",
        "Accept-Language": "zh-CN,zh;q=0.9",
        "Cache-Control": "max-age=0",
        "Connection": "keep-alive",
        "Host": "bkjw.hnist.cn",
        "Referer": "http://bkjw.hnist.cn/casLogin",
        "Upgrade-Insecure-Requests": "1",
        "User-Agent": "Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Mobile Safari/537.36",
    }
    next_url="http://bkjw.hnist.cn/"
    data2={
        "result":"yes"
    }
    r2 = http_session.post(next_url,data=data2)

    print(r2.history) #[]
    print(r2.text) #
    print(r2.url) #


if __name__ == "__main__":
    solve()
    
