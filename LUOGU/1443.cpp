#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
};
queue <node> q;
int f[500][500],n,m,d[8][2]={1,2, -1,2, 2,1, -2,1, 1,-2, 2,-1, -1,-2, -2,1};
int main()
{
	node t;
	memset(f,-1,sizeof(f));
	cin>>n>>m>>t.x>>t.y;
	f[t.x][t.y]=0;
	while(!q.empty()) q.pop();
	q.push(t);
	while(!q.empty())
	{
		t=q.front();
		q.pop();
		for(int i=0;i<8;i++)
		{
			node p;
			p.x=d[i][0]+t.x,p.y=d[i][1]+t.y;
			if(p.x<=n&&p.y<=m&&p.x>0&&p.y>0&&f[p.x][p.y]==-1)
			{
				f[p.x][p.y]=f[t.x][t.y]+1;
				q.push(p);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) 
		cout<<left<<setw(5)<<f[i][j];
        cout<<endl;
	}
	return 0;
}
