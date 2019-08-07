#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double n,a,b;
        scanf("%lf",&n);
        b=(n-sqrt(n*n-4*n))/2;
        a=(n+sqrt(n*n-4*n))/2;
        if(fabs((a+b)-a*b)<=0.000001&&fabs((a+b)-n)<=0.000001)
            printf("Y %.9lf %.9lf\n",a,b);
        else
            printf("N\n");
    }
    return 0;
}
