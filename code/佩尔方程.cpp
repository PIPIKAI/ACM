#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int n;
int main()
{
    cin>>n;

    for(ll i=1;;i++)
    {
        ll temp=n*i*i;
        ll t=sqrt(temp+1);
        if(t*t==temp+1)
        {
            cout<<"x"<<"="<<t<<endl;
            cout<<"y"<<"="<<i;
                return 0;
        }

    }
    return 0;
}
