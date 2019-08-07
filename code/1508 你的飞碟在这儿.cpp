/*
作者:kaiss
题目:p1508 你的飞碟在这儿
*/

#include<stdio.h>
#include<string.h>
    int main()
    {

    char str1[255];
    char str2[255];
   gets(str1);
   gets(str2);
    int i,sum1=1,sum2=1;
    for(i=0;i<strlen(str1);i++)
    {
        sum1=sum1*(str1[i]-'A'+1);
    }
     for(i=0;i<strlen(str2);i++)
    {
        sum2=sum2*(str2[i]-'A'+1);
    }
    sum1=sum1%47;sum2=sum2%47;

    if(sum1==sum2)
        printf("GO");
    else
        printf("STAY");
    return 0;
    }
