#include <cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n,len=0,ans=0;
    scanf("%d",&n);
    int f[n+1]={0};
    for(int i=1,t;i<=n;i++){
        scanf("%d",&t);
        f[t]=i;
    }
    for(int i=1;i<=n;i++){
        f[i-1]<f[i] ? ++len :len=1;
        ans=max(len,ans);
    }
    printf("%d\n",n-ans);
    return 0;
}
