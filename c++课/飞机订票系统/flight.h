#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
class Flight   /// ����
{
public :
    string num_f;///�����
    string ftime;///���ʱ��
    string fstar;///��ʼվ
    string fend;///�յ�վ
    int  fprice;///Ʊ��
    int  fseat;///Ʊ��

    bool setinfo();///���ú�����Ϣ
    void dis();///��ʾ
    void refund();///��Ʊ
    bool book();///��Ʊ
    bool takeoff();///�ж��Ƿ����
    bool deleted();///�ж��Ƿ�ɾ��
};

Flight::bool deleted()
{
    cout<<"��Ҫɾ���ĺ���Ϊ��\n"
    <<"-----------------------------------------------------\n"
	<<"| �����  |    ��ʼֵ    |    �յ�վ    | ���ʱ�� | Ʊ�� | ��Ʊ |"
	<<"-----------------------------------------------------\n";
}
Flight::void dis()
{

cout<<"*************************************************\n***>>1----������Ų�ѯ     >>2----��վ���ѯ    >>0----����***\n*************************************************\n��ѡ��0~2����"<<endl;
    cout<<"\t ������Ϣ����\n"
    <<"-----------------------------------------------------\n"
	<<"|  �����  |    ��ʼվ    |    �յ�վ    | ���ʱ�� | Ʊ�� | ��Ʊ |"
	<<"-----------------------------------------------------\n";

}
#endif // FLIGHT_H_INCLUDED
