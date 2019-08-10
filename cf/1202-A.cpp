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
int n,m;
int f[maxn];
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    string x,y;
    while(T--){
        cin>>x>>y;
        int have,ans=inf,flag=0;
        int lenx=x.size(),leny=y.size();
        reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());
        for(int i=0;i<leny;i++){
            if(y[i]=='1' && !flag){
                have=i;
                flag=1;
            }
        }
        
        for(int i=0;i<lenx;i++){
            if(x[i]=='1' && i>=have){
                ans=min(ans,abs(have-i));
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}