#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n, m;
ll dp[2002][2002];
int  f[2002], a[2002];
/**
dp[i][j]=表示选到了i个数时，选了j后。价值的最小。
*/
int main() {
    //std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
        a[i] = f[i];
    }
    sort(a+1, a + n+1);
    for(int i=1;i<=n;i++){
        ll m=dp[i-1][1];
        for(int j=1;j<=n;j++){
            m=min(m,dp[i-1][j]);
            dp[i][j]= abs(f[i]-a[j])+m;
        }
    }
    ll ans=inf;
    for(int i=1;i<=n;i++){
        ans=min(dp[n][i],ans);
    }
    cout <<ans << endl;
    return 0;
}

