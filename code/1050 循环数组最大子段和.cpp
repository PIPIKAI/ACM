#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[50002],dp[55000],b[50002];
int main()
{
    ll n,ans1=0,ans2=0,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>f[i],sum+=f[i],b[i]=-f[i];
    ll x=0,y=0;
    for(int i=0;i<n;i++)
    {
        x=(x+f[i])>0?(x+f[i]):0;
        y=(y+b[i])>0?(y+b[i]):0;
        ans1=max(ans1,x);
        ans2=max(ans2,y);
    }
    ans1=max(ans1,sum+ans2);
    cout<<ans1<<endl;
    return 0;
}

