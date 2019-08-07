#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED
#include<string>
using namespace std;
class Passenger /// 乘客
{
    string name;
    string sex;
    string email;
    string tel;
    string IDnum;
    bool p_setinfo();///设置乘客信息
    void p_dis();///显示



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
