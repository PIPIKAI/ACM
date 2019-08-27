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
#define mid (l+r)/2
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m;
int f[maxn],root[maxn],cnt, now;
struct node {int l,r;ll sum,lazy;}T[maxn*40];
void built(int &cur,int l,int r){
    cur=++cnt;
    T[cur].lazy=0;
    if(l==r){
        T[cur].sum=f[l];
        return;
    }
    built(T[cur].l,l,mid);
    built(T[cur].r,mid+1,r);
    T[cur].sum=T[T[cur].l].sum+T[T[cur].r].sum;
}
void update(int &rt,int l,int r,int x,int y,int d){
    T[++cnt]=T[rt];
    rt=cnt;
    T[rt].sum+= 1ll*(y-x+1)*d;
    if(x==l && r==y){
        T[rt].lazy+=d;return ;
    }
    if(y <=mid ) update(T[rt].l,l,mid,x,y,d);
    else if(x<=mid) update(T[rt].l,l,mid,x,mid,d),update(T[rt].r,mid+1,r,mid+1,y,d);
    else update(T[rt].r,mid+1,r,x,y,d);
}
ll query(int rt,int l,int r,int x,int y){
    if(x==l && y== r) return T[rt].sum;
    if(y<=mid) return T[rt].lazy*(y-x+1ll)+query(T[rt].l,l,mid,x,y);
    else if(x<=mid) return T[rt].lazy*(y-x+1ll)+query(T[rt].l,l,mid,x,mid)+query(T[rt].r,mid+1,r,mid+1,y);
    else return T[rt].lazy*(y-x+1ll)+query(T[rt].r,mid+1,r,x,y);
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m){
        cnt=0;
        now=0;
        for(int i=1;i<=n;i++){
            cin>>f[i];
        }
        built(root[0],1,n);
        while(m--){
            char c;int l,r,t;
            cin>>c;
            if(c=='C'){
                cin>>l>>r>>t;
                root[now+1]=root[now];
                update(root[++now],1,n,l,r,t);//[l,r] + t  ,time++
            }else if(c=='Q'){
                cin>>l>>r; // query :sum(l,r)
                cout<<query(root[now],1,n,l,r)<<endl;
            }else if(c=='H'){
                cin>>l>>r>>t;
                cout<<query(root[t],1,n,l,r)<<endl;// query time=t :sum(l,r)
            }else if(c=='B'){
                cin>>now; // time become now
            }
        }
    }
    return 0;
}