#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
queue <node> q;
string f[1001] ;
int vis[1001][1001],n,m,d[4][2]={1,0, -1,0, 0,1, 0,-1},ans[1001][1001];
int keep[1000001][2]={0};
void bfs(int x,int y)
{ 
	int sum=1,cnt=0;
	node t,p;
	vis[x][y]=1;
	t.x=x;t.y=y;
	q.push(t);
	keep[cnt][0]=t.x;keep[cnt][1]=t.y;cnt++;
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			p.x=d[i][0]+t.x;
			p.y=d[i][1]+t.y;
			if(p.x<n&&p.y<n&&p.x>=0&&p.y>=0&&!vis[p.x][p.y]&&ans[p.x][p.y]==0)
			{
				if(1==abs(f[t.x][t.y]-f[p.x][p.y]))
				{
					sum++;
					vis[p.x][p.y]=1;
					q.push(p);
					keep[cnt][0]=p.x;keep[cnt][1]=p.y;cnt++;
				}
			}
		}
	}
	cout<<sum<<endl;
for(int i=0;i<cnt;i++) 
ans[keep[i][0]][keep[i][1]]=sum;

}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
	memset(keep,0,sizeof(keep));
	for(int i=0;i<n;i++) cin>>f[i]; 
	for(int i=0;i<m;i++) 
	{
		int x,y;
		cin>>x>>y;
		if(ans[x-1][y-1]!=0)
		cout<<ans[x-1][y-1]<<endl;
		else
		bfs(x-1,y-1);
	}
	return 0;
}
