#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(A,B) memset(A, B, sizeof(A))
const int inf = 0x3f3f3f3f;
const int maxn=1e4+7;
std::vector<pair<int,ll> > f[maxn];
ll dp[maxn][3];
int n,id[maxn];
void dfs1(int now,int pre){
	dp[now][0]=dp[now][1]=dp[now][2]=0;
	for(auto j : f[now]){
		int next=j.first;
		int w=j.second;
		if(next!=pre){
			dfs1(next,now);
			if(dp[now][0]<dp[next][0]+w){
				dp[now][0]=dp[next][0]+w;//子树第一大的长度
				id[now]=next;			//最长的字数的下标
			}
			
		}
	}
	for(auto j : f[now]){
		int next=j.first;
		int w=j.second;
		if(next!=pre && next!=id[now]){
			dp[now][1]=max(dp[now][1],dp[next][0]+w);//第二大
		}
	}

}
void dfs2(int now,int pre){
	for(auto j : f[now]){
		int next=j.first;
		int w=j.second;
		if(next!=pre){
			if(next==id[now]){
				dp[next][2]=w+max(dp[now][1],dp[now][2]);// 如果当前子树就是最长的那条，那么就比较第二长的子树
			}
			else{
				dp[next][2]=w+max(dp[now][0],dp[now][2]);//否则比较最长的那条子树+子节点到父节点的距离
			}
			dfs2(next,now);
		}
	}
}
int main(int argc, char * argv[]) 
{
    //freopen("C:/Users/Administrator/Desktop/CODEING/code/data.in","r",stdin);
    //freopen("C:/Users/Administrator/Desktop/CODEING/code/data.out","w",stdout);
    std::ios::sync_with_stdio(false);
    while(cin>>n){
    	for(int i=1,a,b;i<=n;i++){
    		f[i].clear();
    	}
    	for(int i=2,a,b;i<=n;i++){
    		cin>>a>>b;
    		f[i].push_back(make_pair(a,b));
    		f[a].push_back(make_pair(i,b));
    	}
    	dfs1(1,-1);
    	dfs2(1,-1);
    	for(int i=1;i<=n;i++){
    		cout<<max(dp[i][0],dp[i][2])<<endl;
    	}
    }
    return 0;
}