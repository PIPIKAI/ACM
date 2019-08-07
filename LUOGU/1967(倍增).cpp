#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn = 5e5 + 7;
int cnt, head[maxn << 1], q, n, m;
struct node {
    int next, to, w;
} edge[maxn << 1];
inline add(int from, int to, int w) {
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    edge[cnt].w = w;
    head[from] = cnt;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
    }
    return 0;
}
