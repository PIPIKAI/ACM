#include<stdio.h>
#include<algorithm>
using namespace std;
int f[50010];
int main()
{
    int n,k,flag=1;
    scanf("%d%d",&k,&n);
    for(int i=0;i<n;i++)
        scanf("%d",&f[i]);
    sort(f,f+n);
    for(int i=0;i<n;i++)
    {
        int j=lower_bound(f,f+n,k-f[i])-f;
        if(j<=i)
            break;
        if(f[j]+f[i]==k&&i!=j)
        {
            flag=0;
            printf("%d %d\n",f[i],f[j]);
        }

    }
    if(flag)
        printf("No Solution");
    return 0;
}
