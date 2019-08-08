#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
ll f[60],n,ans=- inf,d,k;
void dfs(int p,int step,ll sum)
{
    if(step>=k)
    {
        ans=max(ans,sum);
        return ;
    }
    for(int i=p+1;i<=min((i+d),n);i++)
        dfs(i,step+1,sum*f[i]);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>f[i];
    cin>>k>>d;
    dfs(0,0,1);
    cout<<ans<<endl;
    return 0;
}
