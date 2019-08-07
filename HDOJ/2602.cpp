#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[1005];
struct node
{
    int w;
    int  v;
};
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int T_T;
	cin>>T_T;
	while(T_T--)
    {
        int n,v,ans=0;
       memset(dp,0,sizeof(dp));
       node f[1010];
       cin>>n>>v;
       for(int i=0;i<n;i++)
       {
           cin>>f[i].w;
       }
       for(int i=0;i<n;i++)
        cin>>f[i].v;
       for(int i=0;i<n;i++)
       {
           for(int j=v;j>=f[i].v;j--)
           {
               dp[j]=max(dp[j],dp[j-f[i].v]+f[i].w);
               ans=max(ans,dp[j]);
           }
       }
       cout<<ans<<endl;
    }
   return 0;
}
