#include<iostream>
#include"employee.h"
#include"internhead.h"
#include"Programmer_head.h"
#include"Managerhead.h"
using namespace std;
void main()
{
	Intern a1(6,"����",20000);
	Programmer a2(3,"����",5000);
	Manager a3("С��","����",8000);
	a1.print();
	a2.print();
	a3.print();
	system("pause");
}