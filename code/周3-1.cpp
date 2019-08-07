#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int n,m,t;
ll ans=0;
void dfs(int sum,int p,int step)
{
    if(sum<0||step>m||p>n)
    {
        return ;
    }
    if(sum==0&&step==m)
    {
        ans++;
    }
    for(int i=p;i<=n;i++)
    {
        dfs(sum-i,i,step+1);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>t;
    {
        while(t--)
        {
            ans=0;
            cin>>n>>m;
            dfs(n,0,0);
            cout<<ans<<endl;
        }
    }
    return 0;
}
