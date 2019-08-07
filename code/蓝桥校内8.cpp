#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char f[110][110];
map <char ,int > kk;
struct node
{
    int x,y,step,key;
};
int n,m,ans,k,flag;
int vis[102][102][660];
int cx[4]={0,-1,1,0};
int cy[4]={1,0,0,-1};
node be,ed;
void ini()
{
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        if(f[x][y]!='#')
        kk['A'+i]=kk['a'+i]=1+i;
        f[x][y]='a'+i;
    }
}
void bfs(int x,int y)
{
    node t;t.x=x,t.y=y,t.step=0,t.key=0;
    vis[x][y][0]=1;
    queue<node > q;q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            node tp;
            tp.x=t.x+cx[i];tp.y=t.y+cy[i];
            tp.key=t.key;tp.step=t.step+1;
            char c=f[tp.x][tp.y];
            if(!vis[tp.x][tp.y][tp.key]&&tp.x<n&&tp.y<m&&tp.x>=0&&tp.y>=0&&c!='#')
            {
                if(c>='a'&&c<='z')
                {
                    if(tp.x==ed.x&&tp.y==ed.y)
                    ans=min(ans,tp.step);

                    int temp=kk[c];
                    if(temp!=0)
                    {
                        if((tp.key&(1<<temp))==0)
                            tp.key+=(1<<temp);
                    }

                }
                if(c>='A'&&c<='Z')
                {
                    int temp=kk[c];
                    if(temp!=0)
                    {
                        if((tp.key&(1<<temp))==0)
                            continue;
                    }
                    if(tp.x==ed.x&&tp.y==ed.y)
                    {
                    ans=min(ans,tp.step);
                    }
                }
                vis[tp.x][tp.y][tp.key]=1;
                q.push(tp);
            }
        }
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	while(cin>>n>>m>>k>>be.x>>be.y>>ed.x>>ed.y)
    {
        ans=9999999;
        int x,y;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
           cin>>f[i];
        ini();
        bfs(be.x,be.y);
        if(ans==9999999)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
    }
   return 0;
}
