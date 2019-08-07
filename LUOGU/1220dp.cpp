#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
int n,m,c;
int dp[60][60][2];
int f[60],sum[60];
int ans=inf;
int ca(int i,int j,int l,int r)
{
    return  (f[j]-f[i] )*(sum[l] +sum[n] -sum[r]);
}
int main()
{
    std::ios::sync_with_stdio(false);
    mem(dp,127);
    mem(f,0);
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        int w;
        cin>>f[i]>>w;
        sum[i]=sum[i-1] + w;
    }
    dp[c][c][0]=0;
    dp[c][c][1]=0;
    for(int j=c;j<=n;j++)
    {
        for(int l=j-1;l>=1;l--)
        {
            dp[l][j][0]=min(dp[l+1][j][0]+ca(l,l+1 ,l,j),dp[l+1][j][1]+ca(l,j,l,j));
            dp[l][j][1]=min(dp[l][j-1][0]+ca(l,j,  l-1,j-1),dp[l][j-1][1]+ca(j-1,j ,l-1, j-1));
        }
    }
    ans=min(dp[1][n][0],dp[1][n][1]);
    cout<<ans<<endl;
    return 0;
}
