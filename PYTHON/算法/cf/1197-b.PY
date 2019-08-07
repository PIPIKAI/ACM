import sys
cin=lambda:map(int,sys.stdin.readline().split())
n=int(input())
f=[*cin()]
for i in range(1,n-1):
    if(f[i-1] >f[i] and f[i] < f[i+1]):
        print("NO");
        exit(0);
print("YES")
