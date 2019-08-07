#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n, m;
ll ans1,ans2;
int f[1005][1005];
void colc(ll x,ll y)
{
    ll ans = x * y;
    if(ans > ans1) {
        ans2 = ans1;
        ans1 = ans;
    } else if(ans > ans2) {
        ans2 = ans;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    string s[1005];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            f[i][j]=s[i][j]=='0' ? 0 : 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i != 0 && f[i][j] != 0) {
                f[i][j] = 1 + f[i - 1][j];
            }
        }
        int   top = 0;
        vector<int> q(m + 5, 0);
        vector<int> w(m + 5, 0);
        for(int j = 0; j <= m; j++) {
            ll t;
            if(j == m) {
                t = 0;
            } else {
                t = f[i][j] ;
            }
            if(q[top] < t) {
                q[++top] = t;
                w[top] = 1;
            } else {
                ll cnt = 0;
                while(top > 0 && q[top] >= t) {
                    ll tp = q[top] * (w[top] + cnt) ;
                    if(tp > ans1) {
                        ans2 = ans1;
                        ans1 = tp;
                    } else {
                        if(tp > ans2) {
                            ans2 = tp;
                        }
                    }
                    cnt += w[top];
                    top--;
                }
                q[++top] = t;
                w[top] = cnt + 1;
            }
        }
    }
    cout << ans2 << endl;
    return 0;
}

