#include<stdio.h>
int is3_5about(int n)
{
    int f;
    if(n%3==0||n%5==0)
    {
        return 0;
    }
    if(n<10)
        return 1;

    while(1)
    {

        if(n%10==3||n%10==5)
            return 0;
            if(n<10)
            {
                if(n==3||n==5)
                    {
                        return 0;
                    }

                    else
                    {
                        break;
                    }
            }

        n/=10;
    }
    return 1;
}
int main()
{
    int n,sum=0,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(is3_5about(i))
        {
            sum+=i*i;
        }
    }

    printf("%d",sum);
    return 0;
}
