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
	cout<<"ʵϰ�ڣ�"<<this->periodOfInternShip<<endl<<endl;
}