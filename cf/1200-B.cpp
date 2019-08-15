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
ll n,m,k;
ll f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int T,Case=0;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(int i=0;i<n;i++){
            cin>>f[i];
        }
        bool flag=1;
        for(int i=0;i<n-1;i++){
            int tp=max((ll)0,f[i+1]-k);
            if(f[i]>tp){
                m+=(f[i]-tp );
            }
            else{
               if(f[i]+m<tp){
                   flag=0;
                   break;
               }
               else{
                   m-=(tp-f[i]);
               }
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}