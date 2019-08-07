#include<bits/stdc++.h>
using namespace std;
int n,vis[28],ans[28];
int  f[4][28];
void dfs(int x,int y ,int z) //  hang  lie  jing wei
{
	if(y==0)
	{
		if(z==0)
		{
			for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
			cout<<endl; 
			exit(0);
		}
		return ;
	}
	for(int i=y-1;i>=1;i--)
		if(ans[f[1][i]]!=-1 && ans[f[2][i]]!=-1 && ans[f[3][i]]!=-1)
			if((ans[f[1][i]]+ans[f[2][i]])%n!= ans[f[3][i]]&&(1+ans[f[1][i]]+ans[f[2][i]])%n!= ans[f[3][i]])
			return ;
	if(ans[f[x][y]]==-1)
	{
		for(int i=n-1;i>=0;i--)
			if(!vis[i])
			{
				if(x!=3)
				{
					ans[f[x][y]]=i;vis[i]=1;
					dfs(x+1,y,z);
					ans[f[x][y]]=-1;vis[i]=0;
				}
				else
				{
					int w=ans[f[1][y]]+ans[f[2][y]]+z;
					if(w%n!=i)
					continue;
					ans[f[x][y]]=i;vis[i]=1;
					dfs(1,y-1,w/n);
					ans[f[x][y]]=-1;vis[i]=0;
				}
			}
	}
	else
	{
		if(x!=3)
		dfs(x+1,y,z);
		else
		{
			int w=ans[f[1][y]]+ans[f[2][y]]+z;
				if(w%n!=ans[f[3][y]])
				return ;
			dfs(1,y-1,w/n);
		}
	}
}
int main()
{
	memset(ans,-1,sizeof(ans));
	memset(vis,0,sizeof(vis));
	cin>>n;	
	for(int i=1;i<=3;i++)
		for(int j=1;j<=n;j++)
		{
			char t;cin>>t;
			f[i][j]=t-'A';
		}	 
	dfs(1,n,0);
	for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
			cout<<endl; 
	return 0;
}
