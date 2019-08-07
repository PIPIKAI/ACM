#include<stdio.h>
typedef long long  ll;

int main()
{
    int k;
    while(~scanf("%d",&k))
    {
        if(k==0)
        {
            printf("0\n");
            continue;
        }
        int i,j;
        int f[50000]={0};
        f[0]=1;
        for(i=2;i<=k;i++)
        {
           int temp=0;
           for(j=0;j<50000;j++)
           {
               int s=f[j]*i+temp;
               f[j]=s%10;
               temp=s/10;
           }
        }
        for(i=50001-1;i>=0;i--)
        {
            if(f[i]!=0)
                break;
        }
        for(;i>=0;i--)
            printf("%d",f[i]);
        printf("\n");
    }

    return 0;
}

