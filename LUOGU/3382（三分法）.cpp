#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
const int maxn=20;
int n;
double f[maxn];
double res(double x)///秦九韶求多项式
{
    double s=0;
      for(int i=n;i;--i){
            s=s*x+f[i];
      }
    return s;
}
int main()
{
    std::ios::sync_with_stdio(false);
    double l,r;
    cin>>n>>l>>r;
    for(int i=n;i;i--){
        cin>>f[i];f[i]*=i;///求导过后
    }
    while(1e-6<r-l)
    {
        double mid=(l+r)/2.0;
        if(res(mid)>0 ){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout<<fixed<<setprecision(5)<<l<<endl;
    return 0;
}
