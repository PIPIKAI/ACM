#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define l 1
#define r -1
double f[2]={0};
int i,flag=1,l_r=l,zhengfu=1,dire=0;
char str[255];
int what(int i)
{
    int sum=0;
    if(str[])
}
int main()
{
    int kg=0,val=0;
    scanf("%s",str);
    for(i=0;str[i];i++)
    {
        if(str[i]=='+')
        {
            f[dire]+=val*flag*l_r*zhengfu;
            dire=1;
            zhengfu=1;
            l_r=-1;
        }
        else if(str[i]=='-')
        {
            f[dire]+=val*flag*l_r*zhengfu;
            dire=1;
            zhengfu=-1;
            l_r=-1;
        }
        else if(str[i]=='=')
        {

            flag=-1;
        }
        else if(isdigit(str[i])==1)
        {
            val=str[i]-'0';
            printf("%d\n",val);
        }
        else if(isalpha(str[i])==1)
        {
            dire=0;
            l_r=1;
        }
    }
    printf("%lf %lf  sum=%.3lf\n",f[0],f[1],f[0]/f[1]);
    return 0;
}
//      6a-5+1=2-2a  a=0.750

