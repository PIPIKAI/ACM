#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e6+7;
int n,m;
int f[maxn];
vector<int> tree[maxn];
vector<int> ans;
int root;
int sum;
void dfs(int rt){
    for(auto i : tree[rt]) dfs(i),f[rt]+=f[i];
    if(f[rt]==sum/3 && rt!=root) f[rt]=0,ans.push_back( t);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1,a;i<=n;i++){
        cin>>a>>f[i];
        sum+=f[i];
        if(!a) root=i;
         tree[a].push_back(i);
    } 
    if(sum%3){
        return cout<<-1<<endl,0;
    }
    dfs(root);
    if(ans.size()>=2 && ans[0] && ans[1]){
        cout<<ans[1]<<" "<<ans[0]<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}