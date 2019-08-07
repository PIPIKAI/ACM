#include<stdio.h>
void swap(int *q,int *p)
{
    int t;
    t=*q;*q=*p;*p=t;
    return ;
}
int main()
{
    int n,sum=0,max=0;
    int i,j,k;
    scanf("%d",&n);
    int dp[n+1];
    int f[1002][2];
    for(k=0;k<n;k++)
    {
        dp[k]=1;
        scanf("%d%d",&f[k][0],&f[k][1]);
        if(f[k][0]>f[k][1])
        swap(&f[k][1],&f[k][0]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(f[j][1]>f[j+1][1])
            {
                swap(&f[j][1],&f[j+1][1]);
                swap(&f[j][0],&f[j+1][0]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(f[i][0]>=f[j][1])
        dp[i] = dp[i]>(dp[j]+1)?dp[i]:(dp[j]+1);

            if(dp[i]>max)
            max=dp[i];
        }


    }
    printf("%d",max);
    return 0;
}
