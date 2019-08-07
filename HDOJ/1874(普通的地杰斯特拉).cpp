#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n,m,sta,ed;
int f[201][201];
int vis[205];
int dis[205];
void ini()
{
    memset(f,inf,sizeof f);
    memset(vis,0,sizeof vis);
}
void dijkstra(int a)
{
    for(int i=0;i<n;i++)
        dis[i]=f[a][i];
    dis[a]=0;
    vis[a]=1;
    for(int i=1;i<n;i++)
    {
        int min=inf;
        int k=0;
        for(int j=0;j<n;j++)
        {
            if(!vis[i]&&min>dis[j])
                min=dis[j],k=j;
        }
        vis[k]=1;
        for(int j=0;j<n;j++)
        {
            if(vis[j]&&dis[j]>min+f[j][k])
                dis[j]=min+f[j][k];
        }
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

