#include <cstdio>
#include <cstring>
#include <algorithm>
#include<bits/stdc++.h>
#define N 210
#define inf 1e8+7
using namespace std;
int dp[N][N],sum[N];
int main()
{
    int n;
    int a[N];
    cin>>n;
        a[0]=0;
        for(int i=1;i<=n;i++)
            cin>>a[i],a[i]+=a[i-1];
        memset(dp,0,sizeof(dp));
        int i,j,k;
		for(i=n-1;i>=1;i--)
        {
            for(j=i+1;j<=n;j++)
            {
                dp[i][j]=inf;
                for(k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][k]+dp[k+1][j]+a[j]-a[i-1],dp[i][j]);
                }
            }
        }
            cout<<dp[1][n]<<endl;

    return 0;
}
