#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
typedef long long ll;
ll avgr,avgc,n,m,t,f[maxn],r[maxn],c[maxn];
ll calc(ll a[],ll n){
	for(int i=1;i<=n;i++){
		a[i]-=t/n;
		f[i]=f[i-1]+a[i];
	}
	sort(f+1,f+n+1);
	ll res=0;
	for(int i=1;i<=n;i++){
		res+=abs(f[n+1>>1] - f[i]);
	}
	return res;
}
int main(){
	cin>>n>>m>>t;

	for(int i=0,a,b;i<t;i++){
		cin>>a>>b;
		r[a]++;
		c[b]++;
	}
	if(t%n==0 && t%m==0){
		cout<<"both "<<calc(r,n)+calc(c,m)<<endl;
	}
	else if(t%n==0){
		cout<<"row "<<calc(r,n)<<endl;

	}
	else if(t%m==0){
		cout<<"column "<<calc(c,m)<<endl;
	}
	else{
		cout<<"impossible"<<endl;
	}
	return 0;
}
