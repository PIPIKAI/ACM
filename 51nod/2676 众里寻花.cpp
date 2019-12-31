#include <bits/stdc++.h>
using namespace std;
int mp[200][200],n,m;
int f[200],vis[200],dis[200];
int inf;
void prime(int x){
	vis[x]=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		dis[i]=mp[x][i];
	}
	for(int i=2;i<=n;i++){
		int mincost=inf,id;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]<mincost){
				mincost=dis[j];
				id=j;
			}
		}
		vis[id]=1;
		if(mincost==1)
		sum+=1;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&dis[j]>mp[id][j]){
				dis[j]=mp[id][j];
			}
		}
	}
	cout<<sum<<endl;
}
int main(int argc, char const *argv[])
{
	cin>>n>>m;
	memset(mp,0x3f,sizeof(mp));
	inf =mp[0][0]+1;
	for(int i=1;i<=n;i++){
		cin>>f[i];
	}

	for(int a,b,i=1;i<=m;i++){
		cin>>a>>b;
		if(f[a]==f[b]){
			mp[a][b]=mp[b][a]=1;
		}
		else{
			mp[a][b]=mp[b][a]=0;
		}
	}
	prime(1);
	return 0;
}