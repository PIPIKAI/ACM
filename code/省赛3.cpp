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
int du[maxn];
struct EDGE
{
    int 
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    for(int i=1,a,b;i<n;i++){
        cin>>a>>b;
        f[b].push_back(a);
        du[a]++;
    }
    return 0;
}