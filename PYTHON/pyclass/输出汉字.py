#coding=utf-8
import os
"""
关于汉字编码体系
a) 国标区位码将汉字分为94区，每区94个汉字或者汉字符号，其中第1至第9区为汉字
符号；第16至55区为一级汉字共3755个，按其汉语拼音字母的顺序排列；第56至87区为二级
汉字共3008个，按其偏旁部首的顺序排列；第10至15区、第88至94区均为空区。
b) 机内码、国标码与区位码的计算
区位码＝区号＋位号［1-94,1-94］
国标码＝区位码＋32［(1-94)+32，(1-94)+32］
机内码＝将国标码的两个字节的第一位置壹。
示例：第26区第17号为“罕”字，则其区位码为2617，国标码为5849，即0011，1010，
0011，0001（5849）；则其机内码为1011，1010，1011，0001（BAB1H）。由此可知，将区
码与位码表示为十六进制后加上A0A0可得机内码；机内码减去A0A0再转换为十进制可得区位
码。
"""
f=open("all_chinese_char.txt",'w')
for i in range(1, 95):
	f.write("第%d区：\n" % i)
	for j in range(1, 95):
		a = i + 0xA0
		b = j + 0xA0
		f.write("%c%c " % (chr(a), chr(b)))
		if j % 10 == 0:
			f.write("\n")
			f.write("\n\n")
f.close()
0100 1000 0100 1011