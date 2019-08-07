#include<bits/stdc++.h>
#define mem(x,y) memset(x,y,sizeof(x))
#define LL long long
#define inf 0x3f3f3f3f
#define pt printf
using namespace std;
int intread() {int x;scanf("%d",&x);return x;}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,f[102], dp[105][2];
    mem(dp,0);
    n=intread();
    for(int i=1;i<=n;i++) f[i]=intread();

    for(int i=1;i<=n;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<i;j++)
            if(f[i]>f[j]) dp[i][0]=max(dp[i][0],dp[j][0]+1);
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=1;
        for(int j=1;j<i;j++)
            if(f[i]<f[j]) dp[i][1]=max(dp[i][1],max(dp[j][0],dp[j][1])+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,max(dp[i][0],dp[i][1]));
    pt("%d\n",n-ans);
    return 0;
}
