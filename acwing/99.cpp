//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=5e3+7;
const int inf = 0x3f3f3f3f;
int n,r,f[maxn][maxn];
int main(int argc, char * argv[]) 
{
    cin>>n>>r;
    int mx=r,my=r;
    for(int i=0;i<n;i++){
    	int x,y,w;
    	cin>>x>>y>>w;
    	x++;y++;
    	f[x][y]+=w;
    	mx=max(mx,x);
    	my=max(my,y);
    }
    for(int i=1;i<=mx;i++){
    	for(int j=1;j<=my;j++){
    		f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1]; // 注意这里一定是+=
    	}
    }
    int ans=0;
    for(int i=r;i<=mx;i++){
    	for(int j=r;j<=my;j++){
    		ans=max(ans,f[i][j]-f[i-r][j]-f[i][j-r]+f[i-r][j-r]);
    	}
    }
    cout<<ans<<endl;
    return 0;
}