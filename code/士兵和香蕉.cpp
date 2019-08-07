#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll k,n,w;
    while(cin>>k>>n>>w)
    {
        ll t=((1+w)*w)*k/2;
        if(t-n>0)
        {
            cout<<t-n<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}
