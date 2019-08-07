/*
作者:kaiss
题目:p1146 ISBN号码
*/
#include <stdio.h>
#include<string.h>
int main()
{
    char str[255];
    gets(str);
    int i,f[10],count=0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]!='-')
        {
            f[count]=str[i]-'0';
            count++;
        }
    }
    int sum=0,ccc=1;
    for(i=0;i<9;i++)
    {
        sum=sum+f[i]*ccc;
        ccc++;
    }
    if(sum%11==10)

    if((sum%11)==f[9])
        printf("Right");
    else
    {
        for(i=0;i<strlen(str)-1;i++)
        {
            printf("%c",str[i]);
        }
        printf("%c",x);
    }
}
