#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[10001];
int main()
{
    int t;
    f[1]=2;
    for(int i=2;i<=10000;i++)
    {
        f[i]=f[i-1]+4*(i-1)+1;
    }
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<f[n]<<endl;
    }
    return 0;
}

