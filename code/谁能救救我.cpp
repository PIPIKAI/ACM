#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n, m;
const int maxn = 1e6 + 7;
int f[maxn];
void show()
{
    for(int i=0;i<n;i++){
        cout<<f[i];
    }
    cout<<endl;
}
int main() {
    string s;
    cin >> n >> s;
    int ans = 0;
    int a[2] = {0, 0};
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] != s[i - 1]) {
            f[i] = f[i - 1] + 1;

        } else {
            a[cnt % 2] = f[i - 1];
            cnt++;
            f[i] = 1;
        }
        ans = max(ans, a[0] + a[1] + f[i]);
    }
    //show();
    cout << ans << endl;
    return 0;
}
/*
14
10100101111001
*/
