#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e6+7;
int n,m;
int a[maxn],b[maxn],mp[maxn],dp[maxn],len;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        if(dp[len]<mp[b[i]]){
            dp[++len]=mp[b[i]];
        }
        else{
            int j=lower_bound(dp+1,dp+len+1,mp[b[i]])-dp;
            dp[j]=mp[b[i]];
        }
    }
    cout<<len<<endl;
    return 0;
}
