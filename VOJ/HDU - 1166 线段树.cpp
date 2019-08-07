#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
const int maxn=5e4+7;
#define read(x) x=read()
int n;
int f[maxn];
struct node{
    int l,r;
    ll lazy,sum;
    void update(ll x){
        sum+=x*(r-l+1);
        lazy+=x;
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
int a[maxn];
void built(int x,int l,int r){
    tree[x]=node{l,r,0,0};
    if(l==r){
        tree[x].sum=f[l];
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
        mem(f,0);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>f[i];
        }
        built(1,1,n);
        string ts;
        int x,y;
        cout<<"Case "<<ca<<":"<<endl;
        while(cin>>ts && ts!="End"){
            cin>>x>>y;
            if(ts=="Query"){
                cout<<query(1,x,y)<<endl;
            }
            else if(ts=="Add"){
                update(1,x,x,y);
            }
            else if(ts=="Sub"){
                update(1,x,x,-y);
            }
        }
    }
    return 0;
}
