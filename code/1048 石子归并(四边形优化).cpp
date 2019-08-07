#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 210
int dp[N][N],sum[N],s[N][N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a[N];sum[0]=0;
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            s[i][i]=i;
            sum[i]=sum[i-1]+a[i];
        }
        memset(dp,0,sizeof(dp));
        int i,j,l,k;
        for(l = 2; l <= n; ++l)
        {
            for(i = 1; i <= n - l + 1; ++i)
            {
                j = i + l - 1;
                dp[i][j] = 2100000000;
                for(k = s[i][j-1]; k <= s[i+1][j]; ++k)
                {
                    if(dp[i][j]>dp[i][k] + dp[k + 1][j] + sum[j] - sum[i-1])
                    {
                        dp[i][j]=dp[i][k] + dp[k + 1][j] + sum[j] - sum[i-1];
                        s[i][j]=k;
                    }
                }
            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                printf("%d ", dp[1][n]);
            printf("\n");
        }

    }
    return 0;
}
