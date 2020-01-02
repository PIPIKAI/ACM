// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(s,b) memset(s, b, sizeof(s))
const int inf = 0x3f3f3f3f;
const int maxn=5e4+7;
ll n,m,f[maxn],k[maxn],sum=0;
int main(int argc, char * argv[]) {
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>f[i];k[i]=-f[i];
        sum+=f[i];
    }
    ll now1=0,now2=0,ans1=0,ans2=0;
    for(int i=n-1;i>=0;i--){
        if(now1 + f[i] <0){
            now1 =0;
        }
        else{
            now1 +=f[i];
            ans1=max(ans1,now1);
        }
        if(now2 + k[i] <0){
            now2 =0;
        }
        else{
            now2 +=k[i];
            ans2=max(ans2,now2);
        }
    }
    cout<<max(ans1,sum+ans2)<<endl;
    return 0;
}