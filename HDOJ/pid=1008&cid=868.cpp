#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
ll n,m;
const int mod=1e9+7;
ll f[1000009];
void ini()
{
    f[1]=1;
    for(int i=2;i<=1000000;i++){
        f[i]=(f[i-1]+ 2*i)%mod;
    }
    for(int i=2;i<=1000000;i++){
        f[i]=(f[i]+f[i-1])%mod;
    }
}
ll qpow(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll inv2(ll a,ll mod)//费马小定理
{
    return qpow(a,mod-2,mod);
}
int main()
{
    std::ios::sync_with_stdio(false);
    ini();
    while(cin>>n){
        ll p=(f[n])%mod;
        ll q=((n*n)%mod*n)%mod;
        cout<<(p* (inv2(q,mod))%mod )%mod<<endl;
    }
    return 0;
}
