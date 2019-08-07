#include<stdio.h>
#include<math.h>
double fab(double a)
{
    return a>=0?a:(-a);
}
int main()
{
    double a[2],b[2];
    while(scanf("%lf%lf%lf%lf",&a[0],&a[1],&b[0],&b[1])!=EOF)
    {
         printf("%.2lf\n",sqrt(fab(1.0*(b[1]-a[1])*(b[1]-a[1])+1.0*(a[0]-b[0])*(a[0]-b[0]))));
    }


    return 0;
}
