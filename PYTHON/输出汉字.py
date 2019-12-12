f=open("num.txt",'r')
n_list=f.readlines()
for i in range(len(n_list)):
	n_list[i]=int(n_list[i])
n_list.sort()
f.close()
f=open("num_sorted.txt",'w')
for _ in n_list:
	f.write(_)