from twilio.rest import Client
import threading

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
	
s=[]
for i in range(0,20):
	s.append(threading.Thread(target=run))
	s[i].start()