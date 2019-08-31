#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m;
int f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int T,a,b;
    cin>>T;
    while(T--){
        cin>>f[0]>>f[1]>>n;
        f[2]=f[1]^f[0];
        cout<<f[n%3]<<endl;
    }
    return 0;
}