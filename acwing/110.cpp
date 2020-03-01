//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,ans;
pair<int ,int>cows[maxn];
map<int,int >spfs;
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int x,y,i=0;i<n;i++){
    	cin>>x>>y;
    	cows[i]={x,y};
    }
    for(int i=0,x,y;i<m;i++){
    	cin>>x>>y;
    	spfs[x]+=y;
    }
    sort(cows,cows+n);
    spfs[0]=spfs[1001]=n;
    for(int i=n-1; i>=0; i--){
    	auto it= spfs.upper_bound(cows[i].second);
    	it--;
    	if(it->first >=cows[i].first){
    		ans++;
    		if(--it->second == 0){
    			spfs.erase(it);
    		}
    	}
    }
    cout<<ans<<endl;
    return 0;
}