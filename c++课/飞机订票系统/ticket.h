#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include"passenger.h"
#include"flight.h"
class Ticket : public Passenger :public Flight
{
    bool take;///�Ƿ�ȡ
    void tinit();/// ��ʼ��Ʊ
    bool trevise();/// �޸�Ʊ����Ϣ
};

#endif // TICKET_H_INCLUDED
