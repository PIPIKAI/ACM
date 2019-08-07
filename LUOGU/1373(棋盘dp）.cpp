#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
int mod =1000000007;
int n,m,k,ans=0;
int dp[810][810][18][2]={0};
int f[810][810];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>k;k++;
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        int t;
        cin>>t;f[i][j]=t%k;
        dp[i][j][t%k][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int h=0;h<=k;h++)
            {
                dp[i][j][h][0]=(dp[i][j][h][0]+dp[i-1][j][(k+h-f[i][j])%k][1])%mod;
                dp[i][j][h][1]=(dp[i][j][h][1]+dp[i-1][j][(k+h+f[i][j])%k][0])%mod;
                dp[i][j][h][0]=(dp[i][j][h][0]+dp[i][j-1][(k+h-f[i][j])%k][1])%mod;
                dp[i][j][h][1]=(dp[i][j][h][1]+dp[i][j-1][(k+h+f[i][j])%k][0])%mod;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        ans=(ans+dp[i][j][0][1])%mod;
    cout<<ans<<endl;
    return 0;
}
