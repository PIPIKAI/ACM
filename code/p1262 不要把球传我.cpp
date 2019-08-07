/*
作者:kaiss
题目:p1262 不要把球传我
*/
#include <stdio.h>
int i=1,j=5;
int aaa(int a)
{

    i=i+j;
    j=i+j;
    a--;
    if(a>=0)
    return aaa(a);
    else
    return i;
}
int main()
{
    int a,count=6;
    scanf("%d",&a);

    if(a<4)
    {
        printf("0");
        return 0;
    }
    if(a==4)
    {
        printf("1");
        return 0;
    }
    if(a==5)
    {
        printf("5");
        return 0;
    }
    a=a-6;
    printf("%d",aaa(a)+6);
    return 0;
}
