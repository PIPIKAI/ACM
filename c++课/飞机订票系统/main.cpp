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
    cout<<"\n************   ��ӭʹ�ú������ϵͳ   ***********\n"<<endl;
    cout<<"-----------------------------------------------------"<<"\t**\t>>1-----���´�����Ϣ��\t\t>>2----������Ϣ**\n\t**\t>>3----�޸���Ϣ\t\t>>4----ɾ����Ϣ\t\t>>4----ɾ����Ϣ              **\n\t**\t>>5----ɾ��ȫ��\t\t>>0----ɾ����Ϣ\t\t>>0----�˳�ϵͳ              **\n"<<"-----------------------------------------------------"<<"����Ҫ��ʲô��  (ѡ��0~5)"<<endl;

}
int main()
{
    while()
    {
        inim();
    }
    return 0;
}
