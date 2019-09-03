#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(A,B) memset(A, B, sizeof(A))
const int inf = 0x3f3f3f3f;
const int maxn=300;
#define LOCAL
int dp[maxn][maxn],sum[maxn],son[maxn];
int n,p;
std::vector<int> v[maxn];
void dfs(int now){
	sum[now]=1;
	if(!v[now].size()){
		dp[now][1]=0;
		sum[now]=1;
	}
	for(auto i : v[now]){
		dfs(i);
		sum[now]+=sum[i];
		for(int j=sum[now];j>=0;j--){
			for(int k=1;k<j;k++){
				dp[now][j]=min(dp[now][j],dp[now][j-k]+dp[i][k]-1);
			}
		}
	}
}
int main(int argc, char * argv[]) 
{
    cin>>n>>p;
   	for(int i=0,a,b;i<n-1;i++){
   		cin>>a>>b;
   		v[a].push_back(b);
   		son[a]++;
   	}
   	mem(dp,0x3f);
   	for(int i=1;i<=n;i++){
   		dp[i][1]=son[i];
   	}
   	dfs(1);
   	int ans=dp[1][p];
    for(int i=2;i<=n;i++){
    	ans=min(ans,dp[i][p]+1);
    }
    cout<<ans<<endl;
    return 0;
}