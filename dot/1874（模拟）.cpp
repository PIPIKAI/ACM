#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
int f[105][105],ans;
int col[105]105],tot=1;
int n,q,ans;
void dfs(int x,int k)
{
    if(k>ans){
        return ;
    }
    if(x>n){
         ans=min(ans,k);
         return ;
    }
    for(int i=1;i<=k;i++){
        int j=0;
        while( col[i][j] && f[x][col[i][j]]==0 ){
            j++;
        }
        if(0==col[i][j]){
            col[i][j]=x;
            dfs(x+1,k);
            col[i][j]=0;
        }
    }
    col[][]=k+1;
    dfs(x+1,k+1);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>q;
    ans=n;
    for(int i=0,a,b;i<q;i++){
        cin>>a>>b;
        f[a][b]=1;
        f[b][a]=1;
    }
   dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
