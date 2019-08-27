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
const int maxn = 1e3+7;
int n,m,k;
int f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    mem(f,0);
        int ans=inf;
        cin>>n>>m>>k;
        for(int i=1,a,b;i<=m;i++){
            cin>>a>>b;
            f[a]++;
            f[b]++;
        }
        for(int i=1,a,b;i<=n;i++){
            ans=min(ans,f[i]);
        }
        if(ans<k){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}