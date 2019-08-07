#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        double  t[n];

    for(int i=0;i<n;i++)
    {
        scanf("%lf",&t[i]);
    }
     for(int i=0;i<n;i++)
        printf("%.0lf\n",t[i]*2);
    }


    return 0;
}
