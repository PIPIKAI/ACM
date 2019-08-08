#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
const ll maxn=1e18;
ll prime[10000100],n;
bool IsPrime[10000100];
int num;
typedef  long long LL;
LL modular_multi(LL x,LL y,LL mo)
{
	LL t;
	x%=mo;
	for(t=0;y;x=(x<<1)%mo,y>>=1)
		if (y&1)
			t=(t+x)%mo;
	return t;
}
LL modular_exp(LL num,LL t,LL mo)
{
	LL ret=1,temp=num%mo;
	for(;t;t>>=1,temp=modular_multi(temp,temp,mo))
		if (t&1)
			ret=modular_multi(ret,temp,mo);
	return ret;
}
bool miller_rabbin(LL n)
{
	if (n==2)return true;
	if (n<2||!(n&1))return false;
	int t=0;
	LL a,x,y,u=n-1;
	while((u&1)==0) t++,u>>=1;
	for(int i=0;i<100;i++)
	{
		a=rand()%(n-1)+1;
		x=modular_exp(a,u,n);
		for(int j=0;j<t;j++)
		{
			y=modular_multi(x,x,n);
			if (y==1&&x!=1&&x!=n-1)
				return false;
			x=y;
		}
		if (x!=1)
			return false;
	}
	return true;
}

void init_prime()
{
    num=0;
    memset(IsPrime,false,sizeof(IsPrime));
    for(ll i=2; i<=10000000; i++)
    {
        if(IsPrime[i]) continue;
        prime[num++]=i;
        for(ll j=i+i; j<=10000000; j+=i)
            IsPrime[j]=true;
    }
}
ll solve(ll n)
{
    ll ans=1,sum;
    for(int i=0; i<num&&prime[i]*prime[i]<=n; i++)
    {
        ll tmp=prime[i];
        sum=0;
        if(n%tmp==0)
        {
            while(n%tmp==0)
            {
                n/=tmp;
                sum++;
            }
            ans*=(sum+1ll);
        }
    }
    if(n>=1e14)
    {
       if(miller_rabbin(n)) ans*=2;
       else
       {
           ll w=sqrt(n);
           if(w*w==n) ans*=3;
           else ans*=4;
       }
       n=1;
    }
    if(n>1) ans*=2;
    return ans;
}
ll qpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a);
        a=(a*a);
        b>>=1;
    }
    return ans;
}
int main()
{
    init_prime();
    cin>>n;
    for(ll i=1;i<=1000000;i++){
        ll tp=solve(i);
        ll aa=qpow(i,tp);
        if(aa==n){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
