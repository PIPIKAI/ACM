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
const int MAXN = 1e5+7;
int head[MAXN],dis[MAXN]; 
int nextt[MAXN];
bool vis[MAXN];
struct node{
	int u,v,c;
	node(){}
	node(int u,int v,int c){
		this->u=u; this->v=v; this->c=c;
	}
}p[MAXN];
int e,n,m;
int cnt[MAXN];
void addnode(int u,int v,int c){
	p[e]=node(u,v,c);
	nextt[e]=head[u]; head[u]=e++;//head[i]表示节点i的第一条边的标号，next[e]表示第e条边的下一条边的编号。
}
bool relax(int u,int v,int c){
	if(dis[v]>dis[u]+c){
		dis[v]=dis[u]+c;
		return true;
	}
	return false;
}
void init(){
	memset(head,-1,sizeof(head));
	memset(nextt,-1,sizeof(nextt));
	e=0;
	for(int i=0;i<m;i++){
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);
		addnode(u,v,-c);
		addnode(v,u,-c);//反向边 
	}
    
}
bool spfa(int src){
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		dis[i]=inf;
	}
	dis[src]=0; vis[src]=true;
	queue<int>que; que.push(src);
	while(que.size()){
		int now=que.front(); que.pop();
		vis[now]=false;//出队后取消标记 
		for(int i=head[now];i!=-1;i=nextt[i]){
			if(relax(now,p[i].v,p[i].c)&&!vis[p[i].v]){//标记必须写在松弛之后，不然无法松弛以在队列内的点
				if((++cnt[p[i].v])>n) break;//一个点如果被松弛了n次，说明产生了负环 
				que.push(p[i].v);
				vis[p[i].v]=true;
			}
		}
	}
	return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        init();
        for(int i=0;i<6;i++){
            int x,y;
            cin>>x>>y;
            spfa(y) ? cout<<1<<endl : cout<<0<<endl;
            cout<<dis[x]<<endl;
        }
    }
    return 0;
}