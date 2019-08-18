if __name__=='__main__':
	a=[0]*700
	a[1]=6
	a[2]=7
	s=[0]*100
	s[1]='COFFEE'
	s[2]='CHICKEN'
	for i in range(3,600):
		a[i]=a[i-1]+a[i-2]
	for i in range(3,10):
		s[i]=s[i-2]+s[i-1]
		# print(s[i])
	# print(s)
	try:
		while True:
			T=int(input())
			for _ in range(T):
				n,k=map(int,input().split())
				kk=k
				nn=n
				if n>61:
					n=60+n%2
				while n>=5:
					if k>a[n-2]:
						k-=a[n-2]
						n-=1
					else:
						n-=2
				# print(s[n])
				if kk+9>a[nn]:
					print(s[n][k-1:k+9])
				else:
					print(s[n+2][k-1:k+9])
	except EOFError:
		pass
