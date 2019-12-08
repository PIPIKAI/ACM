#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n, m;

struct Edge {
    int next, to, dis;//È¨Öµ
} edge[MAXN];
int  cnt, head[MAXN];

void add(int from, int to, int dis) {
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    edge[cnt].dis = dis;
    head[from] = cnt;
}

int main() {
    std::ios::sync_with_stdio(false);
    //´æ±ß
    add(1, 2, 1);
    add(2, 1, 1);
    add(2, 3, 3);
    //±éÀú
    for(int i = head[x]; i; i = edge[i].next)
        if(edge[i].to != fa) {
            dfs(edge[i].to, x);
        }
    return 0;
}
