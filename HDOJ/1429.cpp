#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char f[25][25];
struct node{
    int x,y,step,key;
};
int n,m,tt;
int d[4][2]={1,0,-1,0,0,1,0,-1};
int vis[22][22][1028];
int bfs(int x,int y)
{
    queue <node> q;
    node t;
    t.x=x,t.y=y,t.step=0,t.key=0;
    vis[t.x][t.y][0]=1;
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        node tp;
        for(int i=0;i<4;i++)
        {
            int cx=t.x+d[i][0];
            int cy=t.y+d[i][1];
            tp.x=cx,tp.y=cy;
            tp.step=1+t.step;
            tp.key=t.key;
            if(cx>=0&&cy>=0&&cx<n&&cy<m&&tp.step<tt&&!vis[cx][cy][tp.key]&&f[cx][cy]!='*')
            {
                if(f[cx][cy]=='^')
                    return tp.step;
                if(f[cx][cy]>='A'&&f[cx][cy]<='J')
                {
                    int temp=f[cx][cy]-'A';
                    if((tp.key&(1<<temp))==0)
                        continue;
                }
                if(f[cx][cy]>='a'&&f[cx][cy]<='j')
                {
                    int temp=f[cx][cy]-'a';
                    if((tp.key&(1<<temp))==0)
                        tp.key+=(1<<temp);
                }
                vis[cx][cy][tp.key]=1;
                q.push(tp);
            }
        }
    }
    return -1;
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   while(cin>>n>>m>>tt)
   {
       int x,y;
       memset(vis,0,sizeof vis);
      for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
          {
              char t;
              cin>>t;
              f[i][j]=t;
              if(t=='@')
              {
                  x=i,y=j;
              }
          }
       cout<<bfs(x,y)<<endl;
   }
   return 0;
}
