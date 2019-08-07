#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll sum=n-( n/2 +n/3+ n/5 + n/7 );
    sum+=(n/6+n/15+n/10+n/14+n/35+n/21);
    sum-=(n/30+n/42+n/70+n/105);
    sum+=(n/210);
    cout<<sum;
    return 0;
}
