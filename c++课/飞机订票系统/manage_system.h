#ifndef MANAGE_SYSTEM_H_INCLUDED
#define MANAGE_SYSTEM_H_INCLUDED
#include"ticket.h"
#include"passenger.h"
#include"flight.h"
class Manage
{
    bool BookRefund();///��Ʊ
    ///bool returnticket();///��Ʊ
    bool serchcustomer();///���ҿͻ���Ϣ
    bool serchflight();///���Һ�����Ϣ
    bool dispassenger();///��ʾ���пͻ�
    bool disflight();///��ʾ������Ϣ
    bool exit_system();///�˳�ϵͳ
};
//��ѯ����
int Traffic_system::Search(int invoke)
{
       int tab;
       Read_file();
       cout<<"*************************************************\n***>>1-----������Ų�ѯ         >>2-------��վ���ѯ    >>0----����***\n************************************************\n    ��ѡ��(0~2);"<<endl;
       cin>>tab;
       while (!(tab==1||tab==2||tab==0))
       {
           cout <<"��������ȷѡ��0~2����";
           cin>>tab;
       }
       char str[2][18],ta;
       if(tab==0)
           return -1;
       else if(tab==1)
       {
           cout <<"�����뺽��ţ�";
           cin>>str[0];
           ta='1';
       }
       else{
        cout<<"��������ʼվ��";
        cin>>str[0];
        cout<<"�������յ�վ��";
        cin>>str[1];
        ta='2';
       }
       for(int i=0;i<m_sum;i++)
       {
           if(v_array[i].if_match(str,ta))
           {
               cout<<"��Ҫ��ѯ�Ľ�����£�\n"<<"________________________\n"<<"|�����|��ʼվ|�յ�վ                 |���ʱ��|Ʊ��|��Ʊ" <<"______________________\n"<<endl;
               /// v_array[i].Display();
                if(invoke==0)
                {
                    cout<<"��������������˵���";
                    char c;
                    cin>>c;
                }
                return i;
           }
       }
       cout<<"��Ǹ!����ѯ�ĺ��಻���ڣ�"<<endl;
       return -1;
}


//��Ʊ����Ʊ
bool Manage::BookRefund()
{
    while (1)
    {
        cout
        <<"*****************��ӭ�����Ʊ����ϵͳ******************\n\n"
        <<"________________________________________________________\n"
        <<"��ѡ��\t\t\t\t\t***\n***\t>>1_____��Ʊ\t>>2_______��Ʊ\t>>0______�������˵�      ****\n"<<"_______________________________________________"<<endl;
        int tab;
        cin>>tab;
        while (!(tab==1||tab==2||tab==0))
        {
            cout<<"��������ȷ��ѡ��0~2��:";
            cin>>tab;
        }
        char ta;
        switch(ta)
        {
        case 1:
            {
                cout<<"��������Ҹú���:";<<endl;
                int i;
                i=Search(1);
                if(i!=-1&&v_array[i].Book())
                {
                    cout <<"��ȷ�϶�Ʊ\\Y����   ��ȡ����Ʊ\\N��  \��ѡ��";
                    do
                    {
                        cin>>ta;
                    }while(!(ta=='Y'||ta=='y'||ta=='N'||ta=='n'));
                    if(ta=='Y'||ta=='y')
                    {
                        Save_file();
                        cout<<"��Ʊ�ɹ�!"<<endl;
                    }
                }
                break;
            }
        case 2:
            {
                char str[1][18];
                Read_file();
                cout<<"�����뺽��ţ�";
                cin>>str[0];
                int i=0;
                for(;i<m_sum;i++)
                {
                    if(v_array[i].If_takeoff())
                        continue;
                    if(v_array[i].If_match(str,'I'))
                    {
                        v_array[i].Refund();
                        cout<<"��ȷ����Ʊ\\Y��  ��ȡ����Ʊ\\N��\n ��ѡ��";
                        do
                        {
                            cin>>ta;
                        }while(!(ta=='Y'||ta=='y'||ta=='N'||ta=='n'));
                        if(ta=='Y'||ta=='y')
                        {
                            Save_file();
                            cout<<"��Ʊ�ɹ�!"<<endl;
                        }
                        break;
                    }
                }
                if(i==m_sum)
                {
                    cout<<"�����ڸú����ú�������ɣ�������Ʊ��"<<endl;
                    break;
                }
            }
        case 0:
            return;
        }
    }
}

#endif // MANAGE_SYSTEM_H_INCLUDED
