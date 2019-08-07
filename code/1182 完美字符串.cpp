#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
int main()
{
    char str[10001];
    int f[10002]={0},cont=1,a=26;
    long long ans=0;
    scanf("%s",str);
    int len=strlen(str);
    sort(str,str+len);
    for(int i=0;i<len;i++)
    {
        if(str[i]==str[i+1])
            cont++;
        else
        {
            f[cont]++;
            cont=1;
        }

    }
    for(int i=len;i>=0;i--)
    {
            if(f[i])
        {
            while(f[i]>0)
            {
                ans+=a*i;
                a--;
                f[i]--;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
