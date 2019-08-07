#include<bits/stdc++.h>
using namespace std;
int f[35][35]={0};
void ini()
{
    f[1][1]=1;
    for(int i=2;i<=31;i++)
    {
        for(int j=1;j<=i;j++)
            f[i][j]=f[i-1][j]+f[i-1][j-1];
    }
}
int main()
{
    int n;
    ini();
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<f[i][j];
                if(j!=i)
                cout<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
