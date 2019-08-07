#include<bits/stdc++.h>
using namespace std;
long long  f[51];
int main()
{
    int t;
    f[0]=1;
    f[1]=1;
    for(int i=2;i<=50;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        if(a==b)
        cout<<"0"<<endl;
        else
        cout<<f[b-a]<<endl;
    }
    return 0;
}

