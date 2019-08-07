#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
const int mod=9999973;
ll dp[110][110][103];/// 前i行有j列是1个旗子 ，k列是两个旗子.每一列最多两个旗子嘛
ll hh(ll x){
    return x*(x-1)/2;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    dp[0][0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;j+k<=m;k++){
                dp[i+1][j][k] = (dp[i][j][k] + dp[i+1][j][k])%mod;
                if(m-j-k>=1)
                    dp[i+1][j+1][k] = (dp[i][j][k]*(m-j-k) + dp[i+1][j+1][k])%mod;/// 在没有一个的那一列放一个
                if(j>=1)
                    dp[i+1][j-1][k+1] = ( dp[i][j][k]*j + dp[i+1][j-1][k+1])%mod;/// 在有一个的下面再放一个
                if(m-j-k>=2)
                    dp[i+1][j+2][k] = ( dp[i+1][j+2][k] + hh(m-j-k)*dp[i][j][k])%mod;///放两个，在没有的列
                if(j>=1 && m-j-k>=1)
                    dp[i+1][j][k+1] = ( dp[i+1][j][k+1] + j*(m-j-k) * dp[i][j][k])%mod;/// 放两个,一个在有一个的，一个在没有列
                if(j>=2)
                    dp[i+1][j-2][k+2] = ( dp[i+1][j-2][k+2] + hh(j) * dp[i][j][k])%mod;/// 放两个在两个一个的列
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j+i<=m;j++){
            ans=(ans+dp[n][i][j])%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
