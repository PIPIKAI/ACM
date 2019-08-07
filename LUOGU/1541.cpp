#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int f[600],s[5]={0};
int dp[42][42][42][42];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>f[i];
    for(int i=1;i<=m;i++)
    {
        int t;cin>>t;s[t]++;
    }
    dp[0][0][0][0]=f[1];

    for(int i=0;i<=s[1];i++)
    for(int j=0;j<=s[2];j++)
    for(int k=0;k<=s[3];k++)
    for(int l=0;l<=s[4];l++)
    {
        int x=i+2*j+k*3+l*4+1;
        if(i) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l]+f[x]);
        if(j) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j-1][k][l]+f[x]);
        if(k) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k-1][l]+f[x]);
        if(l) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i][j][k][l-1]+f[x]);
    }
    cout<<dp[s[1]][s[2]][s[3]][s[4]]<<endl;
    return 0;
}
