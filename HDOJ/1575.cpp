#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=11;
ll n,mod=9973;
ll temp[N][N];
void multi(ll a[][N],ll b[][N],ll n)
{
    memset(temp,0,sizeof temp);
   for(ll i=0;i<n;i++)
       for(ll k=0;k<n;k++)
            if(a[i][k])
                for(ll j=0;j<n;j++)
                    temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%mod;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
            a[i][j]=temp[i][j];
}
ll s[N][N];
void qpow(ll a[][N],ll n,ll m)
{
    memset(s,0,sizeof s);
    for(ll i=0;i<n;i++) s[i][i]=1;
    while(m){
        if(m&1) multi(s,a,n);
        multi(a,a,n);m>>=1;
    }
     for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        a[i][j]=s[i][j];
}
void dis(ll a[][N],ll n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    ll k;
    int t;
while(cin>>t)
{
    while(t--)
    {
        cin>>n>>k;
        ll a[N][N],ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>a[i][j];
        qpow(a,n,k);
        for(int i=0;i<n;i++)
           ans=(ans+a[i][i])%mod;
        cout<<ans<<endl;
    }
}
   return 0;
}


