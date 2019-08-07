#include<stdio.h>

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        long long  dp[21][100]={0};

        int i,j,x,cou;
        for(i=1;i<=9;i++)
        {
            dp[1][i]=1;
        }


        for(i=2;i<=n;i++)
        {
            for(j=1;j<=k;j++)
            {
                for(x=j,cou=9;cou>=0&&x>=1;x--,cou--)
                {
                    dp[i][j]+=dp[i-1][x];
                }
            }
        }

        printf("%lld\n",dp[n][k]);
    }
}
