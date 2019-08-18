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
const int maxn = 300;
int n,m;
int f[maxn][maxn],pre[maxn],flow[maxn];
queue<int >q ;
int bfs(int s,int t){
    while(!q.empty()) q.pop;
    mem(pre,-1);
    pre[s]=0;
    q.push(s);
    while (!q.empty()){
        int p=q.front();q.pop();
        if(p==t){
            break;
        }
        
    }
    
}
int  EK(int s,int t){
    int now-=0,tot=0;
    while(1){
        now=bfe(s,t);
        if(now==-1) break;
        int tp=t;
        while(tp!=s){
            f[pre[tp]][tp]-=now;
            f[tp][pre[tp]]+=now;
            tp=pre[tp];
        }
        tot+=tp; 
    }
    return tot;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while (cin>>m>>n)
    {
        mem(f,0);
        mem(flow,0);
        for(int x,z,t,i=0;i<m;i++){
            cin>>x>>z>>t;
            f[x][z]+=t;
        }
        cout<<EK(1,n)<<endl;
    }
    
    return 0;
}