#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED
#include<string>
using namespace std;
class Passenger /// �˿�
{
    string name;
    string sex;
    string email;
    string tel;
    string IDnum;
    bool p_setinfo();///���ó˿���Ϣ
    void p_dis();///��ʾ



    Passenger(string a,string b,string c,string d,string e)
    {
        name=a;
        sex=b;
        email=c;
        tel=d;
        IDnum=e;
    }
    bool setinf()
    {

    }
    bool ensure()
    {

    }
    bool del()
    {

    }
};

#endif // PASSENGER_H_INCLUDED
