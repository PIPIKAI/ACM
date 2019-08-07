#include<bits/stdc++.h>
using namespace std;
#define inf 999999
int n,m,f[500][500],b[500][500],step[500];
int vis[500],dis[500];
queue <int >q;
void disroad(int x)
{
	if (step[x]!=0)
    disroad(step[x]);
	cout << x << " -> ";
}
void ini()
{
    memset(f,inf,sizeof f);
    memset(step,0,sizeof step);
    memset(b,0,sizeof b);
    memset(vis,0,sizeof(vis));
    memset(dis,inf,sizeof(dis));
    while(!q.empty()) q.pop();
}
void spfa(int a,int e)
{
    dis[a]=0;
    vis[a]=1;
    q.push(a);
    while(!q.empty())
    {
        int t=q.front();
        vis[t]=0; //
        q.pop();
        for(int i=1;i<=b[t][0];i++)
        {
            if(dis[b[t][i]]>dis[t]+f[t][b[t][i]])
            {
                dis[b[t][i]]=dis[t]+f[t][b[t][i]];
                if(!vis[b[t][i]])
                {
                    q.push(b[t][i]);
                    vis[b[t][i]]=1;
                }
            }
        }
    }
    //disroad(a);
    if(dis[e]>=inf)
        cout<<"-1"<<endl;
    else
        cout<<dis[e]<<endl;
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
        spfa(a,b);
    }
    return 0;
}
