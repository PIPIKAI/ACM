#include <cstdio>
#define MN 401000
#define mod 23333

int l[MN], r[MN], a[MN];
int lazy[MN], sum1[MN], sum2[MN];
int sdfn[MN], edfn[MN], dfn = 0, ddfn[MN];
int h[MN], nxt[MN * 2], to[MN * 2], K = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void add(int x, int v)
{
    v %= mod;
    sum2[x] += (r[x] - l[x] + 1) % mod * v % mod * v % mod + 2 * sum1[x] * v % mod; sum2[x] %= mod;
    sum1[x] += (r[x] - l[x] + 1) % mod * v % mod; sum1[x] %= mod;
    lazy[x] = (lazy[x] + v) % mod;
}

void pushdown(int x)
{
    if(lazy[x]) add(x << 1, lazy[x]), add(x << 1 | 1, lazy[x]), lazy[x] = 0;
}

void build(int x, int L, int R)
{
    l[x] = L; r[x] = R;
    if(L == R) {add(x, a[ddfn[L]]); return;}
    int mid = L + R >> 1;
    build(x << 1, L, mid);
    build(x << 1 | 1, mid + 1, R);
    sum1[x] = (sum1[x << 1] + sum1[x << 1 | 1]) % mod;
    sum2[x] = (sum2[x << 1] + sum2[x << 1 | 1]) % mod;
}

void modify(int x, int L, int R, int v)
{
    if(L == l[x] && R == r[x]) {add(x, v); return;}
    pushdown(x); int mid = l[x] + r[x] >> 1;
    if(R <= mid) modify(x << 1, L, R, v);
    else if(L > mid) modify(x << 1 | 1, L, R, v);
    else modify(x << 1, L, mid, v), modify(x << 1 | 1, mid + 1, R, v);
    sum1[x] = (sum1[x << 1] + sum1[x << 1 | 1]) % mod;
    sum2[x] = (sum2[x << 1] + sum2[x << 1 | 1]) % mod;
}

int query(int x, int L, int R)
{
    if(L == l[x] && R == r[x]) return sum2[x];
    pushdown(x); int mid = l[x] + r[x] >> 1;
    if(R <= mid) return query(x << 1, L, R);
    else if(L > mid) return query(x << 1 | 1, L, R);
    else return (query(x << 1, L, mid) + query(x << 1 | 1, mid + 1, R)) % mod;
}

void dfs(int x, int fa)
{
    sdfn[x] = ++dfn; ddfn[dfn] = x;
    for(int i = h[x]; i; i = nxt[i])
    {
        if(to[i] == fa) continue;
        dfs(to[i], x);
    }
    edfn[x] = dfn;
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i < n; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        ins(u, v); ins(v, u);
    }
    dfs(1, 0);
    build(1, 1, n);
    for(int i = 1; i <= m; i++)
    {
        int t, l, r; scanf("%d%d", &t, &l);
        if(t == 1)
        {
            scanf("%d", &r);
            modify(1, sdfn[l], edfn[l], r);
        }
        else
        {
            printf("%d\n", query(1, sdfn[l], edfn[l]));
        }
    }
    return 0;
}
