#ifndef Employee_H
#define Employee_H
class Employee
{
public:
	//���췽��
	Employee();
	Employee(char *name,double salary);
	//��ӡԱ����Ϣ
	virtual void print();
	char * getName();
	double getSalary();
	void setSalary(double a);
	//������
	 void pay() ;
private:
	char *name;
	double salary;
};
#endif