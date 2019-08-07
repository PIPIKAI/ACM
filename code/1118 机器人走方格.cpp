#include<stdio.h>
typedef long long ll;
ll  mod=1e9+7;
ll  dp[100000000];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    int i,j;
    dp[1]=1;
    for(i=1;i<=n;i++)
    {

    }

    printf("%d\n",2*dp[n]);
    return 0;
}
