#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100005],n,k,sum=0,ans=1e9+7;
int main()
{
    cin>>n>>k;
    sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
        sum+=f[i];
    }
    for(int i=0;i<=k;i++)
    {
        ll cnt=0;
        for(int j=i;j<n;j+=(k+1))
        {
            cnt+=f[j];
        }
        ans=min(ans,cnt);
    }
    cout<<sum-ans<<endl;
    return 0;
}
