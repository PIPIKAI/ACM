/*6. 归并两个有序字符串，要求输出不能有重复字符*/

#include<stdio.h>
#include<string.h>
/*a={'a','c','c','f','k'}
b ={'b','d','f','l','z'} */
char a[20],b[20],t[100];
void solve()
{
    int i=0,j=0,k=0;

    while(a[i]!='\0'&&b[j]!='\0')
    {
        if(a[i]==a[i+1])
        {
            ++i;
            continue;
        }
        if(b[j]==b[j+1])
        {
            ++j;
            continue;
        }
        if(a[i]<b[j])
        {
            t[k++]=a[i];
            ++i;
        }
        else if(a[i]==b[j])
        {
            t[k++]=a[i];
            ++i,++j;
        }
        else if(a[i]>b[j])
        {
            t[k++]=b[j];
            ++j;
        }
    }
    if(a[i]=='\0')
    {
       while(b[j]!='\0')
        t[k++]=b[j++];
    }
    if(b[j]=='\0')
    {
        for(;a[i]!='\0';i++)
        t[k++]=a[i];
    }
    t[k]='\0';
}
int main()
{
    scanf("%s%s",a,b);
    solve();
    printf("%s\n",t);
    return 0;
}
