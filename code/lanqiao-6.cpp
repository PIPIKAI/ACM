// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int inf = 0x3f3f3f3f;
const int maxn=1e6+7;
#define LOCAL
int f[maxn],fron[maxn],bac[maxn],n;
int main(int argc, char * argv[]) 
{
    
    // #ifdef LOCAL
    // // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    // //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    /* code */
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>f[i];
    	if(i==0)
    	fron[i]=inf;
    	else
    		fron[i]=min(min(fron[i-1],f[i-1]),f[i]);
    }
    for(int i=n-1;i>=0;i--){
    	if(i==n-1)
    	bac[i]=-inf;
    	else
    		bac[i]=max(max(bac[i+1],f[i+1]),f[i]);
    }
    int ans=0;
    for (int i = 0; i < n; ++i)
    {
    	// printf("ft %d\n", fron[i]);
    	// printf("bac %d\n", bac[i]);
    	if(f[i]> fron[i] && f[i]<bac[i]){
    		ans++;
    	}
    }
    cout<<ans<<"\n";
    return 0;
}