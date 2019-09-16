#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+7;
ll ans[11][maxn];
ll add(int x,int n){
	ll res=0;
	while(x){
		ll tp=x%n;
		res+=tp;
		x/=n;
	}
	return res;
}
int main(){
	for(int i=1;i<maxn;i++){
		for(int j=2;j<=10;j++){
			ans[j][i]=ans[j][i-1]+add(i,j);
		}
	}
	int T,b,n,ca=0;
	cin>>T;
	while(T--){
		cin>>n>>b;
		cout<<"Case #"<<++ca<<": ";
		cout<<ans[b][n]<<endl;
	}
	return 0;
}