#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <int > f[1005];
int n,m,k;
int link[1005];
bool vis[1005];
bool dfs(int x)
{
    for(int i=0;i<f[x].size();i++)
    {
        int j=f[x][i];
        if(!vis[j])
        {
            vis[j]=1;
            if(link[j]==-1|| dfs(link[j]))
            {
                link[j]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	while(1)
    {
        cin>>k;
        if(k==0)
            break;
        cin>>n>>m;
        int sum=0;
        memset(link,-1,sizeof link);
        memset(f,0,sizeof f);
        for(int i=0;i<k;i++)
    {
        int a,b;
        cin>>a>>b;
        f[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        if(dfs(i))
            sum++;
    }
    cout<<sum<<endl;
    }
   return 0;
}
