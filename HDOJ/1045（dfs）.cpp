#include<bits/stdc++.h>
using namespace std;
int f[6][6];
int vis[6][6];
int n,ans;
int xx[]={0,1,-1,0};
int yy[]={1,0,0,-1};
int check(int x,int y)
{
     for(int i=x;i>=0&&f[i][y]!=1;i--)//只要搜左上就行了，，剪枝
     {
         if(vis[i][y]) return 0;
     }
      for(int i=y;i>=0&&f[x][i]!=1;i--)
     {
         if(vis[x][i]) return 0;
     }
     return 1;
}
void dfs(int x,int m)
{
    if(x>=n*n)
    {
        ans=max(m,ans);
        return ;
    }
    int ix=x/n,iy=x%n;
    if( vis[ix][iy]==0 && check(ix,iy) && f[ix][iy]!=1)
    {
        vis[ix][iy]=1;
        dfs(x+1,m+1);
        vis[ix][iy]=0;
    }
    dfs(x+1,m);
}
int main()
{
    while(cin>>n)
    {
        if(n==0)
            break;
        int maxn=0;
        ans=0;
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
       for(int i=0;i<n;i++)
       {
           string s;
           cin>>s;
           for(int j=0;j<n;j++)
            f[i][j]=s[j]=='X'?1:0;
       }
        dfs(0,0);
        cout<<ans<<endl;
    }

    return 0;
}
