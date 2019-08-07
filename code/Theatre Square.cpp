#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m,a;
    while(cin>>n>>m>>a)
    {
        ll j,i;
        j=n%a==0?0:1;
        i=m%a==0?0:1;
        ll k=n/a+j;
        ll b=m/a+i;
        ll ans=k*b;
        cout<<ans<<endl;
    }

    return 0;
}

