#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=2e3+7;
int n,m,e,d[maxn],ans;
vector <int> f[maxn];
bitset<maxn> vis;
int dfs(int x)
{
    for(int i=0;i<f[x].size();i++){
        int y=f[x][i];
        if(vis[y]){
            continue;
        }
        vis[y]=1;
        if(!d[y] || dfs(d[y])){
            d[y]=x;
            return 1;
        }
    }
    return 0;

}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m>>e;
    for(int i=0,a,b;i<e;i++){
        cin>>a>>b;
        if(a<=n && b<=m && a<=m && b<= m){
            f[a].push_back(b+n);
            f[b+n].push_back(a);
        }
    }
    for(int i=1;i<=n;i++){
        vis.reset();
        ans+=dfs(i);
    }
    cout<<ans<<endl;
    return 0;
}
