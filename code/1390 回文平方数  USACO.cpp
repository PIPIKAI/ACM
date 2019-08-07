/*
作者:kaiss
题目:p1390 回文平方数
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
     printf(" ");
}
int isbackword(int k,int b)
{
    int a=k*k,i=0,j;
    int str[255];
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
    for(j=0;j<=(i-1)/2;j++)
    {
        if(str[j]!=str[i-j-1])
            return 0;
    }
    change(k,b);
    for(j=i-1;j>=0;j--)
    printf("%c",str[j]);
    printf("\n");
}
int main()
{
    int a,i;
    scanf("%d",&a);
    for(i=1;i<=300;i++)
    {
        isbackword(i,a);

    }
    return 0;
}
