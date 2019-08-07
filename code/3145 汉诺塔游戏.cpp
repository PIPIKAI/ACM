#include<iostream>
#include<stdio.h>
using namespace std;
void hnt(int n,char a,char b,char c)
{
    if(n==1)
    {
        cout<<n<<" from "<<a<<" to "<<c<<endl;
        return ;
    }
    hnt(n-1,a,c,b);
    cout<<n<<" from "<<a<<" to "<<c<<endl;
    hnt(n-1,b,a,c);
}
int a(int n)
{
    int s=1;
    while(n>0)
    {
        s<<=1;n--;
    }
    return s;

}
int main()
{
    int m;
    cin>>m;
    cout<<a(m)-1<<endl;
    hnt(m,'A','B','C');
    return 0;
}
