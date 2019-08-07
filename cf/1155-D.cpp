#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
const int maxn=3e5+7;
int n,x;
ll f[maxn];
ll dp[maxn][3][3];///dp[pos][statemax][statemul]
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    mem(dp,-0x3f);
    dp[0][0][0]=0;
    ///找到一个数列，数列乘x，连续数列相加
    for(int i=0;i<=n;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(k<2){
                    dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]);
                }
                if(j<2){
                    dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
                }
                if(i<n){
                    dp[i+1][j][k]=max(dp[i+1][j][k] ,dp[i][j][k]+ (j==1 ? f[i] : 0) * (k==1 ? x : 1));
                }
            }
        }

    }
    cout<<dp[n][2][2]<<endl;
    return 0;
}
