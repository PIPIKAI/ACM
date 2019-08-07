#include<stdio.h>
int main()
{
    int i,n;
    int f[100]={0};

         while(1)
         {
             scanf("%d",&i);
             if(i==0)
                break;
             else
             f[i]=1;

}

    for(n=0;n<100;n++)
    {
        if(f[n]==1)
            printf("%d\n",n);
    }
    return 0;

}
