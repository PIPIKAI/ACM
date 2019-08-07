#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m,k;
ll f[100050];
ll cnt[100050];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll t;
        cin>>t;
        f[i]=(f[i-1]+t)%k;
        ans+=cnt[f[i]];
        cnt[f[i]]++;
    }
    cout<<cnt[0]+ans<<endl;
    return 0;
}
/**
5 2
1 2 3 4 5
*/
