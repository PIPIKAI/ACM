#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,count=0;
    scanf("%d",&n);
    char str[n][255],t[255];
    for(i=0;i<n;i++)
    {
        scanf("%s",str[i]);
    }
    scanf("%s",t);
    for(i=00;i<n;i++)
    {
        if(strcmp(str[i],t)==0)
            count++;
    }
    printf("%d\n",count);
    return 0;
}
