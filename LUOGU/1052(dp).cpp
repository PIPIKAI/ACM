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
int l,s,t,m;
int dp[2050],b[2050],a[2020],cnt;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>l;
    cin>>s>>t>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    a[m+1]=l;
    sort(a+1,a+1+m+1);
    cnt=0;
    a[0]=0,b[0]=0;
    for(int i=1;i<=m;i++)
    {
        if(a[i]-a[i-1]>=t)
            cnt+=(a[i]-a[i-1])%t+t;
        else
         cnt+=a[i]-a[i-1];
        b[cnt]=1;
    }
    mem(dp,0x3f);
    dp[0]=0;
    for(int i=1;i<=cnt+t-1;i++)
    {
       // cout<<b[i]<<" ";
        for(int j=s;j<=t;j++)
            if(i-j>=0)
            dp[i]=min(dp[i-j]+b[i],dp[i]);
    }
    //cout<<endl;
    int ans=1e8+9;
    for(int i=cnt;i<=cnt+t-1;i++)
    {
        ans=min(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
