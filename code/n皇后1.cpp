#include<stdio.h>
int f[14],sum=0,n;
int abs_(int a)
{
    return a>0?a:-a;
}
void dfs(int step)
{
    int i,j;
    if(step>=n)
    {
        sum++;
    }
    else
    for(i=0;i<n;i++)
    {
        f[step]=i;
        for(j=0;j<step;j++)
        {
           if(abs_(f[j]-i)==abs_(step-j)||i==f[j])
           break;
        }
        if(j==step)
            dfs(step+1);
    }
}
int main()
{
    scanf("%d",&n);
    dfs(0);
    printf("%d",sum);
    return 0;
}
