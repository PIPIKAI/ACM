#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class peopel
{
public :///�麯��
    virtual void cut()
    {
        cout<<"���˾ͻ�cut"<<endl;
    }
};
class actor :public peopel///��Ա
{
public :
    void cut()
    {
        cout<<"ֹͣ����"<<endl;
    }
};
class doc :public peopel///ҽ��
{
public :
    void cut()
    {
        cout<<"��ʼ������"<<endl;
    }
};
class lif :public peopel///��ʦ
{
public :
    void cut()
    {
        cout<<"��ʼ��ͷ��"<<endl;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    lif c;
    doc b;
    actor a;
    ///��������
    peopel *p[3];
    p[0]=&a;
    p[1]=&b;
    p[2]=&c;
    for(int i=0;i<3;i++)
        p[i]->cut();
    return 0;
}
