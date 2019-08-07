#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
ll mod =1000000007;
ll X;
ll gcdp()
ll mi(ll n)
{
    ll s=1,x=3;
    while(n>0)
    {
        if(n%2)
        {
          s=s*x%mod;
        }
        x=x*x%mod;
        n/=2;
    }
    return s;
}
int main()
{
    ll n;
    cin>>n;
    cout<<(mi(n+1)-1)*X%mod<<endl;
    return 0;
}
