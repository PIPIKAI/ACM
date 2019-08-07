#include<bits/stdc++.h>
using namespace std;
int f[550][550],n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ax,ay,bx,by,flag=0;
void dis()
{
    for(int i=1;i<=n;i++)
       {
            for(int j=1;j<=m;j++)
            {
                cout<<f[i][j]<<" ";
            }
            cout<<endl;
       }
}
void dfs(int x,int y)
{
    if(x==bx&&y==by&&f[x][y]==1)
    {
        flag=1;
        cout<<"YES"<<endl;
        return ;
    }
    if(x>n||y>m||x<1||y<1||f[x][y]==1||flag)
        return ;
    f[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int cx=x+dx[i];
        int cy=y+dy[i];
        dfs(cx,cy);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='X')
                f[i][j]=1;
            if(ch=='.')
                f[i][j]=2;
        }
    cin>>ax>>ay>>bx>>by;
    for(int i=0;i<4;i++)
    dfs(ax+dx[i],ay+dx[i]);
    if(!flag)
        cout<<"NO"<<endl;
    return 0;
}
