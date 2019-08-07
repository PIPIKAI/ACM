#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[100005];
struct node
{
    int w,s;
};
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	node f[102];
	int n,m;
	while(cin>>n>>m,n!=0&&m!=0)
    {
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++) cin>>f[i].w;
        for(int i=0;i<n;i++) cin>>f[i].s;
        dp[0]=1;
        for(int i=0;i<n;i++)
        {
            int temp=f[i].s;
            for(int k=1;k<=temp;k<<=1)
            {
                 for(int j=m;j>=f[i].w*k;j--)
                    dp[j]+=dp[j-k*f[i].w];
                temp-=k;
            }
            if(temp)
                for(int j=m;j>=temp*f[i].w;j--)
                dp[j]+=dp[j-temp*f[i].w];
        }
        int ans=0;
        for(int i=1;i<=m;i++)
            if(dp[i])
            ans++;
        cout<<ans<<endl;
    }
   return 0;
}
