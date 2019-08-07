#include<iostream>
#include<cstring>
using namespace std;
typedef unsigned long long ll;
const int maxn = 1e7 + 1000;
ll mod;
ll x0, x1, x, y;
char s[maxn];
typedef struct node {
    ll r[2][2];
    node() {
        memset(r, 0, sizeof(r));
    }
} NODE;
NODE a, b;
NODE pt(NODE ai, NODE bi) {
    NODE c;
    //memset(c.r,0,sizeof(c.r));
    for(ll i = 0; i < 2; i++) {
        for(ll j = 0; j < 2; j++) {
            for(ll k = 0; k < 2; k++) {
                c.r[i][j] += ((ai.r[i][k] % mod) * (bi.r[k][j] % mod)) % mod;
                c.r[i][j] %= mod;
            }
        }
    }
    return c;
}
ll qmod(ll n) {
    //cout << n << endl;
    while(n) {
        if(n & 1)
            b = pt(a, b);
        a = pt(a, a);
        n = n >> 1;
    }
    ll ans = ((b.r[0][0] * x1) % mod + (b.r[0][1] * x0) % mod) % mod;
    cout << ans << endl;
    return 0;
}
ll ouler(ll n) {
    ll ans = n, r = n;
    for(ll i = 2; i * i <= r; i++) {
        if(r % i == 0) {
            ans -= ans / i;
            while(r % i == 0) {
                r /= i;
            }
        }
    }
    if(r > 1) {
        ans -= ans / r;
    }
    return ans;
}

//利用公式
void solve(char *s) {
    ll PHI = ouler(mod);
    ll res = 0, l = strlen(s);
    for(ll i = 0; i < l; i++) {
        res = (res * 10 + s[i] - '0');
        if(res > mod)break;
    }
    if(res < PHI) {
        qmod(res - 1);
        return ;
    } else {
        res = 0;
        for(ll i = 0; i < l; i++) {
            res = (res * 10 + s[i] - '0') % PHI;
        }
        qmod(res + PHI - 1);
        return;
    }
}

int main() {
    cin >> x0 >> x1 >> x >> y;
    cin >> s >> mod;
    x0 %= mod;
    x1 %= mod;
    x %= mod;
    y %= mod;
    b.r[0][0] = 1;
    b.r[0][1] = 0;
    b.r[1][0] = 0;
    b.r[1][1] = 1;
    a.r[0][0] = x;
    a.r[0][1] = y;
    a.r[1][0] = 1;
    a.r[1][1] = 0;
    solve(s);
    return 0;
}
/*
1 1 1 1
100 1000000007
782204094
*/
/*
1 1 1 1
101 1000000001
706307911
*/
