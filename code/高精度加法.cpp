#include<stdio.h>
#include<string.h>
void swap(int *p,int *q)
{
    int t;
    t=*q;*q=*p;*p=t;
}
char *_strrev(char *a)
{
    char t;
    int i,len=strlen(a)-1;
    for(i=0;i<=len/2;i++)
    {
        t=a[i];a[i]=a[len-i];a[len-i]=t;
    }
    return a;
}
char* big_add(char *a,char *b,char *sum)
{
    char t[2555];
    int max_len=strlen(a),i,temp=0,min_len=strlen(b),flag=1;
    if(max_len<min_len)
    {
        strcpy(t,a);strcpy(a,b);strcpy(b,t);
        swap(&max_len,&min_len);
    }
    else if(max_len==min_len)
        flag=3;
        _strrev(a);_strrev(b);
        for(i=0;i<min_len;i++)
        {
            if(a[i]+b[i]+temp-'0'>'9')
            {
                sum[i]=(a[i]+b[i]-'0'-'0'+temp)%10+'0';
                if(flag==3&&i==min_len-1)
                {
                    i++;
                    sum[i]='1';max_len++;break;
                }
            }
                else
                sum[i]=a[i]+b[i]-'0'+temp;
            temp=(a[i]+b[i]-'0'-'0'+temp)/10;
        }
        if(flag==1)
        {
            for(i=min_len;i<max_len;i++)
        {
                if(a[i]+temp>'9')
                {
                    sum[i]=a[i]+temp-10;
                    if(i==max_len-1)
                    {
                        i++;sum[i]='1';
                        max_len++;break;
                    }
                }
                else
                    sum[i]=a[i]+temp;
                    temp=(a[i]-'0'+temp)/10;
        }
        }
        sum[max_len]='\0';
        _strrev(sum);
        return sum;
}
int main()
{
    char a[2555],b[2555],sum[2555];
    scanf("%s\n%s",a,b);
    big_add(a,b,sum);
    printf("%s",sum);
    return 0 ;
}
