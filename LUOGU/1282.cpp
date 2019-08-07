#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int a[1010],b[1010];
int dp[1010][2010*6];
int N=5000;
int intread() {int x;scanf("%d",&x);return x;}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n;n=intread();
    mem(dp,0x3F);
    for(int i=1;i<=n;i++) a[i]=intread(),b[i]=intread();
    dp[0][0+N]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=-N;j<=N;j++)
        {
           int dis=a[i]-b[i];
           dp[i][j+N]=min(dp[i-1][j+N-dis],dp[i-1][j+N+dis]+1);
        }
    }
    for(int i=0;i<=N;i++)
    {
        int ans=min(dp[n][i+N],dp[n][-i+N]);
        if(ans<=1000)
        {
            return pt("%d\n",ans),0;
        }
    }
    return 0;
}
