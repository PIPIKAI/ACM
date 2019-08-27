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
typedef __int128_t ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
const long long mod=1e9+7;
long long x,y,z;
ll n,a,b;
ll pp(ll n){
    if(n&1){
        ll add1=n*n*n*b+n*n*(n-1)*a;
        return add1;
    }
    else{
        ll add1=n*n*n*b+n*n*(n-1)*a;
        n>>=1;
        ll add2=n*n*a*(ll)18+(ll)7*pp(n);
        add1=min(add1,add2);
        return add1;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        cin>>x>>y>>z;
        n=x,a=y,b=z;
        cout<<(long long )(pp(n)%mod)<<endl;
    }
    return 0;
}