#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[100];
ll n, need;
map<ll, string> vis;
void dfs(int l, int r, ll sum, string s, int flag)
{
    if (l >= r){
        if (flag){
            if (vis[need - sum] != "")
                cout << vis[need - sum] << s << endl;
        }
        else{
            vis[sum] = s;
        }
        return;
    }
    dfs(l + 1, r, sum + f[l], s + '1', flag);
    dfs(l + 1, r, sum, s + '0', flag);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> need;
    for (int i = 0; i < n; i++)
        cin >> f[i];
    dfs(0, n / 2, 0, "", 0);
    dfs(n / 2, n, 0, "", 1);
    return 0;
}