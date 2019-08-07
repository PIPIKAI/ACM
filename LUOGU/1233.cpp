#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
bool vis[5100];
int n,m;
struct node
{
    int l,w;
}f[5100];
bool cmp(node a,node b)
{
    if(a.l==b.l)
        return a.w>b.w;
    return a.l>b.l;
}
int main()
{
    std::ios::sync_with_stdio(false);
    mem(vis,0);
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
        cin>>f[i].l>>f[i].w;
    sort(f,f+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            int t=f[i].w;
            for(int j=i+1;j<n;j++)
            {
                if(t>=f[j].w&&!vis[j])
                {
                    vis[j]=1;
                    t=f[j].w;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    if(!vis[i])
    ans++;
    cout<<ans<<endl;
    return 0;
}
