#include <bits/stdc++.h>
using namespace std;

const int maxn = 700;
const int inf = 0x7f7f7f7f;
const int maxm = 80800;
typedef struct Dinic {
  typedef struct Edge {
    int u, v, w, next;
  }Edge;
  int head[maxn], hcnt;
  int cur[maxn];
  int dep[maxn];
  Edge e[maxm];
  int S, T, N;

  void init() {
    memset(head, -1, sizeof head);
    hcnt = 0;
    S = T = N = 0;
  }

  void adde(int u, int v, int w) {
    e[hcnt].u = u, e[hcnt].v = v, e[hcnt].w = w;
    e[hcnt].next = head[u]; head[u] = hcnt++;
    e[hcnt].u = v, e[hcnt].v = u, e[hcnt].w = 0;
    e[hcnt].next = head[v]; head[v] = hcnt++;
    // 01 23 45
    // i i^1
  }

  // BFS 分层
  int bfs() {
    for(int i = 0; i < N; i++) {
      dep[i] = inf;
    }
    queue<int> q;
    q.emplace(S); dep[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      for(int i = head[u]; ~i; i=e[i].next) {
        int v = e[i].v, w = e[i].w;
        if(w > 0 && dep[u] + 1 < dep[v]) {
          dep[v] = dep[u] + 1;
          if(v == T) return 1;
          q.emplace(v);
        }
      }
    }
    return dep[T] != inf;
  }

  // DFS 增广
  int dfs(int s, int mw) {
    if(s == T) return mw;
    for(int i = cur[s]; ~i; i=e[i].next) {
      cur[s] = i;
      int v = e[i].v, w = e[i].w;
      if(w <= 0 || dep[v] != dep[s] + 1) continue;
      int cw = dfs(v, min(w, mw));
      if(cw <= 0) continue;
      e[i].w -= cw;
      e[i^1].w += cw;
      return cw;
    }
    // 找一条链 S -> T
    // min w
    return 0;
  }

  int dinic() {
    int ret = 0;
    while(bfs()) {
      for(int i = 0; i < N; i++) {
        cur[i] = head[i];
      }
      while(int d = dfs(S, inf)) {
        ret += d;
      }
    }
    return ret;
  }

}Dinic;

// 
// 1. 当前弧优化。✔
// 2. BFS分层的时候，只要找到第一个连到T的边就可以停止分层了。 ✔

int n, m;

signed main() {
  // freopen("in", "r", stdin);
  int k, u, v, w;
  while(~scanf("%d %d", &n, &m)) {
    Dinic d;
    d.init(); d.S = 0; d.T = n + m + 1; d.N = d.T + 1;
    int pos = 0;
    for(int i = 1; i <= m; i++) {
      scanf("%d", &w);
      if(w != 0) d.adde(n+i, d.T, w);
      else d.adde(n+i, d.T, inf);
    }
    for(int i = 1; i <= n; i++) {
      scanf("%d %d", &w, &k);
      pos += w;
      if(w != 0) d.adde(d.S, i, w);
      else d.adde(d.S, i, inf);
      for(int j = 0; j < k; j++) {
        scanf("%d", &v);
        d.adde(i, n+v, inf);
      }
    }
    printf("%d\n", pos - d.dinic());
  }
}