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
const int maxn = 1e5+9;
int n,m;
int f[maxn],root[maxn],cnt, now;
set <int > st;
struct node {int l,r;ll sum;}T[maxn*40];
void built(int &cur,int l,int r){
    cur=++cnt;
    if(l==r){
        T[cur].sum=l;
        return ;
    }
    built(T[cur].l,l,mid);
    built(T[cur].r,mid+1,r);
    T[cur].sum=min(T[T[cur].l].sum,T[T[cur].r].sum);
}
void update(int l,int r,int &x,int y,int pos){
    T[++cnt]=T[y];x=cnt;
    if(l==r){
        T[x].sum=inf;
        return ;
    }
    if(mid>= pos){
        update(l,mid,T[x].l,T[y].l,pos);
    }
    else{
        update(mid+1,r,T[x].r,T[y].r,pos);
    }
    T[x].sum=min(T[T[x].l].sum,T[T[x].r].sum);
}
int query(int rt,int l,int r,int x,int y){
    if(l>=x && r<=y){
        return T[rt].sum;
    }
    int ans=inf;
    if(mid>=x){
        ans=min(ans,query( T[rt].l,l,mid ,x,y) );
    }
    if(mid < y){
        ans=min(ans,query( T[rt].r,mid+1,r ,x,y) );
    }
    return ans;
}
void debug(int rt,int l,int r){
    if(l==r) {
        if(l<=n)
        cout<<T[rt].sum<<" ";return ;
    }
    debug(T[rt].l,l,mid);
    debug(T[rt].r,mid+1,r);
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T_T;cin>>T_T;
    int h=1e5+1;
    while(T_T--){
        cnt=0;
        now=0;
        st.clear();
        cin>>n>>m;
        built(root[0],1,h);
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>f[i];
            update(1,h,root[i],root[i-1],f[i]);//[l,r] + t  ,time++
        }
        // for(int i=1;i<=n;i++){
        //     debug(root[i],1,h);//[l,r] + t  ,time++
        //     cout<<endl;
        // }
        while(m--){
            char c;int r,k;
            cin>>c;
            if(c=='1'){
                cin>>k;
                k^=ans;
                st.insert(f[k]);
            }else if(c=='2'){
                cin>>r>>k; 
                r^=ans;k^=ans;
                 int res1=query(root[r],1,h,k,h);
                 int res2=inf;
                 auto it=st.lower_bound(k);
                 if(it!=st.end()){
                     res2=*it;
                 }
                 ans=min(res1,res2);
                 cout<<ans<<endl;
            }
        }
    }
    return 0;
}