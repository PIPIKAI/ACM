#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
const int maxn=5e5+7;
int f[maxn*4];
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
    for(int t,i=1;i<=n;i++){
        cin>>t;
        add(i,t);
    }
    while(m--){
        int c,x,y;
        cin>>c>>x>>y;
        if(c==1){
            add(x,y);
        }
        else{
            cout<<query(y)-query(x-1)<<endl;/// 查找(x,y)区间的和
        }
    }
    return 0;
}
