#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
double pi=3.1415;
class ani
{
public :///´¿Ðéº¯Êý
    virtual void rua()=0;
};
class cat :public ani///Ô²
{
public :
    void rua()
    {
        cout<<"ß÷ß÷ß÷ß÷"<<endl;
    }

};
class dog :public ani///³¤·½ÐÎ
{
public :
    0void rua()
    {
        cout<<"ÍôÍôÍôÍô"<<endl;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cat c;
    c.rua();
    return 0;
}
