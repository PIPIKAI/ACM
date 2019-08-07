#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	int t,n,T_T=0;
	while(cin>>t)
    {
        while(t--)
        {
            cin>>T_T>>n;
            int ans=(1+n)*n/2+n;
            cout<<T_T<<" "<<ans<endl;
        }
    }
   return 0;
}
