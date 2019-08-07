#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int dp[55][55][55][55];
int f[55][55];
int read() {int x;scanf("%d",&x);return x;}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        f[i][j]=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=m;l++)
                {
                    dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l],dp[i][j-1][k-1][l]),max(dp[i-1][j][k][l-1],dp[i][j-1][k][l-1]))+f[i][j]+f[k][l];
                    if(i==k&&j==l)
                     dp[i][j][k][l]-=f[i][j];
                }
        pt("%d\n",dp[n][m][n][m]);
    return 0;
}
