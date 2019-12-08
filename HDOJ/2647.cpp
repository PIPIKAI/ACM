#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=2e4+7;
const int inf = 0x3f3f3f3f;
int n,m;
int d[maxn],val[maxn];
std::vector<int> f[maxn];
#define LOCAL
int topsort(){
	queue<int> q;
	int res=0,counts=0;
	for(int i=1;i<=n;i++){
		if(!d[i]){
			val[i]=888;
			q.push(i);
		}
	}
	while(!q.empty()){
		int tp=q.front();
		q.pop();
		counts++;
		for(int i=0;i<f[tp].size();i++){
			int j=f[tp][i];
			--d[j];
			if(!d[j]){
				q.push(j);
				val[j]=val[tp]+1;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		res+=val[i];
		f[i].clear();
		val[i]=0;
		d[i]=0;
	}
	if(counts<n){
		res=-1;
	}
	return res;
}
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    /* code */

    while (cin>>n>>m)
    {
    	for (int i = 0,a,b; i < m; ++i)
    	{
    		cin>>a>>b;
    		d[a]++;
    		f[b].push_back(a);
    	}
    	cout<<topsort()<<endl;
    }

    return 0;
}