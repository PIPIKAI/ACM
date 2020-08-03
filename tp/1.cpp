//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
ll n,m,T,f[maxn],k[maxn];
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
    	cin>>n>>m;
    	int ans=0;
    	for(int i=0;i<n;i++){
    		cin>>f[i];
    	}
    	sort(f,f+n);
    	for(int i=0;i<n;i++){
    		k[i]=ceil((float)m/f[i]);
    	}
    	int q=n;
    	for(int i=n-1;i>=0;i--){
    		if(k[i] == q-i){
    			q=i;
    			ans++;
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}