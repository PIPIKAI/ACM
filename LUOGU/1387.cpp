#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int intread() {int x;scanf("%d",&x);return x;}
int f[101][101],dp[111][110]={0};
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>f[i][j];
            if(f[i][j])
            dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            ans=max(dp[i][j],ans);
        }
        cout<<ans<<endl;
    return 0;
}
