//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,d,flag,ans=1;
pair<double,double>f[maxn];
queue<pair<double,double> > q;
void change(int x,int y,int i){
	double a,b;
	if(y>d){
		flag=1;
		return ;
	}
	a=double(x)-sqrt(d*d-y*y);
	b=double(x)+sqrt(d*d-y*y);
	f[i]={b,a};
}
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>n>>d;
    for(int i=0,x,y;i<n;i++){
    	cin>>x>>y;
    	change(x,y,i);
    }
    if(flag){
    	cout<<"-1"<<endl;
    }
    else{
    	sort(f,f+n);
    	// for(int i=0;i<n;i++){
    	// 	cout<<f[i].first<<" "<<f[i].second<<endl;
    	// }
    	double tp=f[0].first;
    	for(int i=1;i<n;i++){
    		if(f[i].second >tp){
    			ans++;
    			tp=f[i].first;
    		}
    	} 
    	cout<<ans<<endl;
    }
    return 0;
}