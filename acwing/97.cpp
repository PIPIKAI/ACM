//#pragma comment(linker, "/STACK:1024000000,1024000000")
/**
sum(x,n)= x^0 + x^1 + x^2 + ....+x^n
n 为 奇数时，就是可以分为左右两半。
= （x^0 + x^1+ ...+x^k/2)+ x^(k/2+1)*(x^0 + x^1 + ... x^ k/2)
= sum(x,k/2)*(1+x^(k/2+1))
n 为偶数时，就先把最后一项算出来
sum(x,n) = sum (x,n-1) * x + 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
const int mod= 9901;
int A,B,f[maxn];
int qpow(int x,int n){
	int res=1;
	x%=mod;
	while(n){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll sum(int x,int k){
	if(k==0) return 1;
	if(k%2==0) return (sum(x,k-1)*x%mod+1)%mod;
	return	sum(x,k/2)%mod*(qpow(x,k/2+1)+1)%mod;
}
int main(int argc, char * argv[]) 
{
    cin>>A>>B;
    int res=1;
    for(int i=2;i<=A;i++){
    	int count=0;
    	while(A%i==0){
    		A/=i;
    		count++;
    	}
    	if(count) res=(res*sum(i,count*B))%mod;
    }
    if(A==0) res=0;
    cout<<res<<endl;
    return 0;
}