import numpy as np
res=[]
for x in range(8):
	res.append([int(i%2==0) for i in range(0+ (x%2==0) ,8+ (x%2==0))])
res=np.array(res)
print(res)