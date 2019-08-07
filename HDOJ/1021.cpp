#include<bits/stdc++.h>
using namespace std;
int f[1000001];
void ini()
{
    f[0]=7;f[1]=11;
    for(int i=2;i<1000000;i++)
    {
        f[i]=f[i-1]+f[i-2];f[i]%=3;
    }
}
int main()
{
    int n;
    ini();
    while(cin>>n)
    {
        if(f[n]%3)
            cout<<"no"<<endl;
        else
            cout<<"yes"<<endl;
    }
    return 0;
}

