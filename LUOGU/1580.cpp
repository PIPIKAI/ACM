#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int intread() {int x;scanf("%d",&x);return x;}
int dp[1000][1000]={0},f[1000][1000];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cin>>f[i][j];
    }
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1;j<=m;j++)
            {
                dp[i][j]=f[i][j]+max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
            }
    }
    cout<<dp[n+1][m/2+1]<<endl;
    return 0;
}
