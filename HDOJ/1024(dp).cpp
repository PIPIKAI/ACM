#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll inf= 1e9+7,f[1000001],pre[1000001], dp[1000001];
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	ll ans,m,n;
	while(cin>>m>>n){
        ans=0;
        memset (f,0,sizeof f);
        memset (dp,0,sizeof dp);
        for(int i=1;i<=n;i++)  cin>>f[i];
        ll i,j,maxs;
        for( i=1;i<=m;i++){
            maxs=-inf;
            for( j=i;j<= n;j++){
               dp[j]=max(dp[j-1],pre[j-1])+f[j];
                pre[j-1]=maxs;
                maxs=max(maxs,dp[j]);
            }
            pre[j-1]=maxs;
        }
       cout<<maxs<<endl;
    }
   return 0;
}
