/*
作者:kaiss
题目:p1474 十进制转m进制
*/
#include <stdio.h>
int change(int a,int b)
{
    int i=0,j;
    int str[100];
    while(a>0)
    {
        if(a%b>=10)
        {
            str[i]=a%b-10+'A';
        }
        else
            str[i]='0'+a%b;
        i++;
        a/=b;
    }

   for(j=i-1;j>=0;j--)
    printf("%c",str[j]);
}
int main()
{
    int a, b;
    scanf("%d%d",&a,&b);
    change(a,b);
    return 0;
}

