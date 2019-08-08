#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e9+7
#define ffr(i,a,b)  for(int i=a;i<b;i++)
#define mem(a,b)  memset( a,b,sizeof a)
double l1,l2,x,y;
int T;
void juge(double x,double y)
{
    double d=(double)sqrt(x*x+y*y);
    if(d<fabs(l1-l2))
    printf("%.6lf\n",(double)fabs(l1-l2)-d);
    else if(d>l1+l2)
    printf("%.6lf\n",(double)d-l1-l2);
    else
    printf("%.6lf\n",(double)0);
}
int main()
{
    scanf("%lf%lf%d",&l1,&l2,&T);

    while(T--)
    {
        scanf("%lf%lf",&x,&y);
        juge(x,y);
    }
    return 0;
}
