#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
ll n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    ll ans=inf,id=0;
    for(ll t,i=1;i<=n;i++){
        cin>>t;
        ans=min( ans, min(t/max((ll) 1 ,i-1) , t/max((ll) 1 ,n-i)) );
    }
    cout<<ans<<endl;
    return 0;
}
