#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn=110;
const int INF=0x3f3f3f3f;
using namespace std;
struct edge
{
    int to,w,next;
} edge[maxn];

bool vis[maxn];//maxn是点的个数，p记录状态
int dist[maxn];//dist记录最短边长
int pre[maxn];//pre记录连接信息
int head[maxn];
int tot;

void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}
void addedge(int u,int v,int w)
{
    edge[tot].to=v;
    edge[tot].w=w;
    edge[tot].next=head[u];
    head[u]=tot++;
}

int prim(int n)
{
    for(int i=1; i<=n; i++) dist[i]=INF;
    for(int i=head[1]; i!=-1; i=edge[i].next)
        dist[edge[i].to]=edge[i].w,vis[edge[i].to]=false,pre[edge[i].to]=1;
    dist[1]=0;
    vis[1]=true;
    for(int i=1; i<n; i++)
    {
        int min0=INF,k=0;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && min0>dist[j])
            {
                min0=dist[j];
                k=j;
            }
        }
        if(k==0)return 0;
        vis[k]=true;
        for(int j=head[k]; j!=-1; j=edge[j].next)
            if(!vis[edge[j].to] && edge[j].w<dist[edge[j].to])
                dist[edge[j].to]=edge[j].w, pre[edge[j].to]=k;
    }
    int ans=0;
    for(int i=1; i<=n; i++)
        ans+=dist[i];
    for(int i=1; i<=n; i++)
        printf("%d ",pre[i]);
    puts("");
    return ans;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    while(m--)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
    printf("%d\n",prim(n));
    return 0;
}
