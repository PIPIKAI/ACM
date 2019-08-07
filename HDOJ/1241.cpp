#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[50][50];
int n,m,l,flag;
int d[4][2]={-1,0, 1,0, 0,-1, 0,1},a,b;
int ans[50][50];
void dfs(int x,int y,int step)
{

    if(x>=n||x<0||y<0||y>=m)
    {
        cout<<step<<" step(s) to exit"<<endl;
        return ;
    }
    if(ans[x][y]!=-1)
    {
        b=step-ans[x][y];
         cout<<ans[x][y]<<" step(s) before a loop of "<<b<<" step(s)"<<endl;
        return ;
    }
    ans[x][y]=step;
    int cx=x+d[f[x][y]][0];
    int cy=y+d[f[x][y]][1];
    dfs(cx,cy,step+1);
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	while(cin>>n>>m>>l,n!=0&&m!=0&&l!=0)
    {
        memset(ans,-1,sizeof(ans));
         flag=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                char c;
                cin>>c;
                if(c=='N')  f[i][j]=0;
                if(c=='S') f[i][j]=1;
                if(c=='W') f[i][j]=2;
                if(c=='E') f[i][j]=3;
            }
        dfs(0,l-1,0);
    }
   return 0;
}
