#include<bits/stdc++.h>
using namespace std;
int f[57];
int main()
{
    int n;
    memset(f,0,sizeof f);
    f[0]=1;
    for(int i=1;i<=56;i++)
    {
        if(i<=4)
            f[i]=i;
        else
            f[i]=f[i-1]+f[i-3];
    }
    while(cin>>n,n!=0)
    {
        cout<<f[n]<<endl;
    }
    return 0;
}

