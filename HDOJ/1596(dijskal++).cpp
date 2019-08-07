#include<bits/stdc++.h>
using namespace std;
double f[1020][1020];
double dis[1020];
int vis[1020],n;
void query(int a,int b)
{
    double max;
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof vis);
    vis[a]=1;dis[a]=1;
    for(int i=1;i<=n;i++)
        dis[i]=f[a][i]*dis[a];
    for(int i=2;i<=n;i++)
    {
        int k=a;
         max=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&max<dis[j])
            {
                max=dis[j];k=j;
            }
        }
        vis[k]=1;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dis[j]<f[k][j]*dis[k])
                dis[j]=f[k][j]*dis[k];
    }
     if(dis[b]==0)
        printf("What a pity!\n");
    else
        printf("%.3lf\n",dis[b]);
}
int main()
{
   while(cin>>n)
   {
       memset(f,0,sizeof f);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                scanf("%lf",&f[i][j]);
            }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            query(a,b);
        }
    }
    return 0;
}
