#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int > pii;
const int maxn=1e5+7;
int n,l[maxn],r[maxn] ,local[maxn];
pii ans[maxn] , f[maxn];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i].first;
		f[i].second=i;
	}
	sort(f+1,f+n+1);
	for(int i=1;i<=n;i++){
		local[f[i].second]= i;
		l[i]=i-1;
		r[i]=i+1;
	}
	f[0].first = -1e9;
	f[n+1].first= 1e9;
	for(int i=n ; i >= 1 ;i--){
		int j=local[i], left=l[j] , right= r[j];
		int lw= f[j].first - f[left].first ;
		int rw= f[right].first - f[j].first ;
		if(lw <= rw) {
			ans[i]={ lw,f[left].second};
		}
		else {
			ans[i]={rw, f[right].second};
		}
		r[left]= right;
		l[right] = left;
	}
	for(int i=2;i<=n;i++) {
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	return 0;
}