#include"employee.h"
class Intern:public Employee
{
public:
	Intern(int periodOfInternShip,char *name,double salary);
	Intern();
	void print();
private:
	int periodOfInternShip;
	static int Lunch;
};