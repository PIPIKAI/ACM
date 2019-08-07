#include<bits/stdc++.h>
using namespace std;
int n,m;
char g[1001][1001],vis[1001][1001];
int main(){
 scanf("%d%d",&n,&m);
 for(int i=0;i<n;++i)
    scanf("%s",g[i]);
 for(int i=1;i<n;++i)
 for(int j=1;j<m;++j)
{
  int cnt=0;
  for(int x=-1;x<=1;++x)
  for(int y=-1;y<=1;++y)
  if((x||y)&&g[i+x][j+y]=='#')++cnt;
  if(cnt==8)
  {
     /// cout<<i<<" "<<j<<endl;
      for(int x=-1;x<=1;++x)for(int y=-1;y<=1;++y)if(x||y)vis[i+x][j+y]=1;
  }

 }
 for(int i=0;i<n;++i)
 for(int j=0;j<m;++j)
 if(g[i][j]=='#'&&!vis[i][j])
 return cout<<"NO"<<endl,0;

 cout<<"YES"<<endl;
}
