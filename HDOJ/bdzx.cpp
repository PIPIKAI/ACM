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
ll n,m;
int k[5]={1,1,0,3,0};
int f[6]={3,5,4,1,9,1};
int c[6]={3,4,3,1,6,1};
int main()
{
    std::ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--){
        cin>>n;
        n--;
        if(n<5){
            cout<<k[n]<<endl;
        }
        else{
            n++;
            ll tp= n%6;
            ll lie=n/6-1;
            cout<<ll(f[tp]+c[tp]*lie)<<endl;
        }
    }
    return 0;
}