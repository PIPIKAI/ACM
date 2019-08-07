#include<bits/stdc++.h>
using namespace std;
long long  f[55];
int main()
{
    int t;
    f[0]=0;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<=55;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    while(cin>>t)
    {
        cout<<f[t]<<endl;
    }
    return 0;
}

