#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,q;
const int maxn=1e5+7;
struct node{
    int l,r;
    ll lazy,sum;
    void update(ll x){
        sum=x*(r-l+1);
        lazy=x;
    }
}tree[maxn*4];
void push_up(int x){
    tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
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
    tree[x]=node{l,r,0,0};
    if(l==r){
        tree[x].sum=1;
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
        tree[x].update(val);
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
ll query(int x,int l,int r){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r){
        return tree[x].sum;
    }
    else{
        push_down(x);
        ll ans=0;
        int mid=(L+R)>>1;
        if(mid>=l)
        ans+=query(x<<1,l,r);
        if(mid<r)
        ans+=query(x<<1|1,l,r);
        push_up(x);
        return ans;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,ca=0;
    cin>>t;
    while(t--){
        ca++;
        cin>>n>>q;
        built(1,1,n);
        for(int i=0,x,y,z;i<q;i++){
            cin>>x>>y>>z;
            update(1,x,y,z);
        }
        cout<<"Case "<<ca<<": The total value of the hook is "<<query(1,1,n)<<"."<<endl;
    }
    return 0;
}
