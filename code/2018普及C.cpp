#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int dp[600][600];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    int f[1000];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>f[i];
    sort(f,f+n);
    int ans=1e9+7;
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
       {
           for(int k=i;k<n;k++)
           {
               int t=(f[k]+dp[i][k]+m-j)%m;
               dp[i][k]=min(dp[i][]);
           }
       }
    }
    cout<<ans<<endl;
    return 0;
}
