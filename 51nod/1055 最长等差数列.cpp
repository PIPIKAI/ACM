#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 7;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n, m;
int a[maxn], ans = 2;
short int dp[maxn][maxn];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    for(int i = 1; i < n - 1; i++) {
        int j = i - 1, k = i + 1;
        while(j >= 0 && k <= n - 1) {
            if(a[j] + a[k] == 2 * a[i]) {
                dp[i][k] = dp[j][i] == 0 ? 3 : dp[j][i] + 1;
                Max(ans, dp[i][k]);
                j--;
                k++;
            } else if(a[j] + a[k] < 2 * a[i]) {
                k++;
            } else {
                j--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
