#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define INF 0X7FFFFFF
int ma[10][10],vis[10][10],n=5,c=0,ans=INF;
int zero[70][2];
int a[4]={0,1,-1,0};
int b[4]={1,0,0,-1};
void ser(int x,int y)
{
	int i;
	vis[x][y]=1;
	for(i=0;i<4;i++)
    {
        int nx=x+a[i];
        int ny=y+b[i];
        if(!vis[nx][ny]&&ma[nx][ny])
            ser(nx,ny);
    }
    return ;
}
inline bool juge()
{
    memset(vis,0,sizeof(vis));
	int i,j,flag=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		if(!vis[i][j]&&ma[i][j]==1)
		{
                flag++;ser(i,j);
		}
	}
	return flag==1;
}
void dfs(int x,int y)
{
    if(y>ans)
        return ;
    if(x>=c)
    {
        if(juge())
        ans=min(ans,y);
        return ;
    }

	ma[zero[x][0]][zero[x][1]]=1;
	dfs(x+1,y+1);
	ma[zero[x][0]][zero[x][1]]=0;
	dfs(x+1,y);
}
int main()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		    int t;
			scanf("%1d",&t);
			ma[i][j]=t;
			if(ma[i][j]==0)
			{
				zero[c][0]=i;
				zero[c][1]=j;
				c++;
			}
		}
	}
    dfs(0,0);
    cout<<ans<<endl;
	return 0;
}
