/*
	差分讲解：http://www.pianshen.com/article/2386279923/
*/
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
ll f[maxn],n,m,sum,ans,cnt=1;
int main(int argc, char * argv[]) 
{
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>f[i];
    }
    for(int i=n;i>=1;i--){
    	f[i]=f[i]-f[i-1]; 
    }
    ll up=0,down=0;
    for(int i=2;i<=n;i++)
    	if(f[i]>=0){
    		up+=f[i];
    	}
    	else{
    		down-=f[i];
    	}
    cout<<min(up,down)+abs(up-down)<<"\n"<<abs(up-down)+1;
    return 0;
}