#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
typedef long long ll;
int MM=1e6+32;
ll f[2000000];
inline int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}
int main()
{
    ll n,maxn=0;
    ll ans=0;
    n=read();
    for(int i=0;i<n;i++)
    {
        ll t;
        t=read();
        f[t]++;
    }
    for(int i=0;i<=2000000;i++)
    {
        f[i+1]+=f[i]>>1;
       ans+=f[i]&1;
    }
    cout<<ans;
    return 0;
}
