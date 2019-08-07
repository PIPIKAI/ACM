#ifndef Employee_H
#define Employee_H
class Employee
{
public:
	//构造方法
	Employee();
	Employee(char *name,double salary);
	//打印员工信息
	virtual void print();
	char * getName();
	double getSalary();
	void setSalary(double a);
	//发工资
	 void pay() ;
private:
	char *name;
	double salary;
};
#endif