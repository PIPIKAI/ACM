#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=2e5+7;
map<int,int> f;
int a[maxn],cnt,dp[maxn*2];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0,t;i<n;i++){
        cin>>t;
        f[t]++;
    }
    for(auto i:f){
        a[++cnt]=i.second;
    }
    int ans=0;
    sort(a+1,a+cnt+1);
    for(int i=cnt;i>=1;i--){
        for(int j=1;j<=a[i];j++){
            dp[j]=max(dp[j],j+dp[j*2]);
            Max(ans,dp[j]);
        }

    }
    cout<<ans<<endl;
    return 0;
}
