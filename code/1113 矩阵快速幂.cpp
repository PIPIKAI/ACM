#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
const int N=200;
int temp [200][200];
void multi(ll a[][200],ll b[][200],ll n)
{
    memset(temp,0,sizeof temp);
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        for(ll k=0;k<n;k++)
            temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            a[i][j]=temp[i][j];
}
ll s[200][200];
void qpow(ll a[][N],ll n,ll m)
{
    memset(s,0,sizeof s);
    for(ll i=0;i<n;i++) s[i][i]=1;
    while(m)
    {
        if(m&1)
            multi(s,a,n);
        multi(a,a,n);
        m>>=1;
    }
     for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        cout<<s[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    ll a[200][200],b[200][200];
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    for(ll j=0;j<n;j++)
        cin>>a[i][j];
    qpow(a,n,m);
    return 0;
}
