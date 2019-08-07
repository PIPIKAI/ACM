#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e4+7;
int n,m,ans;
int f[maxn],dp[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n,n){
        ans=0;
        mem(f,0);
        mem(dp,0);
        for(int i=1;i<=n;i++){
        cin>>f[i];
        }
        for(int i=1;i<=n;i++){
            dp[i]=f[i];
            for(int j=1;j<=i;j++){
                if(f[i]>f[j])
                dp[i]=max(dp[i] , dp[j]+f[i] );
                ans=max(ans,dp[j]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
