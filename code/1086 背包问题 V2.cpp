#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[50005];
struct node
{
    int w,v,s;
};
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	node f[102];
	int n,m,ans=0;
	while(cin>>n>>m)
    {
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++) cin>>f[i].v>>f[i].w>>f[i].s;
        for(int i=0;i<n;i++)
        {
            int temp=f[i].s;
            for(int k=1;k<=temp;k<<=1)
            {
                 for(int j=m;j>=f[i].v*k;j--)
                    dp[j]=max(dp[j],dp[j-k*f[i].v]+f[i].w*k),ans=max(ans,dp[j]);
                temp-=k;
            }
            if(temp)
                for(int j=m;j>=f[i].v*temp;j--)
                    dp[j]=max(dp[j],dp[j-temp*f[i].v]+f[i].w*temp),ans=max(ans,dp[j]);;
        }
        cout<<ans<<endl;
    }
   return 0;
}

