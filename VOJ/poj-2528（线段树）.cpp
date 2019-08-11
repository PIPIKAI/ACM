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
const int inf=0x7fffffff;
const int maxn = 1e4+7;
int n,m,ans;
struct nod{
    int l,r;
}f[maxn];
int tot[maxn<<4],cnt=0,vis[maxn<<4];
struct node{
    int l,r;
    ll lazy,sum;
    void update(ll x){
        sum=x;
    }
}tree[maxn<<5];
void push_up(int x){
    //tree[x].sum=(tree[x<<1].sum ==tree[x<<1|1].sum ? tree[x<<1].sum : -1); /// 根据题目要求
}
void push_down(int x){
    int lazytp=tree[x].sum;
    if(lazytp){
        tree[x<<1].update(lazytp);
        tree[x<<1|1].update(lazytp);
        tree[x].sum=0;
    }
}
void built(int x,int l,int r){
    tree[x]=node{l,r,0,0};
    if(l==r){
        return;
    }
    else{
        int mid=(l+r)>>1;
        built(x<<1 ,l ,mid );
        built(x<<1|1 ,mid+1 ,r );
        push_up(x);
    }
}
void update(int x,int l,int r,int val){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r){
        tree[x].sum=val;
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
void query(int x,int l,int r){
    int L=tree[x].l,R=tree[x].r;
    if(!vis[tree[x].sum]){
        vis[tree[x].sum]=1;
        //cout<<tree[x].sum<<endl;
        ans++;
        return ;
    }
    if(L==R) return ;
    push_down(x);
    int mid=(L+R)>>1;
    if(mid>=l)
    query(x<<1,l,r);
    if(mid<r)
    query(x<<1|1,l,r);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        mem(tree,0);
        mem(vis,0);
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>f[i].l>>f[i].r;
            tot[++cnt]=f[i].l;
             tot[++cnt]=f[i].r;
        }
        sort(tot+1,tot+1+cnt);
        int tp=cnt=unique(tot+1,tot+1+cnt)-tot;
        for(int i=1;i<=tp;i++){
            if(tot[i]-tot[i-1]>1){
                tot[++cnt]=(tot[i-1]+1);
            }
        }
        sort(tot+1,tot+1+cnt);
        built(1,1,cnt);
        for(int i=1;i<=n;i++){
            int l=lower_bound(tot+1,tot+cnt+1,f[i].l)-tot;
            int r=lower_bound(tot+1,tot+cnt+1,f[i].r)-tot;
            update(1,l,r,i);
        }
         ans=0;
         vis[0]=1;
        query(1,1,cnt);
        cout<<ans<<endl;
    }
    
    return 0; 
}