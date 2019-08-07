#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define Max 500000
int n,x;
int head[Max];
int  p;
int dis[Max];
bool vis[Max];
struct node
{
    int v,w,next;
}f[Max];
void add(int a,int b,int w)
{
    f[p].v=b;
    f[p].w=w;
    f[p].next=head[a];
    head[a]=p++;
}
void spfa(int x)
{
    queue <int > q;
    int i;
    for(int i=0;i<=n;i++)
        {
            dis[i]=inf;
            vis[i]=0;
        }
    dis[x]=0;
    q.push(x);
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        vis[t]=0;
        for(int i=head[t];i!=-1;i=f[i].next)
        {
            int y=f[i].v;
            if(dis[y]==inf||dis[y]>dis[t]+f[i].w)
            {
                dis[y]=dis[t]+f[i].w;
                if(!vis[y])
                {
                    vis[y]=1;
                    q.push(y);
                }
            }
        }
    }
}
void disp()
{
    for(int i=0;i<=n;i++)
        if(head[i]!=-1){
            cout<<i<<" : ";int j=head[i];
            while(j!=-1){ cout<<f[j].v<<" "; j=f[j].next; }
            cout<<endl;
        }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
	memset(head,-1,sizeof head);
	memset(f,0,sizeof f);
	p=0;
	//cin>>n;
    int a,b;
    cin>>a>>b;
    cout<<a+b<<endl;
	/*for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
       // add(b,a,c);
    }*/
   // disp();
   return 0;
}
/*
7
1 2 3
1 3 3
2 4  1
1 5 1
2 3 1
3 4 1
3 5 2
*/
