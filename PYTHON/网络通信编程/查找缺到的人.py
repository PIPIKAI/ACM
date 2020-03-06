# utf-8
import os
import re

students=['张诗婷', '李紫文', '陶聪', '闫星', '邓林泉', '王悦珂', 
'何俊康', '苗奕杰', '黄戈', '许雁玲', '杨小请', '周杰', '何其豪',
 '冉冰', '贺冰', '周思婷', '黄誉', '刘家熙', '吴文涛', '张雪妍',
  '曾承源', '懃天亮', '景治朝', '张坚', '彭浜', '吴栋梁', '陈乐',
   '周佰全', '王娜', '肖粤斌', '曾云轩', '唐可真', '文龙欢', '钟志锴',
    '王嘉珂', '宾炜华', '王为', '贺龙腾', '雷小东', '高楷修', '熊启臻，',
     '吴炳柱', '刘语寻', '周旦', '肖鑫']
file_name='files'. #文件名
s='网络通信编程上课考勤'
pp='今天'
name_list=os.listdir(file_name)
for name in name_list:
	rq=name[:8]
	if(s in name):
		data=str(open(file_name+'/'+name,'r').readlines())
		if('45人' in data):
			print(rq+" 没人缺勤")
		else:
			ans=[]
			for student in students:
				if(data.find(student)==-1):
					ans.append(student)

			print(rq+" 缺勤的有"+str(ans))

