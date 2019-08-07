#include<bits/stdc++.h>
using namespace std;
double pi =3.1415926;
class cir
{
protected :
    double r;
public :
    cir(double r)
    {
        this->r=r;
    }
    void area()
    {
        double t=this->r;
        cout<<"当前圆的面积是："<<t*t *pi<<endl;
    }
    void out()
    {
        cout<<"当前圆的半径是："<<this->r<<endl;
    }
};
class zhu:public  cir
{
private :
    double h,v;
public :
    zhu(double r,double h):cir(r)
    {
        this->h=h;
    }
    void tiji()
    {
        this->v= h*r*r*pi;
        cout<<"当前圆柱的体积是："<<this->v<<endl;
    }
    void out()
    {
        cout<<"当前圆柱的高是："<<this->h<<endl;
        cout<<"当前圆柱的半径是："<<r<<endl;
    }
};
int main()
{
    zhu z(1,2);
    z.tiji();
    z.out();
    return 0;
}
