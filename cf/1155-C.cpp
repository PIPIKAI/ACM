#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
const int maxn=3e5+7;
ll n,m;
ll f[maxn];
struct node
{
    ll v,id;
}k[maxn];
bool cmp(node a,node b)
{
    return a.v<b.v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    ll kk;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    for(int i=1;i<=m;i++){
        cin>>k[i].v;
        k[i].id=i;
    }
    kk=f[2]-f[1];
    for(int i=2;i<=n;i++){
        ll t=f[i]-f[i-1];
        kk=__gcd(kk,t);
    }
    sort(k+1,k+m+1,cmp);
    ll ans;
    bool flag=0;
    for(int i=1;i<=m;i++){
        if(kk < k[i].v){
            break;
        }
        if( 0==kk%k[i].v){
            flag=1;
            ans=k[i].id;
            break;
        }
    }
    flag ? cout<<"YES"<<endl<<f[1]<<" "<<ans<<endl :cout<<"NO"<<endl;
    return 0;
}
