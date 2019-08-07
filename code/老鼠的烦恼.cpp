#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll mod=1000000000;
ll dp[520][520];
int main()
{
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        dp[x][y]=-1;
    }
    dp[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dp[i][j]==-1)
                continue;
            if(dp[i-1][j]==-1&&dp[i][j-1]!=-1)
            {
                    dp[i][j]+=(dp[i][j-1]);
            }
            if(dp[i-1][j]!=-1&&dp[i][j-1]==-1)
            {
                    dp[i][j]+=(dp[i-1][j]);
            }
           if(dp[i-1][j]!=-1&&dp[i][j-1]!=-1)
            {
                     dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<dp[n][m];
    return 0;
}

