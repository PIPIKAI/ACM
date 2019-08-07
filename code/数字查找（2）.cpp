#include<stdio.h>
int fff(int n,float w,f[])
{
n--;
    if(f[n]==w)
    {
        printf("yes");
        return 0;
    }
if(n<0)
{
    printf("no");
    return 0;
}
}
int main()
{

    float n,*i,w;
    scanf("%f",&n);
    float f[n];
    for(i=f;i<f+n;i++)
        scanf("%f",i);
        scanf("%f",&w);
        fff(f,n,w);
        return 0;
}
