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
        cout<<"��ǰԲ������ǣ�"<<t*t *pi<<endl;
    }
    void out()
    {
        cout<<"��ǰԲ�İ뾶�ǣ�"<<this->r<<endl;
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
        cout<<"��ǰԲ��������ǣ�"<<this->v<<endl;
    }
    void out()
    {
        cout<<"��ǰԲ���ĸ��ǣ�"<<this->h<<endl;
        cout<<"��ǰԲ���İ뾶�ǣ�"<<r<<endl;
    }
};
int main()
{
    zhu z(1,2);
    z.tiji();
    z.out();
    return 0;
}
