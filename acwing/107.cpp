//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=5e5+7;
const int inf = 0x3f3f3f3f;
ll n,m,f[maxn],	tp[maxn],ans;
void msort(int l1,int r1,int l2,int r2){
	int a=l1,b=r1,x=l2,y=r2;
	int k=l1-1,i,j;
	while(a<=b && x<=y){
		if(f[a] > f[x]){
			ans+= l2-a;
			tp[++k]=f[x++];
		}
		else{
			tp[++k]=f[a++];
		}
	}
	while(a<=b){
		tp[++k]=f[a++];
	}
	while(x<=y){
		ans+=l2 -a;
		tp[++k]=f[x++];
	}
	for(int i=l1;i<=r2;i++){
		f[i]=tp[i];
	}
}
void merge(int l,int r){
	if(l<r){
		int mid=(l+r)>>1;
		merge(l,mid);
		merge(mid+1,r);
		msort(l,mid , mid+1, r);
	}
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    while(cin>>n,n){
    	ans=0;
    	for(int i=0;i<n;i++){
    		cin>>f[i];
    	}
    	merge(0,n-1);
    	cout<<ans<<endl;
    }
    return 0;
}