#include<bits/stdc++.h>
using namespace std;
int f[60][60],n,m;
int ans[60][60],d[4][2]={-1,0, 0,1, 1,0, 0,-1};
struct node{
    int x,y,z;
};
node tar ;
queue < node> q;
void bfs()
{
while(!q.empty())
{
node t=q.front();
q.pop();
int dd;
for(int i=0;i<4;i++)
{
    node po;
    for(int k=1;k<=3;k++)
    {
        po.x=t.x+d[i][0]*k,po.y=t.y+k*d[i][1];
        if(f[po.x][po.y]==1) // 当初为了贪心一点，K从3开始，后来发现可能会穿墙！！！WAW了N次
            break;
        if(po.x>0&&po.y>0&&po.x<n&&po.y<m&&ans[t.x][t.y]+1<ans[po.x][po.y])
        {
            if(abs(t.z-i)!=2)
            {
            if(t.z-i==0)
            ans[po.x][po.y]=ans[t.x][t.y]+1; //  同方向
            else
            ans[po.x][po.y]=ans[t.x][t.y]+2; //  左或右
            }
            else
            ans[po.x][po.y]=ans[t.x][t.y]+3; //向后转!
            po.z=i;
            q.push(po);
        }
    }
}
}
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
        int  a;
        cin>>a;
          if(a)
            f[i][j]=f[i-1][j-1]=f[i-1][j]=f[i][j-1]=1; //初始化
        }
    node t;
    char cc;
    cin>>t.x>>t.y>>tar.x>>tar.y>>cc;
    if(cc=='N') t.z=0;  if(cc=='E')	t.z=1;//  0,1,2,3 分别代表上右下左，顺时针QAQ
    if(cc=='S') t.z=2;  if(cc=='W')	t.z=3;

    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    ans[i][j]=999;          // 先赋值到最大

    q.push(t);
    ans[t.x][t.y]=0; // 初始化
    bfs();
    if(ans[tar.x][tar.y]>=999)
        cout<<"-1"<<endl;
    else
        cout<<ans[tar.x][tar.y]<<endl;
    return 0;
}
