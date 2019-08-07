#include<stdio.h>
typedef long long  ll;
int main()
{
    ll n;
    while(~scanf("%lld",&n))
    {
        ll a=n/2;
        ll b=n/5;
        ll c=n/11;
        ll d=n/13;
        //»›≥‚‘≠¿Ì£¨∆Êº”≈ººı°£??
        ll swe=a+b+c+d-n/(2*5)-n/(2*11)-n/(2*13)-n/(5*11)-n/(5*13)-n/(11*13);
        printf("%lld\n",n-swe);
    }
    return 0;
}
