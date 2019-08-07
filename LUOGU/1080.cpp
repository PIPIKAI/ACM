#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
ll n,m;
ll a,b,ans;
const int maxn=1e3+7;
struct node
{
    ll l,r;
    bool  operator < (node t)
    {
        return  l*r<t.l*t.r;
    }
}f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    cin>>a>>b;
    for(int i=0;i<n;i++){
        cin>>f[i].l>>f[i].r;
    }
    sort(f,f+n);
    for(int i=0;i<n;i++){

        ans=max(ans,a/f[i].r );
        a*=f[i].l;
    }
    cout<<ans<<endl;
    return 0;
}
