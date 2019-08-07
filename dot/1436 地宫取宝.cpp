#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int mod=1e9+7;
int n,m,ans=0,k;
int f[56][56];
ll dp[56][56][15][15];/// 第几格 拿了几个 最大价值不超过
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>f[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int p=0;p<=k;p++){
                for(int l=0;l<=12;l++){
                    ll na=0,buna=0;
                    if(i==1&&j==1){
                        if(!p||(p==1 && l>f[i][j] ))
                            dp[i][j][p][l]=1;
                            continue;
                    }
                    if(p && l > f[i][j])
                    na=dp[i-1][j][p-1][f[i][j]] + dp[i][j-1][p-1][f[i][j]];
                    buna=dp[i-1][j][p][l]+dp[i][j-1][p][l];
                    dp[i][j][p][l] = na+buna;
                    dp[i][j][p][l]%=mod;
                }
            }
        }
    }
    cout<<dp[n][m][k][12]<<endl;
    return 0;
}
