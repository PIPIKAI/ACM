#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
typedef long long ll;
ll  q=1e12,w=1e4,e=1e10;
bool cmp(ll a,ll b)
{
    return ((a%q)/w)*e+(a/q)*10000+a%w>((b%q)/w)*e+(b/q)*10000+b%w;
}
int main()
{
    int i;
    ll n;
    ll f[100005];
    cin>>n;
    for( i=0;i<n;i++)
        scanf("%lld",&f[i]);
    sort(f,f+n,cmp);
    for( i=0;i<n;i++)
    {
        printf("%lld  %lld %lld \n",((f[i]%q)/w)*e,(f[i]/q)*10000,f[i]%w);
    }
     // printf("%lld\n",f[i]);
    return 0;
}
