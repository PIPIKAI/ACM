//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=2e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
struct node
{
	double x,y;
	int soldier;
}f[maxn],tp[maxn];
bool cmp1(node a,node b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmp2(node a,node b) {
	return a.y == b.y ? a.x < b.x : a.y < b.y;
}
double dis(node a,node b){
	if(a.soldier==b.soldier) return inf;
	double xx=a.x-b.x , yy=a.y-b.y;
	return sqrt(xx*xx+yy*yy);
}
double work(int l,int r){
	if(l >= r){
		return inf;
	}
	if(r-l==1){
		return dis(f[l],f[r]);
	}
	int mid =(l+r)>>1;
	double ans=min(work(l,mid),work(mid+1,r));
	int cnt=0;
	for(int i=l;i<=r;i++){
		if(ans >= fabs(f[i].x - f[mid].x)){
			tp[cnt++]=f[i];
		}
	}
	sort(tp,tp+cnt,cmp2);
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++){
			if(tp[j].y-tp[i].y>=ans){
				break;
			}
			ans=min(ans,dis(tp[i],tp[j]));
		}
	}
	return ans;
}
int main(int argc, char * argv[]) 
{
	// std::ios::sync_with_stdio(false);
	int T;
	scanf("%d",&T);
	while(T-- ){
		scanf("%d",&n);
		n<<=1;
   		for(int i=0;i<n;i++){
   			scanf("%lf%lf",&f[i].x,&f[i].y);
   			f[i].soldier= i<(n/2);
   		}
   		sort(f,f+n,cmp1);	
   		printf("%.3lf\n", work(0,n-1));
	}
    return 0;
}