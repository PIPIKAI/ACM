#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,i,len,flag;
    scanf("%d%d\n",&a,&b);
    char str[255];
    gets(str);
    len=strlen(str);
    for(i=0,flag=0;i<len;i++)
    {
         if(i==a)
            flag=1;
        if(i==b+a)
            flag=0;
        if(flag==0)
        printf("%c",str[i]);

    }

    return 0;
}
