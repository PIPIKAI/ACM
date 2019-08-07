#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
void solve(ll n)
{
    int flag=1;
    ll i=sqrt(n*2.0),j;
    for(;i>=2;i--)
    {
        if((n-(i-1)*i/2)%i==0)
        {
            flag=0;
            cout<<(n-(i-1)*i/2)/i<<endl;
        }
    }
    if(flag)
        cout<<"No Solution"<<endl;
}
int main()
{

    ll n;
    cin>>n;
    solve(n);
    return 0;
}
