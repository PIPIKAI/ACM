#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt=0,MAX;
ll dp[20][1020][400];
int c[1010],sum[2002];
int getsum(int x)
{
    int t=0;
    while(x)
    {
        t+=(x&1),x>>=1;
    }
    return sum[cnt]=t;
}
int main()
{
    ll ans=0;
    cin>>n>>m;
    MAX=(1<<n);
    for(int i=0;i<MAX;i++)
        if(!(i&(i<<1)))
            c[++cnt]=i,dp[1][cnt][getsum(i)]=1;
    for(int i=2;i<=n;i++)
    {
       for(int j=1;j<=cnt;j++)
       {
           for(int k=1;k<=cnt;k++)
           {
               int x=c[j],y=c[k];
               if( (x&y) || (x&(y<<1)) || ( (x<<1)&y) )
                continue;

                for(int l=0;l<=m;l++)
               dp[i][j][sum[j]+l]+=dp[i-1][k][l];
           }
       }
    }
    for(int i=1;i<=cnt;i++)
    {
        ans+=dp[n][i][m];
    }
    cout<<ans<<endl;
    return 0;
}
