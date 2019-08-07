#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
struct node
{
    int a,b,w;
}f[30010];
int vis[5000];
int sb[550];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int ans;
int n,m,k;
bool juge()
{
    int s=0;
    for(int i=1;i<=n;i++)
        if(vis[i]==i)
            s++;
        if(s!=1)
        return 0;
        else
        return 1;
}
int find(int x)
{
    int r=x,i=x,j;
    while(vis[r]!=r)
       r=vis[r];
    while(r!=i)
    {
        j=vis[i];
        vis[i]=r;
        i=j;
    }
    return r;
}
int merg(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)  return 0;
    if(a>b)   vis[a]=b;
    if(a<b)   vis[b]=a;
    return 1;
}
void kusal()
{
   ans=0;
   for(int i=1;i<=m;i++){
        if(merg(f[i].a,f[i].b))
            ans+=f[i].w;
        if(juge())
            break;
   }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int T;
    cin>>T;
    {
    while(T--)
    {
        while(cin>>n>>m>>k)
      {
          memset(f,0,sizeof f);
          memset(vis,0,sizeof vis);
           for(int i=1;i<=m;i++)
            cin>>f[i].a>>f[i].b>>f[i].w;
            for(int i=1;i<=n;i++)
                vis[i]=i;
           for(int i=0;i<k;i++)
           {
               int t;m++;
               cin>>t;
               for(int j=0;j<t;j++)
                   cin>>sb[j];
               for(int j=0;j<t-1;j++)
               {
                  f[m].a=sb[j];
                  f[m].b=sb[j+1];
                  f[m].w=0;
                  ++m;
               }
           }
           sort(f+1,f+m,cmp);
           kusal();
           if(juge())
           cout<<ans<<endl;
           else
            cout<<"-1"<<endl;
      }
    }
    }
    return 0;
}




