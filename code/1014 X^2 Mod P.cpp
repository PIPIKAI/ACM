#include<stdio.h>
typedef long long ll;
int a,p;

int main()
{
    int x,flag=1;
    scanf("%d%d",&p,&a);
    for(ll i=1;i<=p;i++)
    {
        ll temp=i*i;
        if(temp%p==a)
        {
            flag=0;
            printf("%d ",i);
        }

    }
    if(flag)
        printf("No Solution");
}
