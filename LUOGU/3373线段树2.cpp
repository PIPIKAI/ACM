#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
inline int ls(int p){return p<<1;}///左儿子
inline  int rs(int p){return p<<1|1;}///右儿子
const int maxn=100011;
int n,m,f[maxn],mod;
struct node
{
    ll l,r,p,add,mul;
}t[maxn*4];
void built(int p,int l,int r)
{
    t[p]=node{l,r,0,0,1};
    if(l==r)
    {
        t[p].p=f[l];return ;
    }
    int mid=(l+r)>>1;
    built(ls(p),l,mid);
    built(rs(p),mid+1,r);
    t[p].p=(t[ls(p)].p+t[rs(p)].p)%mod;
}
/// 懒标记
void spread(int p)
{
    if(t[p].add)
    {
        t[ls(p)].p+=t[p].add*(t[ls(p)].r-t[ls(p)].l+1);
        t[rs(p)].p+=t[p].add*(t[rs(p)].r-t[rs(p)].l+1);
        ///下传
        t[ls(p)].add+=t[p].add;///把左右儿子打上懒标记
        t[rs(p)].add+=t[p].add;
        t[p].add=0;///下传之后将该节点的懒标记清0
    }
}
void change(int p,int x,int y,ll z,int cc)
{
    spread_add(p);
    if(cc==1&&x<=t[p].l&&y>=t[p].r)///乘
    {
        t[p].add=(t[p].add*z)%mod;
        t[p].mul=(t[p].mul*z)%mod;
        t[p].p=(t[p].p*t[p].mul)%mod;
        return ;
    }
    if(cc==2&&x<=t[p].l&&y>=t[p].r)
    {
        t[p].add=(t[p].add+z)%mod;
        t[p].p=(t[p].p+t[p].add*(t[p].r-t[p].l+1))%mod;
    }
    int mid=((t[p].l+t[p].r)>>1);
    if (x<=mid) change(ls(p),x,y,z,cc);
    if (y>mid) change(rs(p),x,y,z,cc);
    t[p].p=(t[ls(p)].p+t[rs(p)].p)%mod;
}

ll ask(int p,int x,int y)
{
    if(x<=t[p].l&&y>=t[p].r) return t[p].p;
    ///spread(p);///下传懒标记，并查询左右儿子
    int mid=((t[p].l+t[p].r)>>1);
    ll ans=0;
    if (x<=mid) ans=(ans+ask(ls(p),x,y))%mod;
    if (y>mid)  ans=(ans+ask(rs(p),x,y))%mod;
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>mod;
    for(int i=1;i<=n;i++) cin>>f[i];
    built(1,1,n);
    while(m--)
    {
        int flag,x,y,k;
        cin>>flag;
        if(flag==3)
        {
            cin>>x>>y;
            cout<<ask(1,x,y)%mod;
        }
        else
        {
            cin>>x>>y>>k;
            change(1,x,y,k,flag);
        }
    }
    return 0;
}
