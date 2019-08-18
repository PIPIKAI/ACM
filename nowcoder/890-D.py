
import sys
cin=lambda:map(int,sys.stdin.readline().split())
def exgcd(a,b):
    if b==0:
        return (1,0,a)
    (x,y,r)=exgcd(b,a%b)
    temp=x
    x=y
    y = temp - int(a / b) * y
    return (x,y,r)
if __name__ == "__main__":
    M=1
    ans=0
    flag=1
    n,mm=cin()
    for i in range(n):
        a,b=cin()
        M=M*p[i]

    if flag==0:
        print("he was definitely lying")
    elif ans>mm :
        print("he was probably lying")
    else:
        print(int(ans))