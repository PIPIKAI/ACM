#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double pi=3.1415;
class ani
{
public :///���麯��
    virtual void rua()=0;
};
class cat :public ani///Բ
{
public :
    void rua()
    {
        cout<<"��������"<<endl;
    }

};
class dog :public ani///������
{
public :
    0void rua()
    {
        cout<<"��������"<<endl;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cat c;
    c.rua();
    return 0;
}
