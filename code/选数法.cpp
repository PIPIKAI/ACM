#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll n,d,f[100005]={0},sum=0;
   cin>>n>>d;
        for(int i=1;i<=n;i++)
        cin>>f[i];
    sort(f+1,f+1+n);
    for(ll i=1;i<=n;i++)
    {
        ll t=f[i]+d;
        ll j=upper_bound(f+1,f+n+1,t)-f;
        j=min(j,n);
        for(ll k=j;k>i+1;k--)
        {
            if(f[k]-f[i]<=d&&k<=n)
            {
                //cout<<k<<" "<<i<<endl;
                sum+=(k-i-1);
            }
        }


    }
    cout<<sum<<endl;
    return 0;
}

