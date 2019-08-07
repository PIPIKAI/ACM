#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y)  y>x? x=y: x=x
const int maxn=1e5+7;
struct node{
    int l,r;
    ll lazy,sum;
    void update(ll x){
        sum+=x*(r-l+1); // 更新懒结点，一般的题目只要修改这儿就行了
        lazy+=x;
    }
}tree[maxn*4];
int a[maxn];
void push_up(int x){
    tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum; /// 根据题目要求
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
        tree[x].sum=a[l];
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
        return tree[x].sum; /// 根据题目要求
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
int main(){
    std::ios::sync_with_stdio(false);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    built(1,1,n);
    while(q--){
        int c,l,r,k;
        cin>>c>>l>>r;
        if(c==1){
            cin>>k;
            update(1,l,r,k);
        }
        else{
            cout<<query(1,l,r)<<endl;
        }
    }
    return 0;
}
