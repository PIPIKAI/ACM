#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
char s[120][120];
int vis[120][120];
struct node{
    int x,y,step;
    char c;
    node(int a,int s,int d,char f){x=a,y=s,step=d,c=f;}
    node(){}
};
node be,ed;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
            if(s[i][j]=='A'){
                be={i,j,0,'A'};
            }
            else if(s[i][j]=='B'){
                ed={i,j,0,'A'};
            }
        }
    }
    vis[be.x][be.y]=1;
    queue<node> q;
    q.push(be);
    while(!q.empty()){
        node tp=q.front();
        q.pop();
        if(tp.x==ed.x &&tp.y==ed.y ){
            return cout<<tp.step<<endl,0;
        }
        else{
            node pt=tp;
            for(int i=0;i<4;i++){
                int cx=tp.x+dx[i];
                int cy=tp.y+dy[i];
                if(cx>=0&&cy>=0&&cx<n&&cy<n&&tp.c!=s[cx][cy]&&vis[cx][cy]!=1){
                    pt={cx,cy,tp.step+1,s[cx][cy]};
                    vis[cx][cy]=1;
                    q.push(pt);
                }
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
