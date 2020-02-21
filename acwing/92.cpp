//#pragma comment(linker, "/STACK:1024000000,1024000000")
// 指数型的枚举
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
void dfs(int step,int state){
	if(step==n){
		for(int i=0;i<n;i++){
			if(state >> i &1){
				cout<<i+1<<" ";
			}
		}
		cout<<endl;
		return ;
	}
	dfs(step+1,state);
	dfs(step+1,state | 1<<step);
}
int main(int argc, char * argv[]) 
{
    cin>>n;
    dfs(0,0);
    return 0;
}