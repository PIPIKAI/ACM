#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        ll ans,t=2*n+1;
        ll mid=(n+1);
        if(m>n*2-1)
        {
            cout<<"0"<<endl;
        }
        else
        {
            if(m<mid)
            {
                ans=(m-1)/2;
            }
            else if(m==mid)
            {
                ans=n/2;
            }
            else
            {
                ans=(t-m)/2;
            }
            cout<<ans<<endl;
        }

    }
    return 0;
}



