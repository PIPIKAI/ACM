#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	ll n,j=0,ans=0;
	cin>>n>>ans; j=ans;
	for(ll i=1;i<n;i++)
    {
        ll t;
        cin>>t;
       j=j>0?j:0;
        j+=t;
        ans=ans>j?ans:j;
    }
    cout<<ans<<endl;
   return 0;
}
