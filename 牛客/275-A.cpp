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
ll n;
ll mood=1e9+7;
ll ans,sa=1,sb=1;
ll qkpow(ll a,ll p,ll mod)
{
    ll t=1,tt=a%mod;
    while(p)
    {
        if(p&1)t=t*tt%mod;
        tt=tt*tt%mod;
        p>>=1;
    }
    return t;
}
ll getInv(ll a,ll mod)
{
    return qkpow(a,mod-2,mod);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        a=(b-a);
        sa= (sa*a+mood)%mood;
        sb= (sb*b+mood)%mood;
    }
    sb=(sb+mood)%mood;
    sa=(sb-sa+mood)%mood;
    cout<<(sa*(getInv(sb,mood)))%mood<<endl;
    return 0;
}
