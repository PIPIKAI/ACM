#include<stdio.h>
void isok(int n,int m,int g)
{
    int k=n*2+m*2-4;
    if(g>n||g>m)
    {
        printf("NO\n");
        return ;
    }
    if(k%g==0&&(k/g)<106)
        printf("YES\n");
        else
            printf("NO\n");
    return ;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int x,i;
    scanf("%d",&x);
    int f[x];
    for(i=0;i<x;i++)
    {
        scanf("%d",&f[i]);

    }
    for(i=0;i<x;i++)
isok(n,m,f[i]);
    return 0;
}
