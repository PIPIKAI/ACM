#include<bits/stdc++.h>
using namespace std;
int dp[32005]={0};
struct node
{
    int v,w,s;
}f[60];
node to[1990];
int main()
{
    int cnt=0,n,m,ans=0;
    cin>>n>>m;
   for(int i=0;i<m;i++)
        {
            cin>>f[i].v>>f[i].w>>f[i].s;
            f[i].w=f[i].w*f[i].v;
        }
    node t;
    for(int i=0;i<m;i++)
    {
       if(f[i].s==0)
       {
           to[cnt++]=f[i];
           for(int j=i+1;j<m;j++)
           {
                if(f[j].s!=0)
               {
                   t.v=f[i].v+f[j].v;
                   t.w=f[i].w+f[j].w;
                   to[cnt++]=t;
               }
               if(f[j].s==1)
               {
                   for(int k=j+1;k<m;k++)
                   {
                       if(f[k].s==2)
                       {
                        t.v=f[i].v+f[j].v+f[k].v;
                        t.w=f[i].w+f[j].w+f[k].w;
                        to[cnt++]=t;
                       }
                   }
               }
               if(f[j].s==2)
               {
                   for(int k=j+1;k<m;k++)
                   {
                       if(f[k].s==1)
                       {
                        t.v=f[i].v+f[j].v+f[k].v;
                        t.w=f[i].w+f[j].w+f[k].w;
                        to[cnt++]=t;
                       }
                   }
               }
           }
       }
    }
    for(int i=0;i<cnt;i++)
        cout<<to[i].v<<" "<<to[i].w<<endl;

    for(int i=0;i<cnt;i++)
    {
        for(int j=n;j>=to[i].v;j--)
        {
            if(j-to[i].v>=0)
            dp[j]=max(dp[j],dp[j-to[i].v]+to[i].w),ans=max(ans,dp[j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}

