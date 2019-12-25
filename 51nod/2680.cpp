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
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
    	for(int j=l[i-1];j<l[i];j++){
    		dp[i][l[i]]=(dp[i-1][j]+dp[i][l[i]])%mod;
    	}
    	for(int j=l[i]+1;j<=r[i];j++){
    		dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%mod;
    	}
    }
    for(int i=l[n];i<=r[n];i++){
    	ans=(ans+dp[n][i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}