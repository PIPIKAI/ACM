#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[550];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    sort(f,f+n);
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        if(f[i]<=0)
        ans+=f[i];
    }
    ans=ans*(-1);
    cout<<ans<<endl;
   return 0;
}
