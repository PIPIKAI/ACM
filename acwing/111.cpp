//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,ans[maxn];
pair<pii,int> f[maxn];
priority_queue<pii, vector<pii>,greater<pii> > q; // first 存的是时间 ，second 存的是当前的编号
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>f[i].first.first>>f[i].first.second;
    	f[i].second=i;
    }
    sort(f,f+n);
    for(int i = 0;i < n; i++ ){
    	auto tp=f[i];
    	if(q.empty() || q.top().first >= tp.first.first){
    		pii stall={ tp.first.second , q.size()+1};
    		ans[tp.second]=stall.second;
    		q.push(stall);
    	}
    	else{
    		auto stall =q.top();
    		q.pop();
    		stall.first =tp.first.second;
    		q.push(stall);
    		ans[tp.second]=stall.second;
    	}
    }
    cout<<q.size()<<endl;
    for(int i=0;i<n;i++){
    	cout<<ans[i]<<endl;
    }
    return 0;
}