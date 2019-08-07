#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[5602],b[5600],n;
int dp[5600][5600]; //  表示把i个数字之前变成 单调不减 j 表示和顺序相比 第j种情况
int main()
{
   ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
        cin>>f[i],b[i]=f[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        dp[1][i]=dp[1][i-1]+abs(f[1]-b[i]);
    for(int i=2;i<=n;i++)
    {
        int  t=0;
        for(int j=1;j<=n;j++)
        {
            t=t+abs(f[i]-b[j]);

        }
        cout<<t<<endl;
        //dp[i][j]=min(dp[i-1][j],dp[i][j-1]+abs(f[i]-b[j]));
        //dp[i][j]=min(dp[i-1][j]+t,dp[i][j]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<dp[n][n]<<endl;;
   return 0;
}
/*
4
4 3 2 1
*/
