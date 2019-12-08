// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int inf = 0x3f3f3f3f;
#define LOCAL
int dp[1005][1005];
struct node
{
	int i,j;
	double d;
};
std::vector<node> step;
bool cmp(node a,node b){
	return a.d<b.d;
} 
void init(){
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			node tp;
			tp.i=i;tp.j=j;tp.d=(double) 1.0*sqrt( i*i+j*j);
			step.push_back(tp);
		}
	}
}
int mlower_bound(int l,int r,double pk){
	while(l<=r){
		int mid=l+(r-l)/2;
		double bj=step[mid].d;
		if( bj== pk){
			return mid;
		}
		else if (bj<pk)
		{
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	return l;
}
int main(int argc, char * argv[]) 
{
    
    // #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    // //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    // #endif
    init();
    mem(dp,0X3f);
    dp[0][0]=0;
    sort(step.begin(),step.end(),cmp);
    ios_base::sync_with_stdio(false);
    int n,m,p;
    double d;
    cin>>n>>m>>d;
    p=mlower_bound(0,step.size()-1,d);
    // cout<<p<<endl;
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		for(int k=p;k>= (p-10>=0 ? p-50 : 0);k--){
    			int x=step[k].i;
    			int y=step[k].j;
    			if(x+i <n && y+j < m){
    				dp[x+i][y+j]=min(dp[x+i][y+j],dp[i][j]+1);
    			}
    		}
    	}
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}