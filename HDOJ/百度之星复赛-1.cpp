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
struct Edge {
    int next, to;
} edge[maxn];
int  cnt, head[maxn];

void add(int from, int to) {
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    head[from] = cnt;
}
int w[maxn][2];
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            add(a,b);
        }
        for(int i=1;i<=n;i++){
            cin>>w[i][0]>>w[i][1];
        }
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            a=f[i][0];
            b=f[i][1];
            w[a][0],w[a][1] , w[b][0],w[b][1]
        }
    }
    return 0;
}