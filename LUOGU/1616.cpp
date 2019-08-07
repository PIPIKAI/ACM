#include<bits/stdc++.h>
using namespace std;
int dp[100005]={0};
struct node
{
    int t,w;
}f[10002];
int main()
{
    int t,m,ans=0;
    cin>>t>>m;
   for(int i=0;i<m;i++)
    cin>>f[i].t>>f[i].w;
    for(int i=0;i<m;i++)
    {
       for(int j=f[i].t;j<=t;j++)
       dp[j]=max(dp[j],dp[j-f[i].t]+f[i].w),ans=max(dp[j],ans);

    }
    cout<<ans<<endl;;
    return 0;
}

