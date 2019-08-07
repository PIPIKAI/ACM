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
ll n,m;
ll mod=1e9+7;
ll qow(ll x,ll n)
{
    ll s=1,k;
    while(n)
    {
        if(n%2==1)
            s=(s*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return s;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
       ll ans;
        ans=(n*qow(2,n-1))%mod;
        cout<<ans<<endl;
    }

    return 0;
}
