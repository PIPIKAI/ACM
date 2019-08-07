#include<bits/stdc++.h>
using namespace  std;
int f[300009];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    cout<<f[n-k]-f[0]<<endl;
    return 0;
} 