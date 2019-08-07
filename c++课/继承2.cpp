#include<bits/stdc++.h>
using namespace std;
class course
{
public:
    course(char *cname)
    {
        this->cname=cname;
        cout<<"构造课类"<<endl;
    }
    ~course()
    {
        cout<<"课的析构"<<endl;
    }
private :
    char *cname;
};
class person
{
public :
    person(char *name ,int age)
    {
        cout<<"在父类个人的构造函数中"<<endl;
        this->name=name;
        this->age=age;
    }
    ~person()
    {
        cout<<"在父类析构函数"<<endl;
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
        cout<<"在子类学生的构造函数中"<<endl;
    }
private:
    int id;
    /// 成员属性，对象成员
    course c;
};
int main()
{
    std::ios::sync_with_stdio(false);
    student s("张三",20,12);
    return 0;
}
/// 先祖先再客人后自己
/// 析构的话是反过来的
