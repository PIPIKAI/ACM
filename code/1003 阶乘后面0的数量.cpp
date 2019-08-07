#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,sum=0;
    cin>>n;
    while(n>0)
    {
        n/=5;
        sum+=n;
    }
    cout<<sum<<endl;
    return 0;
}
