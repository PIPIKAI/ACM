#include<bits/stdc++.h>
using namespace std;
char f[60][60];
int aa,bb,a,b,n,m,t,flag=0;
int d[4][2]={1,0,0,1,-1,0,0,-1};
void dfs(int x,int y,int step)
{
	if(x<0||y<0||x>=n||y>=m||f[x][y]=='X'||flag==1)
	return ;
	if(step>=t)
	{
		if(y==bb&&x==aa)
			flag=1;
	return ;
	}
	int juge=t-step-abs(aa-x)-abs(bb-y);
	if(juge<0||juge%2==1)
	return ;
	for(int i=0;i<4;i++)
	{
		int cx=x+d[i][0];
		int cy=y+d[i][1];
		f[x][y]='X';
		dfs(cx,cy,step+1);
		f[x][y]='.';
	}
}
int main()
{
	while(cin>>n>>m>>t,n!=0)
	{
		flag=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>f[i][j];
				if(f[i][j]=='S')
				aa=i,bb=j;
				if(f[i][j]=='D')
				a=i,b=j;
			}
		dfs(a,b,0);
		if(flag)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	return 0;
}
