//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e6+7;
const int inf = 0x3f3f3f3f;
ll n,m,ans,a[maxn],sum[maxn],avg;
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<= n; i++){
    	cin>>a[i];
    	avg+=a[i];
    }
    avg/=n;
    for(int i=1;i<=n;i++){
    	sum[i]+=sum[i-1]+a[i]-avg;
    }
    sort(sum+1,sum+1+n);
    for(int i=1;i<=n;i++){
    	ans+=abs(sum[i]-sum[(n>>1)+1]);
    }
    cout<<ans<<endl;
    return 0;
}