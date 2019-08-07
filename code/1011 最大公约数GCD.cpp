#include<iostream>
using namespace std;
int GCD(int a,int b)
{
    return a%b?GCD(b,a%b):b;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<GCD(a,b);
    return 0;
}
