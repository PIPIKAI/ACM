#include<iostream>
#include"employee.h"
#include"Programmer_head.h"
using namespace std;
Programmer::Programmer(int averageOT,char *name,double salary)
	:Employee(name,salary)
{
	this->averageOT = averageOT;
}
Programmer::Programmer()
{}
void Programmer::print()
{
	Employee::print();
	cout<<"¼Ó°àÊ±¼ä£º"<<this->averageOT<<endl<<endl;
}