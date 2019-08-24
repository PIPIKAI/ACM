#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int maxn=1e6+7;
ll qpow(ll x,ll y,ll mod){
    ll rst=1;
    for(;y;y>>=1){
        if(y&1) rst=(rst*x)%mod;
        x=(x*x)%mod;
    }
    return rst;
}
ll inv[maxn];
int main()
{
    int n;
    inv[0]=inv[1]=1;
    for(int i=2;i<maxn;i++)
        inv[i]= (inv[i-1]+qpow(i,mod-2,mod))%mod;
    while(~scanf("%d",&n)){
        ll ans=0;
        ll mu=qpow(n*n,mod-2,mod);
        for(int i=1;i<=n;i++){
            ans= (ans+  (mu*(inv[n]-inv[i]+mod)%mod)%mod *i )%mod;
        }
        ans= (ans+ (3+n)*qpow(4*n,mod-2,mod))%mod;
        printf("%lld\n",ans);
    }
    return 0;
}