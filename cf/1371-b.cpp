//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
ll T,n,m,f[maxn];
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
    	cin>>n>>m;
    	if(n>m){
    		cout<<(1+m)*m/2<<endl;
    	}
    	else{
    		n=n-1;
    		cout<<((n+1)*n/2)+1<<endl;
    	}
    }
    return 0;
}