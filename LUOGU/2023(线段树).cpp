#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn = 1e5 + 7;
int n, p;
struct node {
    int l, r;
    ll sum, lazy1, lazy2;
} tree[maxn * 4];
int f[maxn];
void push_up(int x) {
    tree[x].sum = (tree[x << 1].sum + tree[x << 1 | 1].sum) % p;
}
void built(int x, int l, int r) {
    tree[x] = {l, r, 0, 0, 1};
    if(l == r) {
        tree[x].sum = f[l];
    } else {
        int mid = (l + r) >> 1;
        built(x << 1, l, mid);
        built(x << 1 | 1, mid + 1, r);
        pusn_up(x);
    }
}
void update(int x, int l, int r, ll val, int flag) {
    int L = tree[x].l, R = tree[x].r;
    int mid = (L + r) >> 1;
    if(flag == 1) {
        if(l <= L && r >= R) {
            tree[x].sum = (tree[x].sum * val) % p;
            tree[x].lazy1 = (tree[x].lazy1 * val) % p;
            tree[x].lazy2 = (tree[x].lazy2 * val) % p;
        } else {
            push_down(x, L, R);
        }
    } else {
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin >> n >> p;
    for(int i = 0; i < n; i++) {
        cin >> f[i];
    }
    built(1, 1, n);
    for(int i = 0; i < n; i++) {
        int nb, t, g, c;
        cin >> nb >> t >> g;
        if(nb != 3) {
            cin >> c;
            update(1, t, g, c, nb)
        } else {
            cout << qurey(1, t, g) << endl;
        }
    }
    return 0;
}
