#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
int n,m;
struct EDGE
{
    int next,to,dis;
}edge[maxn];
int dep[maxn],cur[maxn];
int head[maxn],cnt;
void init()
{
    for(int i=0;i<maxn;i++){
        head[i]=-1;
        edge[i]=EDGE{0,0,0};
    }
    cnt=0;
}
void adde(int from,int to,int dis){
    edge[cnt].next=head[from];
    edge[cnt].dis=dis;
    edge[cnt].to=to;
    head[from]=cnt++;
    edge[cnt].next=head[to];
    edge[cnt].dis=dis;
    edge[cnt].to=from;
    head[to]=cnt++;
}
int bfs(){
    for(int i=0;i<=n;i++){
        dep[i]=inf;
    }
    queue<int> q;
    q.push(1);
    dep[1]=0;
    while (!q.empty()){
        int u=q.front();q.pop();
        for(int i=head[u];~i;i=edge[i].next){
            int to=edge[i].to;
            int dis=edge[i].dis;
            if(dis> 0 && dep[u]+1 < dep[to]){
                dep[to]=dep[u]+1;
                //if(to==n) return 1;
                q.push(to);
            } 
        }
    }
    return dep[n]!= inf;
}
int dfs(int s,int t,int mw){
    if(s==t) return mw;
    int pre=0;
    for(int i=head[s];~i;i=edge[i].next){
       // cur[s]=i;
        int to=edge[i].to,dis=edge[i].dis;
        if(dis <=0 || dep[to]!= dep[s]+1) continue;
        int tmp=min(dis,mw-pre);
        int cw=dfs(to,t,tmp);
        //if(cw<=0) continue;
        edge[i].dis-=cw;
        edge[i^1].dis+=cw;
        pre+=cw;
        if(pre== mw) return  pre;
    }   
    return pre;
}
int dinic(){
    int ret=0;
    while(bfs()){
        // for(int i=1;i<=n;i++){
        //     cur[i]=head[i];
        // }
        ret+=dfs(1,n,inf);
    }
    return ret;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>m>>n){
        init();
        for(int i=0,z,y,x;i<m;i++){
            cin>>x>>y>>z;
            adde(x,y,z);
        }
        cout<<dinic()<<endl;
    }
    return 0;
}