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
ll n,m,f[maxn],ans;
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>f[i];
    }
	
	int l=1,r=n;

	while(l<r){
		ans=max( ans , min(f[l],f[r]) * (r-l));
		if(f[l] > f[r]){
			r--;
		}
		else{
			l++;
		}
	}

	cout<<ans<<endl;
    return 0;
}