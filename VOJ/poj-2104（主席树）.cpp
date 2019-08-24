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
#define mid   (l+r)/2
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m,k;
int f[maxn],li[maxn],T[maxn<<5],L[maxn<<5],R[maxn<<5],sum[maxn<<5],cnt,tot;
int built(int l,int r){
    int rt=++cnt;
    sum[rt]=0;
    if(l<r){
        L[rt]=built(l,mid);
        R[rt]=built(mid+1,r);
    }
    return rt;
}
int update(int pre,int l,int r,int x){
    int rt=++cnt;
    L[rt]=L[pre];
    R[rt]=R[pre];
    sum[rt]=sum[pre]+1;
    if(l<r){
        if(x<=mid){
            L[rt]=update(L[pre],l,mid,x);
        }
        else{
            R[rt]=update(R[pre],mid+1,r,x);
        }
    }
    return rt;
}
int query(int from,int to,int l,int r,int k){
    if(l>=r) return l;
    int c=sum[L[to]]-sum[L[from]];
    if(c>=k){
        return query(L[from],L[to],l,mid,k);
    }
    else{
        return query(R[from],R[to],mid+1,r,k-c);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            cin>>f[i];
            li[i]=f[i];
        }
        sort(li+1,li+1+n);
        tot=unique(li+1,li+1+n)-li-1;
        T[0]=built(1,tot);
        for(int i=1;i<=n;i++){
            int x=lower_bound(li+1,li+1+tot,f[i])-li;
            T[i]=update(T[i-1],1,tot,x);
        }
        while(m--){
            int l,r,k;
            cin>>l>>r>>k;
            int t=query(T[l-1],T[r],1,tot,k);
            cout<<li[t]<<endl;
        }
    }
    return 0;
}