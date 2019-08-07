#include<stdio.h>
double EPF=1e-6;
double def(double x)
{
    return x*x*x-5*x*x+10*x-80;
}
int main()
{
    double x=0,y=100;
    double  mid=(x+y)/2;
    while(x<y)
    {
        if(def(mid)<EPF)
    {
        printf("%.6lf",mid);
    }
    else if(mid>0)
    tow_find(0,100);
    }
    printf("%.8lf\n",mid);
    return 0;
}
