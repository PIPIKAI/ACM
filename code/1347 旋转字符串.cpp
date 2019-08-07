#include<stdio.h>
#include<string.h>
char * Left(char a[],int len)
{
    char t=a[len-1];
    a[len-1]=a[0];
    a[0]=t;
    return a;
}
int juge(char str[],int len)
{
    for(int i=0;i<len/2;i++)
        if(str[i]!=str[len/2+i])
            return 0;
    return 1;
}
int main()
{
    char str[1000000];
    while(~scanf("%s",str))
    {
        int len=strlen(str),i;
        if(len%2==1)
        {
            printf("NO\n");
            continue;
        }
        for(i=0;i<len;i++)
        {
            if(juge(str,len))
            break;
            Left(str,len);
        }

        if(i==len)
        printf("NO\n");
        else
        printf("YES\n");
    }
    return 0;
}
