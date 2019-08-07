#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
char buf[(1 << 22)], *p1 = buf, *p2 = buf;
inline int read() {
    char c = getchar();
    int x = 0, f = 1;
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
#define read(x) x=read()
int n, m;
const int maxn = 1e6 + 7;
int f[maxn];
priority_queue<int, vector<int>, greater<int> >q;
struct Edge {
    int next, to;//Ȩֵ
} edge[maxn];
int  cnt, head[maxn];

void add(int from, int to) {
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    head[from] = cnt;
}
int ans[maxn],id;
bool vis[maxn];
int find(int x) {
    while(f[x]!=x) x=f[x];
    return x;
}
void mer(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);
    if(f1 < f2)
        f[f2] = f1;
    if(f1 > f2)
        f[f1] = f2;
}
void bfs() {
    while(!q.empty()) {
        int tp = q.top();
        q.pop();
        if(!vis[tp]) {
            vis[tp] = 1;
            ans[id++]=tp;
             for(int i = head[tp]; i ; i=edge[i].next) {
            int to=edge[i].to;
            if(!vis[to]) {
                q.push(to);
                }
            }
        }

    }
}
int main() {
    int t;
    read(t);
    while(t--) {
        cnt=id=0;
        read(n);
        read(m);
        for(int i = 1; i <= n; i++) {
            f[i] = i;
            vis[i]=false;
            head[i]=0;
            edge[i].next=0;
            edge[i].to=0;
        }
        for(int i = 0, a, b; i < m; i++) {
            read(a);
            read(b);
            add(a,b);
            add(b,a);
            mer(a, b);
        }
        for(int i = 1; i <= n; i++) {
            if(i == f[i]) {
                q.push(i);
            }
        }
        printf("%d\n", q.size());
        bfs();
        for(int i = 0, k = 0; i < id; i++, k++) {
            printf("%d%s", ans[i], i == id - 1 ?  "\n" : " ");
        }
    }
    return 0;
}
