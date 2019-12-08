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
    int n,b,g,ans=0;
   	cin>>b>>g>>n;
   	for (int i = 0; i <=b; ++i)
   	{
   		for (int j = 0; j <=g; ++j)
   		{	
   			if(i+j==n){
   				ans++;
   			}
   		}
   	}
   	cout<<ans<<endl;

    return 0;
}