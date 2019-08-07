/*
作者:kaiss
题目:p1038 一元三次方程求解
*/
#include <stdio.h>
#include<math.h>
int main()
{
    double a, b,c,d,t;
    int count=0,m,j=0;
    scanf("%lf%lf%lf%lf", &a,&b,&c,&d);
    double x[30],sum[2]={-1,-1},cc;
    int i=-100;
    for(;i<=100;i++)
    {
        sum[j]=1.0*(a*i*i*i+b*i*i+c*i+d);
       if(fabs(sum[j])<1e-3)
        sum[j]=0;
        if(sum[j]==0)
        {
            x[count++]=i;
        }

        if(i!=-100&&sum[0]*sum[1]<0)
        {
            t=i-1;m=1;
            while(t<i)
            {
                t=i-1+m/100.0;

                cc=1.0*(a*t*t*t+1.0*b*t*t+c*t+d);

                if(fabs(cc)<1e-3)
                    cc=0;

                if(cc==0)
                {
                    x[count]=t;
                    count++;
                    }
                m++;

            }

        }
        j++;
        if(j>1)
        j=0;

    }
    printf("%.2lf %.2lf %.2lf",x[0],x[1],x[2]);
    return 0;
}//1 -4.65 2.25 1.4
