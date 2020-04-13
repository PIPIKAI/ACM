//#pragma comment(linker, "/STACK:1024000000,1024000000")
/**
思路： 这题用dfs 如果全搜，就一定会超时
所以开绿剪枝，剪枝方法：
剪枝一：优先递归情况分支少的情况，即把排序，让大的树先填充
剪枝二：当当前的层数大于最优解的层数时，直接return
*/
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



    	386271549752934861419568273275693184941825637638147952824716395593482716167359428