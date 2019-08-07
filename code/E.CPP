#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int v,w;
}f[5200];
int n,m,ans=0,cnt=0;
int dp[60005];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	memset(dp,0,sizeof dp);
	for(int i=0;i<n;i++)
    {
        int a,b,s;
        cin>>a>>b>>s;
        for(int j=0;j<s;j++)
        {
            f[cnt].v=a;
            f[cnt].w=b;
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        for(int j=m;j>=f[i].v;j--)
        {
            dp[j]=max(dp[j],dp[j-f[i].v]+f[i].w);
            ans=max(dp[j],ans);
        }
    }
    cout<<ans<<endl;
   return 0;
}
