#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
int prim[100050]={0},mu[100050]={0},sum[100050]={0};
bool vis[100000]={0};
void ini(int N)
{
    int cnt=0;
    mu[1]=1;
    for(int i=2;i<=N;i++)
    {
        if(!vis[i]){mu[i]=-1;prim[++cnt]=i;}
        for(int j=1;j<=cnt&&i*prim[j]<=N;j++)
        {
            vis[i*prim[j]]=1;
            if(i%prim[j]==0)break;
            else mu[i*prim[j]]=-mu[i];
        }
    }
    for(int i=1;i<=N;i++)sum[i]=sum[i-1]+mu[i];
}
ll cal(ll a,ll b,ll k)
{
    a/=k,b/=k;
    ll ti=min(a,b),ans=0;
    for(ll i=1,j;i<=ti;i=j+1)
    {
        j=min(a/(a/i),b/(b/i));
        ans+=(a/i) * (b/i) * (sum[j]-sum[i-1]);
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    ini(60005);
    scanf("%d",&T);
    while(T--)
    {
        ll a,b,c,d,k;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);
        cout<<cal(b,d,k)-cal(a-1,d,k)-cal(c-1,b,k)+cal(a-1,c-1,k)<<endl;
    }
    return 0;
}
