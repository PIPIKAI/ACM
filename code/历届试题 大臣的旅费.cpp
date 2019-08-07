#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9
#define MAX 100100
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
int vis[MAX]={0},ans=0;
int w[MAX];
void ini()
{
    mem(vis,0);
    mem(w,0);
}
struct node
{
    int v,w;
    node(int vv,int ww):v(vv),w(ww){}
};
vector<vector <node> > f;
void dfs(int fa,int a,int pre)
{
    w[a]=pre;
    for(int i=0;i<f[a].size();i++)
    {
        int j=f[a][i].v,k=f[a][i].w;
        if(!vis[j]/*&&k!=0*/)
        {
            vis[j]=1;
            dfs(j,pre+k);
            vis[j]=0;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
        f.clear();
        f.resize(n+2);
        for(int i=0;i<n-1;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;
            f[x].push_back(node(y,w));
            f[y].push_back(node(x,w));
        }
    for(int i=1;i<=n;i++)
    {
        ini();
        vis[i]=1;
        dfs(i,0);
        for(int j=1;j<=n;j++)
            ans=max(w[j],ans);
    }
    ans=(ans+1)*ans/2+ans*10;
    cout<<ans<<endl;
    }
    return 0;
}
/**
7
1 2 2
1 3 1
2 4 5
2 5 4
4 7 2
4 6 1
*/
