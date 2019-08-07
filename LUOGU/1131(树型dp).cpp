#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn = 1e6 + 7;
int n, s, cnt, head[maxn], dp[maxn];
ll ans;
struct Edge {
    int next, to, dis;//Ȩֵ
} edge[maxn];
void add(int from, int to, int dis) {
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    edge[cnt].dis = dis;
    head[from] = cnt;
}
void dfs(int now, int fa) {
    for(int i = head[now]; i; i = edge[i].next) {
        if(fa != edge[i].to) {
            dfs(edge[i].to, now);
        }
    }
    for(int i = head[now]; i; i = edge[i].next) {
        if(fa != edge[i].to) {
            dp[now] = max(dp[now], edge[i].dis);
        }
    }
    for(int i = head[now]; i; i = edge[i].next) {
        if(fa != edge[i].to) {
            ans += (dp[now] - edge[i].dis);
        }
    }
    for(int i = head[fa]; i; i = edge[i].next) {
        if(now == edge[i].to) {
            edge[i].dis += dp[now];
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> s;

    for(int i = 1, a, b, t; i < n; i++) {
        cin >> a >> b >> t;
        add(a, b, t);
        add(b, a, t);
    }
    vector<int> iv;
    auto ite = iv.begin();
    dfs(s, 0);
    cout << ans << endl;
    return 0;
}
