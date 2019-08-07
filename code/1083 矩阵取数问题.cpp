#include<iostream>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int dp[550][550];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>dp[i][j];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=max(dp[i][j]+dp[i-1][j],dp[i][j]+dp[i][j-1]);
        }
    }
    cout<<dp[n][n];

    return 0;
}
