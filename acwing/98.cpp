//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll ;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
pll calc(ll  n,ll m){
	if(n==0) return {0,0};
	ll len=1ll<<(n-1),cnt=1ll<<(2*n-2);
	pll pos=calc(n-1,m%cnt);
	ll x=pos.first,y=pos.second;
	ll z=m/cnt;
	if (z==0)
		return {y,x};
	if (z==1)
		return make_pair(x,y+len);
	if (z==2)
		return make_pair(x+len,y+len);
	return make_pair(2*len-1-y,len-1-x);
}
int main(int argc, char * argv[]) 
{
    int T;
    ll n,a,b;
    cin>>T;
    while(T--){
    	cin>>n>>a>>b;
    	pll x=calc(n,a-1);
    	pll y=calc(n,b-1);
    	ll dx=x.first-y.first;
    	ll dy=x.second-y.second;
    	double ans=sqrt(dx*dx+dy*dy)*10;
    	printf("%0.lf\n",ans);
    }
    return 0;
}