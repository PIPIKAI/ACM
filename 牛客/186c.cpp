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
int n,m;
int h=10000;
int f[102],dp[102][20006];
int main()
{
    std::ios::sync_with_stdio(false);
    n=read();m=read();
    mem(dp,-0x3f);
    int s=0,ans=0;
    for(int i=0;i<n;i++) f[i]=read(),s+=f[i];
    dp[0][h-f[0]]=f[0];
    dp[0][h+f[0]]=f[0];
    dp[0][0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=h-s ;j<=h+s ;j++)
        {
            dp[i][j]=dp[i-1][j];
            dp[i][j]=max(dp[i][j],dp[i-1][j-f[i]]+f[i]);
            dp[i][j]=max(dp[i][j],dp[i-1][j+f[i]]+f[i]);
        }
    }
    for(int j=h-m ;j<=h+m ;j++)
           ans=max(ans,dp[n-1][j]);
        cout<<ans<<endl;
    return 0;
}
