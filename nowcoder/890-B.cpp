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
const ll maxlen=1e12;
string s[maxn];
int n,m,k;
ll len[60];
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    ll a=1,b=1,c=0,cnt=3;
    s[1]='1',s[2]='0';
    for(int i=3;i<=55;i++){
        c=a+b;
        a=b;
        b=c;
        cout<<c<<endl;
    }
    return 0;
}