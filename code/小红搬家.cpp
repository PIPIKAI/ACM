#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,i,a,b;

    while(~scanf("%d%d",&n,&m))
    {
         int f[m],sum=0,add=n;
    for(i=0;i<m;i++)
        scanf("%d",&f[i]);
        scanf("%d%d",&a,&b);
        if(a==0||b==0)
            return 0;
    if(n==0||n==1)
        {
            printf("0");
             continue;
        }
    sort(f,f+m);
    for(i=m-1;i>=0;i--)
    {

        n=n-f[i];
        sum++;
        if(n<=0)
            break;
        else
            n+=1;

    }
    if(n>0)
        printf("Impossible");
    else
        printf("%d",sum);

    }
    return 0;
}
