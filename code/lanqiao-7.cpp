// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int inf = 0x3f3f3f3f;
#define LOCAL
const int maxn=1e5+7;
int f[maxn];
int main(int argc, char * argv[]) 
{
    
    // #ifdef LOCAL
    // // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    // //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>f[i];
    }
    int ans=1,len=1;
    for(int i=1;i<n;i++){
    	if(f[i-1]<f[i]){
    		len++;
    	}
    	else{
    		ans=max(ans,len);
    		len=1;
    	}
    }
    cout<<ans<<endl;

    return 0;
}