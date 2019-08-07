#include<bits/stdc++.h>
using namespace std;
#define inf 999999
int n,m,f[500][500],b[500][500] ,vis[500],dis[500];
queue <int >q;
void ini()
{
    memset(f,inf,sizeof f);
    memset(b,0,sizeof b);
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    while(!q.empty()) q.pop();
}
void spfa(int a)
{
    int t=a;
    for(int i=1;i<=b[t][0];i++)
    {
        if(dis[b[t][i]]>dis[t]+f[t][b[t][i]])
        {
            dis[b[t][i]]=dis[t]+f[t][b[t][i]];
            spfa(b[t][i]);
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
            int x,y,t;
            cin>>x>>y>>t;
            if(f[x][y]>t)
            {
                b[x][0]++;b[x][b[x][0]]=y;f[x][y]=t;
                b[y][0]++;b[y][b[y][0]]=x;f[y][x]=t;//
            }
        }
        int a,b;
        cin>>a>>b;
        dis[a]=0;
        spfa(a);
        if(dis[b]>=inf)
            cout<<"-1"<<endl;
        else
            cout<<dis[b]<<endl;
    }
    return 0;
}

