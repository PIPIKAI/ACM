#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
double f[1100][1100];
int ans;
int n;
void ini()
{
    for(int i=1;i<=1000;i++)
    {
        for(int k=0;j<=1000;j++)
        {
            if()
        }
    }
}
void prime(int a)
{
    int vis[1100]={0},min,b,i,j;
    int len[1100]={0};
    ans=0;
    vis[a]=1;
    for( i=1;i<=1000;i++)
    len[i]=f[a][i];
    for( i=2;i<=1000;i++)
    {
        min=inf;
        for( j=1;j<=1000;j++)
        {
            if(!vis[j]&&min>len[j])
            {

                b=j;
                min=len[j];
            }
        }
        vis[b]=1;
        ans+=min;
        for( j=1;j<=1000;j++)
        {
            if(len[j]>f[b][j]&&!vis[j])
                len[j]=f[b][j];
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int T;
    while(cin>>T)
          {
              while(T--)
              {
                  memset(f,inf+1,sizeof(f));
                   for(int i=0;i<n;i++)
                   {
                       cin>>x>>y;
                       f[x][y]=1;
                   }
                    ini();
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

          }
    return 0;
}


