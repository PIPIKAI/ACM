/*
作者:kaiss
题目:p1053 笨小猴
*/
#include <stdio.h>
#include<math.h>
int isaple(int a)
{
    int i;
    if(a==0||a==1)
    {
        return 0;
    }
    for(i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int i,j,flag,count=0,f[255]={0},max=-9999,min=9999;
    char str[255],t[255]={0};
    gets(str);
    for(i=0;str[i]!='\0';i++)
    {
        for(j=0,flag=0;t[j]!='\0';j++)
        {
            if(str[i]==t[j])
            {
                f[j]++;
                 flag=1;
            }

        }
        if(flag==0)
        {
            t[count]=str[i];count++;
        }

    }
    for(i=0;i<count;i++)
        {
            if(f[i]>max)
                max=f[i];
            if(f[i]<min)
            {
                min=f[i];
            }
        }
        if(1==isaple(max-min))
            printf("Lucky Word\n%d",max-min);
        else
            printf("No Answer\n0");

    return 0;
}
