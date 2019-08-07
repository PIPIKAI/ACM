#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
struct node
{
    int t,m;
}f[102];
int dp[1000][1000];
int intread() {int x;scanf("%d",&x);return x;}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,k,t,ans=0;
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++) cin>>f[i].t>>f[i].m;

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=f[i].m;j--)
        {
            for(int k=t;k>=f[i].t;k--)
            dp[j][k]=max(dp[j][k],dp[j-f[i].m][k-f[i].t]+1),ans=max(dp[j][k],ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}
