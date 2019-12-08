#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int inf = 0x3f3f3f3f;
#define LOCAL
int main(int argc, char * argv[]) 
{
    
    #ifdef LOCAL
    // freopen("C:/Users/Administrator/Documents/ACM/moban/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    /* code */
    int n;
    cin>>n;
    	string s;
    	int l=0,r=0;
    	cin>>s;
    	for(auto i :s){
    		if(i == '('){
    			l++;
    		}
    		else{
    			if(l==0){
    				r++;
    			}
    			else{
    				l--;
    			}
    		}
    	}
    	if(l==r&&l<=1) {
    		cout<<"Yes"<<endl;
    	}else{
    		cout<<"No"<<endl;
    	}
   

    return 0;
}