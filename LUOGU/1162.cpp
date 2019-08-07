#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
int f[35][35],n;
int d[4][2]={1,0,0,1,-1,0,0,-1};
queue <node> q;
void bfs()
{
	while(!q.empty()) q.pop();
	node t;
	t.x=t.y=0;
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		f[t.x][t.y]=0;
		q.pop();
		for(int i=0;i<4;i++)
		{
			node p;
			p.x=t.x+d[i][0],p.y=t.y+d[i][1];
			if(f[p.x][p.y]==2)
			{
				q.push(p);
			}
		}
	}
}
int main()
{
	memset(f,0,sizeof f);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) 
		{
			cin>>f[i][j];
			if(f[i][j]==0) f[i][j]=2;
		}	
		for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++) 
			if(f[i][j]==0) f[i][j]=2;	
	bfs();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) 
		cout<<f[i][j]<<" ";
		cout<<endl;
	}
	return 0;
 } 
