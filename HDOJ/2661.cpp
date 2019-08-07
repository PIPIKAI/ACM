#include<bits/stdc++.h>
using namespace std;
#define inf  1e8
int f[200010],n;
int h[200010];
void ini()
{
    for(int i=0;i<=n;i++)
        f[i]=i,h[i]=0;
}

int find(int x)
{
   if(f[x]!=x)
   {
       int t=f[x];
       f[x]=find(t);
       h[x]+=h[t];

   }
   return f[x];
}
int mer(int a,int b)
{
    int ss;
    int x=find(a);
    int y=find(b);
    if(x==y)
    {
        return h[a]+h[b]+1;
    }
    else
   {
       f[x]=y;
       h[a]=h[b]+1;
   }
    return inf;
}
int main()
{
    cin>>n;
    ini();
    int ans=inf;
    for(int i=1;i<=n;i++)
    {
       int a;
        int tp=mer(i,a);
        ans=min(tp,ans);
    }
    cout<<ans<<endl;
    return 0;
}
