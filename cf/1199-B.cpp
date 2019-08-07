#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
#define Max(x,y) y>x?x=y:x=x
int n,m;
double h,l;
int main()
{
    cin>>h>>l;
    double ans= (h*h+l*l)/(2*h)*1.0;
    cout<<fixed<<setprecision(7)<<ans-h<<endl;

    return 0;
}
