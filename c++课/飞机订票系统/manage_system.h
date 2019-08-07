#ifndef MANAGE_SYSTEM_H_INCLUDED
#define MANAGE_SYSTEM_H_INCLUDED
#include"ticket.h"
#include"passenger.h"
#include"flight.h"
class Manage
{
    bool BookRefund();///订票
    ///bool returnticket();///退票
    bool serchcustomer();///查找客户信息
    bool serchflight();///查找航班信息
    bool dispassenger();///显示所有客户
    bool disflight();///显示航班信息
    bool exit_system();///退出系统
};
//查询功能
int Traffic_system::Search(int invoke)
{
       int tab;
       Read_file();
       cout<<"*************************************************\n***>>1-----按航班号查询         >>2-------按站点查询    >>0----返回***\n************************************************\n    请选择(0~2);"<<endl;
       cin>>tab;
       while (!(tab==1||tab==2||tab==0))
       {
           cout <<"请输入正确选择（0~2）：";
           cin>>tab;
       }
       char str[2][18],ta;
       if(tab==0)
           return -1;
       else if(tab==1)
       {
           cout <<"请输入航班号：";
           cin>>str[0];
           ta='1';
       }
       else{
        cout<<"请输入起始站：";
        cin>>str[0];
        cout<<"请输入终点站：";
        cin>>str[1];
        ta='2';
       }
       for(int i=0;i<m_sum;i++)
       {
           if(v_array[i].if_match(str,ta))
           {
               cout<<"您要查询的结果如下：\n"<<"________________________\n"<<"|航班号|起始站|终点站                 |起飞时间|票价|余票" <<"______________________\n"<<endl;
               /// v_array[i].Display();
                if(invoke==0)
                {
                    cout<<"按任意键返回主菜单！";
                    char c;
                    cin>>c;
                }
                return i;
           }
       }
       cout<<"抱歉!您查询的航班不存在！"<<endl;
       return -1;
}


//订票和退票
bool Manage::BookRefund()
{
    while (1)
    {
        cout
        <<"*****************欢迎进入机票服务系统******************\n\n"
        <<"________________________________________________________\n"
        <<"请选择：\t\t\t\t\t***\n***\t>>1_____订票\t>>2_______退票\t>>0______返回主菜单      ****\n"<<"_______________________________________________"<<endl;
        int tab;
        cin>>tab;
        while (!(tab==1||tab==2||tab==0))
        {
            cout<<"请输入正确的选择（0~2）:";
            cin>>tab;
        }
        char ta;
        switch(ta)
        {
        case 1:
            {
                cout<<"请输入查找该航班:";<<endl;
                int i;
                i=Search(1);
                if(i!=-1&&v_array[i].Book())
                {
                    cout <<"《确认订票\\Y》》   《取消订票\\N》  \请选择：";
                    do
                    {
                        cin>>ta;
                    }while(!(ta=='Y'||ta=='y'||ta=='N'||ta=='n'));
                    if(ta=='Y'||ta=='y')
                    {
                        Save_file();
                        cout<<"订票成功!"<<endl;
                    }
                }
                break;
            }
        case 2:
            {
                char str[1][18];
                Read_file();
                cout<<"请输入航班号：";
                cin>>str[0];
                int i=0;
                for(;i<m_sum;i++)
                {
                    if(v_array[i].If_takeoff())
                        continue;
                    if(v_array[i].If_match(str,'I'))
                    {
                        v_array[i].Refund();
                        cout<<"《确认退票\\Y》  《取消退票\\N》\n 请选择：";
                        do
                        {
                            cin>>ta;
                        }while(!(ta=='Y'||ta=='y'||ta=='N'||ta=='n'));
                        if(ta=='Y'||ta=='y')
                        {
                            Save_file();
                            cout<<"退票成功!"<<endl;
                        }
                        break;
                    }
                }
                if(i==m_sum)
                {
                    cout<<"不存在该航班或该航班已起飞！不能退票。"<<endl;
                    break;
                }
            }
        case 0:
            return;
        }
    }
}

#endif // MANAGE_SYSTEM_H_INCLUDED
