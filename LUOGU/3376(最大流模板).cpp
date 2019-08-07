#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;

int n,m,x,y,z,maxflow,deep[500];//deep���
struct Edge{
    int next,to,dis;
}edge[500];
int num_edge=-1,head[500],cur[500];//cur���ڸ���head
queue <int> q;

void add_edge(int from,int to,int dis,bool flag)
{
    edge[++num_edge].next=head[from];
    edge[num_edge].to=to;
    if (flag) edge[num_edge].dis=dis;//��ͼ�ı�ȨΪ 0
    head[from]=num_edge;
}

//bfs�����ֲ�
bool bfs(int s,int t)
{
    memset(deep,0x7f,sizeof(deep));
    while (!q.empty()) q.pop();
    for (int i=1; i<=n; i++) cur[i]=head[i];
    deep[s]=0;
    q.push(s);

    while (!q.empty())
    {
        int now=q.front(); q.pop();
        for (int i=head[now]; i!=-1; i=edge[i].next)
        {
            if (deep[edge[i].to]>inf && edge[i].dis)//dis�ڴ˴���������� ����ͼ���Ƿ�ͼ
            {
                deep[edge[i].to]=deep[now]+1;
                q.push(edge[i].to);
            }
        }
    }
    if (deep[t]<inf) return true;
    else return false;
}

//dfs�����ӵ�������
int dfs(int now,int t,int limit)//limitΪԴ�㵽������·���ϵ���С��Ȩ
{
    if (!limit || now==t) return limit;

    int flow=0,f;
    for (int i=cur[now]; i!=-1; i=edge[i].next)
    {
        cur[now]=i;
        if (deep[edge[i].to]==deep[now]+1 && (f=dfs(edge[i].to,t,min(limit,edge[i].dis))))
        {
            flow+=f;
            limit-=f;
            edge[i].dis-=f;
            edge[i^1].dis+=f;
            if (!limit) break;
        }
    }
    return flow;
}

void Dinic(int s,int t)
{
    while (bfs(s,t))
        maxflow+=dfs(s,t,inf);
}

int main()
{
//  for (int i=0; i<=500; i++) edge[i].next=-1;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&m,&n);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z,1); add_edge(y,x,z,0);
    }
    Dinic(1,n);
    printf("%d",maxflow);
    return 0;
}
