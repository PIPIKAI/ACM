#include<iostream>
using namespace std;
int f[45];
int main()
{
    int n;
    cin>>n;
    f[1]=1;
    int i,j;
    for(i=2;i<=n;i++)
        f[i]=f[i-1]+f[i-2];
        cout<<f[n];
    return 0;
}
