#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    return a%b?gcd(b,a%b):b;
}
long long lcm(long long a,long long b)
{
    long long p=a*b;
    return p/gcd(a,b);
}
int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<lcm(a,b);
    return 0;
}
