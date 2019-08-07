#include<stdio.h>
int sum;
int zuixiaogongbeishu(int a,int b)
{
    int da,val;
    if(a%b==0)
    return b;

    return zuixiaogongbeishu(b,a%b);
}
int main()
{
    int a,b,c,val;
    scanf("%d%d%d",&a,&b,&c);
    val=a*b/zuixiaogongbeishu(a,b);
    sum=val*c/zuixiaogongbeishu(val,c);
    printf("%d\n",sum);
    return 0;
}
