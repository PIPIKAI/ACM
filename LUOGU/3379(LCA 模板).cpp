#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn = 5e5 + 7;
int n, m, s, head[maxn << 1], cnt;
struct Edge {
    int next, to;
} edge[maxn << 1];
int depth[maxn], fa[maxn][22], lg[maxn];
inline void add(int from, int to) {
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    head[from] = cnt;
}
void dfs(int now, int father) {
    depth[now] = depth[father] + 1;
    fa[now][0] = father;
    for(int i = 1; (1 << i) <= depth[now]; i++) {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
        ///意思是f的2^i祖先
        ///等于f的2^(i-1)祖先的2^(i-1)祖先
    }
    for(int i = head[now]; i; i = edge[i].next) {
        if(edge[i].to != father) {
            dfs(edge[i].to, now);
        }
    }
}
int lca(int x, int y) {
    if(depth[x] < depth[y]) {
        swap(x, y); ///设x的深度>=y的深度
    }
    while(depth[x] > depth[y]) {
        x = fa[x][lg[depth[x] - depth[y]] - 1];
        //先跳到同一深度
    }
    if(x == y) {
        return x;
    }
    for(int i = lg[depth[x]] - 1; i >= 0; i--) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
int main() {
    //std::ios::sync_with_stdio(false);
    scanf("%d%d%d", &n, &m, &s);
    for(int i = 0, x, y; i < n - 1; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs(s, 0);
    for(int i = 1; i <= n; i++) {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
    /// 常数优化
    while(m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
