#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 25 22:57:06 2020
@author: zhongzhikai
"""

import smtplib  
import os
from email.mime.text import MIMEText
from email.utils import formataddr
file= ''.join(open('send_email.txt').readlines())
sender_count='1652091948@qq.com' 
reciver_count='3557147682@qq.com'
def send_mail():
    try:
        msg=MIMEText(file,'plain','utf-8')  
        msg['Subject']="信工17 34号 钟志锴" 
        server=smtplib.SMTP("smtp.qq.com",25)  
        server.login(sender_count,"ekuuddrzupozdigj")    
        server.sendmail(sender_count,[reciver_count,],msg.as_string())
        server.quit()   
    except Exception as e:  
        print(e.args)
send_mail()
