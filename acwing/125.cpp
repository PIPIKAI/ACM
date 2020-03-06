//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
struct node
{
	int v,w;
}f[maxn];
bool cmp(node a,node b){
	return a.v+a.w < b.v+b.w;
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>f[i].v>>f[i].w;
    }
    sort(f,f+n,cmp);
    ll ans=-inf,sum=0;
    for(int i=0;i<n;i++){
    	ans=max(ans, sum-f[i].w );
    	sum+=f[i].v;
    }
    cout<<ans<<endl;
    return 0;
}