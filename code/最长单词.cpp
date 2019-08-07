#include<stdio.h>
#include<string.h>
char str[100000];
int   re[100000];
int main()
{
    int i,j,a,b,max_len=0,max_a,max_b;
   gets(str);
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]!=' ')
        {
            re[i]=1;
        }

        else
            re[i]=0;
    }
    for(i=0;i<strlen(str);i++)
    {
        if(re[i]==1)
        {
            for( j=i;re[j]!=0;j++)


                if(max_len<j-i)
            {
                max_a=i;max_b=j;max_len=j-i;
            }
            i=j;
        }
    }
    for(i=max_a;i<=max_b;i++)
    {
        printf("%c",str[i]);
    }

    return 0;
}

