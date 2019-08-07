#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class peopel
{
public :///虚函数
    virtual void cut()
    {
        cout<<"是人就会cut"<<endl;
    }
};
class actor :public peopel///演员
{
public :
    void cut()
    {
        cout<<"停止表演"<<endl;
    }
};
class doc :public peopel///医生
{
public :
    void cut()
    {
        cout<<"开始动手术"<<endl;
    }
};
class lif :public peopel///理发师
{
public :
    void cut()
    {
        cout<<"开始剪头发"<<endl;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    lif c;
    doc b;
    actor a;
    ///向上引用
    peopel *p[3];
    p[0]=&a;
    p[1]=&b;
    p[2]=&c;
    for(int i=0;i<3;i++)
        p[i]->cut();
    return 0;
}
