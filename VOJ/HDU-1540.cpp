#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
#include<stack>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 5e4+7;
int n,m;
struct node{
    int l,r;
    int maxl,minr;
}tree[maxn*4];
void push_up(int x){
    tree[x].maxl=max(tree[x<<1].maxl,tree[x<<1|1].maxl); /// 根据题目要求
    tree[x].minr=min(tree[x<<1].minr,tree[x<<1|1].minr);
}
void built(int x,int l,int r){
    tree[x]=node{l,r,0,n+1};
    if(l==r){
        tree[x].maxl=0;
        tree[x].minr=n+1;
        return ;
    }
    else{
        int mid=(l+r)>>1;
        built(x<<1 ,l ,mid );
        built(x<<1|1 ,mid+1 ,r );
        push_up(x);
    }
}
void update(int x,int l,int r,int val,int flag){
    int L=tree[x].l,R=tree[x].r;
    if(L==R){
        //cout<<L<<endl;
        flag ? tree[x].minr=val : tree[x].maxl=val;
    }
    else{
        int mid=(L+R)>>1;
        if(mid>=l)
        update(x<<1,l,r,val,flag);
        if(mid<r)
        update(x<<1|1,l,r,val,flag);
        push_up(x);
    }
}
ll query(int x,int l,int r,int flag){
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r){
        return flag ? tree[x].minr : tree[x].maxl;
    }
    else{
        ll ans=flag ? inf : 0;
        int mid=(L+R)>>1;
        if(mid>=l)
        ans=flag ? min(ans,query(x<<1,l,r,flag)):max(ans,query(x<<1,l,r,flag)) ;
        if(mid<r)
        ans=flag ? min(ans,query(x<<1|1,l,r,flag)):max(ans,query(x<<1|1,l,r,flag)) ;
        return ans;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m){
        int x;
        built(1,1,n);
        char c;
        stack<int> q;
        for(int i=0,tp;i<m;i++){
            cin>>c;
            if(c=='D'){
                cin>>tp;
                q.push(tp);
                x=q.top();
                update(1,x,x,x,1);
                update(1,x,x,x,0);
            }else if(c=='Q'){
                cin>>tp;
                int a=query(1,1,tp,0);
                int b=query(1,tp,n,1);
                a!=b ?cout<<b-a-1<<endl : cout<<0<<endl;
            }else if(c=='R'){
                x=q.top();
                update(1,x,x,n+1,1);
                update(1,x,x,0,0);
                q.pop();
            }
        }
    }
    return 0;
}