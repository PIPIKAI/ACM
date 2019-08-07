#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn = 1e3 + 7;
ll n, m;
ll lcm(ll a, ll b) {
    ll t = __gcd(a, b);
    return (a * b) / t;
}
ll ans[maxn], f[maxn];
int main() {
    std::ios::sync_with_stdio(false);
    while(cin >> n >> m) {
        mem(f, 0);
        mem(ans, 0);
        ll act = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> f[i];
            sum += f[i];
        }
        act = f[0];
        for(int i = 1; i < n; i++) {
            act = lcm(act, f[i]);
        }
        ll actsum = 0;
        for(int i = 0; i < n; i++) {
            actsum += (act / f[i]);
        }
        if(m >= actsum && m % actsum == 0) {
            cout << "Yes" << endl;
            ll k = m / actsum;
            for(int i = 0; i < n; i++) {
                cout << k*(act / f[i]);
                if(i!=n-1){
                    cout<<" ";
                }
            }
            cout << endl;
        } else {
            cout << "No" << endl;
            continue;
        }
    }
    return 0;
}
