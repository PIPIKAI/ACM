#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn = 5e5+7;
ll n,m,c[maxn*8],tot=0;
ll a[maxn*8];
struct  pt
{
    int l,r,len;   /* data */
    const bool operator<(pt x)const{
        return x.len>len;
    }
}f[maxn*8];
struct node{
    int l,r;
    ll lazy,sum;
    void update(ll x){
        sum+=x; // 更新懒结点，一般的题目只要修改这儿就行了
        lazy+=x;
    }
}tree[maxn*8];
void push_up(int x){
    tree[x].sum=max(tree[x<<1].sum,tree[x<<1|1].sum); /// 根据题目要求
}
void push_down(int x){
    int lazytp=tree[x].lazy;
    if(lazytp){
        tree[x<<1].update(lazytp);
        tree[x<<1|1].update(lazytp);
        tree[x].lazy=0;
    }
}
void built(int x,int l,int r){
    tree[x].l=l;tree[x].r=r;
    if(l==r){
        return;
    }
    else{
        int mid=(l+r)>>1;
        built(x<<1 ,l ,mid );
        built(x<<1|1 ,mid+1 ,r );
    }
}
void update(int x,int l,int r,ll val){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r){
        tree[x].lazy+=val;
        tree[x].sum+=val;
    }
    else{
        push_down(x);
        int mid=(L+R)>>1;
        if(mid>=l)
        update(x<<1,l,r,val);
        if(mid<r)
        update(x<<1|1,l,r,val);
        push_up(x);
    }
}
void init(){
    //freopen("testdate.in",in,stdin)
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i].l>>f[i].r;
        f[i].len=f[i].r-f[i].l;
        c[++tot]=f[i].l;
        c[++tot]=f[i].r;
    }
    if(m>n){
        cout<<-1<<endl;
        exit(-1);
    }
    sort(f+1,f+n+1);
    sort(c+1,c+1+tot);
    tot=unique(c+1,c+1+tot)-c-1;///离散化去重
    ll minn=inf,maxx=-inf+1;
    for(int i=1;i<=n;i++){
        f[i].l=lower_bound(c+1,c+1+tot,f[i].l)-c;
        minn=min(minn,(ll)f[i].l);
        f[i].r=lower_bound(c+1,c+1+tot,f[i].r)-c;
        maxx=max(maxx,(ll)f[i].r);
    }
    built(1,minn,maxx);
}
int main()
{
    std::ios::sync_with_stdio(false);
    init();
    
    ll l=1,ans=inf;
    for(int i=1;i<=n&&l<=n;i++){
        update(1,f[i].l,f[i].r,1);
        while(tree[1].sum>=m&&l<=n){
            ans=min(ans,ll(f[i].len-f[l].len));
            update(1,f[l].l,f[l].r,-1);
            l++;
        }
    }
    if(ans==inf){
        cout<<-1<<endl;
    }else{
        cout<<ans<<endl;
    }
    return 0;
}