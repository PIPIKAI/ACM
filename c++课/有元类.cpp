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
    cout<<"���� course����"<<endl;
    this->id=id;
    strcpy(this->name, n);
}
stu::stu(int id,char *nn,int cid,char *n)
:c(cid,n),id(id)
{
    cout<<"����student����"<<endl;
    strcpy(this->name,nn);
}
stu::~stu()
{
    cout<<"����student��������"<<endl;
}
cou::~cou()
{
    cout<<"����course��������"<<endl;
}
int main()
{
    stu s(2,"����");
    cou c(1,"��ѧ",3,"����");

    return 0;
}
