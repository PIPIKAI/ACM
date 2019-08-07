#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
struct node
{
    int a,b,w;
}f[6010];
int vis[5000];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int ans;
int n,m;
bool juge()
{
    for(int i=1;i<=m-1;i++)
        if(vis[i]!=vis[i+1])
        return 0;
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
    if(a==b)
        return 0;
    if(a>b)
         vis[a]=b;
    if(a<b)
        vis[b]=a;
    return 1;
}
void kusal()
{
   ans=0;
   for(int i=1;i<=n;i++)
    vis[i]=i;
   for(int i=1;i<=m;i++)
   {
        if(merg(f[i].a,f[i].b))
            ans+=f[i].w;
        if(juge())
        break;
   }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n,n!=0)
      {
          vis[0]=-1;
          memset(f,0,sizeof f);
          memset(vis,0,sizeof vis);
          m=(n-1)*n/2;
           for(int i=1;i<=m;i++)
               cin>>f[i].a>>f[i].b>>f[i].w;
           sort(f+1,f+m+1,cmp);
           kusal();
           cout<<ans<<endl;
      }
    return 0;
}


