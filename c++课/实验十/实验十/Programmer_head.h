#include"employee.h"
class Programmer:public Employee
{
public:
	Programmer(int averageOT,char *name,double salary);
	Programmer();
	void print();
private:
	int averageOT;
	static int Lunch ;
	static int House ;
	static int Hospital ;
};