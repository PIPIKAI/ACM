#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=2e3+7;
vector<int > f[maxn];
int ans[maxn],cnt;
bitset<maxn> vis;
int dfs(int x)
{
    for(int i=0;i<f[x].size();i++){
        int y=f[x][i];
        if(vis[y]){
            continue;
        }
        vis[y]=1;
        if(!ans[y] || dfs(ans[y])){
            ans[y]=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);

    cin>>n>>m;
    int x,y;
    while(cin>>x>>y,x!=-1&&y!=-1){
        if(x<=n &&y <=m){
             f[x].push_back(y);
            f[y].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        vis.reset();
        cnt+=dfs(i);
    }
    if(!cnt){
        cout<<"No Solution!"<<endl;
    }
    else{
        cout<<cnt<<endl;
        for(int i=n+1;i<=m;i++){
            if(ans[i]){
                cout<<ans[i]<<" "<<i<<endl;
            }
        }
    }
    return 0;
}
