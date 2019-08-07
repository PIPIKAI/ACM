#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[50002],dp[55000];
int main()
{
    ll n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i];
    for(int i=0;i<n;i++)
    {        dp[i]=max( dp[i-1] ,(ll)0)+f[i];
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
