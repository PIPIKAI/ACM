#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod =1000;
ll qpow(ll x,ll n)
{
    ll s=1;
    while(n){
        if(1&n) s=(s*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return s;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	ll ans,m,n;
	while(cin>>m>>n)
    {
        ll ans=qpow(m,n);
        cout<<ans%10<<endl;
    }
   return 0;
}
