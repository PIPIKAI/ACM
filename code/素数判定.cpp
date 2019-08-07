#include<stdio.h>
#include<math.h>
int isapper(int n)
{
    int i;
    if(n==0||n==1)
    {
        return 0;
    }
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
            return 0;
    }

    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(1==isapper(n))
        printf("\\t");
    else
        printf("\\n");

    return 0;
}
