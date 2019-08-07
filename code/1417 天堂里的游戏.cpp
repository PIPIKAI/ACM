#include<iostream>
using namespace std;
typedef long long ll;
ll jian(ll a,ll b)
{
    return a%b?jian(b,a%b):b;
}
void diserve(ll a,ll b)
{
    ll x=(a+3*b),y=4*(a+b);
        cout<<x/jian(x,y)<<"/"<<y/jian(x,y)<<endl;
}
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        diserve(a,b);
    }
    return 0;
}
