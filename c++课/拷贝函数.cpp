#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f
#define mem(a,b)  memset( a,b,sizeof a)
/*******************************************/
///ǳ����
class Cat
{
    public:
    char *col;
    static int num;
    Cat(char *c)
    {
        ///��̬�ڴ����
        this -> col=new char [strlen(c)+1];
        strcpy(this->col, c);

    }
    Cat (Cat & C1)
    {
        /**ǳ����*/
        this->col = C1.col;
        /*******/

        /**���*/
        this -> col=new char [strlen(c)+1];
        strcpy(this->col, C1.col);
        /***********/
    }
    void display()
    {
        cout<<this->col<<" ��ɫ��è������ˣ "<<endl;
        //play();
    }
    ~Cat()
    {
        if(Cat::num==0)
        {
            delete [] this->col ;
            cout<<"������һֻè "<<endl;
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
// ��̬��ֻ�ܷ��ʾ�̬��
