#include<stdio.h>
#include<string.h>
int b[1000002][2];
int dp[1000][1000];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        memset(b,0,sizeof(b));
        memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++)
        scanf("%d%d",&b[i][0],&b[i][1]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            dp[i][j]=max()
        }
    }

    }
    return 0;
}
