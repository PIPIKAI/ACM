//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int > pii;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,w,f[maxn],ans=inf,vis,minid;
std::vector<int> car;
void dfs(int now ){
	int num=car.size();
	if(num >= ans) return ;
	if(now == 0){
		ans=min(ans,num);
		return ;
	}
	for(int i=0;i<car.size();i++){
		if(car[i]+f[now]<=w){
			car[i]+=f[now];
			dfs(now-1);
			car[i]-=f[now];
		}
	}
	car.push_back(f[now]);
	dfs(now-1);
	car.pop_back();
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n>>w;
    for(int i=1; i <= n ;i++){
    	cin>>f[i];
    }
    sort(f,f+n);
    dfs(n);
    cout<<ans<<endl;
    return 0;
}
