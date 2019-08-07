#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<22, stdin), p1 == p2) ? EOF : *p1++)
#define Max(x,y) y>x?x=y:x=x
int n,m;
const int maxn=1e5+7;
int fa[maxn];
vector<int > f[maxn];
int pre[maxn],vis[maxn];
int be,ed;
vector<int > ans;
void dfs(int now)
{
    if(vis[now]){
        return ;
    }
    vis[now]=1;
    for(int i=0;i<f[now].size();i++){
        int j=f[now][i];
        if(vis[j])
            continue;
        if(now==be && j==ed)
            continue;
        pre[j]=now;
        if(j==ed){
            return ;
        }
        dfs(j);
    }
}
int findf(int x){
    while(x!=fa[x])
        x=fa[x];
    return x;
}
bool mer(int x,int y)
{
    int a=findf(x);
    int b=findf(y);
    if(a<b)
        fa[b]=a;
    else if(a>b)
        fa[a]=b;
    else
        return true;
    return false;

}

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1,a,b;i<=n;i++){
        cin>>a>>b;
        f[a].push_back(b);
        f[b].push_back(a);
        if(mer(a,b)){
            be=a;ed=b;
        }
    }
    pre[be]=be;
    dfs(be);
    while( ed !=pre[ed]){
        ans.push_back( ed );
        ed=pre[ed];
    }
    ans.push_back( be );
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
        if(i!=ans.size()-1)
            cout<<" ";
    }
    cout<<endl;
    return 0;
}
