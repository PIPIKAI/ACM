#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 10007;
ll n,m,a,b,k;
ll f[1001];
ll qpow(ll x,ll n)
{
    ll s=1;
    while(n){
        if(n&1)  s=(s*x)%mod;
        x=(x*x)%mod; n>>=1;
    }
    return s%mod;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>a>>b>>k>>n>>m;
    f[0]=1;
    for(int i=1;i<=k;i++)
        f[i]=(f[i-1]*i)%mod;
    ll p=(f[k]*(qpow(a%mod,n))*(qpow(b%mod,m)))%mod;
    ll aa=(f[n]*f[k-n]);
    ll q=qpow(aa,mod-2);
    cout<<(q*p)%mod<<endl;
    return 0;
}
