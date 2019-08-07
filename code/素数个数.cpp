#include<stdio.h>
#include<math.h>
int isaples(int n)
{
    int k;
    for(k=2;k<=sqrt(n);k++)
    {
        if(n%k==0)
        {
           return 0;
        }

    }
    return 1;
}
int main()
{
   int l,r,sum=0;
   scanf("%d%d",&l,&r);
   if(l<2)
   l=2;
   while(l<=r)
   {
       if(isaples(l))
        sum++;
    l++;
   }
    printf("%d",sum);
    return 0;
}
