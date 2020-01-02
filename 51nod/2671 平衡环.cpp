#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn = 1e2 + 7;
int n,head[maxn << 1], cnt;
struct Edge {
    int next, to,w;
} edge[maxn << 1];
int depth[maxn], fa[maxn][22], lg[maxn],root[maxn];
inline void add(int from, int to,int w) {
    edge[++cnt].next = head[from];
    edge[cnt].to = to;
    edge[cnt].w=w;
    head[from] = cnt;
}
void dfs(int now, int father,int w) {
    depth[now] = depth[father] + 1;
    root[now]=root[father] + w;
    fa[now][0] = father;
    for(int i = 1; (1 << i) <= depth[now]; i++) {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
        ///意思是f的2^i祖先
        ///等于f的2^(i-1)祖先的2^(i-1)祖先
    }
    for(int i = head[now]; i; i = edge[i].next) {
        if(edge[i].to != father) {
            dfs(edge[i].to, now,edge[i].w);
        }
    }
}
int lca(int x, int y) {
    if(depth[x] < depth[y]) {
        swap(x, y); ///设x的深度>=y的深度
    }
    while(depth[x] > depth[y]) {
        x = fa[x][lg[depth[x] - depth[y]] - 1];
        //先跳到同一深度
    }
    if(x == y) {
        return x;
    }
    for(int i = lg[depth[x]] - 1; i >= 0; i--) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i], y = fa[y][i];
        }
    }
    return fa[x][0];
}
int dis(int x,int y){
	return root[x]+root[y]-2*root[lca(x,y)];
}
int len(int x,int y){
	return depth[x]+depth[y]-2*depth[lca(x,y)];
}
int main() {
    // std::ios::sync_with_stdio(false);
    scanf("%d", &n);
    for(int i = 0, x, y,w; i < n - 1; i++) {
        scanf("%d%d%d", &x, &y,&w);
        if(w==4) w=-1;
        if(w==7) w=1;
        add(x, y,w);
        add(y, x,w);
    }
    dfs(1, 0 , 0);
    for(int i = 1; i <= n; i++) {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }
    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		if(dis(i,j)==1 && len(i,j) >=3){
    			printf("%d %d %d\n",i,j,4 );
    			return 0;
    		}
    		if(dis(i,j)==-1 && len(i,j) >=3){
    			printf("%d %d %d\n",i,j,7 );
    			return 0;
    		}
    	}
    }
    printf("-1\n");
    return 0;
}
