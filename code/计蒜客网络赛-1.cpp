#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int K = 100 + 5;
typedef pair<int, int > P;
vector<P> G[N];
int n, k;
int sz[N];
long long dp[N][K], ans;
void dfs(int u, int from)
{
    for (int i = 1; i <= k; i++)
    {
        dp[u][i]=0x3f3f3f3f3f3f3f3f;
    }
    dp[u][0] = 0;
    sz[u] = 0;
    if (G[u].size() == 1)
    {
        dp[u][1] = 0;
        sz[u] = 1;
    }
    for (auto &p : G[u])
    {
        if (p.first == from)
            continue;
        dfs(p.first, u);
        for (int i = min(sz[u], k); i >= 0; i--)
        {
            for (int j = min(sz[p.first], k - i); j >= 0; j--)
                    dp[u][i + j] = min(dp[u][i + j], dp[u][i] + dp[p.first][j] + 1ll*j * (k - j)*p.second);
        }
        sz[u] += sz[p.first];
    }
    ans = min(ans, dp[u][k]);
}
int main()
{
    int kase;
    scanf("%d", &kase);
    for (int kas = 1; kas <= kase; kas++)
    {
        scanf("%d%d" ,&n, &k);
        for(int i = 1; i <= n; i ++)
            G[i].clear();
        for (int i = 1, u, v, w; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        printf("Case #%d: ", kas);
        ans=0x3f3f3f3f3f3f3f3f;
        dfs(1, 1);
        printf("%lld\n", ans);
    }
}
