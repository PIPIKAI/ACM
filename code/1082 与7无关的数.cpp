#include<iostream>
#include<stdio.h>
#include<algorithm>
long long via[1000005]={0};
void is_about(int t,int b)
{
    for(long long j=1;j<=1000000;j++)
    {
        if(j<10)
        {
            if(j!=b)
                via[j]=j*j;
        }
        else
            if(j%b!=0)
            {
                int temp=j;
                while(temp%10!=b&&temp!=0) temp/=10;
                if(temp==0)
                    via[j]=j*j;
            }
    }
}
int main()
{
    int n,temp;
    scanf("%d",&n);
    is_about(temp,7);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        long long sum=0;
        for(int i=1;i<=temp;i++)
            sum+=via[i];
        printf("%lld\n",sum);
    }
    return 0;
}
