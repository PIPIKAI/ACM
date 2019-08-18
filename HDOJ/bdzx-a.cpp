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
int n,m;
int f[maxn],k[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int T;cin>>T;
    while(T--){
        ll a=0,b=0;
        cin>>n;
        for(int i=0,x,y;i<n;i++){
            cin>>f[i];
        }
         for(int i=0,x,y;i<n;i++){
            cin>>k[i];
        }
        for(int i=n-1;i>=0;i--){
            if(f[i]==0 &&k[i]==0 ){
                continue;
            }
            else if(f[i]==0){
                cout<<"0/1"<<endl;
            }
            else if(k[i]==0){
                cout<<"1/0"<<endl;
            }
            else{
                ll tp=__gcd(f[i],k[i]);
                cout<<f[i]/tp<<"/"<<k[i]/tp<<endl;
            }
            break;
        }
    }
    return 0;
}