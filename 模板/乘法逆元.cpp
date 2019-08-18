#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
ll inv[3000010];

ll qpow(ll a,ll b,ll mod)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    ll GCD=exgcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;
    return GCD;
}

ll inv1(ll a,ll mod)//扩展欧几里得求逆元
{
    ll x,y;
    ll d=exgcd(a,mod,x,y);
    if(d==1) return (x%mod+mod)%mod;
    return -1;
}

ll inv2(ll a,ll mod)//费马小定理
{
    return qpow(a,mod-2,mod);
}

void inv3(ll n,ll mod)//线性递推求逆元
{
    mod=n;
    inv[1]=1;
    puts("1");
    for(int i=2;i<=n;i++)
    {
        inv[i]=(i-mod/i)*inv[mod%i]%mod;
        printf("%lld\n",inv[i]);
    }
}

int main()
{
    ll n,mod;
    while(~scanf("%lld%lld",&n,&mod))
    {
        //for(ll i=1;i<=n;i++){
          //  cout<<inv2(i,mod)<<endl;
        //}
        cout<<inv1(n,mod)<<endl;
        //inv3(n,mod);
    }
}
