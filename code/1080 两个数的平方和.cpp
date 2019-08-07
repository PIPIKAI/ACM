#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,flag=1;
    cin>>n;
    for(int i=0;i<=sqrt(n);i++)
    {
        int a=sqrt(n-i*i);
        if(a*a+i*i==n&&i<=a)
        {
            flag=0;
            cout<<i<<" "<<a<<endl;
        }
    }
    if(flag)
        cout<<"No Solution"<<endl;
    return 0;
}
