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
const int maxn = 2e5+7;
int n,m;
int f[maxn],li[maxn];
int T[maxn<<5],R[maxn<<5],L[maxn<<5],cnt,sum[maxn<<5];
int built(int l,int r){
    int rt=++cnt;
    sum[rt]=0;
    if(l<r){
        L[rt]=built(l,mid);
        R[rt]=built(mid+1,r);
    }
    return rt;
}
int update(int pre,int l,int r,int tp){
    int rt=++cnt;
    L[rt]=L[pre];
    R[rt]=R[pre];
    sum[rt]=sum[pre]+1;
    if(l<r){
        if(tp<=mid){
            L[rt]=update(L[pre],l,mid,tp);
        }else{
            R[rt]=update(R[pre],mid+1,r,tp);
        }
    }
    return rt;
}
int query(int u,int v,int l,int r,int k){
    if(l>=r) return l;
    int x=sum[L[v]]-sum[L[u]];
    if(x>=k){
        return query(L[u],L[v],l,mid,k);
    }
    else{
        return query(R[u],R[v],mid+1,r,k-x);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>f[i];li[i]=f[i];
    }
    sort(li+1,li+n+1);
    int tot=unique(li+1,li+1+n)-li-1;
    T[0]=built(1,tot);
    for(int i=1;i<=n;i++){
        int tp=lower_bound(li+1,li+tot+1,f[i])-li;
        T[i]=update(T[i-1],1,tot,tp);
    }
    while(m--){
        int l,r,k;
        cin>>l>>r>>k;
        int t=query(T[l-1],T[r],1,tot,k);
        cout<<li[t]<<endl;
    }
    return 0;
}