#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    while(cin>>n)
    {
        if(!n)
        {
            cout<<"0"<<endl;
            continue;
        }
        ll t=n+1;
        if(t&1)
            cout<<t<<endl;
        else
            cout<<t/2<<endl;
    }
    return 0;
}
