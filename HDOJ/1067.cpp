#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ti;
char f[15][15][2];
int vis[15][15][2];
int d[4][2]={1,0,-1,0   ,0,1,0,-1};
struct node
{
    int x,y,z,step;
};
bool bfs()
{
    queue < node >  q;
    node t;
    t.x=0,t.y=0,t.step=0,t.z=0;
    vis[t.x][t.y][t.z]=1;
    q.push(t);
    while(!q.empty())
    {
        node nb;
        t=q.front();
        q.pop();
        if(f[t.x][t.y][t.z]=='P'&&t.step<=ti)
        {
            return true;
        }
        nb.step=t.step+1;nb.z=t.z;
        for(int i=0;i<4;i++)
        {
            nb.x=t.x+d[i][0];
            nb.y=t.y+d[i][1];
            if(nb.x>=0&&nb.x<n&&nb.y>=0&&nb.y<m&&f[nb.x][nb.y][nb.z]!='*'&&nb.z<2&&nb.z>=0&&!vis[nb.x][nb.y][nb.z]&&nb.step<=ti)
            {
                vis[nb.x][nb.y][nb.z]=1;
                if(f[nb.x][nb.y][nb.z]=='#'&&f[nb.x][nb.y][abs(nb.z-1)]=='.'||f[nb.x][nb.y][abs(nb.z-1)]=='P'&&!vis[nb.x][nb.y][abs(nb.z-1)])
                {
                    nb.z=abs(nb.z-1);
                    q.push(nb);
                }
                if(f[nb.x][nb.y][nb.z]=='.'||f[nb.x][nb.y][nb.z]=='P')
                {

                    q.push(nb);
                }
            }
        }
    }
    return 0;
}

int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    int c;
    cin>>c;
    while(c--)
    {
        int a,b,c,d;
        memset(vis,0,sizeof vis);
        cin>>n>>m>>ti;
        for(int k=0;k<2;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>f[i][j][k];
        bool u=bfs();
        if(u)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
   return 0;
}
