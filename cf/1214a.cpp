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
    // freopen("C:/Users/Administrator/Documents/ACM/code/data.in", "r", stdin);
    //freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
    #endif
    int n;// rubles 
    int d;// 1 dollar = d rubles
    int e; // 1 euro  = e rubles
    int ans=inf;
    // int ans=inf; //minimum  rubles 
    cin>>n>>d>>e;
	for (int i = 0; i*5*e <=n; ++i)
	{
		ans=min(ans, (n- i*5*e)%d);
	}
    cout<<ans<<endl;
    return 0;
}