#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e6+7;
int n, m;
string s;
int dp[maxn];
int ans1, ans2 = 1;
int update(int x) {
    if(x > ans1)
        ans1 = x, ans2 = 1;
    else if(x == ans1&&ans1!=0)
        ans2++;
}
int main() {
    int l = 0;
    std::ios::sync_with_stdio(false);
    cin >> s;
    vector<int > q;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            q.push_back(i);
        } else {
            if(q.empty()){
                continue;
            }
            int t=q.back();
           dp[i]=dp[t-1]+i-t+1;
           update(dp[i]);
           q.pop_back();
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}

/*
())()(()
2 3
)((())))(()())
6 2
((((())((((())
4 2
(((()))(((
6 1
*/
