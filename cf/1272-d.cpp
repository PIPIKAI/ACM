#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=2e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
int f[maxn];
int k[maxn];
#define LOCAL
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>f[i];
    }
    k[0]=1;
    for (int i = 1; i < n; ++i)
    {
    	if(f[i-1]<f[i]){
    		k[i]=k[i-1]+1;
    	}
    	else{
    		k[i]=1;
    	}
    }
    int ans=k[n-1];
    int tp=0,flag=0;
    tp=k[n-1];
    // cout<<tp<<endl;
    for (int i = n-1; i>=0; i--)
    {
    	if(flag){
    		ans=max(ans,k[i]);
    		// cout<<k[i]<<endl;
    		if(f[i]<f[i+2]){
    			ans=max(ans,tp+k[i]-1);
    		}
    		else if(f[i-1] <f[i+1] ){
    			ans=max(ans,tp+k[i]-1);
    		}
    		tp=k[i];
    		flag=0;
    	}
    	if(k[i]==1){
    		flag=1;
    	}
    	 
    }
    cout<<ans<<endl;
    return 0;
}
/***

10
1 2 5 3 4 5 3 6 7  8 

4
1 4 3 2
3
1 3 2
*/