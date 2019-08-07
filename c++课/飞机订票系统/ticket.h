#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include"passenger.h"
#include"flight.h"
class Ticket : public Passenger :public Flight
{
    bool take;///是否被取
    void tinit();/// 初始化票
    bool trevise();/// 修改票的信息
};

#endif // TICKET_H_INCLUDED
