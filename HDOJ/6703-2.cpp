#define bug(x) cout<<#x<<" is "<<x<<endl
#define IO std::ios::sync_with_stdio(0)
#include <bits/stdc++.h>
#define iter ::iterator
#define pa pair<int,ll>
using namespace  std;
#define ll long long
#define mk make_pair
#define pb push_back
#define se second
#define fi first
ll mod=998244353;
const int N=1e5+50;
int a[N],rt[N],minv[N*20],ls[N*20],rs[N*20],n,m;
int cnt,tot;
void build(int &o,int l,int r){
    o=++tot;
    if(l==r){
        minv[o]=l;
        return;
    }
    int m=(l+r)/2;
    build(ls[o],l,m);
    build(rs[o],m+1,r);
    minv[o]=min(minv[ls[o]],minv[rs[o]]);
}
void up(int &o,int pre,int l,int r,int p){
    o=++cnt;
    ls[o]=ls[pre];
    rs[o]=rs[pre];
    if(l==r){
        minv[o]=1e9;
        return;
    }
    int m=(l+r)/2;
    if(p<=m)up(ls[o],ls[pre],l,m,p);
    else up(rs[o],rs[pre],m+1,r,p);
    minv[o]=min(minv[ls[o]],minv[rs[o]]);
}
int qu(int o,int l,int r,int ql,int qr){
    if(l>=ql&&r<=qr){
        return minv[o];
    }
    int m=(l+r)/2;
    int res=1e9;
    if(ql<=m)res=min(res,qu(ls[o],l,m,ql,qr));
    if(qr>m)res=min(res,qu(rs[o],m+1,r,ql,qr));
    return res;
}
void debug(int o,int l,int r){
    if(l==r){
        if(l<=n)
        cout<<minv[o]<<" ";
        return;
    }
    int mid=(l+r)/2;
    debug(ls[o],l,mid);
    debug(rs[o],mid+1,r);
}
int T,q;
int main(){
    scanf("%d",&T);
    int h=1e5+1;
    build(rt[0],1,h);
    
    while(T--){
        scanf("%d%d",&n,&q);
        debug(rt[0],1,h),printf("\n");
        cnt=tot;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            up(rt[i],rt[i-1],1,h,a[i]);
        }
        for(int i=1;i<=n;i++)
        debug(rt[i],1,h),printf("\n");
        int t,x,y,ans=0;
        set<int>s;
        while(q--){
            scanf("%d%d",&t,&x);
            x^=ans;
            if(t==1)s.insert(a[x]);
            else{
                scanf("%d",&y);
                y^=ans;
                int res1=qu(rt[x],1,h,y,h);
                int res2=1e9;
                auto it=s.lower_bound(y);
                if(it!=s.end())res2=*it;
                ans=min(res1,res2);
                printf("%d\n",ans);
            }
        }
    }
}