#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+7
int vis[500];
int n,m;
struct node
{
    int a,b,w;
}f[2005];
bool cmp(node a,node b)
{
    return a.w<b.w;
}
void init()
{
    for(int i=0;i<=n;i++)
        vis[i]=i;
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
void merg(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a<b)
        vis[b]=a;
    if(a>b)
        vis[a]=b;
}
int query(int x,int y)
{
    int ans=inf;
    for(int i=0;i<m;i++)
    {
        init();
        for(int j=i;j<m;j++)
        {
            int a=find(f[j].a),b=find(f[j].b);
            if(find(a)!=find(b))
                merg(a,b);
            if(find(x)==find(y))
            {
                if(ans>f[j].w-f[i].w)
                    ans=f[j].w-f[i].w;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<m;i++)
            cin>>f[i].a>>f[i].b>>f[i].w;
        int q;
        sort(f,f+m,cmp);
        cin>>q;
        for(int j=0;j<q;j++)
        {
            int x,y,z;
            cin>>x>>y;
            z=query(x,y);
            if(z==inf)
                cout<<"-1"<<endl;
            else
                cout<<z<<endl;
        }
    }
    return 0;
}
