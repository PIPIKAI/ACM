#include<stdio.h>
int main()
{
    int f[10],hand=0;
    int sum=0,b;
    int i;
    for(i=0;i<10;i++ )
        scanf("%d",&f[i]);
        scanf("%d",&hand);
        hand+=30;
    for(i=9;i>=0;i--)
    {

        if(f[i]<=hand)
        {
            sum++;
        }
    }

    printf("%d",sum);

        return 0;
}

