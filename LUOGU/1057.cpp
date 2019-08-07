#include<bits/stdc++.h>
using namespace  std;
int dp[35][35];
int main()
{
    int n,m;
    dp[1][0]=1;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int l=j-1,r=j+1;
            if(l==0)
                l=n;
            if(r>n)
                r=1;
            dp[j][i]=dp[l][i-1]+dp[r][i-1];
        }

    }
    cout<<dp[1][m];
    return 0;
}
