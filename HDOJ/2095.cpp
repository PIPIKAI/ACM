//   autor: zzk  2018-8-2 10.42
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans,n;
    while(cin>>n,n)
    {
        ans=0;
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d",&t);
            ans^=t;
        }
            printf("%d\n",ans);
    }
    return 0;
}
