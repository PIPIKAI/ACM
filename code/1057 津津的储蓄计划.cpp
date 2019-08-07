/*
作者:kaiss
题目:p1057 津津的储蓄计划
*/

#include <stdio.h>
int main()
{
    int a[12], b,count=0,sum=0,i; //定义两个变量名
    for(b=0;b<12;b++)
    scanf("%d", &a[b]);//从标准输入流中输入两个整数
    for(b=0;b<12;b++)
    {
        count+=300;
        count-=a[b];
        if(count>=100)
        {
            sum+=(count/100)*100;
            count=count-(count/100)*100;

        }
        if(count<0)
        {
            printf("-%d",b+1);
            return 0;
        }
    }
    sum+=0.2*sum+count;
    printf("%d",sum);
    return 0;
}
