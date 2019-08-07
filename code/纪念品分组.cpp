#include<stdio.h>
int main()
{
    int i,j,mark[100]={-9},max,n,flag,t,gg=0,p,q ;
    scanf("%d\n%d",&max,&n);
    int f[n];
    for(i=0;i<n;i++)
        scanf("%d",&f[i]);
        for(i=0;i<n-1;i++)
            for(j=0;j<n-1-i;j++)
        {
            if(f[i]>f[i+1])
            {
                t=f[i];f[i]=f[i+1];f[i+1]=t;
            }
        }
    for(i=0;i<=n/2;i++)
    {
        for(j=n-1;j>=n/2;j--)
        {
            for(q=0,flag=0;q<=gg;q++)
            {
               if(mark[q]==j)
                flag=1;
            }
            if(flag!=1)
            {
                if(f[i]+f[j]==max)
                {
                    mark[gg++]=j;

                    i++;
                }
                else if(f[i]+f[j]<max)
                {
                    mark[gg++]=j;

                    i++;
                }
                else if(f[i]+f[j]>max)
                {
                    ;
                }
            }
            else
                {
                    continue;
                }

        }

    }

    printf("%d",n-gg);
}
