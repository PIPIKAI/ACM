#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e3+7;
const int inf = 0x3f3f3f3f;
struct node
{
	double x,y;
}f[maxn];
double dis[maxn][maxn];
bool vis[maxn];
int n,m;
#define LOCAL

int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int t=0;
    while(~scanf("%d",&n)&&n){
    	for (int i = 0; i < n; ++i){
    		scanf("%lf%lf",&f[i].x，&f[i].y);
    	}


    	printf("Scenario #%d\n",++t);
		printf("Frog Distance = %.3lf\n\n",edge[i].dis);
    }

    return 0;
}