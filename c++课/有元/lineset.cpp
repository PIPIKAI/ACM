#include<bits/stdc++.h>
#include"linehead.h"
line::line(int a,int b,int c)
{
    this->a=a;
    this->b=b;
    this->c=c;
}
double dis(point p,line l)
{
    double d=fabs(line.a*point.getX()+line.b*point.getY()+line.c)
    return d*1.0/sqrt(line.a*line.a+line.b*line.b);
}
