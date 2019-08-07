#include<bits/stdc++.h>
using namespace std;
class RMB
{
private :
    int yu,fen;
public :
    RMB(int yu=0,int fen=0)
    {
        this->yu=yu;this->fen=fen;
    }
    void dis()
    {
        yu=yu+ (fen/100);fen%=100;
        cout<<"ÓÐ"<<yu<<"Ôª"<<" "<<fen<<"·Ö"<<endl;
    }
    /**RMB operator+ (RMB p)
    {
        RMB t;
        t.yu=this->yu + p.yu;
        t.fen=this->fen+p.fen;
        return t;
    }
    */
    RMB operator++ ()
    {
        this->yu ++;
        this->fen++;
        ///return *this;
    }
    friend RMB operator+ (RMB p,RMB q)
    {
        RMB t;
        t.fen=p.fen+q.fen;
        t.yu=p.yu+q.yu;
        return t;
    }
};
int main()
{
    RMB a(2,30),b(3,80),c;
    c=a+b;
    c.dis();
    return 0;
}z
