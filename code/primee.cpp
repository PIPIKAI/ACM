#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
int f[2000][2000],n,bian;
#define INF  1e9
void prime(int a)
{
	int vis[2000]={0},minn,sum=0;
	int next[2000];
	vis[a]=1;
	int cost[2000]={0};
	for(int i=1;i<=n;i++)
	cost[i]=f[a][i];
	int ta=a;
	for(int i=2;i<=n;i++)
	{
		minn=INF;
		for(int j=1;j<=n;j++)
		{
			if(minn>cost[j]&&!vis[j])
				ta=j,minn=cost[j];
		}
		vis[ta]=1;
		sum+=minn;
		for(int l=1;l<=n;l++)
			if(!vis[l]&&cost[l]>f[ta][l])
			cost[l]=f[ta][l],next[l]=ta;	
	}
	 printf("%d\n",sum);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&f[i][j]);
		}
		
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(f[i][j]==0)
		f[i][j]=INF;
	prime(1);
	return 0;
 } 

