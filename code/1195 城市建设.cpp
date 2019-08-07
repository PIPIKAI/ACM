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
int n,m,ans=1e9,a[20000];
vector<vector<int > > f;
int main()
{
    std::ios::sync_with_stdio(false);
    read(n),read(m);
    for(int i=0;i<m;i++){
        int a,b,c;
        read(a),read(b),read(c);
        f[a][b]=f[b][a]=c;
    }
    for(int i=0;i<n;i++){
        read(a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
