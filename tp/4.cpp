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
const int mod=1e9+7;
const int inf = 0x3f3f3f3f;
int n,m,y[maxn],x[maxn];
ll a[500][500],b[500][500];
ll ans;
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    // for(int i=0;i<3;i++){
    // 	cin>>x[i]>>y[i];
    // }
    // n=x[2]-x[0],m[y2]-y[0];
    a[1][1]=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		a[i][j]+=a[i-1][j]+a[i][j-1];
    	}
    }
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}