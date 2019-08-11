#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y)  y>x? x=y: x=x
const int maxn=1e4+7;
int vis[maxn],last;
struct node{
    int l,r;
    ll sum;
    void update(ll x){
        sum=x;
    }
}tree[maxn*4];
void push_up(int x){
    //tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum; /// 根据题目要求
}
void push_down(int x){
    int lazytp=tree[x].sum;
    if(lazytp!=-1){
        tree[x<<1].update(lazytp);
        tree[x<<1|1].update(lazytp);
        tree[x].sum=-1;
    }
}
void built(int x,int l,int r){
    tree[x]=node{l,r,-1};
    if(l==r){
        return ;
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
    int po=tree[x].sum;
    if(L==R){
        if(po!=last && po!=-1){
                vis[po]++;
            }
        last=po;return ;
    }
    push_down(x);
    int mid=(L+R)>>1;
    if(mid>=l)
    query(x<<1,l,r);
    if(mid<r)
    query(x<<1|1,l,r);
}
int main(){
    std::ios::sync_with_stdio(false);
    int n,q;
    while(cin>>n){
        built(1,1,8001);
        for(int l,r,x,i=0;i<n;i++){
            cin>>l>>r>>x;
            update(1,l+1,r,x);///这里是l+1要注意，不然一直wa
        }
        last=-1;
        mem(vis,0);
        query(1,1,8001);
        for(int i=0;i<=8000;i++){
            if(vis[i]){
                cout<<i<<" "<<vis[i]<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
