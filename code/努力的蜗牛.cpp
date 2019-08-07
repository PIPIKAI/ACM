#include<stdio.h>
int main()
{
    int h,a,b,sum=0,day=1,count;
    scanf("%d%d%d",&h,&a,&b);

    if(a>=h)
    {
        printf("1");
        return 0;
    }
    else if(a<=b)
    {
        printf("-1");
        return 0;
    }
  while(1)
  {
      sum+=a;
      if(sum>=h)
        break;

        sum-=b;
        day++;
  }
printf("%d",day);
    return 0;
}
