#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
#include<set>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 4e5+7;
int n;
ll x[maxn],y[maxn],a[3],b[3],c[3],m[3];
ll l[maxn],r[maxn];
struct node{
    int l,r;
    ll lazy,sum;
    void update(ll x){
        sum+=x*(r-l+1); // 更新懒结点，一般的题目只要修改这儿就行了
        lazy+=x;
    }
}tree[maxn*4];
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
        tree[x].sum=0;
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
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    cin>>x[1]>>x[2]>>a[1]>>b[1]>>c[1]>>m[1];
    cin>>y[1]>>y[2]>>a[2]>>b[2]>>c[2]>>m[2];
    for(int i=1;i<=n;i++){
        if(i>=3){
            x[i]=(a[1]*x[i-1]+b[1]*x[i-2]+c[1])% m[1];
            y[i]=(a[2]*y[i-1]+b[2]*y[i-2]+c[2])% m[2];
        }
        l[i]=min(x[i],y[i]);
        r[i]=max(x[i],y[i]);
    }
    return 0;
}