#include<stdio.h>
int main()
{
    int n,i,t,sum=0,flag,ft=0;
    scanf("%d",&n);
    int f[500000]={0};
    for(i=0;i<n;i++)
    {
        scanf("%d",&t);
        f[t]++;
    }
    for(i=0,flag=0;i<500000;)
    {
        if(flag==2)
        {
            f[ft]++;
            sum+=ft;
            ft=0;
            flag=0;
        }
        else if(f[i]!=0)
        {
            f[i]--;
            ft+=i;flag++;
        }
        else
            i++;
    }
    printf("%d",sum);
    return 0;
}

