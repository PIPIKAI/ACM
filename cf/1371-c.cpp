//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mem(x,y) memset(x, y, sizeof(x))
const int maxn=1e5+7;
const int inf = 0x3f3f3f3f;
ll a,b,n,m,T;
int main(int argc, char * argv[]) 
{
	std::ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        bool ans=true;
    	cin>>a>>b>>n>>m;
    	if(a+b < n+m ){
            ans=false;
        }
        else{
            if( (m-n)>min(a-n,b-n)){
                ans=false;
            }

        }
        if(ans){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}