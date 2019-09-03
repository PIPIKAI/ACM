#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 2e4+7;
int n,m,ans;
int dp[maxn];
vector<int> f[maxn];
void dfs(int rt,int pre){
    for(auto i : f[rt]){
        if(pre!=i){
            dfs(i,rt);
            dp[rt]+=max(0,dp[i]);
            ans=max(ans,dp[rt]);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>dp[i];
    }
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        f[a].push_back(b);
        f[b].push_back(a);
    }
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}