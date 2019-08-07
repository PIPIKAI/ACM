#include<stdio.h>
#include<algorithm>
using namespace std;
int f[10];
int main()
{
    int n,k,sum,cc=0;
    scanf("%d%d",&k,&n);
    int i=0,temp=n;
    while(1)
    {

        f[i]=temp%10;
        cc+=f[i];
        if(temp/10==0)
            break;
        temp/=10;
        i++;
    }
    sort(f,f+i);
    if(cc>=k)
    {
        sum=0;
    }
    else
    {

    }
    printf("%d",cc);
    return 0;
}

