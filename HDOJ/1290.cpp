#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1001];
int main()
{
    f[1]=2;
    for(int i=2;i<=1000;i++)
    {
        f[i]=f[i-1]+(i-1)*i/2+1;
    }
    int n;
    while(cin>>n)
    {
        cout<<f[n]<<endl;
    }
    return 0;
}

