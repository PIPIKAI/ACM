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
        cout<<"����Ŀ����� :"<<car<<endl;
         cout<<"�����������: "<<book<<endl;
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
        cout<<"��ѧ������Ϊ��"<<name<<endl;
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
                cout<<"�ҵ���ѧ��!"<<endl<<"��ѧ����ϢΪ��"<<endl;
                dis();
            }
            else
            {
                cout<<"û���ҵ���ѧ��!"<<endl;
            }
        }
        void dis()
        {
            DispStu();
            DispLib();
            cout<<"��������:"<<dataj<<endl;
            cout<<"��������:"<<datah<<endl;
        }
};
int main()
{
    Reader r("����","123","ƽ��������","20180101","20180205");
    r.dis();
    cout<<endl<<endl;
    r.find("����");
    return 0;
}
