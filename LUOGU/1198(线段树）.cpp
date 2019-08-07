#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y)  y>x? x=y: x=x
ll m,p;
const int maxn=2e5+7;
int tree[maxn*4];
void update(int x,int o,int l,int r,ll val){
    if(l==r){
        tree[o]=val;
        return ;
    }
    else{
        int mid=(l+r)>>1;
        if(mid>=x)
        update(x,o<<1,l,mid,val);
        if(mid<x)
        update(x,o<<1|1,mid+1,r,val);
        tree[o]=max(tree[o<<1],tree[o<<1|1]);
    }
}
ll query(int lr,int rr,int o,int l,int r){
    if(lr<=l&&rr>=r){
        return tree[o];
    }
    else{
        ll a=-2147483647;
        ll b=-2147483647;
        int mid=(l+r)>>1;
        if(mid>=lr)
        a=max(a,query(lr,rr,o<<1,l,mid) );
        if(mid<rr)
        b=max(b,query(lr,rr,o<<1|1,mid+1,r) );
        return max(a,b);
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    cin>>m>>p;
    ll qq=0,cnt=0;
    for(int i=0;i<m;i++){
        char c;
        ll t;
        cin>>c>>t;
        if(c=='Q'){
            if(t==0){
                cout<<0<<endl;
                continue;
            }
            qq=query(cnt-t+1,cnt,1,1,m)%p;
            cout<<qq<<endl;
        }
        else{
            update(1+cnt, 1,1,m, (t+qq)%p);
            cnt++;
        }
    }
    return 0;
}
