#include<bits/stdc++.h>
using namespace std;
class course
{
public:
    course(char *cname)
    {
        this->cname=cname;
        cout<<"�������"<<endl;
    }
    ~course()
    {
        cout<<"�ε�����"<<endl;
    }
private :
    char *cname;
};
class person
{
public :
    person(char *name ,int age)
    {
        cout<<"�ڸ�����˵Ĺ��캯����"<<endl;
        this->name=name;
        this->age=age;
    }
    ~person()
    {
        cout<<"�ڸ�����������"<<endl;
    }
protected :
    char *name;
    int age;
};
class student : public person
{
public :
    student(char *name,int age,int id,)
    :person(name,age)course(char cname)
    {
        this->age=age;
        this->name=name;
        this->id=id;
        this->cname=cname;
        cout<<"������ѧ���Ĺ��캯����"<<endl;
    }
private:
    int id;
    /// ��Ա���ԣ������Ա
    course c;
};
int main()
{
    std::ios::sync_with_stdio(false);
    student s("����",20,12);
    return 0;
}
/// �������ٿ��˺��Լ�
/// �����Ļ��Ƿ�������
