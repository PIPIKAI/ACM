#include<bits/stdc++.h>
using namespace std;
int f[41];
int main()
{
    int t;
    for(int i=1;i<=40;i++)
    {
        if(i<=2)
            f[i]=1;
        else
            f[i]=f[i-1]+f[i-2];
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

