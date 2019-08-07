#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n, m;
struct node {
    int l, r;
    bool operator < (const node &a)const {
        return r > a.r;
    }
};
priority_queue<node> q1;/// ¥Ê“ª∂‘
priority_queue<int ,vector<int>,greater<int> > q2;/// µ•∂¿µƒ◊Û
int main() {
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int ans1 = 0, ans2 = 0;
        while(!q1.empty()) q1.pop();
         while(!q2.empty()) q2.pop();
        cin >> n;
        for(int i = 0, t; i < n; i++) {
            cin >> t;
            if(q2.empty()) {
                q2.push(t);
            } else {
                if(q1.empty()) {
                    if(t > q2.top()) {
                        ans2 += 2;
                        q1.push(node{q2.top(), t});
                        ans1 += t - q2.top();
                        q2.pop();
                    } else {
                        q2.push(t);
                    }
                } else {
                    int tp = q2.top();
                    node k = q1.top();
                    int a = t - tp;/// ”Î◊Û¿®∫≈≈‰∂‘
                    int  b = t - k.l;/// ÃÊªª”“¿®∫≈
                    if(a <= 0 && b <= 0) {
                        q2.push(t);
                    } else if(a < b) {
                        ans1 += (b - (k.r - k.l));
                        q1.pop();
                        q2.pop();
                        q1.push(node{k.l, t});
                        q2.push(k.r);
                    } else {
                        ans1 += a;
                        ans2 += 2;
                        q2.pop();
                        q1.push(node{tp, t});
                    }
                }
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
