#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define lll __int128_t
int n,m,f[90];
lll ans=0,dp[90][90],k[99];
void pt(lll x)
{
    if(!x) return;
    if(x) pt(x/10);
    putchar(x%10+'0');
}
int main()
{
    std::ios::sync_with_stdio(false);
    k[0]=1;
    for(int i=1;i<=80;i++)
        k[i]=k[i-1]*2;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=m;j++)
       cin>>f[j];
          for(int l=0;l<m;l++)
        {
            for(int j=1;j+l<=m;j++)
            {
                dp[j][j+l]=max(dp[j+1][j+l]+k[m-l]*f[j],dp[j][j+l-1]+k[m-l]*f[j+l]);
            }
        }
        ans+=dp[1][m];
    }
    if(ans==0)
    cout<<"0";
    else
    pt(ans);
    return 0;
}
/*
1 3
1 2 3
*/
