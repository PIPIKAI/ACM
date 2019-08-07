#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n, x, k;
ll f[300], dp[300][300];
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> k >> x;
    mem(dp, -1);
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    for(int i = 1; i <= k; i++) {
        dp[i][1]=f[i];
    }
    for(int j=2;j<=x;j++){
        for(int i=1;i<=n;i++){
            for(int p=max(i-k,1);p<i;p++){
                if(dp[p][j-1]==-1)
                    continue;
                dp[i][j]=max(dp[i][j],dp[p][j-1]+f[i]);
            }
        }
    }
    ll ans=-1;
    for(int i=n-k+1;i<=n;i++){
        ans=max(ans,dp[i][x]);
    }
    cout << ans << endl;
    return 0;
}
