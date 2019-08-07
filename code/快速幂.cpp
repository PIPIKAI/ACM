#include<iostream>
using namespace std;
int ss(int a,int n)
{
    int s=1;
    while(n>0)
    {
        if(n%2)
            s*=a;

        a*=a;
        n/=2;
    }
    return s;

}
int main()
{

    cout<<ss(3,5);
    return 0;
}
