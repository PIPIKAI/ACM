#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
const int maxn=5e5+7;
int f[maxn],b[maxn];
int lowbit(int x){
    return x&(-x);
}
ll query(int x){
    ll ans=0;
    while(x){
        ans+=f[x];
        x-=lowbit(x);
    }
    return ans;
}
ll add(int x,int val){
    ll ans=0;
    while(x<=n){
        f[x]+=val;
        x+=lowbit(x);
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int t,p=0,i=1;i<=n;i++){
        cin>>t;
        add(i,f[i]-f[i-1]); /// 差分
    }
    while(m--){
        int c,x,y,k;
        cin>>c;
        if(c==1){
            cin>>x>>y>>k; /// 在x,y区间上加k
            add(x,k);
            add(y+1,-k);
        }
        else{
            cin>>x;
            cout<<query(x)<<endl;/// 单点查询
        }
    }
    return 0;
}
