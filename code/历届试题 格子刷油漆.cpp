#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();return x * f;
}
#define read(x) x=read()
int n,m;
int dp[3][1003][2003]; /// 在 i,j 位置上 填好了k 个 字母的 总方案个数
int main()
{
    std::ios::sync_with_stdio(false);
    read(n);
    for(int i=1;i<=2;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=x*n;k++){
                dp[i][j][k]=dp[i-1][j][k-1] + dp[i-1][j-1][k-1] + dp[i][j-1][k-1] + dp[i+1][j];
            }
        }
    }
    return 0;
}
