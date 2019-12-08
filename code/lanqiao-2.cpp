// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int inf = 0x3f3f3f3f;
// #define LOCAL
int check(int i){
	int res=0;
	while(i){
		res+= (i%10)*(i%10);
		i/=10;
	}
	return res;
}
int main(int argc, char * argv[]) 
{
    
    // #ifdef LOCAL
    // // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    // //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    int n,m,ans=0;;
    cin>>n>>m;
    if(m>486){
    	cout<<0<<endl;
    }
    else{
    	for(int i=1;i<=n;i++){
    		if(check(i)==m){
    			ans++;
    		}
    	}
    	cout<<ans<<endl;
    }


    return 0;
}