#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b;
    ll ans=0;
    cin>>a>>b;
    for(int j=1;j<=b;j++)
    {
        ll p= j%2==0?1:-1;
        ll q=j-a>0?j-a:0;
        ll t=(a+b+q)*(b-a-q+1)/(2*j)*p;
        ans+=t;
    }
    cout<<ans<<endl;
    return 0;
}
