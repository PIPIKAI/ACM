import requests
import random
import lxml

def solve():
    username="14173903380"
    password=""
    header={
        "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3",
        "Accept-Encoding": "gzip, deflate",
        "Accept-Language": "zh-CN,zh;q=0.9",
        "Host": "bkjw.hnist.cn",
        "Connection": "keep-alive",
        "User-Agent": "Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Mobile Safari/537.36",
        "Referer": "http://bkjw.hnist.cn/login",
        "Cookie": "JSESSIONID=abcev2Tt7NpO_b01b8eWw; selectionBar=1183421",
    }
    http_session = requests.session()
    #####初始化
    tar_url="http://bkjw.hnist.cn/"
    img_url="http://bkjw.hnist.cn/img/captcha.jpg"
    '''
    #第一次请求
    response =http_session.get(tar_url,headers=header)
    #获取验证码
    response = http_session.get(img_url,headers=header, stream=True)
    pic = response.content
    with open('1.png', 'wb') as f:
        f.write(pic)
    captcha=input("请输入验证码  :")

    data={
        "j_username": username,
        "j_password": password,
        "j_captcha": captcha,
    }
    print(username)
    print(password)
    #response =http_session.get(tar_url,headers=header)
    '''
    response = http_session.post(tar_url,headers=header)
    print(response.url)
    print(response.text)


if __name__ == "__main__":
    solve()
    
