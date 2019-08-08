#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
struct node
{
    int x,y,time;
};
node fir,ac,ed;
queue<node> q;
int dir[4][2]={1,0,
               0,1,
               -1,0,
               0,-1};
bool BFS()
{
     while(!q.empty())
        {
            node h=fq.front();
            if(f[h.x][h.y]=='E')
            {
                if(abs(fir.x-h.x))
            }
            for(int i=0;i<4;i++)
            {
                int dx=h.x+dir[i][0];
                int dy=h.y+dir[i][1];
                if(ff[dx][dy]!=0)
                {
                    ff[dx][dy]=1;
                    node j;j.x=dx,j.y=dy;
                    fq.push(j);
                }
            }
        }
}
void ini()
{
    while(!q.empty())
    {q.pop();}
    mem(vis,0);
}
int main()
{
    int n,m;
    while(cin>>n>>m){
        queue<node> q;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>f[i][j];
                if(f[i][j]=='F')
                    fir.x=i,fir.y=j;
                if(f[i][j]=='S')
                    t.x=i,t.y=j;
                if(f[i][j]=='E')
                    ed.x=i,ed.y=j;
            }
        ini();
        t.time=0;
        q.push(t);
       if(BFS())
            cout<<"PIG PIG PIG!"<<endl;
        else
            cout<<"A! WO SI LA!"<<endl;
    }
    return 0;
}
