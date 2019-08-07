#include<iostream>
using namespace std;
typedef long long ll;
ll poww(ll x,ll n)
{
    ll s=1;
    while(n>0)
    {
        if(n%2!=0)
            s=(s*x)%10;
        x=(x%10)*(x%10);
        n/=2;
      //  cout<<s<<"  "<<n<<endl;
    }
    return s;
}
int main()
{
    ll   n;
    cin>>n;
    ll t=poww(n,n);
    cout<<t%10;
    return 0;
}

