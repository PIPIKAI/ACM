#include <iostream>
#include<vector>
#include<string>
#include<fstream>
#include"ticket.h"
#include"passenger.h"
#include"flight.h"
#include"manage_system.h"
using namespace std;
vector<Flight> f;
vector<Passenger> p;
vector<Ticket> t;
ifstream fin;
ofstream fout;
//fout.open("test.txt");
//fout.close();
//fin.open("test.txt");
//fin.close();
/*void f_ini()
{
    fout.open("fli.txt");
    string a,b,c,d;
    while(fin>>a>>b>>c>>d)
    fout.close();
}
void p_ini()
{

}
void t_ini()
{

}*/
void inim()
{
    cout<<"\n************   欢迎使用航班管理系统   ***********\n"<<endl;
    cout<<"-----------------------------------------------------"<<"\t**\t>>1-----重新创建信息库\t\t>>2----插入信息**\n\t**\t>>3----修改信息\t\t>>4----删除信息\t\t>>4----删除信息              **\n\t**\t>>5----删除全部\t\t>>0----删除信息\t\t>>0----退出系统              **\n"<<"-----------------------------------------------------"<<"你需要做什么？  (选择0~5)"<<endl;

}
int main()
{
    while()
    {
        inim();
    }
    return 0;
}
