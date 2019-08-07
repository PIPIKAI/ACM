#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m,ans;
ll f[100050];
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
        ans=0;
        ll minn=1e9;
        for(int i=0;i<n;i++)
        {
            cin>>f[i];
            minn=min(minn,f[i]);
        }
        for(int i=0;i<n;i++)
            ans+= (f[i]-minn);
        cout<<ans<<endl;
    }
    return 0;
}
