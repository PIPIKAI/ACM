//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e3+7;
const int inf = 0x3f3f3f3f;
int n,m,f[maxn];
bool dfs(int now,int depth){
	if(now ==depth) return f[now-1] == n ;
	bool vis[maxn]={false};
	for(int i=now-1;i>=0;i--){
		for(int j=i;j>=0;j--){
			int s=f[i]+f[j];
			if(s > f[now-1] && s <= n && !vis[s]){
				vis[s]=true;
				f[now]=s;
				if(dfs(now+1, depth)) return true;
			}
		}
	}
	return false;
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    while(cin>>n&&n){
    	f[0]=1;
    	for(int depth=1;1;depth++){
    		if(dfs(1,depth)){
    			for(int i=0;i<depth;i++){
    				cout<<f[i]<<" ";
    			}
    		 break;
    		}
    	}
    	cout<<endl;
    }
    return 0;
}