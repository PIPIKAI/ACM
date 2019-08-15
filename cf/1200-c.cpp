#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof a)
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
ll a[3],q;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>a[1]>>a[2]>>q;
    ll p=__gcd(a[1],a[2]);
    a[1]/=p;a[2]/=p;
    while (q--){
        ll x,y,xa,yb;
        cin>>x>>y>>xa>>yb;
        cout<<((y-1)/a[x]==( yb-1)/a[xa]?"YES":"NO")<<endl;
    }
    
    return 0;
}