#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lson l,(l+r)/2
#define rson (l+r)/2+1,r
#define L tree[x].l
#define R tree[x].r
#define Max(x,y) y>x?x=y:x=x
const int maxn=5e5+7;
const int inf=0x3f3f3f3f;
struct node{
    int l,r,len;
    bool operator < (node a){
        return len<a.len;
    }
}f[maxn<<3];
struct TREE{
    int l,r;
    ll sum,lazy;
    void push_down(int x){
        sum+=x;
        lazy+=x;
    }
}tree[maxn<<3];
void push_up(int x){
    tree[x].sum=max(tree[x<<1].sum,tree[x<<1|1].sum);
}
void built(int x,int l,int r){
    tree[x]=TREE{l,r,0,0};
    if(l==r){
        return;
    }
    built(x<<1,lson);
    built(x<<1|1,rson);
}
void push_down(int x){
    int tp=tree[x].lazy;
    if(tp){
        tree[x<<1].push_down(tp);
        tree[x<<1|1].push_down(tp);
        tree[x].lazy=0;
    }
}
void update(int x,int l,int r,int val){
    int mid=(L+R)>>1;
    if(L >=l && R<=r){
        tree[x].sum+=val;
        tree[x].lazy+=val;
    }
    else{
        push_down(x);
        if(mid >= l)
            update(x<<1,l,r,val);
        if(mid < r)
            update(x<<1|1,l,r,val);
        push_up(x);
    }
}
vector<int> ls;
int get_id(int x){
    return upper_bound(ls.begin(),ls.end(),x)-ls.begin();
}
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>f[i].l>>f[i].r;
        ls.push_back(f[i].l);ls.push_back(f[i].r);
        f[i].len=f[i].r-f[i].l;
    }
    sort(ls.begin(),ls.end());
    ls.erase(unique(ls.begin(),ls.end()),ls.end());
    sort(f,f+n);
    int tn=0;
    for(int i=0;i<n;i++){
        f[i].l=get_id(f[i].l);
        f[i].r=get_id(f[i].r);
        Max(tn,f[i].l);Max(tn,f[i].r);
    }
    built(1,1,tn);
    ll l=0,ans=inf;
    for(int i=0;i<n;i++){
        update(1,f[i].l,f[i].r,1);
        while(tree[1].sum>=m && l<n){
            ans=min(ans, ll (f[i].len-f[l].len));
            update(1,f[l].l,f[l].r,-1);
            l++;
        }
    }
    if(ans!=inf)
    cout<<ans<<endl;
    else
    cout<<-1<<endl;
    return 0;
}