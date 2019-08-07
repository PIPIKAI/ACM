#include<stdio.h>
int main()
{
    int i,n;
    scanf("%d\n",&n);
    char str[n],p;
    gets(str);
    for(i=0;i<n/2;i++)
    {
        p=str[i];
        str[i]=str[n-1-i];
        str[n-1-i]=p;
         printf("%s\n",str);
    }
    return 0;
}
