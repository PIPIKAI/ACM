#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int inf = 0x3f3f3f3f;
const int maxn=1e6+7;
string mp[maxn];
int n,m;
#define LOCAL
int dfs(int x,int y){
	if(mp[x][y]=='#'){
		return 0;
	}
	if(x+y==m+n-2){
		return 1;
	}
	mp[x][y]='#';
	return ((x+1<n&&dfs(x+1,y))||(y+1<m&&dfs(x,y+1)));
}
int main(int argc, char * argv[]) 
{
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin>>n>>m;
    int ans=0;
    for(int i=0;i<n;i++){
    	cin>>mp[i];
    }
    ans+=dfs(0,0);
    mp[0][0]='.';
    ans+=dfs(0,0);
    cout<<ans<<endl;
    return 0;
}