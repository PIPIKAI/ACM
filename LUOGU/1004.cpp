#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[11][11];
int dp[11][11][11][11]={0};
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n;int x,y,w;
	cin>>n;
	while(cin>>x>>y>>w,x!=0&&y!=0&&w!=0)
    {
        f[x][y]=w;
    }
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=1;k<=n;k++)
                {
                    for(int l=1;l<=n;l++)
                    {
                        dp[i][j][k][l]=max(max(dp[i-1][j][k-1][l], dp[i][j-1][k-1][l]),max(dp[i-1][j][k][l-1], dp[i][j-1][k][l-1] ))+f[i][j]+f[k][l];
                        if(i==k&&j==l)
                        dp[i][j][k][l]-=f[i][j];
                    }
                }

            }
        }
        cout<<dp[n][n][n][n]<<endl;
   return 0;
}
