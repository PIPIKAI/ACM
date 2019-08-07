#include<bits/stdc++.h>
using namespace std;
class Father
{
public:
    char *name;
protected :
    double income;
private :
    int id;
~Father()
{
    cout<<""
}
};
class son:private Father
{
public :
    void dis()
    {
        cout<<"存款有"<<this->income<<" 元。"<<endl;
    }
};
int main()
{
    son s;
    Grandson g;
    return 0;
}

/**
public      到处友好
protected   本类友好  父子友好 友元友好
private     本类友好  友元友好

基类的私有成员派生类内部成员无法直接访问

在保护继承下父类的所有成员在子类当值最高的访问权限只能是受保护的
*/
