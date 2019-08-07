#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m;
ll f[80050];
int vis[80000];
ll ans[80050];
bool flag=0;
void dfs(ll s,ll step)
{
    if(flag||s>m||step>n)
        return ;
    if(s==m)
    {
        flag=1;
        for(int i=0;i<step;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=step;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans[step]=f[i];
            dfs(s+f[i],step+1);
            vis[i]=0;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    {
        ll t=0;
        mem(vis,0);
        flag=0;
        for(int i=0;i<n;i++)
            cin>>f[i],t+=f[i];
        if(t<m)
        {
            cout<<"No Solution!"<<endl;
            return 0;
        }
        dfs(0,0);
        if(!flag)
        {
            cout<<"No Solution!"<<endl;
        }
    }
    return 0;
}
