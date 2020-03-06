# -*- coding: utf-8 -*-
import time,datetime
from openpyxl import load_workbook

def in_this_time(nowtime):
	begin_time=nowtime[:5]
	end_time=nowtime[6:]
	print
	return (localtime >= begin_time and localtime <= end_time)
	
localtime = time.asctime( time.localtime(time.time()) )[11:16]
path='/Users/zhongzhikai/Documents/MyFile/日程表.xlsx'
file=load_workbook(path,False)
week_day_dict = {0 : 'D', 1 : 'E', 2 : 'F', 3 : 'G', 4 : 'H', 5 : 'I', 6 : 'J', }
data=file['Sheet1']
# compare_time
compare_time=[data['C'+str(i)].value for i in range(3,20) ]
# weekday
lie=week_day_dict[datetime.datetime.now().weekday()]
merges=data.merged_cell_ranges
merges_dict=dict()
for rdata in merges:
	rdata=str(rdata)
	i=int(str(rdata).find(':'))
	a=str(rdata[:i])
	b=str(rdata[i+1:])
	for i in range(ord(a[0]),ord(b[0])+1): # ascii 码
		for j in range(int(a[1:]),int(b[1:])+1):
			add={str(chr(i)+str(j)):a}
			merges_dict.update(add)
hang=3

for i in range(0,17):
	if(in_this_time(compare_time[i])==True):
		print(data[lie+str(2)].value,localtime,"该"+data[merges_dict[lie+str(hang)]].value+"了！")
		break
	hang+=1
	pass
file.close()
