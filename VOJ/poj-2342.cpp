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
const int maxn = 1e5+7;
int n,m;
int dp[maxn][2];
int du[maxn];
vector<int> f[maxn];
bool vis[maxn];
void dfs(int rt){

    for(int i=0;i<f[rt].size();i++){
        int j=f[rt][i];
        if(!vis[j]){
            vis[j]=1;
            dfs(j);
            dp[rt][0]+=max(dp[j][0],dp[j][1]);
            dp[rt][1]+=dp[j][0];
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>dp[i][1];
            f[i].clear();
            dp[i][0]=0;
            vis[i]=0;
            du[i]=0;
        }
        int l,k;
        while(cin>>l>>k,l||k){
            f[k].push_back(l);
            du[l]++;
        }
        for(int i=1;i<=n;i++){
            if(du[i]==0){
                dfs(i);
                cout<<max(dp[i][1],dp[i][0])<<endl;
            }
        }
    }
    return 0;
}