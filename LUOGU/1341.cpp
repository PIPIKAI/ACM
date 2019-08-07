#include <bits/stdc++.h>
using namespace std;
const int maxn = 255;
int G[maxn][maxn], depth[maxn], n, cnt, hen, f[maxn], sum[maxn];
char tmp[maxn], rb[maxn * maxn];
void dfs(int x)
{
    for (int i = 0; i < maxn; i++)
        if (G[x][i])
            G[x][i] = G[i][x] = 0, dfs(i);
    rb[n--] = x;
}
inline int find(int x)
{
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}
int main()
{
    cin >> n;
    for (int i = 0; i < maxn; i++)
        f[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        G[tmp[0]][tmp[1]] = G[tmp[1]][tmp[0]] = 1;
        int fx = find(tmp[0]), fy = find(tmp[1]);
        f[fx] = fy;
        depth[tmp[0]]++;
        depth[tmp[1]]++;
    }
    int ans = 0;
    for (int i = 0; i < maxn; i++)
        if (f[i] == i && depth[i])
            ans++;
    if (ans != 1)
    {
        puts("No Solution");
        return 0;
    }
    for (int i = 0; i < maxn; i++)
        if (depth[i] & 1)
        {
            cnt++;
            if (!hen)
                hen = i;
        }
    if (!hen)
        for (int i = 0; i < maxn; i++)
            if (depth[i])
            {
                hen = i;
                break;
            }
    if (cnt && cnt != 2)
    {
        puts("No Solution");
        return 0;
    } /// 两个的那种情况
    dfs(hen);
    puts(rb);
    return 0;
}