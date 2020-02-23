//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m,p,h,d[maxn],c[maxn];
set <pair<int,int > > f;
int main(int argc, char * argv[]) 
{
    cin>>n>>p>>h>>m;
    for(int i=0;i<m;i++){
    	int a,b;
    	cin>>a>>b;
    	if(a>b) swap(a,b);
    	if(!f.count({a,b})){
    		f.insert({a,b});
    		d[a+1]--,d[b]++;
    	}
    }
    for(int i=1;i<=n;i++){
    	c[i]=c[i-1]+d[i];
    }
    for(int i=1;i<=n;i++){
    	cout<<c[i]+h<<endl;
    }

    return 0;
}