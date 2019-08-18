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
int f[8];
int bi[5];
int ans[5][5]={
    0,2,4,0,0,//n
    0,3,2,1,0,//2
    0,3,2,1,0,//3
    0,4,0,2,0,//2.3
    0,4,1,0,1,//2.2
};
string ss[5]={ "n-hexane","2-methylpentane","3-methylpentane","2,3-dimethylbutane","2,2-dimethylbutane"};
int G[10][10];
int vis[10][10];
struct node  
{
    int now,len;
};

int sp()
{
    mem(vis,0);
    queue<node> q;
    int a[3],cnt=0;
    for(int i=1;i<=6;i++){
        if(f[i]==3){
            q.push(node{i,0});
            break;
        }
    }
    while(!q.empty()){
        node p=q.front();q.pop();
        int flag=1;
        for(int i=1;i<=6;i++){
            if(!vis[p.now][i] && G[p.now][i]>0){
                q.push(node{i,p.len+1});
                vis[p.now][i]=vis[i][p.now]=1;
                flag=0;
            }
        }
        if(flag){
            a[cnt++]=p.len;
        }
    }
    sort(a,a+3);
    if(a[2]==2){
        return 2;
    }
    else{
        return 1;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        mem(f,0);
         mem(bi,0);
         mem(G,-1);
        for(int i=1,a,b;i<=5;i++){
            cin>>a>>b;
            G[a][b]=G[b][a]=1;
            f[a]++;
            f[b]++;
        }
        for(int i=1;i<=6;i++){
            bi[f[i]]++;
        }
        for(int i=0;i<5;i++){
            int flag=0;
            for(int j=0;j<5;j++){
                if(ans[i][j]!=bi[j]){
                    flag=1;
                }
            }
            if(!flag){
                if(i==1){
                    int tp=sp();
                    cout<<ss[tp]<<endl;
                    break;
                }
                else{
                    cout<<ss[i]<<endl;
                }
            }
        }
    }
    return 0;
}
