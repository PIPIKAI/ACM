#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll n,s;
ll phi(ll n)
{
    ll s=n;
     for(ll i=2;i*i<=n;i++)
        if(n%i==0)
        {
            s-=s/i;
            while(n%i==0)
                n/=i;
        }
     if(n>1) s=s/n*(n-1);
     return s;
}
ll quick_mod(ll a,ll b,ll m){
    ll ans=1;
    while(b){
        if(b&1){
            ans=(ans*a%m);
        }
        a=a*a%m;
        b>>=1;
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    s=1;
    cin>>n;
    for(int i=0;i<n;i++)
        s=2*s%mod;
    cout<<quick_mod(2,phi(s)%mod ,mod)<<endl;
    return 0;
}
