// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int inf = 0x3f3f3f3f;
const int maxn=1e5+7;
#define LOCAL
int n,m;
struct node
{
	int i,w;
}f[maxn];
bool cmp1(node a,node b){
	return a.w>b.w;
}
bool cmp2(node a,node b){
	return a.i<b.i;
}
int main(int argc, char * argv[]) 
{
    
    // #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
    	cin>>f[i].w;
    	f[i].i=i;
    }
    sort(f,f+n,cmp1);
    sort(f,f+m,cmp2);
    for (int i = 0; i < m; ++i)
    {
    	cout<<f[i].w<<" ";
    }
    cout<<endl;
    return 0;
}