#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
int f[100005];
int ans[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
        cin>>f[i];
    for(int i=n;i>=1;i--)
    {
        if(ans[i]==0)
            ans[i]++;
        ans[f[i]] += ans[i];
    }
    sort(ans+1,ans+1+n);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}
