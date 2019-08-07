#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char f[110][110];
map <char ,int > kk;
struct node
{
    int x,y,step,key;
};
void ini()
{
    kk['B']=kk['b']=1;
    kk['Y']=kk['y']=2;
    kk['R']=kk['r']=3;
    kk['G']=kk['g']=4;
}
int n,m,ans,flag;
int vis[102][102][50];
int cx[4]={0,-1,1,0};
int cy[4]={1,0, 0,-1};
void bfs(int x,int y)
{

    node t;
    t.x=x,t.y=y,t.step=0,t.key=0;
    vis[x][y][0]=1;
    queue<node > q;
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            node tp;
            tp.x=t.x+cx[i];
            tp.y=t.y+cy[i];
            tp.key=t.key;
            tp.step=t.step+1;
            char c=f[tp.x][tp.y];
            if(!vis[tp.x][tp.y][tp.key]&&tp.x<n&&tp.y<m&&tp.x>=0&&tp.y>=0&&c!='#')
            {
                if(c>='a'&&c<='z')
                {
                    int temp=kk[c];
                    if(temp!=0)
                    {
                        if((tp.key&(1<<temp))==0)
                            tp.key+=(1<<temp);
                    }
                }
                if(c>='A'&&c<='Z')
                {
                    if(c=='X')
                    {
                        ans=min(ans,tp.step);
                    }
                    else{
                    int temp=kk[c];
                        if(temp!=0)
                        {
                            if((tp.key&(1<<temp))==0)
                                continue;
                        }
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
   ini();
	while(cin>>n>>m,n!=0&&m!=0)
    {
        ans=9999999;
        int x,y;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                char t;cin>>t;
                if(t=='*') {x=i,y=j;}
                f[i][j]=t;
            }
        bfs(x,y);
        if(ans==9999999)
            cout<<"The poor student is trapped!"<<endl;
        else
            cout<<"Escape possible in "<<ans<<" steps."<<endl;
    }
   return 0;
}
