#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        ll a,b,c,d;
        a=n/2,b=m/1;
        c=m*(n%2)/2;
        cout<<a*b+c<<endl;
    }
    return 0;
}
