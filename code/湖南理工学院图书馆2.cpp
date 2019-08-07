#include<stdio.h>
int dp[1001][101]={0};
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,j,k,sum=0;
	int m,n,v;
	int c[2000],w[2000];
	scanf("%d%d%d",&m,&n,&v);
	for(i=1;i<=n;i++)
        scanf("%d%d",&w[i],&c[i]);

    for(i=1;i<=n;i++)
    {
        for(j=v;j>0;j--)
        {
            for(k=1;k<=m;k++)
            {
                if(j-c[i]>=0)
                    dp[j][k]=max(dp[j][k],dp[j-c[i]][k-1]+w[i]);
            }
        }
        sum=max(dp[v][m],sum);
    }
    printf("%d",sum);
	return 0;

 }
