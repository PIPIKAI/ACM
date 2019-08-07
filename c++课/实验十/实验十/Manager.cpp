#include<iostream>
#include"employee.h"
#include"Programmer_head.h"
#include"Managerhead.h"
using namespace std;
Manager::Manager(char  *secretaryName,char *name,double salary)
	:Employee(name,salary)
{
	this->secretaryName = secretaryName;
}
Manager::Manager()
{}
void Manager::print()
{
	Employee::print();
	cout<<"ÃØÊéÊÇ£º"<<this->secretaryName<<endl<<endl;
}