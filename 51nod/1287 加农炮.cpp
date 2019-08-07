#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Min(x,y) y<x?x=y:x=x
const int maxn=50007;
int n,m;
struct node{
    int l,r;
    ll lazy,sum;
    void update(ll x){
        sum+=x*(r-l+1); // 更新懒结点，一般的题目只要修改这儿就行了
        lazy+=x;
    }
}tree[maxn*4];
ll a[maxn];
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
    if(l==r){
        tree[x].sum=a[l];
        return ; /// 根据题目要求
    }
    else{
        int mid=(L+R)>>1;
        if(mid>= val)
        update(x<<1,l,mid,val);
        else
        update(x<<1|1,mid+1,r,val);
        push_up(x);
    }
}
int query(int x,int l,int r,int val){
    int L=tree[x].l,R=tree[x].r;
    if(l==r){
        return l; /// 根据题目要求
    }4
    else{
        int ans;
        int mid=(L+R)>>1;
        if(tree[x<<1].sum >= val)
        query(x<<1,l,mid,val);
        else
        query(x<<1|1,mid+1,r,val);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    built(1,1,n);
    for(int i=0,t;i<m;i++){
        cin>>t;
        if(t<=a[1] || t>tree[1].sum){
            continue;
        }
        int j=query(1,1,n,t);
        //cout<<j<<endl;
        a[j-1]++;
        update(1,1,n,j-1);
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
/***
4 4
1 2 0 4
2 1 3 3

*/
