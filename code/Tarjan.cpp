#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 1000000
int ans[maxn];
int vis[maxn];
int dfn[maxn];
int low[maxn];
struct M{
    int s;
    int next[200];
}mp[maxn];
int n,m,tt,cnt,sig;
void init()
{
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(vis,0,sizeof(vis));
    memset(mp,0,sizeof(mp));
}
void Tarjan(int u)
{
    vis[u]=1;
    low[u]=dfn[u]=cnt++;
    for(int i=0;i<mp[u].s;i++)
    {
        int v=mp[u].next[i];
        if(vis[v]==0) Tarjan(v);
        if(vis[v]==1) low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u])
    {
        sig++;
    }
}
void Slove()
{
    tt=-1;cnt=1;sig=0;//³õÊ¼»¯
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            Tarjan(i);
        }
    }
    printf("ans = %d\n",sig);
}
void dis_mp()
{
    for(int i=0;i<m;i++)
        {
            printf("%d ->  ",i);
            for(int j=0;j<mp[i].s;j++)
            {
                printf("%d ",mp[i].next[j]);
            }
            printf("\n");
        }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mp[x].next[mp[x].s]=y;
            mp[x].s++;
        }
        Slove();
    }
}
