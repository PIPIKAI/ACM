#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int f[5001];
int dp[225033];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n;
    while(~scanf("%d",&n),n>0)
    {
        memset(dp,0,sizeof dp);
        memset(f,0,sizeof f);
        int sum=0,cnt=0,a=0;
        for(int i=0;i<n;i++)
        {
            int v,m;
            scanf("%d%d",&v,&m);
            sum+=v*m;
            for(int j=0;j<m;j++)
                f[cnt++]=v;
        }
        for(int i=0;i<cnt;i++)
        {
           for(int j=sum/2;j>=f[i];j--)
            {
                dp[j]=max(dp[j-f[i]]+f[i],dp[j]),a=max(a,dp[j]);
            }
        }
        printf("%d %d\n",sum-a,a);
    }
    return 0;
}
