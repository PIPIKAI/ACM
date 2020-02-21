//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,ans[20];
void dfs(int step,int vis){
	if(step>=n){
		for(int i=0;i<step;i++){
			cout<<ans[i]+1<<" "; 
		}
		cout<<endl;
		return ;
	}
	for(int i=0;i<n;i++){
		if(~vis >> i & 1){
			ans[step]=i;
			dfs(step+1,vis | 1<<i);
		}
	}
}
int main(int argc, char * argv[]) 
{
    cin>>n;
    dfs(0,0);
    return 0;
}