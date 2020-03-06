import numpy as np
import math
def change_bin(a):
	res=[]
	k=math.floor(math.sqrt(max(a)))+1
	for x in  a:
		tp=list(map(int , list(bin(x).replace('0b',''))))
		res.append([0 for i in range(k-len(tp))]+tp)
	return np.array(res)
		
a=[12,2,3,5,15]
print(change_bin(a))
