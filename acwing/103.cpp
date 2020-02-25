//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=2e5+7;
const int inf = 0x3f3f3f3f;
int n,m,a[maxn],b[maxn],c[maxn];
unordered_map<int,int> mp;
std::vector<int> v;
struct node
{
	int id,b,c;
}f[maxn];
int get_id(int x){
	int i=lower_bound(v.begin(),v.end(),x)-v.begin();
	if(v[i]!=x) return 0;
	return i+1;
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0,tp;i<n;i++){
    	cin>>a[i];
    	v.push_back(a[i]);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
    	cin>>b[i];
    }
    for(int i=1;i<=m;i++){
    	cin>>c[i];
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<n;i++){
		int j=get_id(a[i]);
		if(j)
		mp[j]++;
	}
    int ans=1;
    for(int i=1;i<=m;i++){
    	// cout<<mp[get_id(b[i])]<<endl;
    	if(mp[get_id(b[ans])]==mp[get_id(b[i])]){
    		if(mp[get_id(c[ans])]< mp[get_id(c[i])]){
    			ans=i;
    		}
    	}
    	else if(mp[get_id(b[ans])]<mp[get_id(b[i])]){
    		ans=i;
		}
    }
    cout<<ans<<endl;
    return 0;
}