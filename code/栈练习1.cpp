#include<stdio.h>
int a,b[100];
int main()
{
    int n,count=0;
    scanf("%d",&n);
    while(n>0)
    {
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d",&b[count]);
            count++;
        }
        else if(a==2)
        {
            count--;
        }
        n--;
    }
    printf("%d\n",b[count-1]);
    return 0;
}
