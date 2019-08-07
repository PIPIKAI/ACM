#include<stdio.h>
#include<string.h>
int main()
{
    char str[90];
    scanf("%s",str);
    int i=0,j=strlen(str)-1;
    if(j==1)
    {
        printf("False\n");
        return 0;
    }
    char t='-';
    while(1)
    {

            if(i==j)
            {
                 printf("True\n");
                 return 0;
            }
        if(str[i]=='('||str[i]=='{'||str[i]=='[')
            {
                if(str[i]=='(')
                    t=')';
                else if(str[i]=='{')
                    t='}';
                else if(str[i]=='[')
                    t=']';

                if(str[j]==')'||str[j]=='}'||str[j]==']')
            {
                if(str[j]!=t)
                {
                   printf("False\n");
                    return 0;
                }
                else
                {
                    i++;
                    j--;
                }
            }
            else
                j--;
            }
            else if(str[i]==')'||str[i]==']'||str[i]=='}')
            {
                printf("False\n");
                return 0;
            }
            else
            {
                i++;
            }
       // printf("i=%d  j=%d\n",i,j);
    }
    return 0;
}
