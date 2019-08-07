#include"employee.h"
class Manager:public Employee
{
public:
	Manager(char  *secretaryName,char *name,double salary);
	Manager();
	void print();
private:
	char *secretaryName;
	static int Lunch;
	static int House;
	static int Hospital;
	static int Carrer;
};