#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int mod=1e9+7;
int n,m;
int dp[2020][2020];///dp[i][j]
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m){
        for(int i=0;i<=n+m;i++){
            for(int j=0;j<=n+m;j++){
                dp[i][j]=0;
            }
        }
        dp[0][0]=1;
        for(int i=0;i<=n+m;i++){
            for(int j=0;j<=n+m;j++){
                if(i+1 <= j+n ){
                    dp[i+1][j]=(dp[i][j]+dp[i+1][j])%mod;
                }
                if(j+1 <= i+m){
                    dp[i][j+1]=(dp[i][j]+dp[i][j+1])%mod;
                }
            }
        }
        cout<<dp[n+m][m+n]<<endl;
    }
    return 0;
}
