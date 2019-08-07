#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+10
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
ll n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    ll ans=0;
    ll minn=inf;
    //cout<<minn<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll t;
        cin>>t;
        minn=min(t,minn);
        ans+=t;
    }
    cout<<ans+(n-2)*minn<<endl;
    return 0;
}
