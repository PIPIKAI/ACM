#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn = 2e3 + 7;
int n, ans, u, v, w, b[maxn];
int d[maxn];
int f[maxn];
int o[maxn];
bool cmp(int a, int b) {
    return d[a] > d[b];
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    b[1] = 1, o[1] = o[0] = maxn;
    for(int i = 2; i <= n; i++) {
        cin >> f[i];
        d[i] = d[f[i]] + 1;
        b[i] = i;
        o[i] = maxn;
    }
    sort(b + 1, b + 1 + n, cmp);
    for(int i = 1; i <= n; i++) {
        v = b[i];
        w = f[v];
        u = f[f[v]];
        o[v] = min(o[v], min(o[w] + 1, o[u] + 2));
        if(o[v] > 2) {
            o[u] = 0;
            ans++;
            o[f[u]] = min(o[f[u]], 1);
            o[f[f[u]]] = min(2, o[f[f[u]]]);
        }
    }
    cout << ans << endl;
    return 0;
}
