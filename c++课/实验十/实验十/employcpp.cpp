#include<iostream>
#include"employee.h"
using namespace std;
//���췽��
Employee::Employee()
{}
Employee::Employee(char *name,double salary)
{
	this->name = name;
	this->salary = salary;
}
//��ӡԱ����Ϣ
void Employee::print()
{
	cout<<"������"<<this->name<<endl;
	cout<<"нˮ��"<<this->salary<<endl;
}