#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=2e5+7;
int n,m;
int f[maxn];
struct node{
    int l,r;
    ll ma;
}tree[maxn*4];
int a[maxn];
void push_up(int x){
    tree[x].ma=max(tree[x<<1].ma,tree[x<<1|1].ma);
}
void built(int x,int l,int r){
    tree[x]=node{l,r,-1};
    if(l==r){
        tree[x].ma=f[l];
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
        tree[x].ma=val;
    }
    else{
        int mid=(L+R)>>1;
        if(mid>=l)
        update(x<<1,l,r,val);
        if(mid<r)
        update(x<<1|1,l,r,val);
        push_up(x);
    }
}
ll query(int x,int l,int r){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r){
        return tree[x].ma;
    }
    else{
        ll ans=0;
        int mid=(L+R)>>1;
        if(mid>=l)
        ans=max(ans,query(x<<1,l,r));
        if(mid<r)
        ans=max(ans,query(x<<1|1,l,r) );
        return ans;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            cin>>f[i];
        }
        built(1,1,n);
        char c;
        int x,y;
        while(m--){
            cin>>c>>x>>y;
            if(c=='Q'){
                cout<<query(1,x,y)<<endl;
            }
            else if(c=='U'){
                update(1,x,x,y);
            }
        }
    }
    return 0;
}
