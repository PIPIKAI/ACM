#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,c,ti;
int f[61][61][61];
int vis[61][61][61];
int d[6][3]={1,0,0,0,1,0,0,0,1,-1,0,0,0,-1,0,0,0,-1,};
struct node
{
    int x,y,z,step;
};
bool bfs()
{
    node tp;
    tp.x=0,tp.y=0,tp.z=0,tp.step=0;
    queue<node > q;
    q.push(tp);
    while(!q.empty())
    {
        tp=q.front();
        q.pop();
        node ne;
        if(tp.x==a-1&&tp.y==b-1&&tp.z==c-1&&tp.step<=ti)
        {
            printf("%d\n",tp.step);
            return 1;
        }
        ne.step=tp.step+1;
        for(int i=0;i<6;i++)
        {
            ne.x=tp.x+d[i][0];ne.y=tp.y+d[i][1];ne.z=tp.z+d[i][2];
            if(ne.x>=0&&ne.x<a&&ne.y>=0&&ne.y<b&&ne.z<c&&ne.z>=0&&!f[ne.x][ne.y][ne.z]&&!vis[ne.x][ne.y][ne.z]&&ne.step<=ti)
            {
                q.push(ne);
                vis[ne.x][ne.y][ne.z]=1;
            }
        }
    }
    return 0;
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--){
    memset(f,0,sizeof f);
    memset(vis,0,sizeof vis);
    scanf("%d%d%d%d",&a,&b,&c,&ti);
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
            for(int k=0;k<c;k++)
                scanf("%d",&f[i][j][k]);
    if(!bfs())
        printf("-1\n");
   }
   return 0;
}
