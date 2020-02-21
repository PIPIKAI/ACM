#include<iostream>
using namespace std;
typedef long long ll;
int main(int argc, char const *argv[])
{
	ll res=1,a,b,p;
	cin>>a>>b>>p;
	while(b){
		if(b&1){
			res=(a+res)%p;
		}
		b>>=1;
		a=(a*2)%p;
	}
	cout<<res%p<<endl;
	return 0;
}