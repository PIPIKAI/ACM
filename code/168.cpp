#include<stdio.h>
int tss(int a,int b)
{
    int t,i=a,sum;
    for(;i<=b;i++)
    {
        sum=0;
        t=i;
        while(t>0)
        {
            sum+=t%10;
            t/=10;
        }
        if(sum==5)
        printf("%d\n",i);
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    tss(a,b);
    return 0;
}
