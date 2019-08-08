#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    if(n&1)
        cout<<(n+1)/2<<endl;
    else
        cout<<n/2<<endl;
    return 0;
}
