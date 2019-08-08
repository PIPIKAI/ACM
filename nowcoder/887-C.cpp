#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include<cstring>
using namespace std;
#define Max(x,y) y>x?x=y:x=x
#define mem(a,b)  memset( a,b,sizeof (a))
typedef long long ll;
const int inf=0x7fffffff;
const int maxn = 1e5+7;
ll n,m,sum;
struct node{
    ll h,c,p;
    const bool operator < (node a){
        return a.h<h;
    } 
}f[maxn];
ll C[300];
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>n){
        mem(C,0);
        sum=0;
        for(int i=0;i<n;i++){
            cin>>f[i].h>>f[i].c>>f[i].p;
            C[f[i].c]+=f[i].p;
            sum+=f[i].p;
        }
        sort(f,f+n);
        ll ans=(ll)1<<60,pre=0;
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=i;j<n;j++){
                if(f[i].h==f[j].h){
                    t=j;
                }else{
                    break;
                }
            }
            ll have=0,need;
            for(int j=i;j<=t;j++){
                have+=f[j].p;
                C[f[j].c]-=f[j].p;
                sum-=f[j].p;
            }
            need=sum-have+1;
            ll add=0;
            if(need>0){
                for(int j=1;j<=200;j++){
                    if(need <= C[j]){
                        add+=need*j;
                        need=0;
                        break;
                    }
                    need-=C[j];
                    add+=j*C[j];
                }
            }
            
            if(need<=0){
                ans=min(ans,add+pre);
            }
            for(int j=i;j<=t;j++){
                pre+=f[j].p*f[j].c;
            }
            i=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}