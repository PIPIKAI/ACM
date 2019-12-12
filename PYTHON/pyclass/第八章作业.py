# 班级：信工17-1bf 作者：钟志锴 序号：34
import os
print "SAMPLE OUTPUT 2\n--------------------------"
begin=int (input("Enter Begin Value: "))
end=int (input("Enter End Value: "))
print "DEC    BIN    OCT    HEX   ASCII\n"
print "----------------------------------"
for i in range(begin,end+1):
	ch=chr(i)
	if i<32 or i>126:
		ch=""
	print "%-5d %-8s %-5o %-5x %-5s"%(i,bin(i)[2:],i,i, ch)
os.system("pause")


