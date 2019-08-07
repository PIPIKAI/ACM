#include<bits/stdc++.h>
using namespace std;
class ONE
{
private :
    int shi,xu;
public :
    ONE(int shi=0,int xu=0)
    {
        this->xu=xu;this->shi=shi;
    }
    void dis()
    {
        cout<<"实部为"<<shi<<"   "<<"虚部为"<<xu<<endl;
    }
    friend ONE operator+ (ONE p,ONE q)
    {
        ONE t;
        t.shi=p.shi+q.shi;
        t.xu=p.xu+q.xu;
        return t;
    }
    friend ONE operator- (ONE p,ONE q)
    {
        ONE t;
        t.shi=p.shi-q.shi;
        t.xu=p.xu-q.xu;
        return t;
    }
};
int main()
{
    ONE a(2,30),b(3,80),c;
    c=a+b;
    c.dis();
    return 0;
}
