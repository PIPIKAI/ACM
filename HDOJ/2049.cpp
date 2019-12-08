#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
int n,m;
#define LOCAL
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("C:/Users/Administrator/Documents/ACM/code/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    /* code */

    while (cin>>n,n)
    {
    	set<string> win,lose;
    	for(int i=0;i<n;i++){
    		string a,b;
    		cin>>a>>b;
    		win.insert(a);
    		win.insert(b);
    		lose.insert(b);
    	}
    	if(win.size()-lose.size()==1){
    		cout<<"Yes"<<endl;
    	}else{
    		cout<<"No"<<endl;	
    	}
    }

    return 0;
}