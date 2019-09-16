#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
std::vector<int> tree[maxn];
ll up[maxn],down[maxn],son[maxn],n;
void dfs1(int pre,int now){
	son[now]=1;
	for(auto i:tree[now]){
		if(i!=pre){
			dfs1(now,i);
			son[now]+=son[i];
			down[now]+=down[i]+son[i];
		}
	}
}
void dfs2(int pre,int now){
	for(auto next:tree[now]){
		if(next!=pre){
			up[next]=up[now]+(n-son[now])+(son[now]-son[next])+(down[now]-down[next]-son[next]);
			dfs2(now,next);
		}
	}
}
int main(){
	cin>>n;
	for(int i=0,a,b;i<n-1;i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs1(-1,1);
	dfs2(-1,1);
	for(int i=1;i<=n;i++){
		cout<<up[i]+down[i]<<endl;
	}
	return 0;
}