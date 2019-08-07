#include<bits/stdc++.h>
using namespace std;int main(){int n,ans=0,f[2000]={0};cin>>n;for(int i=0;i<n;i++)     { int t;cin>>t;if(f[t]==0) ans++,f[t]++;}cout<<ans<<endl;for(int i=0;i<=1000;i++)    if(f[i]!=0)cout<<i<<" ";cout<<endl;return 0;}
