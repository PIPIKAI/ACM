#include<stdio.h>
int main()
{
    int f[7][2],flag=0;
    int a=0,b;
    int i;
    for(i=0;i<7;i++ )
        scanf("%d%d",&f[i][0],&f[i][1]);
    for(i=6;i>=0;i--)
    {
        int t=f[i][0]+f[i][1];
        if(t>=8)
        {
            flag=1;
            if(a<=t)
            {
                a=t;
                b=i;
            }
        }
    }
    if(flag)
    printf("%d",b+1);
    else
        printf("0");




        return 0;
}
