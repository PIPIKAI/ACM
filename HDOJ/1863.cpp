#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
struct node
{
    int a,b,w;
}f[6010];
int vis[101];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
int ans;
int n,m;
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
   int num=0;
   for(int i=1;i<=m;i++)
    vis[i]=i;
   for(int i=1;i<=n;i++)
   {
        if(merg(f[i].a,f[i].b))
            ans+=f[i].w,num++;
        if(num==m-1)
            break;
   }
   if(num==m-1)
   cout<<ans<<endl;
   else
    cout<<"?"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    while(cin>>n>>m,n!=0)
      {
          memset(f,0,sizeof f);
          memset(vis,0,sizeof vis);
           for(int i=1;i<=n;i++)
               cin>>f[i].a>>f[i].b>>f[i].w;
           sort(f+1,f+n+1,cmp);
           kusal();
      }
    return 0;
}



