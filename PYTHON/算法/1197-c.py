import sys
cin=lambda:map(int,sys.stdin.readline().split())
n,k=cin()
a=list(cin())
print(sum(sorted(y-x for x,y in zip(a,a[1:])) [:n-k] ) )