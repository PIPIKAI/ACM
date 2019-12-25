#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=2e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
std::vector<int> f[maxn];
int ans[maxn],a[maxn],h[maxn];
#define LOCAL
void bfs(int m){
	queue<int> q;
	mem(h,-1);
	for(int i=1;i<=n;i++){
		if(m == a[i]%2){
			q.push(i);
			h[i]=0;
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int c: f[u]){
			if(h[c]==-1){
				h[c]=h[u]+1;
				q.push(c);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if((a[i]&1)!=m){
			ans[i]=h[i];
		}
	}

}
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int tp,i=1;i<=n;i++){
    	cin>>tp;
    	a[i]=tp;
    	if(tp+i<=n){
    		f[i+tp].push_back(i);
    	}
    	if(i-tp>=1){
    		f[i-tp].push_back(i);
    	}
    }
    bfs(1);
    bfs(0);
    for (int i = 1; i <= n; ++i)
    {
    	cout<<ans[i]<<" ";
    }
    return 0;
}