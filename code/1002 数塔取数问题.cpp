#include<iostream>
using namespace std;
int dp[501][501];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
        cin>>dp[i][j];
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<i;j++)
        {
            dp[i-1][j]=max(dp[i][j+1]+dp[i-1][j],dp[i][j]+dp[i-1][j]);
        }
    }
    cout<<dp[1][1];
    return 0;
}
