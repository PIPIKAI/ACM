#include<bits/stdc++.h>
/* 1078 最小生成树*/
using namespace std;
typedef long long ll;
#define INF 1000000000
int m[200][200];
int n;
ll ans=0;
void prim(int a)
{
    int vis[105]={0};
    int dis[105]={0};
    int clo[105]={0};
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    int i,k=a,l,j=a;
    for(i=1;i<=n;i++)
        dis[i]=m[1][i];
    for(i=2;i<=n;i++)
    {
        int min=INF;
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]<min)
                {
                    min=dis[j];
                    k=j;
                }
        }
        vis[k]=1;
        for(l=1;l<=n;l++)
        {
            if(vis[l]==0&&m[k][l]<dis[l])
            {
                dis[l]=m[k][l];
                clo[l]=k;
            }
        }
    }
    for(i=1;i<=n;i++)
        ans+=dis[i];
}
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>m[i][j];
    prim(1);
    cout<<ans;
    return 0;
}
