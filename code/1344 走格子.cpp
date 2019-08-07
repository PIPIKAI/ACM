#include<stdio.h>
typedef long long ll;
ll min(ll a,ll b)
{
    return a>b?b:a;
}
int main()
{
    ll n;
    ll add=0,ans=0,temp;
    scanf("%lld",&n);
    scanf("%lld",&add);
    for(int i=1;i<n;i++)
    {

        scanf("%lld",&temp);
        ans=min(add+temp,ans);
        add+=temp;

    }
    printf("%lld\n",-ans);
    return 0;
}
