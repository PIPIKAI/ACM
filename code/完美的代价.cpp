#include<stdio.h>
int main()
{
    char str[80001],t;
    int i,j,n,sum=0,flag=0;
    scanf("%d\n",&n);
    gets(str);
    for(i=0;i<n;i++)
    {
        //int temp=n-1-i;
        for(j=n-1-i;j>=i;j--)
        {
            if(j==i&&str[i]!=str[j])
            {
                if(n%2==0)
                {
                    printf("Impossible\n");
                    return 0;
                }
                else
                {
                 sum+=n/2-i;
                 break;
                }
            }

            if(str[i]!=str[j])
                continue;

 //           else  if ()// only one

            else
            {
                for(int a=j;a<n-1-i;a++)
                    str[a]=str[a+1];
                    sum=sum+(n-2-j);
                   // str[n-1-i]=str[i];
                    break;
            }

        }
    }

    printf("%s\n%d\n",str,sum);
    return 0;
}
