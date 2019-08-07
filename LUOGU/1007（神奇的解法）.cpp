#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int l, n, m, ans, mans = 0;
int main() {
    std::ios::sync_with_stdio(false);
    cin >> l >> n;
    for(int i = 0, t; i < n; i++) {
        cin >> t;
        ans = max(ans, min( abs(l + 1 - t), t));
        mans = max(mans, max( abs(l + 1 - t), t));
    }
    cout << ans << " " << mans << endl;
    return 0;
}
