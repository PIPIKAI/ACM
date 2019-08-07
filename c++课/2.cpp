#include<bits/stdc++.h>
using namespace std;
class Library
{
protected :
    char car[50],book[50];
public :
    Library(char rtc[],char tb[])
    {
        strcpy(car,rtc);
        strcpy(book,tb);
    }
    void DispLib()
    {
        cout<<"所借的卡号是 :"<<car<<endl;
         cout<<"所借的书名是: "<<book<<endl;
    }
};
class Student
{
protected :
    char name[50];
public :
    Student(char tn[])
    {
      strcpy(name,tn);
    }
    void DispStu()
    {
        cout<<"该学生姓名为："<<name<<endl;
    }
};
class Reader: public Library,public Student
{
protected:
    char dataj[10];
    char datah[10];
public:
    Reader(char tn[],char rtc[], char tb[],char tj[],char th[]):Student(tn),Library(rtc,tb)
        {
             strcpy(dataj,tj);
            strcpy(datah,th);
        }
        void find(char f[])
        {
            if(strcmp( f , name)==0)
            {
                cout<<"找到该学生!"<<endl<<"该学生信息为："<<endl;
                dis();
            }
            else
            {
                cout<<"没有找到该学生!"<<endl;
            }
        }
        void dis()
        {
            DispStu();
            DispLib();
            cout<<"借书日期:"<<dataj<<endl;
            cout<<"还书日期:"<<datah<<endl;
        }
};
int main()
{
    Reader r("张三","123","平凡的世界","20180101","20180205");
    r.dis();
    cout<<endl<<endl;
    r.find("张三");
    return 0;
}
