//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=5e5+7;
const int inf = 0x3f3f3f3f;
ll n,m,f[maxn],ans;
void msort(int l1,int r1,int l2,int r2){
	int a=l1,b=r1,x=l2,y=r2;
	int tp[maxn];
}
void merge(int l,int r){
	if(l>r){
		return;
	}
	int mid=(l+r)>>1;
	merge(l,mid);
	merge(mid+1,r);
	msort(l,mid , mid+1, r);
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
    }
    return 0;
}