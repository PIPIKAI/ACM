#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n,m,sta,ed;
int f[201][201];
int vis[205];
int dis[205];
struct node
{
    int num,dis;
}t;
priority_queue <node> q;
bool operator < (node a,node b)
{
    if(a.dis==b.dis)
        return a.num>b.num;
    return a.dis>b.dis;
}
void ini()
{
    memset(f,inf,sizeof f);
    memset(vis,0,sizeof vis);
    memset(dis,inf,sizeof dis);
    while(!q.empty())  q.pop();
}
void dijkstra(int a)
{
    dis[a]=0;
    t.num=a;
    t.dis=0;
    q.push(t);
        while(!q.empty())
        {
            for(int i=0;i<n;i++)
            {
                int b=dis[q.top().num]+f[q.top().num][i];
                if(f[q.top().num][i]!=-1 &&dis[i]>b)
                {
                    dis[i]=b;
                    t.num=i,t.dis=dis[i];
                    q.push(t);
                }
            }
            q.pop();
        }
}
int main()
{

    while(cin>>n>>m)
    {
        ini();
        for(int i=0;i<m;i++)
        {
            int x,y,v;
            cin>>x>>y>>v;
            {
                if(f[x][y]>v)
                f[x][y]=f[y][x]=v;
            }
        }
        cin>>sta>>ed;
        dijkstra(sta);
        if(dis[ed]>=inf)
            cout<<"-1"<<endl;
        else
            cout<<dis[ed]<<endl;
    }
    return 0;
}
