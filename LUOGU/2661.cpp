#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, f[maxn], ans = 0x7777777, d[maxn];
int ff(int x)
{
    if (x != f[x])
    {
        int last = f[x];
        f[x] = ff(f[x]);
        d[x] += d[last];
    }
    return f[x];
}
void mer(int a, int b)
{
    int x = ff(a);
    int y = ff(b);
    if (x != y)
    {
        f[y] = x;
        d[b] = d[a] + 1;
    }
    else
    {
        ans = min(ans, d[a] + d[b] + 1);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1, t; i <= n; i++)
    {
        cin >> t;
        mer(i, t);
    }
    cout << ans << endl;
    return 0;
}