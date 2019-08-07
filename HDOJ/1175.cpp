#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int f[1001][1002];
int dir[4][2]={1,0, 0,1, -1,0, 0,-1};
struct node
{
    int x,y,z,h,d;
};
int hh(node a,node b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
bool bfs(node a,node b)
{
    if(f[a.x][a.y]!=f[b.x][b.y])
        return 0;
    a.z=0;
    a.h=hh(a,b);
    queue<node> q;
    q.push(a);
    while(!q.empty())
    {
        node t=q.front();
        if(t==b)
            return 1;
        node b;
        for(int i=0;i<4;i++)
        {

        }
    }
}
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n>>m,n!=0&&m!=0)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>f[i][j];
        int q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            node a,b;
            cin>>a.x>>a.y>>b.x>>b.y;
            if(bfs(a,b))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
