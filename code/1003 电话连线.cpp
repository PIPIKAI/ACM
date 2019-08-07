#include<iostream>
using namespace std;
#define inf 99999999
int n,m,ans=0;
int f[200][200];
void prim(int a)
{
    int i,j,k=a,vis[200]={0};
    int dis[200]={0};
    int ax[200],bx[200];
    int co=0;
    int col[200]={0};
    memset(col,1,sizeof(col));
    vis[a]=1;
    for(i=1;i<=n;i++)
        dis[i]=f[i][a];
    for( i=2;i<=n;i++)
    {
        int min=inf;
        for(j=1;j<=n;j++)
            if(!vis[j]&&min>dis[j])
            {
                k=j;
                min=dis[j];
            }
        vis[k]=1;
        ans+=dis[k];
        if(dis[k])
        {
            ax[co]=k;
            bx[co++]=col[k];
        }
        for(j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]>f[k][j])
            {
                col[j]=k;
                dis[j]=f[k][j];

            }
        }
    }
    cout<<co<<endl;
    for(i=0;i<co;i++)
        cout<<ax[i]<<" "<<bx[i]<<endl;;
    cout<<ans<<endl;
}
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        cin>>f[i][j];
    prim(1);
    return 0;
}
