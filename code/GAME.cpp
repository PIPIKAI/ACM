#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int f[2000];
        for(int i=0;i<n;i++)
            cin>>f[i];
        sort(f,f+n);
        if(n&1)
        cout<<f[n/2]<<endl;
        else
        cout<<f[n/2-1]<<endl;
    }
    return 0;
}
