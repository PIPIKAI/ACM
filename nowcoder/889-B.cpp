#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
ll c,b;
ll x,y;
const int mod=1e9+7;
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
    int T,Case=0;
    cin>>T;
    while(T--){
        cin>>b>>c;
        cout<<b*c<<endl;
        ll d=b*b-4*c;
        if(d<0){
            b+=mod;
            c=inv2(c,mod);
            d=b*b-4*c;
            if(d<0)
            cout<<-1<<endl;
            else{
                x=b-sqrt(d);
            x/=2;
            y=b+sqrt(d);
            y/=2;
            cout<<x<<" "<<y<<endl;
            }
        }
        else{
            x=b-sqrt(d);
            x/=2;
            y=b+sqrt(d);
            y/=2;
            cout<<x<<" "<<y<<endl;

        }
    }
    return 0;
}