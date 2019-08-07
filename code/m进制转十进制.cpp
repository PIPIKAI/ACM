/*
作者:zzk
题目:p1475 m进制转十进制
*/
#include<stdio.h>
int main()
{
    int i=0,a,b,t,sum=0,x;
    char str[255];
    scanf("%s%d",str,&b);
    int f[100];
    int count =0;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        f[count]=str[i]-'0';
        else if(str[i]>='A'&&str[i]<='Z')
            f[count]=str[i]-'A'+10;

        count ++;
    }
   for(i=count-1;i>=0;i--)
    {
        x=f[i];
        for(t=0;t<count-i-1;t++)
        {
            x*=b;
        }
        sum+=x;
    }
    printf("%d",sum);
    return 0;
}
