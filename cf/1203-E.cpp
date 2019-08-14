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
const int maxn = 150007;
int n,m;
int f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0,tp;i<n;i++){
        cin>>tp;
        f[tp]++;
    }
    int ans=0;
    for(int i=1;i<maxn;i++){
        if(f[i-1]){
            f[i-1]++;
            ans++;
        }else if(f[i]){
            f[i]--;
            ans++;
        }else if(f[i+1]){
            f[i+1]--;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}