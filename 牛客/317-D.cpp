#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll  inf =1e9+7;
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
ll n,k,A,B,ans=0;
ll phi(ll n) /// logn µÄ¸´ÔÓ¶È
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
ll qpow(ll x,ll n)
{   ll ans=1;
    while(n)
    {
        if(n&1)
            ans=ans*x%inf;
        x=x*x%inf;
        n>>=1;
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k>>A>>B;
    ans= (A+B)%inf*qpow(k%inf, (phi(n)/2*n%inf) )%inf;
    cout<<ans<<endl;
    return 0;
}
