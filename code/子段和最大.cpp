#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
typedef long long ll;
int main()
{
    ll n,ans=0,sum=0;
   cin>>n;
        for(ll i=0;i<n;i++)
    {
        ll t;
        scanf("%lld",&t);
        ans+=t;
        if(ans<0)
            ans=0;
        sum=max(ans,sum);
    }
    cout<<sum<<endl;

    return 0;
}

