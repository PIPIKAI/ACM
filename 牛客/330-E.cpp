# include <cstdio>
# include <cstring>
# include <algorithm>
# define mod 1000000007
using namespace std;
typedef long long ll;
const int maxn = 100050;
char a[maxn],b[maxn];

ll quick_pow(ll a, ll k)
{
    ll ans=1;
    while(k)
    {
        if(k&1)
        {
            ans=(ans*a)%mod;
            k--;
        }
        k/=2;
        a=a*a%mod;
    }
    return ans;
}

int main()
{
	scanf("%s%s",a,b);
    ll len = strlen(a);
    ll mod1 = mod-1;
    ll k = a[0]-'0';
    for(ll i=1;i<len;i++) k = (k*10 +(a[i]-'0')) % mod1;
    printf("%lld\n",quick_pow(2,k));
	return 0;
}
