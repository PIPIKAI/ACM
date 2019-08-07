#include<stdio.h>
#include<math.h>
int f[100];
int isapa(int a)
{
    int i;
    for(i=2;i<=sqrt(a);i++)
        if(a%i==0)
        return 0;
    return 1;
}
int main()
{
    int n,temp,i,j;
    scanf("%d",&n);

    for(i=0;i<n;i++)
       {
           scanf("%d",&temp);
           for( j=2;j<=temp;j++)
           {
               if(1==isapa(j))
               {
                   if(0==temp%j&&isapa(temp/j))
                   {
                      // printf("%d  %d\n",j,temp/j);
                       f[i]=1;
                       break;
                   }

               }
           }
           if(j==temp)
            f[i]=0;

       }
       for(i=0;i<n;i++)
        if(f[i]==1)
        printf("Yes\n");
       else
        printf("No\n");

    return 0;
}
