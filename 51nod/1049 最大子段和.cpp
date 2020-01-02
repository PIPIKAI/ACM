// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(s,b) memset(s, b, sizeof(s))
const int inf = 0x3f3f3f3f;
const int maxn=5e4+7;
ll n,m,f[maxn];
int main(int argc, char * argv[]) {
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>f[i];
    }
    ll now=0,ans=0;
    for(int i=0;i<n;i++){
    	if(now + f[i] <0){
    		now =0;
    	}
    	else{
			now +=f[i];
    		ans=max(ans,now);
    	}
    }
    cout<<ans<<endl;
    return 0;
}