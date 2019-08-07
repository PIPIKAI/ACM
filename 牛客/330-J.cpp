#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
double pi=3.1415926535;
double f1,f2,a;
int main()
{
    std::ios::sync_with_stdio(false);
    scanf("%lf%lf%lf",&f1,&f2,&a);
    double ans= sqrt(f1*f1+f2*f2+2*f1*f2*cos( pi*a/180) );
    printf("%lf\n",ans);
    return 0;
}
