#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans=1e7;
int n,tar;
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    while( cin>>n)
    {
        ans=1e7;
        memset(vis,0,sizeof(vis));

         tar=sqrt(n)+1;
         //cout<<dp[tar]<<endl;
        dfs(2,2,2);
        cout<<ans<<endl;
    }

   return 0;
}
