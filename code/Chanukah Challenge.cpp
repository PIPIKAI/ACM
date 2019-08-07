#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	ll t,n,x,k;
	while(cin>>t)
    {
        while(t--)
        {
            cin>>x>>k>>n;
            ll temp=n,ans=0;
            while(temp!=0)
            {
                ans+=(temp%k)*(temp%k);
                temp=temp/k;
            }
            cout<<x<<" "<<ans<<endl;
        }
    }
   return 0;
}
