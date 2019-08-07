
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char ma[1005][1005];
int n,m;
int act[2];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ans=1e9;
int flag=0;
typedef struct {
	int door[1000][2],dd;
}dor; 
dor car[11];
void dfs(int x,int y,int step)
{
	if(x<=0||y<=0||x>n||y>m||ma[x][y]=='#')
	return ;
	if(ma[x][y]=='*')
	{
		flag=1;
		//cout<<step<<endl;
		ans=min(ans,step);
		return ;
	}
	int flag=0;
	if(ma[x][y]>='0'&&ma[x][y]<='9')
		{
			flag=1;
		}
		int nm=ma[x][y]-'0';
				for(int i=0;i<4;i++)
			{
				ma[x][y]='#';
				int cx=x+dx[i],cy=y+dy[i];
				dfs(cx,cy,step+1);
			}
			if(flag)
			{
				for(int i=0;i<car[nm].dd;i++)
			{	
				int cx=car[nm].door[i][0];
				int cy=car[nm].door[i][1];
				if(cx==x&&cy==y)
				continue;
				ma[cx][cy]='#';
				//cout<<cx<<" "<<cy<<" "<<step<<endl;
					dfs(cx+0,cy+1,step+1);
					dfs(cx+1,cy+0,step+1);
					dfs(cx+0,cy-1,step+1);
					dfs(cx-1,cy+0,step+1);
			}
			}
				
}
int main()
{
	cin>>n>>m;
	memset(car,0,sizeof(car));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			ma[i][j]=c;
			if(c>='0'&&c<='9')
			{
				int nm=c-'0';
				car[nm].door[car[nm].dd][0]=i;
				car[nm].door[car[nm].dd][1]=j;
				car[nm].dd++;
			}
			if(c=='l')
			{
				act[0]=i,act[1]=j;
			}
		}
	}	
	dfs(act[0],act[1],0);
	if(flag)
	cout<<ans<<endl;
	else
	cout<<"-1"<<endl;
	return 0;
 } 
 /*
 5 5
l####
.....
####2
3*3#2
##32*

*/
