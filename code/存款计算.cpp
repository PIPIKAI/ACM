#include<stdio.h>
double func(double m, int y)
{
    double sum= m;
      if(y==3)
    return  sum=sum+sum*0.021*3;
    else if(y==1)
        return sum=sum+sum*0.015*1;
    else if(y==5)
        return sum=sum+sum*0.0275*5;

}
int main()
{
    double m;
    int y;
    scanf("%lf%d",&m,&y);
    if(y!=3&&y!=5&&y!=1)
    {
        printf("-1");
        return 0;
    }
    printf("%.2lf" ,func(m,y));
    return 0;
}
