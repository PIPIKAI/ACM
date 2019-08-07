#include<bits/stdc++.h>
using namespace std;
#define inf 999999
int f[2000][2000],n,m;
int dis[2005],vis[2005];
int kus(int a,int b)
{
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);
    for(int i=1;i<=n;i++)
        dis[i]=f[a][i];
    vis[a]=1;
    for(int i=1;i<=n-1;i++)
    {
        int min=inf,k=-1;
        for(int j=1;j<=n;j++)
        {
            if(dis[j]<min&&!vis[j])
                min=dis[j],k=j;
        }
        if(k==-1)
            break;
        vis[k]=1;
        for(int j=1;j<=n;j++)
        {
            if(dis[j]>min+f[k][j]&&!vis[j])
            {
                dis[j]=min+f[k][j];
            }
        }
    }
    return dis[b];
}
int main()
{
    cin>>n>>m;
    memset(f,inf,sizeof(f));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        f[x][y]=f[y][x]=1;
    }
    int ans1,ans2;
    ans1=kus(1,n);
    for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			f[i][j] == 1 ?f[i][j] = inf:f[i][j] = 1;
    ans2=kus(1,n);
    ans1=max(ans1,ans2);
    if(ans1>=inf)
        cout<<"-1";
    else
        cout<<ans1;
    return 0;
}
