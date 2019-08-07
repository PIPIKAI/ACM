#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   int n;
	while(cin>>n)
    {
        int t,ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>t;
            ans+=t;
        }
        cout<<ans<<endl;
    }
   return 0;
}
