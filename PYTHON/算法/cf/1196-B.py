import sys
cin=lambda:map(int,sys.stdin.readline().split())#要有这句话输入才够快
for _ in range(int(input())):
    n,k=cin()
    a=list(cin())
    ans=[i+1 for i in range(n) if a[i]%2==1]
    l=len(ans)
    if l>=k and k%2==l%2:
        print("YES")
        print(*ans[:k-1],n)
    else :
        print("NO")
