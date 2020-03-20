//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e3+7;
const int inf = 0x3f3f3f3f;
int n,m,f[maxn][maxn],ans=-inf;
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		cin>>f[i][j];
    		ans=max(ans,f[i][j]);
    	}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		f[i][j]+=f[i-1][j];
    	}
    }
    for(int up=1;up<=n;up++){
    	for(int down=up;down<=n;down++){
    		int sum=0;
    		for(int i=1;i<=n;i++){
    			sum+=(f[down][i]-f[up-1][i]);
    			ans=max(ans,sum);
    			if(sum<0){
    				sum=0;
    			}
    		}
    	}
    }
    cout<<ans<<endl;
    return 0;
}