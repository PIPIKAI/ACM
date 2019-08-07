#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
ll giao5(ll x)
{
    int s=0;
    while(x!=0)
    {
        if(x%5==0)
            s++,x/=5;
        else
            break;
    }
    return s;
}
int main()
{
    ll n;
    while(cin>>n)
    {
        if(n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
      ll sum2=0,sum5=0;
      for(ll i=0;i<=n;i+=5)
      {
        sum5+=giao5(i)*(n-i+1);
      }
      cout<<sum5<<endl;
    }
    return 0;
}
