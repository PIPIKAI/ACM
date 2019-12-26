#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn = 1e3+7;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
int l[maxn],r[maxn],dp[207][10007];
int n,ans;
#define LOCAL
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>l[i]>>r[i];
    }
    for(int i=l[1];i<=r[1];i++){
    	dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
    	int pre=0;
    	for(int j=1;j<=r[i];j++){
    		if(j>=l[i]){
    			dp[i][j]=pre;
    			if(i==n){
    				ans=(ans+dp[i][j])%mod;
    			}
    		}
    		pre=(pre+dp[i-1][j])%mod;
    	}
    }
    cout<<ans<<endl;
    return 0;
}