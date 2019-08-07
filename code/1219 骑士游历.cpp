#include<stdio.h>
int main()
{
    int x1,x2,y1,y2;
    long long  f[250][250]={0};
    int n,m;
    scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
    int i,j;
    f[x1][y1]=1;

    for(i=x1+1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {

           if(i-1>0)
           {
               if(j-2>0)
               f[i][j]+=f[i-1][j-2];
               if(j+2<=m)
               f[i][j]+=f[i-1][j+2];
           }
            if(i-2>0)
            {
                if(j-1>0)
                f[i][j]+=f[i-2][j-1];
               if(j+1<=m)
               f[i][j]+=f[i-2][j+1];
            }
               }

    }
   /* for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%lld ",f[i][j]);
        printf("\n");
    }*/
    printf("%lld\n",f[x2][y2]);
    return 0;
}
