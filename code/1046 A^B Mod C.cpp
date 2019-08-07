#include<iostream>
using namespace std;
typedef long long ll;
ll mi(ll a,ll b,ll c)
{
    ll s=1;
    while(b>0)
    {
        if(b&1)
            s=(s*a)%c;
        a=(a*a)%c;
        b>>=1;
    }
    return s;
}
int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<mi(a,b,c);
    return 0;
}
