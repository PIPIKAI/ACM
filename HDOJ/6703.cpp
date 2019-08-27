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
#define mid (l+r)/2
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5;
int n,m;
int f[maxn],root[maxn],cnt, now;
set <int > st;
struct node {int l,r;ll sum;}T[maxn*40];
void built(int &cur,int l,int r){
    cur=++cnt;
    if(l==r){
        T[cur].sum=l;
        return;
    }
    built(T[cur].l,l,mid);
    built(T[cur].r,mid+1,r);
    T[cur].sum=min(T[T[cur].l].sum,T[T[cur].r].sum);
}
void update(int &rt,int l,int r,int d){
    T[1+cnt].l=T[rt].l;
    T[1+cnt].r=T[rt].r;
    rt=++cnt;
    if(l==r){
        T[rt].sum=inf;return ;
    }
    if(d <=mid ) update(T[rt].l,l,mid,d);
    else update(T[rt].r,mid+1,r,d);
    T[rt].sum=min(T[T[rt].l].sum,T[T[rt].r].sum);
}
int query(int rt,int l,int r,int x,int y){
    if(l>=x && r<=y){
        return T[rt].sum;
    }
    int res=inf;
    if(mid >=x){
        res=min(res,query(T[rt].l,l,mid,x,y));
    }
    if(mid < y){
        res=min(res,query(T[rt].r,mid+1,r,x,y));
    }
    return res;
}
void debug(int cur,int l,int r){
    if(l==r){
        if(l<=n)
        cout<<T[cur].sum<<" ";
        return;
    }
    debug(T[cur].l,l,mid);
    debug(T[cur].r,mid+1,r);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T_T;cin>>T_T;
    while(T_T--){
        cnt=0;
        now=0;
        int h=1e5+1;
        built(root[0],1,h);
        st.clear();
        cin>>n>>m;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>f[i];
            update(root[i],1,maxn,f[i]);//[l,r] + t  ,time++
        }
        for(int i=0;i<=n;i++){
            debug(root[i],1,h);
            cout<<endl;
        }
        while(m--){
            char c;int r,k;
            cin>>c;
            if(c=='1'){
                cin>>k;
                k^=ans;
                st.insert(f[k]);
            }else if(c=='2'){
                cin>>r>>k; // query :sum(l,r)
                r^=ans;k^=ans;
                 int res1=query(root[r],1,maxn,k,maxn);
                 int res2=inf;
                 auto it=st.lower_bound(k);
                 if(it!=st.end()){
                     res2=*it;
                 }
                 cout<<res2<<" "<<res1<<endl;
            }
        }
    }
    return 0;
}