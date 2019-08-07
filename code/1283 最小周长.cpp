#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long  n;
    int a,b;
    cin>>n;
    for(int i=1;i<=sqrt(n)+1;i++)
    {
        if(n%i==0)
            a=i;
    }
    b=n/a;
    cout<<2*a+b*2;

    return 0;
}
