#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y)  y>x? x=y: x=x
const int maxn = 1e5 + 7;
int n, q, p, a[maxn];
struct node {
    int l, r;
    ll adlazy, mulazy, sum; /// 乘法和加法取模
} tree[maxn * 4];
void push_up(int x) {
    tree[x].sum = (tree[x << 1].sum + tree[x << 1 | 1].sum) % p;
}
void built(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].adlazy = 0;
    tree[x].mulazy = 1;
    if(l == r) {
        tree[x].sum = a[l];
    } else {
        int mid = (l + r) >> 1;
        built(x << 1, l, mid);
        built(x << 1 | 1, mid + 1, r);
        push_up(x);
    }
}
void push_down(int x, int l, int r) {
    int mid = (l + r) >> 1;
    tree[x << 1].sum = (tree[x << 1].sum * tree[x].mulazy + tree[x].adlazy * (mid - l + 1)) % p;
    tree[x << 1 | 1].sum = (tree[x << 1 | 1].sum * tree[x].mulazy + tree[x].adlazy * (r - mid)) % p;
    tree[x << 1].mulazy = (tree[x << 1].mulazy * tree[x].mulazy) % p;
    tree[x << 1 | 1].mulazy = (tree[x << 1 | 1].mulazy * tree[x].mulazy) % p;
    tree[x << 1].adlazy = (tree[x << 1].adlazy * tree[x].mulazy + tree[x].adlazy) % p;
    tree[x << 1 | 1].adlazy = (tree[x << 1 | 1].adlazy * tree[x].mulazy + tree[x].adlazy) % p;
    tree[x].adlazy = 0;
    tree[x].mulazy = 1;
    push_up(x);
}

void update1(int x, int l, int r, int val) {
    int L = tree[x].l, R = tree[x].r;
    if(l <= L && R <= r) {
        tree[x].sum = (tree[x].sum * val) % p;
        tree[x].mulazy = (tree[x].mulazy * val) % p;
        tree[x].adlazy = (tree[x].adlazy * val) % p;
    } else {
        push_down(x, L, R);
        int mid = (L + R) >> 1;
        if(mid >= l)
            update1(x << 1, l, r, val);
        if(mid < r)
            update1(x << 1 | 1, l, r, val);
        push_up(x);
    }
}
void update2(int x, int l, int r, int val) {
    int L = tree[x].l, R = tree[x].r;
    if(l <= L && R <= r) {
        tree[x].adlazy = (tree[x].adlazy + val) % p;
        tree[x].sum = (tree[x].sum + val * (R - L + 1)) % p;
    } else {
        push_down(x, L, R);
        int mid = (L + R) >> 1;
        if(mid >= l)
            update2(x << 1, l, r, val);
        if(mid < r)
            update2(x << 1 | 1, l, r, val);
        push_up(x);
    }
}
ll query(int x, int l, int r) {
    int L = tree[x].l, R = tree[x].r;
    if(l <= L && R <= r) {
        return tree[x].sum;
    } else {
        push_down(x, L, R);
        ll ans = 0;
        int mid = (L + R) >> 1;
        if(mid >= l)
            ans += query(x << 1, l, r);
        if(mid < r)
            ans += query(x << 1 | 1, l, r);
        ans %= p;
        push_up(x);
        return ans;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> q >> pzz;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    built(1, 1, n);
    while(q--) {
        int c, l, r, k;
        cin >> c >> l >> r;
        if(c == 1) {
            cin >> k;
            update1(1, l, r, k);
        } else if(c == 2) {
            cin >> k;
            update2(1, l, r, k);
        } else {
            cout << query(1, l, r) << endl;
        }
    }
    return 0;
}
