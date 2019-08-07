#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;
int main()
{
    ll f[100005];
    ll n,k,l,ans=0;
    cin>>n>>k>>l;
    for(ll i=0;i<n*k;i++)
        scanf("%lld",f+i);
    sort(f,f+n*k);
    ll t=f[0],tm(0);
    ll crt=0;
    for(ll i=n*k;i--;)
    {
        tm++;
        if(tm>=k&&f[0]+l>=f[i])
        {
            tm-=k;
            ans+=f[i];
            crt++;
        }
    }
    cout<<(crt==n?ans:0)<<endl;
    return 0;
}
