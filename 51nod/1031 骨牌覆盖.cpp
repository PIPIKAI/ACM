#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ans[1005]={0,1,2};
int main(){
	int n;
	for(int i=3;i<1001;i++){
		ans[i]=(ans[i-1]+ans[i-2])%mod;
	}
	while(cin>>n){
		cout<<ans[n]<<endl;
	}
	return 0;
}