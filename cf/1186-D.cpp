#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=1e6+7;
ll n,m;
ll f[maxn][2];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    double t;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t>0){
            f[i][0]=floor(t);
            f[i][1]=ceil(t);
        }
        else{
            f[i][1]=floor(t);
            f[i][0]=ceil(t);
        }
        sum+=f[i][0];

    }
    int i=0;
    while(sum!=0 && i<n){
        if(sum>0){
            if(f[i][1]<0 && f[i][1]!=f[i][0]){
                swap(f[i][0],f[i][1]);
                sum--;
            }
        }
        else if(sum<0){
            if(f[i][1]>0 && f[i][1]!=f[i][0]){
                swap(f[i][0],f[i][1]);
                sum++;
            }
        }
        i++;
    }
    for(int i=0;i<n;i++){
        cout<<f[i][0]<<endl;
    }
    return 0;
}
/***
6
-2.000
-1.001
-8.999
4.000
6.000
2.000
*/

