#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int  maxn=1e6+7;
ll n,m,x;
ll f[maxn],dp[maxn],len=1,ans;
ll A(ll x)
{
    ll res=1;
    while(x>=1){
        res*=x;
            x--;
    }
    return res;
}
ll C(ll x,ll y)
{
    return A(x)/(A(x-y)*A(y));
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    dp[0]=f[0];
    for(int i=1;i<n;i++){
        if(dp[len-1]<f[i]){
            dp[len++]=f[i];
        }
        else if(dp[len-1]>f[i]){
            int j=lower_bound(dp,dp+len,f[i])-dp;
            dp[j]=f[i];
        }
    }
    ans=(1+x)*x/2 -C(x,min(abs(len-x),len));
    cout<<ans<<endl;
    return 0;
}
