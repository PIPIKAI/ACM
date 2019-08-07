#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e5+7;
int n,m;
ll a[maxn][3],dp[maxn][4];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i][2];
    }
    for(int i=1;i<=n;i++){
        dp[i][1]=max( dp[i-1][2]+a[i][1], max( dp[i-1][3]+a[i][1],a[i][1]) );
        dp[i][2]=max( dp[i-1][1]+a[i][2], max( dp[i-1][3]+a[i][2],a[i][2]) );
        dp[i][3]=max( dp[i-1][2],dp[i-1][1] );
    }
    cout<<max(dp[n][2],dp[n][1])<<endl;
    return 0;
}
