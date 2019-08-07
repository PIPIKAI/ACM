#include<stdio.h>
#include<string.h>
int main()
{
    int i,a,min=9999;
    scanf("%d",&a);
    char str[a][255],t[255];
    for(i=0;i<a;i++)
        scanf("%s",str[i]);
    i=a-1;
    while(i>=0)
    {
        if(strlen(str[i])<=min)
        {
            min=strlen(str[i]);
            strcpy(t,str[i]);
        }
        i--;
    }
    printf("%s\n",t);
}
