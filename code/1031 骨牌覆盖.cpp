#include<iostream>
using namespace std;
int mod=1e9+7;
int f[1005];
int main()
{
    int n;
    f[1]=0,f[2]=2,f[3]=3;
    cin>>n;
    for(int i=4;i<=n;i++)
    {
        f[i]=(f[i-1]+f[i-2])%mod;
    }
    cout<<f[n];
    return 0;
}
