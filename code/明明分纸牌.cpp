#include<stdio.h>
int f[200],n,sum=0;
int main()
{
    int avr=0,i,j;
    scanf("%d",&n);
    for( i=0;i<n;i++)
    {
        scanf("%d",&f[i]);
        avr+=f[i];
    }
    avr/=n;

    for( i=0;i<n-1;i++)
    {
        if(f[i]!=avr)
        {
            f[i+1]=f[i]-avr+f[i+1];
            sum++;
        }

    }
    printf("%d",sum);
    return 0;
}
