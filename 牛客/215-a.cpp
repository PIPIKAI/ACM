#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
int n,m;
int f[100050]={0},k[100050];
int main()
{
    std::ios::sync_with_stdio(false);
    n=read();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int t=read();
        k[i]=t;
        f[t]++;
    }
    sort(k,k+n);
    for(int i=0;i<n;i++)
    {
        int t= k[i]*2;
        t=sqrt(t);
        t*=t;
        t=t-k[i];

        if(f[t])
        {
            ans+=f[t];
            ///cout<<f[t]<<endl;
            f[t]-=2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
