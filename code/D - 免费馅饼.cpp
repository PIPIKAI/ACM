#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=1e5+7;
int f[maxn][11];
int dp[maxn][11];//dp[i][j]表示在i时刻在j点可以接到的最大的
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n,n){
        mem(f,0);
        mem(dp,0);
        int maxt=0;
        for(int i=0,x,t;i<n;i++){
            cin>>x>>t;
            Max(maxt,t);
            f[t][x]++;
        }
        int ans=0;
        dp[0][5]=1;
        for(int t=1;t<=maxt;t++){
            for(int i=0;i<=10;i++){
                int add=0;
                if(dp[t-1][i+1] && i!=10){
                    Max(add,dp[t-1][i+1]);
                }
                if(dp[t-1][i]){
                    Max(add,dp[t-1][i]);
                }
                if(dp[t-1][i-1] && i!=0){
                    Max(add,dp[t-1][i-1]);
                }
                dp[t][i]=f[t][i]+add;
                Max(ans,dp[t][i]);
            }
        }
        cout<<ans-1<<endl;

    }
    return 0;
}

