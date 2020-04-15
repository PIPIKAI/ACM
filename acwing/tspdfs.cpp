//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e3+7;
const int inf = 0x3f3f3f3f;
int n,m,f[maxn][maxn];
int ans=inf,res=inf;
int vis[maxn];
pair<int, int > path[maxn],aapath[maxn];
void dfs(int now,  int begins, int len ,int step){
	cout<<now<<endl;
	if(step+1  >= n ){
		path[step]={now ,begins};
		if(len < ans){
			memcpy(aapath,path,sizeof path);
			// aapath=path;
		}
		ans=min(ans, len );
		return ;
	}
	for(int i= 0; i<n;i++){
		if(f[i][now] ==0 ){
			continue;
		}
		if( vis[i] ){
			continue;
		}
		path[step]={now,i} ;
		vis[i]=1;
		dfs(i,  begins , len + f[i][now] , step+1);
		vis[i]=0;
	}
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
    	for (int j = 0; j < n; ++j){
    		cin>>f[i][j];
    	}
    }
    for(int i=0;i<n;i++){
    	mem(vis,0);
    	ans=inf;
    	vis[i]=1;
    	dfs(i  , i , 0 , 0);
    	cout<<ans<<endl;
    	for(int i=0;i<n;i++){
    		cout<<aapath[i].first<<"->"<<aapath[i].second<<" "<<f[aapath[i].first][aapath[i].second]<<endl;;
    	}
    	cout<<endl;
    	break;
    	res=min(res,ans);
    }
    return 0;
}