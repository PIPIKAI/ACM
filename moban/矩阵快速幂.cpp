#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4;
ll n,mod=1e9+9, k[10];
ll temp[N][N];
void multi(ll a[][N],ll b[][N],ll n)
{
    memset(temp,0,sizeof temp);
    for(ll i=0;i<n;i++)
       for(ll k=0;k<n;k++)
         for(ll j=0;j<n;j++)
            if(a[i][k])
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
    while(m)
    {
        if(m&1)
            multi(s,a,n);
        multi(a,a,n);
        m>>=1;
    }
     for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        a[i][j]=s[i][j];
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
    ll n,k,p;
    while(cin>>n)
    {
        ll ans=0,a[4][4];
        memset(a,0,sizeof a);
         for (int i = 0; i < 4; ++i)
        for (int j = i; j < 4; ++j)
            a[i][j] = 1;
        a[0][0] = a[0][2] = a[1][2] = 2;
        ///n%=mod;
        qpow(a,4,n);
        ans=(a[0][3])%mod;
        cout<<ans<<endl;
    }
   return 0;
}