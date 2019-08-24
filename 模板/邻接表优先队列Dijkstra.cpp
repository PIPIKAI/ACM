#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
const int M = 4444;
int d[M],head[M],vis[M];
struct nod{
    int nex,to,w;
}eg[M];
typedef pair<int,int> P;
int cnt=0;
inline void add(int u,int v,int w){
    eg[cnt].to=v;
    eg[cnt].w=w;
    eg[cnt].nex=head[u];
    head[u]=cnt++;
}
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> >que;
    
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        for(int i=head[v];~i;i=eg[i].nex){
            nod e=eg[i];
            if(e.w+d[v]<d[e.to]){
                d[e.to]=e.w+d[v];
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main(){
    int t,n;
    scanf("%d %d",&t,&n);
    memset(d,inf,sizeof(d));
    memset(head,-1,sizeof(head));
    for(int i=0;i<t;i++){
        int u,v,cost;
        scanf("%d %d %d",&u,&v,&cost);
        add(u,v,cost);
        add(v,u,cost);
    }
    dijkstra(1);
    printf("%d\n",d[n]);
    return 0;
}