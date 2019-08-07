#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef pair <int ,int > P;
int f[1005][1005];
bool vis[1005];
int ans,a,b,n,m;
int BFS(int i)
{
    memset(vis,false,sizeof(vis));
    int x;
    queue <int> q;
    q.push(i);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        int y;
        for(y=1;y<=n;y++)
        {
            if(f[x][y]&&y==i)
                return 1;
            else if(!vis[y]&&f[x][y]&&y!=i)
            {
                q.push(y);
                vis[y]=true;
            }
        }
    }
    return 0;
}
int main()
{
    int i;
    cin>>n>>m;
    memset(f,0,sizeof(f));
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        f[x][y]=1;
    }
    for(i=1;i<=n;i++)
        if(BFS(i))
            cout<<"T"<<endl;
        else
            cout<<"F"<<endl;
    return 0;
}

