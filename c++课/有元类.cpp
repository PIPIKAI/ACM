#include<bits/stdc++.h>
using namespace std;
class cou
{
private :
    int id;
    char name[50];
public :
    cou(int id,char *name);
    ~cou();
};
class stu
{
public :
    stu(int id,char *name,int cid, char *s);
private :
    int id;
    char name[50];
    cou c;
    ~stu();
};
cou::cou(int id,char *n)
{
    cout<<"构造 course函数"<<endl;
    this->id=id;
    strcpy(this->name, n);
}
stu::stu(int id,char *nn,int cid,char *n)
:c(cid,n),id(id)
{
    cout<<"构造student函数"<<endl;
    strcpy(this->name,nn);
}
stu::~stu()
{
    cout<<"构造student析构函数"<<endl;
}
cou::~cou()
{
    cout<<"构造course析构函数"<<endl;
}
int main()
{
    stu s(2,"张三");
    cou c(1,"数学",3,"李四");

    return 0;
}
