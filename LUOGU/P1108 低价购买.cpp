#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n, m;
const int maxn = 5e3 + 7;
ll f[maxn], dp1[maxn], dp2[maxn], ans1, ans2;
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    for(int i = 1; i <= n; i++) {
        dp1[i] = 1;
        for(int j = 1; j < i; j++) {
            if(f[i] < f[j]) {
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }

        }
        ans1 = max(ans1, dp1[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(dp1[i] == 1) {
            dp2[i] = 1;
        }
        for(int j = 1; j < i; j++) {
            if(f[i] == f[j] && dp1[i] == dp1[j]) {
                dp2[i] = 0;
            } else if(f[i] < f[j] && dp1[i] == dp1[j] + 1) {
                dp2[i] += dp2[j];
            }
        }
        if(ans1 == dp1[i])
            ans2 += dp2[i];
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
