#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e3+7;
const int inf = 0x3f3f3f3f;
int n,m;
int d[maxn];
std::vector<int> f[maxn];
priority_queue<int ,vector<int >,greater<int > > q;
#define LOCAL
void topsort(){
	std::vector<int> ans;
	for(int i=1;i<=n;i++) if(d[i]==0) q.push(i);
	while(!q.empty()){
		int tp=q.top();
		q.pop();
		ans.push_back(tp);
		for(int i=0;i<f[tp].size();i++){
			int j=f[tp][i];
			d[j]--;
			if(!d[j]) q.push(j);
		}		
	}
	for(int i=0;i<ans.size() ;i++){
		if(i+1==ans.size()){
			cout<<ans[i]<<endl;
		}
		else{
			cout<<ans[i]<<" ";
		}
	}
	for(int i=1;i<=n;i++){
		f[i].clear();
	}
}
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    while (cin>>n>>m)		
    {
    	mem(d,0);
    	for(int i=0;i<m;i++){
    		int a,b;
    		cin>>a>>b;
    		f[a].push_back(b);
    		d[b]++;
    	}
    	topsort();
    }

    return 0;
}