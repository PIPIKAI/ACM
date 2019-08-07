#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#define LL long long int
#define N 100000+10
#define M 1000000+10
#define MOD 142857
//N<=10^5, M<=10^6

using namespace std;
int n, m;
struct node
{
    int v, w;
    bool operator<(const node &dd)const{
        return w>dd.w;
    }
};
vector<node>q[N];
bool vis[N];
LL ans;

void queue_prim()
{
    priority_queue<node>que;
    while(!que.empty())
        que.pop();
    ans = 0;
    memset(vis, false, sizeof(vis));
    for(int i=0; i<q[1].size(); i++){
        que.push(q[1][i]);
    }
    vis[1]=true;
    int edge=n-1;//边数
    node cur;
    while(edge--)
    {
        cur = que.top();
        que.pop();
        if(vis[cur.v]==true){
            while(vis[cur.v]){
                cur=que.top(); que.pop();
            }
        }
        ans = ans+cur.w;
        vis[cur.v]=true;
        for(int i=0; i<q[cur.v].size(); i++){
            if(vis[ q[cur.v][i].v ]==false)
                que.push(q[cur.v][i]);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int i, j;
    int u, v, w;
    node cur;
    for(i=0; i<=n; i++)
        q[i].clear();

    for(i=0; i<m; i++)
    {
       scanf("%d %d %d", &u, &v, &w);
       cur.v=v; cur.w=w;
       q[u].push_back(cur);
       cur.v=u;
       q[v].push_back(cur); //建立双向边
    }
    queue_prim();
    printf("%lld\n", ans );
    return 0;
}
