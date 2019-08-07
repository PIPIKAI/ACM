#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fpow(ll a,ll n, ll mod)
{
    ll s=1;
    while(n>0)
    {
        if(n%2)
            s=a*s%mod;
        a=a*a%mod;
        n/=2;
    }
    return s%mod;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	ll a,b,m;
	cin>>a>>b>>m;
	ll ans;
	ans=fpow(a,b,m);
	printf("%lld^%lld mod %lld=%lld\n",a,b,m,ans);
   return 0;
}
