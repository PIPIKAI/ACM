#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
ll n,m;
ll ans[35]={1};
ll qpow(ll a,ll b)
{
    int ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a);
        a=(a*a);
        b>>=1;
    }
    return ans;
}

void ini()
{
    for(int i=1;i<=33;i++){
        ans[i]=ans[i-1]*2+qpow(2,i-1);
    }
}
int main()
{
    int T;
    ini();
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&m);
        printf("%lld\n",ans[m-1]);

    }
    return 0;
}
