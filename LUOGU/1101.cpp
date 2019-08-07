#include<bits/stdc++.h>
using namespace std;
string yizhong="yizhong",f[101];
int ans[110][110],p[7][2],n;
int d[8][2]={    -1,0,1,0,    0,-1,0,1,    -1,-1,1,1,   -1,1,1,-1,};
void dfs(int x,int y,int step,int dir)
{
    if(step==7) for(int i=0;i<7;i++) ans[p[i][0]][p[i][1]]=1;
    if(x<0||y<0||x>=n||y>=n||step==7) return ;
    if(f[x][y]==yizhong[step]){p[step][0]=x,p[step][1]=y; dfs(x+d[dir][0], y+d[dir][1] ,step+1, dir);}
}
int main()
{
    memset(ans,0,sizeof ans);
    cin>>n;
    for(int i=0;i<n;i++) cin>>f[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        if(f[i][j]=='y')
            for(int k=0;k<8;k++)
                dfs(i,j,0,k);
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n;j++)
        if(ans[i][j])
        cout<<f[i][j];
        else if(ans[i][j]==0)
        cout<<"*";
        cout<<endl;
    }
    return 0;
}

