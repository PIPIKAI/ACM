#include<bits/stdc++.h>
using namespace std;
int n,dp[50][50],root[50][50],f[50];
void ftree(int l,int r)
{
    if(l>r) return ;
    if(l==r)
    {
        cout<<l<<" ";return ;
    }
       cout<<root[l][r]<<" ";
       ftree(l,root[l][r]-1);
       ftree(root[l][r]+1,r);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>f[i];
    for(int i=1;i<=n;i++)
        dp[i][i]=f[i],dp[i][i-1]=1;
    for(int i=n;i>=1;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                if(dp[i][j]<dp[i][k-1]*dp[k+1][j]+dp[k][k])
                {
                    dp[i][j]=dp[i][k-1]*dp[k+1][j]+dp[k][k];
                    root[i][j]=k;
                }

            }
        }
    }
    cout<<dp[1][n]<<endl;
    ftree(1,n);
    return 0;
}
