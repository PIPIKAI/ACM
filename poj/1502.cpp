// 最短路堆优化：O(（V+E logV )
#pragma comment(linker, "/STACK:1024000000,1024000000")
// #include <bits/stdc++.h>
#include<set>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int maxm=1e5+7;
const int inf = 0x3f3f3f3f;
struct edge
{
	int v,w,next;
}e[maxm];
int f[maxn],p[maxn],eid,dis[maxn];
bool vis[maxn];
int n,m,t;
typedef pair<int,int> PII;
set<PII, less<PII> > min_heap;  // 用 set 来伪实现一个小根堆，并具有映射二叉堆的功能。堆中 pair<int, int> 的 second 表示顶点下标，first 表示该顶点的 dist 值
set<PII,less<PII> >:: iterator iter;
#define LOCAL
void mapinit(){
	mem(p,-1);
	eid=0;
}
void insert1(int u,int v,int w){
	e[eid].v=v;
	e[eid].w=w;
	e[eid].next=p[u];
	p[u]=eid++;
}
void insert2(int u,int v,int w){
	insert1(u,v,w);
	insert1(v,u,w);
}
bool dijkstra(int s) {
    // 初始化 dist、小根堆和集合 U
    mem(vis, 0);
    mem(dis, 0x3f);
    min_heap.insert(make_pair(0, s));
    dis[s] = 0;
    for (int i = 0; i < n; ++i) {
        if (min_heap.size() == 0) {  // 如果小根堆中没有可用顶点，说明有顶点无法从源点到达，算法结束
            return false;
        }
        // 获取堆顶元素，并将堆顶元素从堆中删除
        iter = min_heap.begin();
        int v = iter->second;
        min_heap.erase(*iter);
        vis[v] = true;
        // 进行和普通 dijkstra 算法类似的松弛操作
        for (int j = p[v]; j != -1; j = e[j].next) {
            int x = e[j].v;
            if (!vis[x] && dis[v] + e[j].w < dis[x]) {
                // 先将对应的 pair 从堆中删除，再将更新后的 pair 插入堆
                min_heap.erase(make_pair(dis[x], x));
                dis[x] = dis[v] + e[j].w;
                min_heap.insert(make_pair(dis[x], x));
            }
        }
    }
    return true;  // 存储单源最短路的结果
}
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    mapinit();
    cin>>t>>n;
    while(t--){
    	int a,b,w;
    	cin>>a>>b>>w;
    	insert2(a,b,w);
    }
    dijkstra(1);
    cout<<dis[n]<<endl;
    return 0;
}