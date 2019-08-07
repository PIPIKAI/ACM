#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
ll n,m;
ll f[100050];
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>f[i];
        }
        sort(f,f+n);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            int j=lower_bound(f,f+n,f[n-1]-f[i])-f;
            if(f[j]+f[i]>f[n-1]&&j!=n-1)
                ans=max(ans,f[j]-f[i]+f[n-1]-f[i]+f[n-1]-f[j]);
        }
            cout<<ans<<endl;
    }
    return 0;
}
