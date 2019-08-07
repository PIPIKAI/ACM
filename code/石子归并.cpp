#include<stdio.h>
#include<string.h>
int dp[100][100];
int f[100],sum[100]={0};
int min(int x,int y)
{
    return x<y?x:y;
}
int main()
{
    int n;
    scanf("%d",&n);
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i]);
        sum[i]=sum[i-1]+f[i];
        dp[i][i]=0;
    }
    int i,j,k;
    for(i=n-1;i>=1;i--)
    {
        for(j=i+1;j<=n;j++)
        {
            for(k=i;k<=j-1;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+ sum[j]- sum[i-1]);
            }
        }
    }
    printf("%d",dp[1][n]);

    return 0;
}
