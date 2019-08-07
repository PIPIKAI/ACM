#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
/*******************************************/
///浅拷贝
class Cat
{
    public:
    char *col;
    static int num;
    Cat(char *c)
    {
        ///动态内存分配
        this -> col=new char [strlen(c)+1];
        strcpy(this->col, c);

    }
    Cat (Cat & C1)
    {
        /**浅拷贝*/
        this->col = C1.col;
        /*******/

        /**深拷贝*/
        this -> col=new char [strlen(c)+1];
        strcpy(this->col, C1.col);
        /***********/
    }
    void display()
    {
        cout<<this->col<<" 颜色的猫正在玩耍 "<<endl;
        //play();
    }
    ~Cat()
    {
        if(Cat::num==0)
        {
            delete [] this->col ;
            cout<<"析构了一只猫 "<<endl;
        }
        Cat::num++;

    }
};
int Cat::num=0;
int main()
{
    Cat c("red");
    Cat  c1(c);
    c1.display();
    strcpy(c1.col,"blue");
    c.display();
    c1.display();
    return 0;
}
// 静态的只能访问静态的
