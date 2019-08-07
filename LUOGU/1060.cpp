#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
}f[30];
int dp[30005]={0};
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<m;i++)
        cin>>f[i].v>>f[i].w;
    for(int i=0;i<m;i++)
    {
        for(int j=n;j>=f[i].v;j--)
        {
            dp[j]=max(dp[j],dp[j-f[i].v]+f[i].v*f[i].w);
            ans=max(ans,dp[j]);
        }
    }

    cout<<ans<<endl;
    return 0;
}
