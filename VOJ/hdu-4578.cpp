#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
const ll mod=10007;
int n,m;
int op,x,y;
ll v;
ll sum[maxn<<2][3],mul[maxn<<2],add[maxn<<2],che[maxn<<2];
void build(int root,int l,int r)
{
    sum[root][0]=sum[root][1]=sum[root][2]=0;
    mul[root]=1; add[root]=0; che[root]=0;
    if(l==r) return;
    int mid=l+r>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
}
void up(int root)
{
    for(int i=0;i<3;i++)
        sum[root][i]=(sum[root<<1][i]+sum[root<<1|1][i])%mod;
}
void up1(int root,ll c,int l,int r)
{
    int len=r-l+1;
    sum[root][2]=(sum[root][2]+c*c%mod*c%mod*len%mod+3*c*sum[root][1]%mod+3*c*c%mod*sum[root][0]%mod)%mod;
    sum[root][1]=(sum[root][1]+c*c%mod*len%mod+2*c*sum[root][0]%mod)%mod;
    sum[root][0]=(sum[root][0]+c*len)%mod;
}
void up2(int root,ll c)
{
    sum[root][2]=sum[root][2]*c%mod*c%mod*c%mod;
    sum[root][1]=sum[root][1]*c%mod*c%mod;
    sum[root][0]=sum[root][0]*c%mod;
}
void up3(int root,ll c,int l,int r)
{
    int len=r-l+1;
    sum[root][0]=c*len%mod;
    sum[root][1]=c*c%mod*len%mod;
    sum[root][2]=c*c%mod*c%mod*len%mod;
}
void down(int root,int l,int r)
{
    int lr=root<<1,rr=root<<1|1;
    int mid=l+r>>1;
    if(che[root])
    {
        che[lr]=che[rr]=che[root];
        mul[lr]=mul[rr]=1;
        add[lr]=add[rr]=0;
        ll c=che[root];
        up3(lr,c,l,mid);
        up3(rr,c,mid+1,r);
        che[root]=0;
    }
    if(mul[root]!=1)
    {
        mul[lr]=mul[lr]*mul[root]%mod;
        mul[rr]=mul[rr]*mul[root]%mod;
        if(add[lr]) add[lr]=add[lr]*mul[root]%mod;
        if(add[rr]) add[rr]=add[rr]*mul[root]%mod;
        up2(lr,mul[root]);
        up2(rr,mul[root]);
        mul[root]=1;
    }
    if(add[root])
    {
        add[lr]=(add[lr]+add[root])%mod;
        add[rr]=(add[rr]+add[root])%mod;
        up1(lr,add[root],l,mid);
        up1(rr,add[root],mid+1,r);
        add[root]=0;
    }
}
void updata(int root,int nowa,int nowb,int l,int r,int p,int c)
{
    if(nowb<l||r<nowa) return;
    if(l<=nowa&&nowb<=r)
    {
        if(p==3)
        {
            up3(root,c,nowa,nowb);
            mul[root]=1; add[root]=0; che[root]=c;
        }
        else if(p==2)
        {
            up2(root,c);
            mul[root]=mul[root]*c%mod;
            if(add[root]) add[root]=add[root]*c%mod;
        }
        else
        {
            up1(root,c,nowa,nowb);
            add[root]=(add[root]+c)%mod;
        }
 
 
        return ;
    }
    down(root,nowa,nowb);
    int mid=(nowa+nowb)/2;
    updata(root<<1,nowa,mid,l,r,p,c);
    updata(root<<1|1,mid+1,nowb,l,r,p,c);
    up(root);
}
ll query(int root,int nowa,int nowb,int l,int r,int p)
{
    if(nowb<l||r<nowa) return 0;
    if(l<=nowa&&nowb<=r) return sum[root][p]%mod;
    down(root,nowa,nowb);
    ll ans=0;
    int mid=(nowa+nowb)/2;
    ans+=query(root<<1,nowa,mid,l,r,p)%mod;
    ans+=query(root<<1|1,mid+1,nowb,l,r,p)%mod;
    return (ans+mod)%mod;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        build(1,1,n);
        while(m--)
        {
            scanf("%d%d%d%lld",&op,&x,&y,&v);
            if(op<=3) updata(1,1,n,x,y,op,v);
            else printf("%lld\n",query(1,1,n,x,y,v-1));
        }
    }
    return 0;
}
 