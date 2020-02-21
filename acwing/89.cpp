#include<iostream>
using namespace std;
typedef long long ll;
ll solve(ll n,ll m,ll p){
	int res=1;
	while(m){
		if(m&1){
			res=(res*n)%p;
		}
		n=(n*n)%p;
		m>>=1;
	}
	return res%p;
}
int main(int argc, char const *argv[])
{
	ll n,m,p;
	cin>>n>>m>>p;
	cout<<solve(n,m,p);
	return 0;
}