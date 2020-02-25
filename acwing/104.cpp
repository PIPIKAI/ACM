//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,f[maxn],ans;
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>f[i];
    }
    int z;
    sort(f,f+n);
    if(n&1){
    	z=f[n/2];
    }
    else{
    	z=f[n/2-1];
    }
    for(int i=0;i<n;i++){
    	ans+=abs(z-f[i]);
    }
    cout<<ans<<endl;
    return 0;
}