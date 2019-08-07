#include<stdio.h>

int  max_(int p,int q)
{
    return p>q?p:q;
}

int main()
{
     int n,v;
     scanf("%d%d",&n,&v);
     int f[10000]={0};
     int c[10000],w[10000];
     int i,j,sum=0;
     for(i=1;i<=n;i++)
        scanf("%d%d",&w[i],&c[i]);

     for(i=1;i<=n;i++)

     {
         for(j=v;j>=c[i];j--)
         {
             f[j]=max_(f[j],f[j-c[i]]+w[i]);
			 sum=max_(f[j],sum);
         }

     }
     printf("%d\n",sum);
    return 0;
}
