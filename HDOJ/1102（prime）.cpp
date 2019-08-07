#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int f[110][110];
int ans;
int n;
void prime(int a)
{
    int vis[110]={0},min,b,i,j;
    int len[110]={0};
    ans=0;
    vis[a]=1;
    for( i=1;i<=n;i++)
    len[i]=f[a][i];
    for( i=2;i<=n;i++)
    {
        min=inf;
        for( j=1;j<=n;j++)
        {
            if(!vis[j]&&min>len[j])
            {

                b=j;
                min=len[j];
            }
        }
        vis[b]=1;
        ans+=min;
        for( j=1;j<=n;j++)
        {
            if(len[j]>f[b][j]&&!vis[j])
                len[j]=f[b][j];
        }
    }
    cout<<ans<<endl;
}
int main()
{
    while(cin>>n)
          {
                memset(f,0,sizeof(f));
               for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                         cin>>f[i][j];
               int q;
               cin>>q;
               for(int i=0;i<q;i++)
               {
                   int x,y;
                   cin>>x>>y;
                   f[x][y]=f[y][x]=0;
               }
               prime(1);
          }
    return 0;
}

