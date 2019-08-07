#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=0;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
    	ans=0;
    	ll n;
    	cin>>n;
    	ans =n*n-(n+1)*n/2;
    	cout<<ans<<endl;
    }
    return 0;
}
