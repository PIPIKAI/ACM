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
        cout<<"�����"<<this->income<<" Ԫ��"<<endl;
    }
};
int main()
{
    son s;
    Grandson g;
    return 0;
}

/**
public      �����Ѻ�
protected   �����Ѻ�  �����Ѻ� ��Ԫ�Ѻ�
private     �����Ѻ�  ��Ԫ�Ѻ�

�����˽�г�Ա�������ڲ���Ա�޷�ֱ�ӷ���

�ڱ����̳��¸�������г�Ա�����൱ֵ��ߵķ���Ȩ��ֻ�����ܱ�����
*/
