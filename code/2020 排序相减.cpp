#include<stdio.h>
int ans[10001],cont=1;
int n;
int  fengli(int a)
{
    int i=0,j,b;
    int f[5];
    while(a>0)
    {
        f[i++]=a%10;
        a/=10;
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3-i;j++)
        {
            if(f[j]>f[j+1])
            {
                int t=f[j];f[j]=f[j+1];f[j+1]=t;
            }
        }
    }
    a=1000*f[0]+100*f[1]+10*f[2]+f[3];
    for(i=0;i<3;i++)
    {
        for(j=0;j<3-i;j++)
        {
            if(f[j]<f[j+1])
            {
                int t=f[j];f[j]=f[j+1];f[j+1]=t;
            }
        }
    }
    b=1000*f[0]+100*f[1]+10*f[2]+f[3];
    return a-b>0?a-b:b-a;
}
void paixuxiangjian(int a,int b)
{

    for(int i=0;i<b;i++)
    {
        a=fengli(a);

    }
    ans[cont++]=a;
}
int main()
{
    scanf("%d",&n);
    int co=n,a,b;
    for(int i=1;i<=n;i++)
    {
         scanf("%d%d",&a,&b);
         paixuxiangjian(a,b);
    }

    for(int i=1;i<=co;i++)
        printf("%d\n",ans[i]);
    return 0;
}
