#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m,k;
const int maxn=109;
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
    while(cin>>n,n){
        cnt=0;
        cin>>m>>k;
        for(int i=0;i<maxn;i++){
            f[i].clear();
        }
        for(int i=0,x,y;i<k;i++){
            cin>>i>>x>>y;
            f[x].push_back(y);
        }
        for(int i=1;i<=n;i++){
            cnt+=dfs(i);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
