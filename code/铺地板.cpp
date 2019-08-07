#include<stdio.h>
int main()
{
    int n,i,a=1,b=1;
    scanf("%d",&n);
    if(n==2)
    {
        printf("2\n");return 0;
    }
    else if(n==1)
    {
        printf("1\n");return 0;
    }
    for(i=2;i<=n;i++)
    {
        if(i%2==0)
        a=a+b;
        else
            b=a+b;
}
  if(n%2==0)
  {
        printf("%d",b);
  }
        else
            {
        printf("%d",a);
  }
    return 0;
}
