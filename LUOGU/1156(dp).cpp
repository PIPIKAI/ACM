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
int d,g;
struct node
{
    int t,f,h;
}f[101];
bool cmp(node a,node b)
{
    return a.t<b.t;
}
int dp[3000][3000];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>d>>g;
    int ans=-9999;
    for(int i=1;i<=g;i++)
        cin>>f[i].t>>f[i].f>>f[i].h;
    sort(f+1,f+1+g,cmp);
    for(int i=0;i<2010;i++)
        for(int j=0;j<2100;j++)
        dp[i][j]= -100000;
    dp[0][0]=10;
    for(int i=1;i<=g;i++)
    {
        for(int j=d; j>=0;j--)
        {
            if(dp[i-1][j]<f[i].t-f[i-1].t)
            continue;
            if(j+f[i].h>=d)
           {
               cout<<f[i].t<<endl;
               return 0;
           }
           dp[i][j]=max(dp[i-1][j]+f[i].f-(f[i].t-f[i-1].t),dp[i][j]);
           dp[i][j+f[i].h]=max(dp[i-1][j]-(f[i].t-f[i-1].t),dp[i][j+f[i].h]);

        }
        ans=max(ans,dp[i][0]+f[i].t);
    }
    /*for(int i=0;i<=g;i++)
    {
        for(int j=0;j<=d;j++)
        {
           cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<ans<<endl;
    return 0;
}
