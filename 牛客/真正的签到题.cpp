#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5;
ll n,mod=1e9+7, k[5];
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
   ios::sync_with_stdio(false);
    ll a[N][N];
    k[0]=1;k[1]=2;k[2]=4;k[3]=8;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ll ans=0;
        if(n<4)
        {
            cout<<k[n]<<endl;
            continue;
        }
        memset(a,0,sizeof a);
        for(int i=0;i<4;i++)
            a[0][i]=1;
        for(int i=1;i<4;i++)
            a[i][i-1]=1;
        qpow(a,4,n-3);
        for(int i=0;i<4;i++)
            ans=(ans+a[0][i]*k[4-i-1])%mod;
        cout<<ans<<endl;
    }
   return 0;
}
