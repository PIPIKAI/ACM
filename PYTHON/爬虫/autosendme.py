# -*- coding: utf-8 -*-
from twilio.rest import Client
import time,datetime
from openpyxl import load_workbook
import warnings
warnings.filterwarnings('ignore')
def in_this_time(nowtime):
	begin_time=nowtime[:5]
	end_time=nowtime[6:]
	return (localtime >= begin_time and localtime <= end_time)
def get_data():	
	localtime = time.asctime( time.localtime(time.time()) )[11:19]
	hang=3
	# return localtime
	for i in range(0,17):
		if(in_this_time(compare_time[i])==True):
			res=data[merges_dict[lie+str(hang)]].value
			if(len(res)!=0):
				return str(" 该"+data[merges_dict[lie+str(hang)]].value+"了！")
			break
		hang+=1
		pass
	file.close()

	return "1"
def sendthat(tos,from_,date):
	# Your Account SID from twilio.com/console
	account_sid = "ACc7334327f1ef0d4744abf7ce5608d707"
	# Your Auth Token from twilio.com/console
	auth_token  = "536a575df963dd20a018a02ee9dab2cc"
	client = Client(account_sid, auth_token)
	message = client.messages.create(
		# 这里中国的号码前面需要加86
		to=tos,
		from_=from_,
		body=date,
	)
	print(message.sid)
def run():	
	DWK="+8618163886630"
	tos="+8615674006152"
	from_="+12082161093",
	date=message
	cishu=0
	attempts = 0
	success = False
	while attempts < 3 and not success:
	    try:
	        sendthat(tos,from_,date)
	        success = True
	    except:
	        attempts += 1
	        if attempts == 3:
	            break
tp="1"
localtime = time.asctime( time.localtime(time.time()) )[11:16]
print(localtime)
merges_dict=dict()
path='/Users/zhongzhikai/Documents/MyFile/日程表.xlsx'
file=load_workbook(path,False)
week_day_dict = {0 : 'D', 1 : 'E', 2 : 'F', 3 : 'G', 4 : 'H', 5 : 'I', 6 : 'J', }
data=file['Sheet1']
# compare_time
compare_time=[data['C'+str(i)].value for i in range(3,20) ]
# weekday
lie=week_day_dict[datetime.datetime.now().weekday()]
merges=data.merged_cell_ranges

for rdata in merges:
	rdata=str(rdata)
	i=int(str(rdata).find(':'))
	a=str(rdata[:i])
	b=str(rdata[i+1:])
	for i in range(ord(a[0]),ord(b[0])+1): # ascii 码
		for j in range(int(a[1:]),int(b[1:])+1):
			add={str(chr(i)+str(j)):a}
			merges_dict.update(add)
while True:
	message=get_data()
	if(message != tp and message!="1"):
		print("发送短信",message)
		run()
		tp=message
	else:
		time.sleep(1)
		