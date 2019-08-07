#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
ll n,m,ans=0;
ll f[500050]={-1},w[500050];
int main()
{
    std::ios::sync_with_stdio(false);
    n=read();
    ans=0;
    int top=0;
    ffr(i,1,n+2)
    {
        ll t;
        t= (i==n+1 ? 0 :read());
        if(t>f[top])
            f[++top]=t,w[top]=1;
        else
        {
            ll cnt=0;
            while(t<=f[top])
            {
                ans=max(ans,(w[top]+cnt)*f[top]);
                cnt+=w[top--];
            }
            f[++top]=t;
            w[top]=cnt+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
