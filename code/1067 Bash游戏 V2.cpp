#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    memset(f,0,sizeof(f));
    int t;
    cin>>t;
    int n,k;
    while(cin>>n>>k)
    {
        int flag=0;
        if(n%(k+1))
            flag=1;
        if(flag)
            cout<<"A"<<endl;
        else
            cout<<"B"<<endl;
    }
    return 0;
}

