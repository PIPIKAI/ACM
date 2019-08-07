#include<stdio.h>
int n,f[14][14],via[100][100],tot=0,sum=0,w[14];
int abs_(int a)
{
    return a>0?a:-a;
}
void dfs(int step)
{
    int i,j;
    if(step==n)
    {
        for(i=0;i<n;i++)
            via[tot][i]=w[i];
        tot++;
    }
    else
        for(i=0;i<n;i++)
        if(f[step][i])
        {
            w[step]=i;
            for(j=0;j<step;j++)
                if(w[j]==i||abs_(w[j]-i)==abs_(j-step))
                break;
            if(j==step)
                dfs(step+1);
        }
}
int check_b_and_w(int a[],int b[])
{
    for(int i=0;i<n;i++)
        if(a[i]==b[i])
        return 0;
    return 1;
}
void result(int w)
{
    for(int i=0;i<w;i++)
    {
        for(int j=i+1;j<w;j++)
        {
            if(check_b_and_w(via[i],via[j]))
                sum++;
        }
    }
    printf("%d",2*sum);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&f[i][j]);
    }
    dfs(0);
    result(tot);

    return 0;
}
