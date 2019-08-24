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
int f[maxn],li[maxn],T[maxn*20],L[maxn*20],R[maxn*20],sum[maxn*20],cnt,tot;
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
int query(int x,int l,int r,int k){
    if(r<=k) return sum[x];
    int ans=query(L[x],l,mid,k);
    if(k>mid) ans+= query(R[x],mid+1,r,k);
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,ca=0;cin>>t;
    while(t--){
        cin>>n>>m;
        cnt=0;
        mem(sum,0);
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
        cout<<"Case "<<++ca<<": "<<endl;
        while(m--){
            int l,r,k,h;
            cin>>l>>r>>h;
            k=upper_bound(li+1,li+1+n,h)-li;
            k--;
            if(!k) cout<<0<<endl;
            else
            cout<<query(T[r+1],1,tot,k)-query(T[l],1,tot,k)<<endl;
        }
    }
    return 0;
}