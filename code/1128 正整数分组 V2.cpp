#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[50100];
int main()
{
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>f[i],f[i]+=f[i-1];
        for(int i=0;i<n;i++)
            cout<<f[i]<<" ";
    return 0;
}
