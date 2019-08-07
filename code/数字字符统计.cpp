#include<stdio.h>
int find (char *str)
{
    char *c;c=str;
        int count=0;
    for(;*c!='\0';c++)
    {
        if(*c>='0'&&*c<='9')
            count++;
    } return count;
}
int main()
{
    char str[255];
    gets(str);
    printf("%d", find(str));
    return 0;
}


