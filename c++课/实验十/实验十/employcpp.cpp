#include<iostream>
#include"employee.h"
using namespace std;
//构造方法
Employee::Employee()
{}
Employee::Employee(char *name,double salary)
{
	this->name = name;
	this->salary = salary;
}
//打印员工信息
void Employee::print()
{
	cout<<"姓名："<<this->name<<endl;
	cout<<"薪水："<<this->salary<<endl;
}