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
const int maxn = 1e5+7;
int n,m;
struct node{
    int l,r;
    ll lazy,sum;
}tree[maxn*4];
ll a[maxn];
void push_up(int x){
    tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum; /// 根据题目要求
}
void push_down(int x){
    int L=tree[x].l,R=tree[x].r;
    if(L==R){
        tree[x].sum=sqrt(tree[x].sum*1.0);
        return ;
    }
    push_down(x<<1);
    push_down(x<<1|1);
    push_up(x);
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
void update(int x,int l,int r){
    int L=tree[x].l,R=tree[x].r;
    if(tree[x].sum==R-L+1){
        //cout<<-1<<endl;
        return; 
    }
            
    if(l<=L&&R<=r){
        push_down(x);
    }
    else{
        int mid=(L+R)>>1;
        if(mid>=l)
        update(x<<1,l,r);
        if(mid<r)
        update(x<<1|1,l,r);
        push_up(x);
    }
}
ll query(int x,int l,int r){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r){
        return tree[x].sum; /// 根据题目要求
    }
    else{
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
    int Case=0;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        built(1,1,n);
        cout<<"Case #"<<++Case<<":"<<endl;
        cin>>m;
        for(int i=0,t,x,y;i<m;i++){
            cin>>t>>x>>y;
            if(x>y) swap(x,y);
            if(t==0){
                update(1,x,y);
            }
            else if(t==1){
                cout<<query(1,x,y)<<endl;
            }
        }
        cout<<endl;//wa
    }
    return 0;
}