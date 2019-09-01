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
int dp[maxn][2];
int xiashu[maxn];
vector<int> f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n){
        mem(father,0);
        for(int i=1;i<=n;i++){
            cin>>dp[i][1];
            f[i].clear();
        }
        int l,k;
        while(cin>>l>>k,l&&k){
            f[k].push_back(l);
            xiashu[k]=l;
        }
    }
    return 0;
}