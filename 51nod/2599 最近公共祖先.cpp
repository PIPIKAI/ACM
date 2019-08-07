#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=1e4+7;
struct node {
    int next,to;
}e[maxn<<1];
int head[maxn<<1],cnt;
void add_edge(int from,int to)
{
    e[++cnt].next=head[from];
    e[cnt].to=to;
    head[from]=cnt;

}
int tot,seq[maxn<<1],pos[maxn<<1],dep[maxn<<1];/*结束*/
///预处理dep，dfs序数组seq
void dfs(int now,int fa,int d)
{
    pos[now]=++tot,seq[tot]=now,dep[tot]=d;
    for(int i=head[now];i;i=e[i].next){
        int v=e[i].to;
        if(v==fa){
            continue;
        }
        dfs(v,now,d+1);
        seq[++tot]=now,dep[tot]=d;
    }
}
int anc[maxn<<1][20];///anc[i][j]代表i结点向上跳2^j层对应的结点
void init(int len)
{
    for(int i=1;i<=len;i++){
        anc[i][0]=i;
    }
    for(int k=1;(1<<k)<=len;k++){
        for(int i=1;i+(1<<k)-1<=len;i++){
            if(dep[anc[i][k-1] ]< dep[anc[i+1<<(k-1)][k-1]] ){
               anc[i][k]=anc[i][k-1];
               }
               else{
                anc[i][k]=anc[i+1<<(k-1)][k-1];
               }
        }
    }
}
int rmq(int l,int r){
    int k=log2(r-l+1);
    return dep[anc[l][k]] < dep[anc[r+1-(1<<k)][k] ] ? anc[l][k] : anc[r+1-(1<<k)][k];
}
int calc(int x,int y)
{
    x=pos[x],y=pos[y];
    if( x >y) swap(x,y);
    return seq[rmq(x,y)];
}
int lca(int a,int b)
{

    return calc(a,b);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        add_edge(x,y);
        add_edge(y,x);
    }
    dep[0]=inf;
    dfs(1,0,1);
    init(tot);
    cin>>m;
    for(int i=0,a,b;i<m;i++){
        cin>>a>>b;
        cout<<lca(a,b)<<endl;;
    }
    return 0;
}
