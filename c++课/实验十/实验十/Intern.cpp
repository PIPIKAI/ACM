#include<iostream>
#include"employee.h"
#include"internhead.h"
using namespace std;
Intern::Intern(int periodOfInternShip,char *name,double salary)
	:Employee(name,salary)
{
	this->periodOfInternShip = periodOfInternShip;
}
Intern::Intern()
{}
void Intern::print()
{
	Employee::print();
	cout<<"ÊµÏ°ÆÚ£º"<<this->periodOfInternShip<<endl<<endl;
}